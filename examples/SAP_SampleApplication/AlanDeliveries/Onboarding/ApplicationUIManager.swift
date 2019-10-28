//
// AlanDeliveries
//
// Created by SAP Cloud Platform SDK for iOS Assistant application on 24/04/19
//

import SAPCommon
import SAPFiori
import SAPFioriFlows
import SAPFoundation

class SnapshotViewController: UIViewController {}

class ApplicationUIManager: ApplicationUIManaging {
    // MARK: – Properties

    let window: UIWindow

    /// Save ViewController while splash/onboarding screens are presented
    private var _savedApplicationRootViewController: UIViewController?
    private var _onboardingSplashViewController: (UIViewController & InfoTextSettable)?
    private var _coveringViewController: UIViewController?

    // MARK: – Init

    public init(window: UIWindow) {
        self.window = window
        self.window.addAlan()
    }

    // MARK: - ApplicationUIManaging

    func hideApplicationScreen(completionHandler: @escaping (Error?) -> Void) {
        // Check whether the covering screen is already presented or not
        guard self._coveringViewController == nil else {
            completionHandler(nil)
            return
        }

        self.saveApplicationScreenIfNecessary()
        self._coveringViewController = SnapshotViewController()
        self.window.rootViewController = self._coveringViewController

        completionHandler(nil)
    }

    func showSplashScreenForOnboarding(completionHandler: @escaping (Error?) -> Void) {
        // splash already presented
        guard self._onboardingSplashViewController == nil else {
            completionHandler(nil)
            return
        }

        setupSplashScreen()

        completionHandler(nil)
    }

    func showSplashScreenForUnlock(completionHandler: @escaping (Error?) -> Void) {
        guard self._onboardingSplashViewController == nil else {
            completionHandler(nil)
            return
        }

        self.saveApplicationScreenIfNecessary()

        setupSplashScreen()

        completionHandler(nil)
    }

    func showApplicationScreen(completionHandler: @escaping (Error?) -> Void) {
        // Check if an application screen has already been presented
        guard self.isSplashPresented else {
            completionHandler(nil)
            return
        }

        // Restore the saved application screen or create a new one
        let appViewController: UIViewController
        if let savedViewController = self._savedApplicationRootViewController {
            appViewController = savedViewController
        } else {
            let appDelegate = (UIApplication.shared.delegate as! AppDelegate)
            let splitViewController = UIStoryboard(name: "Main", bundle: Bundle.main).instantiateViewController(withIdentifier: "MainSplitViewController") as! UISplitViewController
            splitViewController.delegate = appDelegate
            splitViewController.modalPresentationStyle = .currentContext
            splitViewController.preferredDisplayMode = .allVisible
            appViewController = splitViewController
        }
        self.window.rootViewController = appViewController
        self.window.moveAlanToFront()
        self._onboardingSplashViewController = nil
        self._savedApplicationRootViewController = nil
        self._coveringViewController = nil

        completionHandler(nil)
    }

    func releaseRootFromMemory() {
        self._savedApplicationRootViewController = nil
    }

    // MARK: – Helpers

    private var isSplashPresented: Bool {
        return self.window.rootViewController is FUIInfoViewController || self.window.rootViewController is SnapshotViewController
    }

    /// Helper method to capture the real application screen.
    private func saveApplicationScreenIfNecessary() {
        if self._savedApplicationRootViewController == nil, !self.isSplashPresented {
            self._savedApplicationRootViewController = self.window.rootViewController
        }
    }

    private func setupSplashScreen() {
        self._onboardingSplashViewController = FUIInfoViewController.createSplashScreenInstanceFromStoryboard()
        self.window.rootViewController = self._onboardingSplashViewController

        // Set the splash screen for the specific presenter
        let modalPresenter = OnboardingFlowProvider.modalUIViewControllerPresenter
        modalPresenter.setSplashScreen(self._onboardingSplashViewController!)
        modalPresenter.animated = true
    }
}
