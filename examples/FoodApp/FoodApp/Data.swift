//
//  Data.swift
//  FoodApp
//
//  Created by Sergey Yuryev on 01/10/2019.
//  Copyright © 2019 Alan. All rights reserved.
//

import Foundation

struct Item: Hashable {
    let name: String
    let imageName: String
    let subitems: [Item]
    
    static func == (lhs: Item, rhs: Item) -> Bool {
        return lhs.name == rhs.name
    }
}


let pizza: [Item] = [
    Item(name: "Pepperoni", imageName: "pizza-pepperoni", subitems: []),
    Item(name: "Margarita", imageName: "pizza-margarita", subitems: []),
    Item(name: "Four cheese", imageName: "pizza-four-cheese", subitems: []),
    Item(name: "Hawaiian", imageName: "pizza-hawaii", subitems: [])
]

let street: [Item] = [
    Item(name: "Burrito", imageName: "street-food-burrito", subitems: []),
    Item(name: "Burger", imageName: "street-food-burger", subitems: []),
    Item(name: "Taco", imageName: "street-food-taco", subitems: []),
    Item(name: "Sandwich", imageName: "street-food-sandwich", subitems: [])
]

let drinks: [Item] = [
    Item(name: "Cola", imageName: "drinks-cola", subitems: []),
    Item(name: "Americano", imageName: "drinks-americano", subitems: []),
    Item(name: "Latte", imageName: "drinks-latte", subitems: []),
    Item(name: "Cappuccino", imageName: "drinks-cappuccino", subitems: []),
    Item(name: "Orange juice", imageName: "drinks-orange-juice", subitems: []),
    Item(name: "Tea", imageName: "drinks-tea", subitems: [])
]

let desserts: [Item] = [
    Item(name: "Apple Pie", imageName: "dessert-apple-pie", subitems: []),
    Item(name: "Cheesecake", imageName: "dessert-cheesecake", subitems: [])
]

let menuItems: [Item] = [
    Item(name: "Pizza", imageName: "pizza-four-cheese", subitems: pizza),
    Item(name: "Street food", imageName: "street-food-burger", subitems: street),
    Item(name: "Drinks", imageName: "drinks-americano", subitems: drinks),
    Item(name: "Dessert", imageName: "dessert-apple-pie", subitems: desserts)
]


func findCategory(_ name: String) -> Item? {
    for item in menuItems {
        for subitem in item.subitems {
            if subitem.name.lowercased() == name.lowercased() {
                return item
            }
        }
    }
    return nil
}

func findItem(_ name: String) -> Item? {
    for item in menuItems {
        for subitem in item.subitems {
            if subitem.name.lowercased() == name.lowercased() {
                return subitem
            }
        }
    }
    return nil
}
