//
//  CheckoutManager.swift
//  FoodApp
//
//  Created by Sergey Yuryev on 02/10/2019.
//  Copyright © 2019 Alan. All rights reserved.
//

import Foundation

extension Notification.Name {
     static let checkoutItems = Notification.Name("checkoutItems")
}

class CheckoutManager {

    /// Singleton var
    static let shared = CheckoutManager()
    
    /// Items  for checkout
    fileprivate var items: [Item: Int] = [:] {
        didSet {
            NotificationCenter.default.post(name: .checkoutItems, object: nil)
        }
    }
    
    func getItems() -> [Item] {
        var array: [Item] = []
        for item in self.items {
            array.append(item.key)
        }
        return array
    }
    
    func addItem(_ item: Item, quantity: Int = 1) {
        if var itemCount = self.items[item] {
            itemCount += quantity
            self.items[item] = itemCount
        }
        else {
            self.items[item] = 1
        }
    }
    
    func removeItem(_ item: Item, quantity: Int = 1) {
        if var itemCount = self.items[item] {
            itemCount -= quantity
            if itemCount > 0 {
                self.items[item] = itemCount
            }
            else {
                self.items[item] = nil
            }
        }
    }
    
    func removeAllItems() {
        self.items.removeAll()
    }
    
    func itemCount(_ item: Item) -> Int {
        var result = 0
        if let itemCount = self.items[item] {
            result = itemCount
        }
        return result
    }
    
}
