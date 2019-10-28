//
// AlanDeliveries
//
// Created by SAP Cloud Platform SDK for iOS Assistant application on 24/04/19
//

import SAPCommon
import SAPFiori
import SAPFioriFlows
import SAPFoundation

// custom data handling of the application
open class ApplicationOnboardingSession: OnboardingSession {
    var odataController: OnlineODataController

    public required init(flow: OnboardingFlow) {
        guard let step = flow.steps.first(where: { $0 is ODataOnboardingStep }) as? ODataOnboardingStep, let odataController = step.controller else {
            fatalError("Reaching this point is a critical developer error. A successful run must contain an OData step which has a controller")
        }
        self.odataController = odataController

        super.init(flow: flow)
    }
}

public class OnboardingErrorHandler: OnboardingControllerDelegate {
    // MARK: – Init

    public init() {}

    // MARK: - OnboardingControllerDelegate

    /// Application specific error handling
    public func onboardingController(_ controller: OnboardingControlling, didFail flow: OnboardingFlow, with error: Error, completionHandler: @escaping (OnboardingErrorDisposition) -> Void) {
        switch flow.flowType {
        case .onboard:
            self.onboardFailed(with: error, completionHandler: completionHandler)
        case .restore:
            self.restoreFailed(with: error, controller: controller, onboardingID: flow.context.onboardingID, completionHandler: completionHandler)
        default:
            completionHandler(.retry)
        }
    }

    /// Onboarding error handling can be customized here
    public func handleOnboardingError(_ error: Error) {
        switch error {
        case WelcomeScreenError.demoModeRequested:
            AppDelegate.shared.startDemoMode()
        default:
            // An error here means a critical error – the `OnboardingErrorHandler` responded with OnboardingDisposition.stop to stop the onboarding.
            DispatchQueue.main.async {
                AppDelegate.shared.onboardUser()
            }
        }
    }

    /// Unlocking error handling can be customized here
    public func handleUnlockingError(_ error: Error) {
        switch error {
        // We reset the OnboardingSessionManager if the user has chosen to reset their passcode
        case StoreManagerError.resetPasscode:
            self.resetOnboardingSessionManager()
        // We reset the OnboardingSessionManager if the user has exceeded the maximum retry limit
        case StoreManagerError.passcodeRetryLimitReached:
            let alertController = UIAlertController(title: LocalizedStrings.Onboarding.passcodeRetryLimitReachedTitle, message: LocalizedStrings.Onboarding.passcodeRetryLimitReachedMessage, preferredStyle: .alert)
            alertController.addAction(UIAlertAction(title: LocalizedStrings.Onboarding.resetTitle, style: .destructive) { _ in
                self.resetOnboardingSessionManager()
            })

            DispatchQueue.main.async {
                guard let topViewController = ModalUIViewControllerPresenter.topPresentedViewController() else {
                    fatalError("Invalid UI state")
                }
                topViewController.present(alertController, animated: true)
            }
        default:
            return
        }
    }

    // MARK: - Private

    /// Onboarding related error handling
    private func onboardFailed(with error: Error, completionHandler: @escaping (OnboardingErrorDisposition) -> Void) {
        switch error {
        case WelcomeScreenError.demoModeRequested:
            completionHandler(.stop(error))
            return
        default:
            let alertController = UIAlertController(
                title: LocalizedStrings.Onboarding.failedToLogonTitle,
                message: error.localizedDescription,
                preferredStyle: .alert
            )
            alertController.addAction(UIAlertAction(title: LocalizedStrings.Onboarding.retryTitle, style: .default) { _ in
                completionHandler(.retry)
            })

            DispatchQueue.main.async {
                guard let topViewController = ModalUIViewControllerPresenter.topPresentedViewController() else {
                    fatalError("Invalid UI state")
                }
                topViewController.present(alertController, animated: true)
            }
        }
    }

    /// Restoring related error handling
    private func restoreFailed(with error: Error, controller: OnboardingControlling, onboardingID: UUID?, completionHandler: @escaping (OnboardingErrorDisposition) -> Void) {
        let alertController = UIAlertController(title: nil, message: nil, preferredStyle: .alert)

        switch error {
        case StoreManagerError.cancelPasscodeEntry, StoreManagerError.skipPasscodeSetup, StoreManagerError.resetPasscode:
            self.resetOnboarding(onboardingID, controller: controller, completionHandler: completionHandler)
            return
        case StoreManagerError.passcodeRetryLimitReached:
            alertController.title = LocalizedStrings.Onboarding.passcodeRetryLimitReachedTitle
            alertController.message = LocalizedStrings.Onboarding.passcodeRetryLimitReachedMessage
        default:
            alertController.title = LocalizedStrings.Onboarding.failedToLogonTitle
            alertController.message = error.localizedDescription
            alertController.addAction(UIAlertAction(title: LocalizedStrings.Onboarding.retryTitle, style: .default) { _ in
                completionHandler(.retry)
            })
        }

        alertController.addAction(UIAlertAction(title: LocalizedStrings.Onboarding.resetTitle, style: .destructive) { _ in
            self.resetOnboarding(onboardingID, controller: controller, completionHandler: completionHandler)
        })

        DispatchQueue.main.async {
            guard let topViewController = ModalUIViewControllerPresenter.topPresentedViewController() else {
                fatalError("Invalid UI state")
            }
            topViewController.present(alertController, animated: true)
        }
    }

    /// Reset onboarding, then start a new onboarding flow
    private func resetOnboarding(_ onboardingID: UUID?, controller: OnboardingControlling, completionHandler: @escaping (OnboardingErrorDisposition) -> Void) {
        guard let onboardingID = onboardingID else {
            completionHandler(.retry)
            return
        }

        (controller as? OnboardingController)?.resetFlow(for: onboardingID) { _ in
            completionHandler(.retry)
        }
    }

    // Private function that resets the OnboardingSessionManager
    private func resetOnboardingSessionManager() {
        OnboardingSessionManager.shared.removeSession { _ in
            DispatchQueue.main.async {
                let applicationUIManager = OnboardingSessionManager.shared.presentationDelegate as? ApplicationUIManager
                applicationUIManager?.releaseRootFromMemory()
                OnboardingSessionManager.shared.open { _ in }
            }
        }
    }
}
