//
//  ContainerViewController.swift
//  FoodApp
//
//  Created by Sergey Yuryev on 01/10/2019.
//  Copyright © 2019 Alan. All rights reserved.
//

import UIKit

class ContainerViewController: UIViewController {
    
    // MARK: - Outlets
    
    /// Menu container view
    @IBOutlet weak var menuContainer: UIView!
    
    /// Checkout container view
    @IBOutlet weak var checkoutContainer: UIView!
    
    /// Checkout button
    @IBOutlet weak var checkoutButton: UIButton!
    
    
    
    // MARK: - View lifecycle

    override func viewDidLoad() {
        super.viewDidLoad()
        
        NotificationCenter.default.addObserver(self, selector: #selector(checkoutItemUpdate(_:)), name: .checkoutItems, object: nil)
    }
    
    
    // MARK: - Helpers
    
    @objc func checkoutItemUpdate(_ notification: Notification) {
        let show = CheckoutManager.shared.getItems().count > 0
        self.showCheckoutButton(show)
        self.updateState()
    }

    func getMenuNavigationController() -> UINavigationController? {
        guard let nc = self.children.first as? UINavigationController else  {
            return nil
        }
        return nc
    }

    func getCheckoutNavigationController() -> UINavigationController? {
        guard let nc = self.children.last as? UINavigationController else  {
            return nil
        }
        return nc
    }
    
    func getCheckoutController() -> CheckoutViewController? {
        guard let nc = self.getCheckoutNavigationController() else {
            return nil
        }
        guard let cc = nc.children.first as? CheckoutViewController else {
            return nil
        }
        return cc
    }
    
    func getMenuController() -> MenuViewController? {
        guard let nc = self.getMenuNavigationController() else {
            return nil
        }
        guard let mc = nc.children.first as? MenuViewController else {
            return nil
        }
        return mc
    }
    
    func getItemController() -> ItemViewController? {
        guard let nc = self.getMenuNavigationController() else {
            return nil
        }
        guard let ic = nc.children.last as? ItemViewController else {
            return nil
        }
        return ic
    }
    
    func getCurrentScreenName() -> String {
        var screen = ""
        guard let title = self.checkoutButton.titleLabel else {
            return screen
        }
        if title.text == "Checkout" {
            screen = "checkout"
        }
        else {
            screen = "main"
        }
        return screen
    }
    
    
    // MARK: - Actions
    
    @IBAction func checkoutButtonTap(_ sender: Any) {
        guard let title = self.checkoutButton.titleLabel else {
            return
        }
        if title.text == "Checkout" {
            self.checkoutButton.setTitle("Finish", for: .normal)
            self.showCheckout()
        }
        else {
            self.checkoutButton.setTitle("Checkout", for: .normal)
            CheckoutManager.shared.removeAllItems()
            self.showMenu()
        }
    }
    
    
    // MARK: - Navigation
    
    func showCheckoutButton(_ show: Bool) {
        self.checkoutButton.isHidden = !show
    }
    
    func showCheckout() {
        DispatchQueue.main.async {
            UIView.animate(withDuration: 0.25, animations: {
                self.menuContainer.alpha = 0
                self.checkoutContainer.alpha = 1
            }) { (finished) in
                if let cc = self.getCheckoutController() {
                    cc.tableView.reloadData()
                    self.updateState()
                }
            }
        }
    }
    
    func showMenu() {
        DispatchQueue.main.async {
            UIView.animate(withDuration: 0.25, animations: {
                self.menuContainer.alpha = 1
                self.checkoutContainer.alpha = 0
            }) { (finished) in
                if let ic = self.getItemController() {
                    ic.collectionView.reloadData()
                    self.updateState()
                }
            }
        }
    }
    
    func showCategory(_ name: String) {
        var shouldUpdate = true
        if let ic = self.getItemController() {
            if let title = ic.title {
                shouldUpdate = title.lowercased() != name.lowercased()
            }
        }
        if shouldUpdate {
            DispatchQueue.main.async {
                if let nc = self.getMenuNavigationController() {
                    nc.popToRootViewController(animated: true)
                    DispatchQueue.main.async {
                        if let mc = self.getMenuController() {
                            mc.showCategory(name)
                        }
                    }
                }
            }
        }
    }

    func checkoutOrder() {
        DispatchQueue.main.async {
            self.checkoutButton.setTitle("Finish", for: .normal)
            self.showCheckout()
        }
    }
    
    func finishOrder() {
        DispatchQueue.main.async {
            self.checkoutButton.setTitle("Checkout", for: .normal)
            CheckoutManager.shared.removeAllItems()
            self.showMenu()
        }
    }
    
    func highlight(name: String) {
        if let category = findCategory(name) {
            self.showCategory(category.name.lowercased())
        }
        DispatchQueue.main.async {
            if let ic = self.getItemController() {
                ic.highlight(name: name)
            }
        }
    }
    
    func updateState() {
        /// get current screen name for script
        let currentScreen = self.getCurrentScreenName()
        /// create empty visual state object
        var visual: [String: Any] = [:]
        /// add current screen
        visual["screen"] = currentScreen
        /// add items for checkout
        var order: [[String: Any]] = []
        for item in CheckoutManager.shared.getItems() {
            let name = item.name.lowercased()
            let quantity = CheckoutManager.shared.itemCount(item)
            let orderItem: [String: Any] = ["title": name, "quantity": quantity]
            order.append(orderItem)
        }
        visual["order"] = order
        /// send visual state object to script
        UIApplication.shared.sendVisual(visual)
    }
}
