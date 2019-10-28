// # Proxy Compiler 19.1.3-b8851a-20190408

import Foundation
import SAPOData

public class ESPMContainerMetadata {
    private static var document_: CSDLDocument = ESPMContainerMetadata.resolve()

    public static var document: CSDLDocument {
        get {
            objc_sync_enter(ESPMContainerMetadata.self)
            defer { objc_sync_exit(ESPMContainerMetadata.self) }
            do {
                return ESPMContainerMetadata.document_
            }
        }
        set(value) {
            objc_sync_enter(ESPMContainerMetadata.self)
            defer { objc_sync_exit(ESPMContainerMetadata.self) }
            do {
                ESPMContainerMetadata.document_ = value
            }
        }
    }

    private static func resolve() -> CSDLDocument {
        try! ESPMContainerFactory.registerAll()
        ESPMContainerMetadataParser.parsed.hasGeneratedProxies = true
        return ESPMContainerMetadataParser.parsed
    }

    public class ComplexTypes {
        private static var address_: ComplexType = ESPMContainerMetadataParser.parsed.complexType(withName: "ESPM.Address")

        public static var address: ComplexType {
            get {
                objc_sync_enter(ESPMContainerMetadata.ComplexTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.ComplexTypes.self) }
                do {
                    return ESPMContainerMetadata.ComplexTypes.address_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.ComplexTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.ComplexTypes.self) }
                do {
                    ESPMContainerMetadata.ComplexTypes.address_ = value
                }
            }
        }
    }

    public class EntityTypes {
        private static var customer_: EntityType = ESPMContainerMetadataParser.parsed.entityType(withName: "ESPM.Customer")

        private static var product_: EntityType = ESPMContainerMetadataParser.parsed.entityType(withName: "ESPM.Product")

        private static var productCategory_: EntityType = ESPMContainerMetadataParser.parsed.entityType(withName: "ESPM.ProductCategory")

        private static var productText_: EntityType = ESPMContainerMetadataParser.parsed.entityType(withName: "ESPM.ProductText")

        private static var purchaseOrderHeader_: EntityType = ESPMContainerMetadataParser.parsed.entityType(withName: "ESPM.PurchaseOrderHeader")

        private static var purchaseOrderItem_: EntityType = ESPMContainerMetadataParser.parsed.entityType(withName: "ESPM.PurchaseOrderItem")

        private static var salesOrderHeader_: EntityType = ESPMContainerMetadataParser.parsed.entityType(withName: "ESPM.SalesOrderHeader")

        private static var salesOrderItem_: EntityType = ESPMContainerMetadataParser.parsed.entityType(withName: "ESPM.SalesOrderItem")

        private static var stock_: EntityType = ESPMContainerMetadataParser.parsed.entityType(withName: "ESPM.Stock")

        private static var supplier_: EntityType = ESPMContainerMetadataParser.parsed.entityType(withName: "ESPM.Supplier")

        public static var customer: EntityType {
            get {
                objc_sync_enter(ESPMContainerMetadata.EntityTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntityTypes.self) }
                do {
                    return ESPMContainerMetadata.EntityTypes.customer_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.EntityTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntityTypes.self) }
                do {
                    ESPMContainerMetadata.EntityTypes.customer_ = value
                }
            }
        }

        public static var product: EntityType {
            get {
                objc_sync_enter(ESPMContainerMetadata.EntityTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntityTypes.self) }
                do {
                    return ESPMContainerMetadata.EntityTypes.product_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.EntityTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntityTypes.self) }
                do {
                    ESPMContainerMetadata.EntityTypes.product_ = value
                }
            }
        }

        public static var productCategory: EntityType {
            get {
                objc_sync_enter(ESPMContainerMetadata.EntityTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntityTypes.self) }
                do {
                    return ESPMContainerMetadata.EntityTypes.productCategory_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.EntityTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntityTypes.self) }
                do {
                    ESPMContainerMetadata.EntityTypes.productCategory_ = value
                }
            }
        }

        public static var productText: EntityType {
            get {
                objc_sync_enter(ESPMContainerMetadata.EntityTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntityTypes.self) }
                do {
                    return ESPMContainerMetadata.EntityTypes.productText_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.EntityTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntityTypes.self) }
                do {
                    ESPMContainerMetadata.EntityTypes.productText_ = value
                }
            }
        }

        public static var purchaseOrderHeader: EntityType {
            get {
                objc_sync_enter(ESPMContainerMetadata.EntityTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntityTypes.self) }
                do {
                    return ESPMContainerMetadata.EntityTypes.purchaseOrderHeader_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.EntityTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntityTypes.self) }
                do {
                    ESPMContainerMetadata.EntityTypes.purchaseOrderHeader_ = value
                }
            }
        }

        public static var purchaseOrderItem: EntityType {
            get {
                objc_sync_enter(ESPMContainerMetadata.EntityTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntityTypes.self) }
                do {
                    return ESPMContainerMetadata.EntityTypes.purchaseOrderItem_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.EntityTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntityTypes.self) }
                do {
                    ESPMContainerMetadata.EntityTypes.purchaseOrderItem_ = value
                }
            }
        }

        public static var salesOrderHeader: EntityType {
            get {
                objc_sync_enter(ESPMContainerMetadata.EntityTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntityTypes.self) }
                do {
                    return ESPMContainerMetadata.EntityTypes.salesOrderHeader_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.EntityTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntityTypes.self) }
                do {
                    ESPMContainerMetadata.EntityTypes.salesOrderHeader_ = value
                }
            }
        }

        public static var salesOrderItem: EntityType {
            get {
                objc_sync_enter(ESPMContainerMetadata.EntityTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntityTypes.self) }
                do {
                    return ESPMContainerMetadata.EntityTypes.salesOrderItem_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.EntityTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntityTypes.self) }
                do {
                    ESPMContainerMetadata.EntityTypes.salesOrderItem_ = value
                }
            }
        }

        public static var stock: EntityType {
            get {
                objc_sync_enter(ESPMContainerMetadata.EntityTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntityTypes.self) }
                do {
                    return ESPMContainerMetadata.EntityTypes.stock_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.EntityTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntityTypes.self) }
                do {
                    ESPMContainerMetadata.EntityTypes.stock_ = value
                }
            }
        }

        public static var supplier: EntityType {
            get {
                objc_sync_enter(ESPMContainerMetadata.EntityTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntityTypes.self) }
                do {
                    return ESPMContainerMetadata.EntityTypes.supplier_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.EntityTypes.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntityTypes.self) }
                do {
                    ESPMContainerMetadata.EntityTypes.supplier_ = value
                }
            }
        }
    }

    public class EntitySets {
        private static var customers_: EntitySet = ESPMContainerMetadataParser.parsed.entitySet(withName: "Customers")

        private static var productCategories_: EntitySet = ESPMContainerMetadataParser.parsed.entitySet(withName: "ProductCategories")

        private static var productTexts_: EntitySet = ESPMContainerMetadataParser.parsed.entitySet(withName: "ProductTexts")

        private static var products_: EntitySet = ESPMContainerMetadataParser.parsed.entitySet(withName: "Products")

        private static var purchaseOrderHeaders_: EntitySet = ESPMContainerMetadataParser.parsed.entitySet(withName: "PurchaseOrderHeaders")

        private static var purchaseOrderItems_: EntitySet = ESPMContainerMetadataParser.parsed.entitySet(withName: "PurchaseOrderItems")

        private static var salesOrderHeaders_: EntitySet = ESPMContainerMetadataParser.parsed.entitySet(withName: "SalesOrderHeaders")

        private static var salesOrderItems_: EntitySet = ESPMContainerMetadataParser.parsed.entitySet(withName: "SalesOrderItems")

        private static var stock_: EntitySet = ESPMContainerMetadataParser.parsed.entitySet(withName: "Stock")

        private static var suppliers_: EntitySet = ESPMContainerMetadataParser.parsed.entitySet(withName: "Suppliers")

        public static var customers: EntitySet {
            get {
                objc_sync_enter(ESPMContainerMetadata.EntitySets.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntitySets.self) }
                do {
                    return ESPMContainerMetadata.EntitySets.customers_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.EntitySets.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntitySets.self) }
                do {
                    ESPMContainerMetadata.EntitySets.customers_ = value
                }
            }
        }

        public static var productCategories: EntitySet {
            get {
                objc_sync_enter(ESPMContainerMetadata.EntitySets.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntitySets.self) }
                do {
                    return ESPMContainerMetadata.EntitySets.productCategories_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.EntitySets.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntitySets.self) }
                do {
                    ESPMContainerMetadata.EntitySets.productCategories_ = value
                }
            }
        }

        public static var productTexts: EntitySet {
            get {
                objc_sync_enter(ESPMContainerMetadata.EntitySets.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntitySets.self) }
                do {
                    return ESPMContainerMetadata.EntitySets.productTexts_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.EntitySets.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntitySets.self) }
                do {
                    ESPMContainerMetadata.EntitySets.productTexts_ = value
                }
            }
        }

        public static var products: EntitySet {
            get {
                objc_sync_enter(ESPMContainerMetadata.EntitySets.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntitySets.self) }
                do {
                    return ESPMContainerMetadata.EntitySets.products_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.EntitySets.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntitySets.self) }
                do {
                    ESPMContainerMetadata.EntitySets.products_ = value
                }
            }
        }

        public static var purchaseOrderHeaders: EntitySet {
            get {
                objc_sync_enter(ESPMContainerMetadata.EntitySets.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntitySets.self) }
                do {
                    return ESPMContainerMetadata.EntitySets.purchaseOrderHeaders_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.EntitySets.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntitySets.self) }
                do {
                    ESPMContainerMetadata.EntitySets.purchaseOrderHeaders_ = value
                }
            }
        }

        public static var purchaseOrderItems: EntitySet {
            get {
                objc_sync_enter(ESPMContainerMetadata.EntitySets.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntitySets.self) }
                do {
                    return ESPMContainerMetadata.EntitySets.purchaseOrderItems_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.EntitySets.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntitySets.self) }
                do {
                    ESPMContainerMetadata.EntitySets.purchaseOrderItems_ = value
                }
            }
        }

        public static var salesOrderHeaders: EntitySet {
            get {
                objc_sync_enter(ESPMContainerMetadata.EntitySets.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntitySets.self) }
                do {
                    return ESPMContainerMetadata.EntitySets.salesOrderHeaders_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.EntitySets.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntitySets.self) }
                do {
                    ESPMContainerMetadata.EntitySets.salesOrderHeaders_ = value
                }
            }
        }

        public static var salesOrderItems: EntitySet {
            get {
                objc_sync_enter(ESPMContainerMetadata.EntitySets.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntitySets.self) }
                do {
                    return ESPMContainerMetadata.EntitySets.salesOrderItems_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.EntitySets.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntitySets.self) }
                do {
                    ESPMContainerMetadata.EntitySets.salesOrderItems_ = value
                }
            }
        }

        public static var stock: EntitySet {
            get {
                objc_sync_enter(ESPMContainerMetadata.EntitySets.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntitySets.self) }
                do {
                    return ESPMContainerMetadata.EntitySets.stock_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.EntitySets.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntitySets.self) }
                do {
                    ESPMContainerMetadata.EntitySets.stock_ = value
                }
            }
        }

        public static var suppliers: EntitySet {
            get {
                objc_sync_enter(ESPMContainerMetadata.EntitySets.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntitySets.self) }
                do {
                    return ESPMContainerMetadata.EntitySets.suppliers_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.EntitySets.self)
                defer { objc_sync_exit(ESPMContainerMetadata.EntitySets.self) }
                do {
                    ESPMContainerMetadata.EntitySets.suppliers_ = value
                }
            }
        }
    }

    public class ActionImports {
        private static var generateSamplePurchaseOrders_: DataMethod = ESPMContainerMetadataParser.parsed.dataMethod(withName: "GenerateSamplePurchaseOrders")

        private static var generateSampleSalesOrders_: DataMethod = ESPMContainerMetadataParser.parsed.dataMethod(withName: "GenerateSampleSalesOrders")

        private static var resetSampleData_: DataMethod = ESPMContainerMetadataParser.parsed.dataMethod(withName: "ResetSampleData")

        private static var updateSalesOrderStatus_: DataMethod = ESPMContainerMetadataParser.parsed.dataMethod(withName: "UpdateSalesOrderStatus")

        public static var generateSamplePurchaseOrders: DataMethod {
            get {
                objc_sync_enter(ESPMContainerMetadata.ActionImports.self)
                defer { objc_sync_exit(ESPMContainerMetadata.ActionImports.self) }
                do {
                    return ESPMContainerMetadata.ActionImports.generateSamplePurchaseOrders_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.ActionImports.self)
                defer { objc_sync_exit(ESPMContainerMetadata.ActionImports.self) }
                do {
                    ESPMContainerMetadata.ActionImports.generateSamplePurchaseOrders_ = value
                }
            }
        }

        public static var generateSampleSalesOrders: DataMethod {
            get {
                objc_sync_enter(ESPMContainerMetadata.ActionImports.self)
                defer { objc_sync_exit(ESPMContainerMetadata.ActionImports.self) }
                do {
                    return ESPMContainerMetadata.ActionImports.generateSampleSalesOrders_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.ActionImports.self)
                defer { objc_sync_exit(ESPMContainerMetadata.ActionImports.self) }
                do {
                    ESPMContainerMetadata.ActionImports.generateSampleSalesOrders_ = value
                }
            }
        }

        public static var resetSampleData: DataMethod {
            get {
                objc_sync_enter(ESPMContainerMetadata.ActionImports.self)
                defer { objc_sync_exit(ESPMContainerMetadata.ActionImports.self) }
                do {
                    return ESPMContainerMetadata.ActionImports.resetSampleData_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.ActionImports.self)
                defer { objc_sync_exit(ESPMContainerMetadata.ActionImports.self) }
                do {
                    ESPMContainerMetadata.ActionImports.resetSampleData_ = value
                }
            }
        }

        public static var updateSalesOrderStatus: DataMethod {
            get {
                objc_sync_enter(ESPMContainerMetadata.ActionImports.self)
                defer { objc_sync_exit(ESPMContainerMetadata.ActionImports.self) }
                do {
                    return ESPMContainerMetadata.ActionImports.updateSalesOrderStatus_
                }
            }
            set(value) {
                objc_sync_enter(ESPMContainerMetadata.ActionImports.self)
                defer { objc_sync_exit(ESPMContainerMetadata.ActionImports.self) }
                do {
                    ESPMContainerMetadata.ActionImports.updateSalesOrderStatus_ = value
                }
            }
        }
    }
}
