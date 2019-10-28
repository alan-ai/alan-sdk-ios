//
// AlanDeliveries
//
// Created by SAP Cloud Platform SDK for iOS Assistant application on 24/04/19
//

import Foundation
import SAPCommon
import SAPFioriFlows
import SAPFoundation

open class ODataOnboardingStep: OnboardingStep {
    var controller: OnlineODataController?

    public func onboard(context: OnboardingContext, completionHandler: @escaping (OnboardingResult) -> Void) {
        self.configureOData(using: context, completionHandler: completionHandler)
    }

    public func restore(context: OnboardingContext, completionHandler: @escaping (OnboardingResult) -> Void) {
        self.configureOData(using: context, completionHandler: completionHandler)
    }

    public func reset(context _: OnboardingContext, completionHandler: @escaping () -> Void) {
        completionHandler()
    }

    // Read more about consumption of OData services in mobile applications: https://help.sap.com/viewer/fc1a59c210d848babfb3f758a6f55cb1/Latest/en-US/1c7d937d0c8a43f4aca7175e9051d108.html
    private func configureOData(using context: OnboardingContext, completionHandler: @escaping (OnboardingResult) -> Void) {
        // Adjust this path so it can be called after authentication and returns an HTTP 200 code. This is used to validate the authentication was successful.
        let configurationURL = URL(string: "https://hcpms-p2001280901trial.hanatrial.ondemand.com/app.alan.saptest")!

        do {
            let onlineOdataController = OnlineODataController()
            try onlineOdataController.configureOData(sapURLSession: context.sapURLSession, serviceRoot: configurationURL)

            self.controller = onlineOdataController
            completionHandler(.success(context))
        } catch {
            completionHandler(.failed(error))
        }
    }
}
