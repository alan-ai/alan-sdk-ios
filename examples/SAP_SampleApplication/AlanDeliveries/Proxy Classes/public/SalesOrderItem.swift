// # Proxy Compiler 19.1.3-b8851a-20190408

import Foundation
import SAPOData

open class SalesOrderItem: EntityValue {
    public required init(from decoder: Decoder) throws {
        try super.init(from: decoder)
    }

    private static var currencyCode_: Property = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "CurrencyCode")

    private static var deliveryDate_: Property = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "DeliveryDate")

    private static var grossAmount_: Property = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "GrossAmount")

    private static var itemNumber_: Property = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "ItemNumber")

    private static var netAmount_: Property = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "NetAmount")

    private static var productID_: Property = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "ProductId")

    private static var quantity_: Property = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "Quantity")

    private static var quantityUnit_: Property = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "QuantityUnit")

    private static var salesOrderID_: Property = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "SalesOrderId")

    private static var taxAmount_: Property = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "TaxAmount")

    private static var header_: Property = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "Header")

    private static var productDetails_: Property = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "ProductDetails")

    public init(withDefaults: Bool = true) {
        super.init(withDefaults: withDefaults, type: ESPMContainerMetadata.EntityTypes.salesOrderItem)
    }

    open class func array(from: EntityValueList) -> [SalesOrderItem] {
        return ArrayConverter.convert(from.toArray(), [SalesOrderItem]())
    }

    open func copy() -> SalesOrderItem {
        return CastRequired<SalesOrderItem>.from(self.copyEntity())
    }

    open class var currencyCode: Property {
        get {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                return SalesOrderItem.currencyCode_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                SalesOrderItem.currencyCode_ = value
            }
        }
    }

    open var currencyCode: String? {
        get {
            return StringValue.optional(self.optionalValue(for: SalesOrderItem.currencyCode))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderItem.currencyCode, to: StringValue.of(optional: value))
        }
    }

    open class var deliveryDate: Property {
        get {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                return SalesOrderItem.deliveryDate_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                SalesOrderItem.deliveryDate_ = value
            }
        }
    }

    open var deliveryDate: LocalDateTime? {
        get {
            return LocalDateTime.castOptional(self.optionalValue(for: SalesOrderItem.deliveryDate))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderItem.deliveryDate, to: value)
        }
    }

    open class var grossAmount: Property {
        get {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                return SalesOrderItem.grossAmount_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                SalesOrderItem.grossAmount_ = value
            }
        }
    }

    open var grossAmount: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: SalesOrderItem.grossAmount))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderItem.grossAmount, to: DecimalValue.of(optional: value))
        }
    }

    open class var header: Property {
        get {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                return SalesOrderItem.header_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                SalesOrderItem.header_ = value
            }
        }
    }

    open var header: SalesOrderHeader? {
        get {
            return CastOptional<SalesOrderHeader>.from(self.optionalValue(for: SalesOrderItem.header))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderItem.header, to: value)
        }
    }

    open override var isProxy: Bool {
        return true
    }

    open class var itemNumber: Property {
        get {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                return SalesOrderItem.itemNumber_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                SalesOrderItem.itemNumber_ = value
            }
        }
    }

    open var itemNumber: Int? {
        get {
            return IntValue.optional(self.optionalValue(for: SalesOrderItem.itemNumber))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderItem.itemNumber, to: IntValue.of(optional: value))
        }
    }

    open class func key(itemNumber: Int?, salesOrderID: String?) -> EntityKey {
        return EntityKey().with(name: "ItemNumber", value: IntValue.of(optional: itemNumber)).with(name: "SalesOrderId", value: StringValue.of(optional: salesOrderID))
    }

    open class var netAmount: Property {
        get {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                return SalesOrderItem.netAmount_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                SalesOrderItem.netAmount_ = value
            }
        }
    }

    open var netAmount: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: SalesOrderItem.netAmount))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderItem.netAmount, to: DecimalValue.of(optional: value))
        }
    }

    open var old: SalesOrderItem {
        return CastRequired<SalesOrderItem>.from(self.oldEntity)
    }

    open class var productDetails: Property {
        get {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                return SalesOrderItem.productDetails_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                SalesOrderItem.productDetails_ = value
            }
        }
    }

    open var productDetails: Product? {
        get {
            return CastOptional<Product>.from(self.optionalValue(for: SalesOrderItem.productDetails))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderItem.productDetails, to: value)
        }
    }

    open class var productID: Property {
        get {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                return SalesOrderItem.productID_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                SalesOrderItem.productID_ = value
            }
        }
    }

    open var productID: String? {
        get {
            return StringValue.optional(self.optionalValue(for: SalesOrderItem.productID))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderItem.productID, to: StringValue.of(optional: value))
        }
    }

    open class var quantity: Property {
        get {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                return SalesOrderItem.quantity_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                SalesOrderItem.quantity_ = value
            }
        }
    }

    open var quantity: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: SalesOrderItem.quantity))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderItem.quantity, to: DecimalValue.of(optional: value))
        }
    }

    open class var quantityUnit: Property {
        get {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                return SalesOrderItem.quantityUnit_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                SalesOrderItem.quantityUnit_ = value
            }
        }
    }

    open var quantityUnit: String? {
        get {
            return StringValue.optional(self.optionalValue(for: SalesOrderItem.quantityUnit))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderItem.quantityUnit, to: StringValue.of(optional: value))
        }
    }

    open class var salesOrderID: Property {
        get {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                return SalesOrderItem.salesOrderID_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                SalesOrderItem.salesOrderID_ = value
            }
        }
    }

    open var salesOrderID: String? {
        get {
            return StringValue.optional(self.optionalValue(for: SalesOrderItem.salesOrderID))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderItem.salesOrderID, to: StringValue.of(optional: value))
        }
    }

    open class var taxAmount: Property {
        get {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                return SalesOrderItem.taxAmount_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderItem.self)
            defer { objc_sync_exit(SalesOrderItem.self) }
            do {
                SalesOrderItem.taxAmount_ = value
            }
        }
    }

    open var taxAmount: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: SalesOrderItem.taxAmount))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderItem.taxAmount, to: DecimalValue.of(optional: value))
        }
    }
}
