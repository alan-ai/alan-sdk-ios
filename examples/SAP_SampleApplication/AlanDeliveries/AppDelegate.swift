//
// AlanDeliveries
//
// Created by SAP Cloud Platform SDK for iOS Assistant application on 24/04/19
//

import Foundation
import SAPCommon
import SAPFiori
import SAPFioriFlows
import SAPFoundation
import SAPOData
import UserNotifications

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, UISplitViewControllerDelegate, UNUserNotificationCenterDelegate {
    var window: UIWindow?
    /// Logger instance initialization
    private let logger = Logger.shared(named: "AppDelegateLogger")
    private var flowProvider = OnboardingFlowProvider()

    /// Delegate implementation of the application in a custom class
    var onboardingErrorHandler: OnboardingErrorHandler?

    /// Application controller instance for the application
    var sessionManager: OnboardingSessionManager<ApplicationOnboardingSession>!

    func application(_: UIApplication, didFinishLaunchingWithOptions _: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        self.initializeLogUploader()
        // Set a FUIInfoViewController as the rootViewController, since there it is none set in the Main.storyboard
        // Also, hide potentially sensitive data of the real application screen during onboarding
        self.window = UIWindow(frame: UIScreen.main.bounds)
        self.window!.rootViewController = FUIInfoViewController.createInstanceFromStoryboard()

        // Read more about Logging: https://help.sap.com/viewer/fc1a59c210d848babfb3f758a6f55cb1/Latest/en-US/879aaebaa8e6401dac100ea9bb8b817d.html
        Logger.root.logLevel = .debug

        self.initializeOnboarding()

        // Customize the UI to align SAP style
        // Read more: https://help.sap.com/doc/978e4f6c968c4cc5a30f9d324aa4b1d7/Latest/en-US/Documents/Frameworks/SAPFiori/Extensions/UINavigationBar.html
//        UINavigationBar.applyFioriStyle()

        return true
    }

    func applicationDidEnterBackground(_: UIApplication) {
        // Hides the application UI by presenting a splash screen, @see: ApplicationUIManager.hideApplicationScreen
        OnboardingSessionManager.shared.lock { _ in }
    }

    func applicationWillEnterForeground(_: UIApplication) {
        // Triggers to show the passcode screen
        OnboardingSessionManager.shared.unlock { error in
            guard let error = error else {
                return
            }

            self.onboardingErrorHandler?.handleUnlockingError(error)
        }
    }

    // MARK: - UISplitViewControllerDelegate

    func splitViewController(_: UISplitViewController, collapseSecondary _: UIViewController, onto _: UIViewController) -> Bool {
        // The first Collection will be selected automatically, so we never discard showing the secondary ViewController
        return false
    }

    func application(_: UIApplication, supportedInterfaceOrientationsFor _: UIWindow?) -> UIInterfaceOrientationMask {
        // Onboarding is only supported in portrait orientation
        switch OnboardingFlowController.presentationState {
        case .onboarding, .restoring:
            return .portrait
        default:
            return .allButUpsideDown
        }
    }
}

// Convenience accessor for the AppDelegate
extension AppDelegate {
    static var shared: AppDelegate {
        return (UIApplication.shared.delegate as! AppDelegate)
    }
}

// MARK: – Onboarding related functionality

// MARK: OnboardingSessionManager helper extension

extension OnboardingSessionManager {
    static var shared: OnboardingSessionManager<ApplicationOnboardingSession>! {
        return AppDelegate.shared.sessionManager
    }
}

extension AppDelegate {
    /// Setup an onboarding session instance
    func initializeOnboarding() {
        let presentationDelegate = ApplicationUIManager(window: self.window!)
        self.onboardingErrorHandler = OnboardingErrorHandler()
        self.sessionManager = OnboardingSessionManager(presentationDelegate: presentationDelegate, flowProvider: self.flowProvider, delegate: self.onboardingErrorHandler)
        presentationDelegate.showSplashScreenForOnboarding { _ in }

        self.onboardUser()
    }

