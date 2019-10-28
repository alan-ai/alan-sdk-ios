//
// AlanDeliveries
//
// Created by SAP Cloud Platform SDK for iOS Assistant application on 24/04/19
//

import Foundation

/// Localized strings used by Onboarding
class LocalizedStrings {
    enum AppDelegate {
        static let startDemoModeTitle = NSLocalizedString("keyDemoModeSelectedTitle", value: "Demo Mode", comment: "XTIT: Title of alert action that the demo mode is selected.")
        static let startDemoModeMessage = NSLocalizedString("keyDemoModeSelectedMessage", value: "The Demo mode with Offline OData is not implemented in the generated application.", comment: "XMSG: Message that the user selected the demo mode.")
        static let startDemoModeRestartTitle = NSLocalizedString("keyGoBackButtonTitle", value: "Go back", comment: "XBUT: Title of go back button.")
    }

    enum Onboarding {
        static let failedToLogonTitle = NSLocalizedString("keyErrorLogonProcessFailedTitle", value: "Failed to logon!", comment: "XTIT: Title of alert message about logon process failure.")
        static let retryTitle = NSLocalizedString("keyRetryButtonTitle", value: "Retry", comment: "XBUT: Title of Retry button.")
        static let resetTitle = NSLocalizedString("keyResetButtonTitle", value: "Reset", comment: "XBUT: Title of Reset button.")
        static let passcodeRetryLimitReachedTitle = NSLocalizedString("keyErrorPasscodeRetryLimitReachedTitle", value: "Passcode Retry Limit Reached!", comment: "XTIT: Title of alert action that the passcode retry limit has been reached.")
        static let passcodeRetryLimitReachedMessage = NSLocalizedString("keyErrorPasscodeRetryLimitReachedMessage", value: "Reached the maximum number of retries. Application should be reset.", comment: "XMSG: Message that the application shall be reseted because the passcode retry limit has been reached.")
    }
}
