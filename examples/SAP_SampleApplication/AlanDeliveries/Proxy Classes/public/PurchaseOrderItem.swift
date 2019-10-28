// # Proxy Compiler 19.1.3-b8851a-20190408

import Foundation
import SAPOData

open class PurchaseOrderItem: EntityValue {
    public required init(from decoder: Decoder) throws {
        try super.init(from: decoder)
    }

    private static var currencyCode_: Property = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "CurrencyCode")

    private static var grossAmount_: Property = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "GrossAmount")

    private static var itemNumber_: Property = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "ItemNumber")

    private static var netAmount_: Property = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "NetAmount")

    private static var productID_: Property = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "ProductId")

    private static var purchaseOrderID_: Property = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "PurchaseOrderId")

    private static var quantity_: Property = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "Quantity")

    private static var quantityUnit_: Property = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "QuantityUnit")

    private static var taxAmount_: Property = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "TaxAmount")

    private static var header_: Property = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "Header")

    private static var productDetails_: Property = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "ProductDetails")

    public init(withDefaults: Bool = true) {
        super.init(withDefaults: withDefaults, type: ESPMContainerMetadata.EntityTypes.purchaseOrderItem)
    }

    open class func array(from: EntityValueList) -> [PurchaseOrderItem] {
        return ArrayConverter.convert(from.toArray(), [PurchaseOrderItem]())
    }

    open func copy() -> PurchaseOrderItem {
        return CastRequired<PurchaseOrderItem>.from(self.copyEntity())
    }

    open class var currencyCode: Property {
        get {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                return PurchaseOrderItem.currencyCode_
            }
        }
        set(value) {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                PurchaseOrderItem.currencyCode_ = value
            }
        }
    }

    open var currencyCode: String? {
        get {
            return StringValue.optional(self.optionalValue(for: PurchaseOrderItem.currencyCode))
        }
        set(value) {
            self.setOptionalValue(for: PurchaseOrderItem.currencyCode, to: StringValue.of(optional: value))
        }
    }

    open class var grossAmount: Property {
        get {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                return PurchaseOrderItem.grossAmount_
            }
        }
        set(value) {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                PurchaseOrderItem.grossAmount_ = value
            }
        }
    }

    open var grossAmount: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: PurchaseOrderItem.grossAmount))
        }
        set(value) {
            self.setOptionalValue(for: PurchaseOrderItem.grossAmount, to: DecimalValue.of(optional: value))
        }
    }

    open class var header: Property {
        get {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                return PurchaseOrderItem.header_
            }
        }
        set(value) {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                PurchaseOrderItem.header_ = value
            }
        }
    }

    open var header: PurchaseOrderHeader? {
        get {
            return CastOptional<PurchaseOrderHeader>.from(self.optionalValue(for: PurchaseOrderItem.header))
        }
        set(value) {
            self.setOptionalValue(for: PurchaseOrderItem.header, to: value)
        }
    }

    open override var isProxy: Bool {
        return true
    }

    open class var itemNumber: Property {
        get {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                return PurchaseOrderItem.itemNumber_
            }
        }
        set(value) {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                PurchaseOrderItem.itemNumber_ = value
            }
        }
    }

    open var itemNumber: Int? {
        get {
            return IntValue.optional(self.optionalValue(for: PurchaseOrderItem.itemNumber))
        }
        set(value) {
            self.setOptionalValue(for: PurchaseOrderItem.itemNumber, to: IntValue.of(optional: value))
        }
    }

    open class func key(itemNumber: Int?, purchaseOrderID: String?) -> EntityKey {
        return EntityKey().with(name: "ItemNumber", value: IntValue.of(optional: itemNumber)).with(name: "PurchaseOrderId", value: StringValue.of(optional: purchaseOrderID))
    }

    open class var netAmount: Property {
        get {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                return PurchaseOrderItem.netAmount_
            }
        }
        set(value) {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                PurchaseOrderItem.netAmount_ = value
            }
        }
    }

    open var netAmount: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: PurchaseOrderItem.netAmount))
        }
        set(value) {
            self.setOptionalValue(for: PurchaseOrderItem.netAmount, to: DecimalValue.of(optional: value))
        }
    }

    open var old: PurchaseOrderItem {
        return CastRequired<PurchaseOrderItem>.from(self.oldEntity)
    }

    open class var productDetails: Property {
        get {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                return PurchaseOrderItem.productDetails_
            }
        }
        set(value) {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                PurchaseOrderItem.productDetails_ = value
            }
        }
    }

    open var productDetails: Product? {
        get {
            return CastOptional<Product>.from(self.optionalValue(for: PurchaseOrderItem.productDetails))
        }
        set(value) {
            self.setOptionalValue(for: PurchaseOrderItem.productDetails, to: value)
        }
    }

    open class var productID: Property {
        get {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                return PurchaseOrderItem.productID_
            }
        }
        set(value) {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                PurchaseOrderItem.productID_ = value
            }
        }
    }

    open var productID: String? {
        get {
            return StringValue.optional(self.optionalValue(for: PurchaseOrderItem.productID))
        }
        set(value) {
            self.setOptionalValue(for: PurchaseOrderItem.productID, to: StringValue.of(optional: value))
        }
    }

    open class var purchaseOrderID: Property {
        get {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                return PurchaseOrderItem.purchaseOrderID_
            }
        }
        set(value) {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                PurchaseOrderItem.purchaseOrderID_ = value
            }
        }
    }

    open var purchaseOrderID: String? {
        get {
            return StringValue.optional(self.optionalValue(for: PurchaseOrderItem.purchaseOrderID))
        }
        set(value) {
            self.setOptionalValue(for: PurchaseOrderItem.purchaseOrderID, to: StringValue.of(optional: value))
        }
    }

    open class var quantity: Property {
        get {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                return PurchaseOrderItem.quantity_
            }
        }
        set(value) {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                PurchaseOrderItem.quantity_ = value
            }
        }
    }

    open var quantity: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: PurchaseOrderItem.quantity))
        }
        set(value) {
            self.setOptionalValue(for: PurchaseOrderItem.quantity, to: DecimalValue.of(optional: value))
        }
    }

    open class var quantityUnit: Property {
        get {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                return PurchaseOrderItem.quantityUnit_
            }
        }
        set(value) {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                PurchaseOrderItem.quantityUnit_ = value
            }
        }
    }

    open var quantityUnit: String? {
        get {
            return StringValue.optional(self.optionalValue(for: PurchaseOrderItem.quantityUnit))
        }
        set(value) {
            self.setOptionalValue(for: PurchaseOrderItem.quantityUnit, to: StringValue.of(optional: value))
        }
    }

    open class var taxAmount: Property {
        get {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                return PurchaseOrderItem.taxAmount_
            }
        }
        set(value) {
            objc_sync_enter(PurchaseOrderItem.self)
            defer { objc_sync_exit(PurchaseOrderItem.self) }
            do {
                PurchaseOrderItem.taxAmount_ = value
            }
        }
    }

    open var taxAmount: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: PurchaseOrderItem.taxAmount))
        }
        set(value) {
            self.setOptionalValue(for: PurchaseOrderItem.taxAmount, to: DecimalValue.of(optional: value))
        }
    }
}