    /// Start demo mode
    func startDemoMode() {
        let alertController = UIAlertController(
            title: LocalizedStrings.AppDelegate.startDemoModeTitle,
            message: LocalizedStrings.AppDelegate.startDemoModeMessage,
            preferredStyle: .alert
        )
        alertController.addAction(
            UIAlertAction(title: LocalizedStrings.AppDelegate.startDemoModeRestartTitle, style: .default) { _ in
                self.onboardUser()
        })

        DispatchQueue.main.async {
            guard let topViewController = ModalUIViewControllerPresenter.topPresentedViewController() else {
                fatalError("Invalid UI state")
            }
            topViewController.present(alertController, animated: true)
        }
    }

    /// Application specific code after successful onboard
    func afterOnboard() {
        guard let _ = self.sessionManager.onboardingSession else {
            fatalError("Invalid state")
        }

        self.initializeRemoteNotification()
        self.uploadLogs()
    }

    /// Start onboarding a user
    func onboardUser() {
        self.sessionManager.open { error in
            if let error = error {
                self.onboardingErrorHandler?.handleOnboardingError(error)
                return
            }
            self.afterOnboard()
        }
    }
}

// MARK: - Remote notification handling

extension AppDelegate {
    // Read more about Remote Notifications on mobile services: https://help.sap.com/doc/978e4f6c968c4cc5a30f9d324aa4b1d7/Latest/en-US/Documents/Frameworks/SAPFoundation/Remote%20Notifications.html

    func initializeRemoteNotification() {
        // Registering for remote notifications
        UIApplication.shared.registerForRemoteNotifications()
        let center = UNUserNotificationCenter.current()
        center.requestAuthorization(options: [.alert, .badge, .sound]) { _, _ in
            // Enable or disable features based on authorization.
        }
        center.delegate = self
    }

    func uploadDeviceTokenForRemoteNotification(_ deviceToken: Data) {
        guard let session = sessionManager.onboardingSession else {
            // Onboarding not yet performed
            return
        }
        let parameters = SAPcpmsRemoteNotificationParameters(deviceType: "iOS")
        session.registerDeviceToken(deviceToken: deviceToken, withParameters: parameters) { error in
            if let error = error {
                self.logger.error("Register DeviceToken failed", error: error)
                return
            }
            self.logger.info("Register DeviceToken succeeded")
        }
    }

    // MARK: AppDelegate method implementations for remote notification handling

    func application(_: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
        self.uploadDeviceTokenForRemoteNotification(deviceToken)
    }

    func application(_: UIApplication, didFailToRegisterForRemoteNotificationsWithError error: Error) {
        self.logger.error("Failed to register for Remote Notification", error: error)
    }

    // Called to let your app know which action was selected by the user for a given notification.
    func userNotificationCenter(_: UNUserNotificationCenter, didReceive response: UNNotificationResponse, withCompletionHandler completionHandler: @escaping () -> Void) {
        self.logger.info("App opened via user selecting notification: \(response.notification.request.content.body)")
        // Here is where you want to take action to handle the notification, maybe navigate the user to a given screen.
        completionHandler()
    }

    // Called when a notification is delivered to a foreground app.
    func userNotificationCenter(_: UNUserNotificationCenter, willPresent notification: UNNotification, withCompletionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void) {
        self.logger.info("Remote Notification arrived while app was in foreground: \(notification.request.content.body)")
        // Currently we are presenting the notification alert as the application were in the background.
        // If you have handled the notification and do not want to display an alert, call the completionHandler with empty options: completionHandler([])
        completionHandler([.alert, .sound])
    }
}

// MARK: - Log upload initialization and handling

// Read more about Log upload: https://help.sap.com/doc/978e4f6c968c4cc5a30f9d324aa4b1d7/Latest/en-US/Documents/Frameworks/SAPFoundation/Log%20Upload.html
extension AppDelegate {
    private func initializeLogUploader() {
        do {
            // Attaches a LogUploadFileHandler instance to the root of the logging system
            try SAPcpmsLogUploader.attachToRootLogger()
        } catch {
            self.logger.error("Failed to attach to root logger.", error: error)
        }
    }

    private func uploadLogs() {
        guard let session = self.sessionManager.onboardingSession else {
            // Onboarding not yet performed
            return
        }
        // Upload logs after onboarding
        SAPcpmsLogUploader.uploadLogs(session) { error in
            if let error = error {
                self.logger.error("Error happened during log upload.", error: error)
                return
            }
            self.logger.info("Logs have been uploaded successfully.")
        }
    }
}
