// # Proxy Compiler 19.1.3-b8851a-20190408

import Foundation
import SAPOData

internal class ESPMContainerFactory {
    static func registerAll() throws {
        ESPMContainerMetadata.ComplexTypes.address.registerFactory(ObjectFactory.with(create: { Address(withDefaults: false) }, createWithDecoder: { d in try Address(from: d) }))
        ESPMContainerMetadata.EntityTypes.customer.registerFactory(ObjectFactory.with(create: { Customer(withDefaults: false) }, createWithDecoder: { d in try Customer(from: d) }))
        ESPMContainerMetadata.EntityTypes.product.registerFactory(ObjectFactory.with(create: { Product(withDefaults: false) }, createWithDecoder: { d in try Product(from: d) }))
        ESPMContainerMetadata.EntityTypes.productCategory.registerFactory(ObjectFactory.with(create: { ProductCategory(withDefaults: false) }, createWithDecoder: { d in try ProductCategory(from: d) }))
        ESPMContainerMetadata.EntityTypes.productText.registerFactory(ObjectFactory.with(create: { ProductText(withDefaults: false) }, createWithDecoder: { d in try ProductText(from: d) }))
        ESPMContainerMetadata.EntityTypes.purchaseOrderHeader.registerFactory(ObjectFactory.with(create: { PurchaseOrderHeader(withDefaults: false) }, createWithDecoder: { d in try PurchaseOrderHeader(from: d) }))
        ESPMContainerMetadata.EntityTypes.purchaseOrderItem.registerFactory(ObjectFactory.with(create: { PurchaseOrderItem(withDefaults: false) }, createWithDecoder: { d in try PurchaseOrderItem(from: d) }))
        ESPMContainerMetadata.EntityTypes.salesOrderHeader.registerFactory(ObjectFactory.with(create: { SalesOrderHeader(withDefaults: false) }, createWithDecoder: { d in try SalesOrderHeader(from: d) }))
        ESPMContainerMetadata.EntityTypes.salesOrderItem.registerFactory(ObjectFactory.with(create: { SalesOrderItem(withDefaults: false) }, createWithDecoder: { d in try SalesOrderItem(from: d) }))
        ESPMContainerMetadata.EntityTypes.stock.registerFactory(ObjectFactory.with(create: { Stock(withDefaults: false) }, createWithDecoder: { d in try Stock(from: d) }))
        ESPMContainerMetadata.EntityTypes.supplier.registerFactory(ObjectFactory.with(create: { Supplier(withDefaults: false) }, createWithDecoder: { d in try Supplier(from: d) }))
        ESPMContainerStaticResolver.resolve()
    }
}
