//
// AlanDeliveries
//
// Created by SAP Cloud Platform SDK for iOS Assistant application on 24/04/19
//

import Foundation

enum CollectionType: String {
    case suppliers = "Suppliers"
    case productCategories = "ProductCategories"
    case productTexts = "ProductTexts"
    case purchaseOrderItems = "PurchaseOrderItems"
    case purchaseOrderHeaders = "PurchaseOrderHeaders"
    case stock = "Stock"
    case salesOrderItems = "SalesOrderItems"
    case customers = "Customers"
    case salesOrderHeaders = "SalesOrderHeaders"
    case products = "Products"
    case none = ""
    static let all = [suppliers, productCategories, productTexts, purchaseOrderItems, purchaseOrderHeaders, stock, salesOrderItems, customers, salesOrderHeaders, products]
}
