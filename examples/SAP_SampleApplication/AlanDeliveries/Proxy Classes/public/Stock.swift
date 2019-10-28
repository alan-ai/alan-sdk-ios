// # Proxy Compiler 19.1.3-b8851a-20190408

import Foundation
import SAPOData

open class Stock: EntityValue {
    public required init(from decoder: Decoder) throws {
        try super.init(from: decoder)
    }

    private static var lotSize_: Property = ESPMContainerMetadata.EntityTypes.stock.property(withName: "LotSize")

    private static var minStock_: Property = ESPMContainerMetadata.EntityTypes.stock.property(withName: "MinStock")

    private static var productID_: Property = ESPMContainerMetadata.EntityTypes.stock.property(withName: "ProductId")

    private static var quantity_: Property = ESPMContainerMetadata.EntityTypes.stock.property(withName: "Quantity")

    private static var quantityLessMin_: Property = ESPMContainerMetadata.EntityTypes.stock.property(withName: "QuantityLessMin")

    private static var updatedTimestamp_: Property = ESPMContainerMetadata.EntityTypes.stock.property(withName: "UpdatedTimestamp")

    private static var productDetails_: Property = ESPMContainerMetadata.EntityTypes.stock.property(withName: "ProductDetails")

    public init(withDefaults: Bool = true) {
        super.init(withDefaults: withDefaults, type: ESPMContainerMetadata.EntityTypes.stock)
    }

    open class func array(from: EntityValueList) -> [Stock] {
        return ArrayConverter.convert(from.toArray(), [Stock]())
    }

    open func copy() -> Stock {
        return CastRequired<Stock>.from(self.copyEntity())
    }

    open override var isProxy: Bool {
        return true
    }

    open class func key(productID: String?) -> EntityKey {
        return EntityKey().with(name: "ProductId", value: StringValue.of(optional: productID))
    }

    open class var lotSize: Property {
        get {
            objc_sync_enter(Stock.self)
            defer { objc_sync_exit(Stock.self) }
            do {
                return Stock.lotSize_
            }
        }
        set(value) {
            objc_sync_enter(Stock.self)
            defer { objc_sync_exit(Stock.self) }
            do {
                Stock.lotSize_ = value
            }
        }
    }

    open var lotSize: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: Stock.lotSize))
        }
        set(value) {
            self.setOptionalValue(for: Stock.lotSize, to: DecimalValue.of(optional: value))
        }
    }

    open class var minStock: Property {
        get {
            objc_sync_enter(Stock.self)
            defer { objc_sync_exit(Stock.self) }
            do {
                return Stock.minStock_
            }
        }
        set(value) {
            objc_sync_enter(Stock.self)
            defer { objc_sync_exit(Stock.self) }
            do {
                Stock.minStock_ = value
            }
        }
    }

    open var minStock: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: Stock.minStock))
        }
        set(value) {
            self.setOptionalValue(for: Stock.minStock, to: DecimalValue.of(optional: value))
        }
    }

    open var old: Stock {
        return CastRequired<Stock>.from(self.oldEntity)
    }

    open class var productDetails: Property {
        get {
            objc_sync_enter(Stock.self)
            defer { objc_sync_exit(Stock.self) }
            do {
                return Stock.productDetails_
            }
        }
        set(value) {
            objc_sync_enter(Stock.self)
            defer { objc_sync_exit(Stock.self) }
            do {
                Stock.productDetails_ = value
            }
        }
    }

    open var productDetails: Product? {
        get {
            return CastOptional<Product>.from(self.optionalValue(for: Stock.productDetails))
        }
        set(value) {
            self.setOptionalValue(for: Stock.productDetails, to: value)
        }
    }

    open class var productID: Property {
        get {
            objc_sync_enter(Stock.self)
            defer { objc_sync_exit(Stock.self) }
            do {
                return Stock.productID_
            }
        }
        set(value) {
            objc_sync_enter(Stock.self)
            defer { objc_sync_exit(Stock.self) }
            do {
                Stock.productID_ = value
            }
        }
    }

    open var productID: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Stock.productID))
        }
        set(value) {
            self.setOptionalValue(for: Stock.productID, to: StringValue.of(optional: value))
        }
    }

    open class var quantity: Property {
        get {
            objc_sync_enter(Stock.self)
            defer { objc_sync_exit(Stock.self) }
            do {
                return Stock.quantity_
            }
        }
        set(value) {
            objc_sync_enter(Stock.self)
            defer { objc_sync_exit(Stock.self) }
            do {
                Stock.quantity_ = value
            }
        }
    }

    open var quantity: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: Stock.quantity))
        }
        set(value) {
            self.setOptionalValue(for: Stock.quantity, to: DecimalValue.of(optional: value))
        }
    }

    open class var quantityLessMin: Property {
        get {
            objc_sync_enter(Stock.self)
            defer { objc_sync_exit(Stock.self) }
            do {
                return Stock.quantityLessMin_
            }
        }
        set(value) {
            objc_sync_enter(Stock.self)
            defer { objc_sync_exit(Stock.self) }
            do {
                Stock.quantityLessMin_ = value
            }
        }
    }

    open var quantityLessMin: Bool? {
        get {
            return BooleanValue.optional(self.optionalValue(for: Stock.quantityLessMin))
        }
        set(value) {
            self.setOptionalValue(for: Stock.quantityLessMin, to: BooleanValue.of(optional: value))
        }
    }

    open class var updatedTimestamp: Property {
        get {
            objc_sync_enter(Stock.self)
            defer { objc_sync_exit(Stock.self) }
            do {
                return Stock.updatedTimestamp_
            }
        }
        set(value) {
            objc_sync_enter(Stock.self)
            defer { objc_sync_exit(Stock.self) }
            do {
                Stock.updatedTimestamp_ = value
            }
        }
    }

    open var updatedTimestamp: LocalDateTime? {
        get {
            return LocalDateTime.castOptional(self.optionalValue(for: Stock.updatedTimestamp))
        }
        set(value) {
            self.setOptionalValue(for: Stock.updatedTimestamp, to: value)
        }
    }
}
