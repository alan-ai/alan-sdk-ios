// # Proxy Compiler 19.1.3-b8851a-20190408

import Foundation
import SAPOData

open class Product: EntityValue {
    public required init(from decoder: Decoder) throws {
        try super.init(from: decoder)
    }

    private static var category_: Property = ESPMContainerMetadata.EntityTypes.product.property(withName: "Category")

    private static var categoryName_: Property = ESPMContainerMetadata.EntityTypes.product.property(withName: "CategoryName")

    private static var currencyCode_: Property = ESPMContainerMetadata.EntityTypes.product.property(withName: "CurrencyCode")

    private static var dimensionDepth_: Property = ESPMContainerMetadata.EntityTypes.product.property(withName: "DimensionDepth")

    private static var dimensionHeight_: Property = ESPMContainerMetadata.EntityTypes.product.property(withName: "DimensionHeight")

    private static var dimensionUnit_: Property = ESPMContainerMetadata.EntityTypes.product.property(withName: "DimensionUnit")

    private static var dimensionWidth_: Property = ESPMContainerMetadata.EntityTypes.product.property(withName: "DimensionWidth")

    private static var longDescription_: Property = ESPMContainerMetadata.EntityTypes.product.property(withName: "LongDescription")

    private static var name_: Property = ESPMContainerMetadata.EntityTypes.product.property(withName: "Name")

    private static var pictureUrl_: Property = ESPMContainerMetadata.EntityTypes.product.property(withName: "PictureUrl")

    private static var price_: Property = ESPMContainerMetadata.EntityTypes.product.property(withName: "Price")

    private static var productID_: Property = ESPMContainerMetadata.EntityTypes.product.property(withName: "ProductId")

    private static var quantityUnit_: Property = ESPMContainerMetadata.EntityTypes.product.property(withName: "QuantityUnit")

    private static var shortDescription_: Property = ESPMContainerMetadata.EntityTypes.product.property(withName: "ShortDescription")

    private static var supplierID_: Property = ESPMContainerMetadata.EntityTypes.product.property(withName: "SupplierId")

    private static var updatedTimestamp_: Property = ESPMContainerMetadata.EntityTypes.product.property(withName: "UpdatedTimestamp")

    private static var weight_: Property = ESPMContainerMetadata.EntityTypes.product.property(withName: "Weight")

    private static var weightUnit_: Property = ESPMContainerMetadata.EntityTypes.product.property(withName: "WeightUnit")

    private static var stockDetails_: Property = ESPMContainerMetadata.EntityTypes.product.property(withName: "StockDetails")

    private static var supplierDetails_: Property = ESPMContainerMetadata.EntityTypes.product.property(withName: "SupplierDetails")

    public init(withDefaults: Bool = true) {
        super.init(withDefaults: withDefaults, type: ESPMContainerMetadata.EntityTypes.product)
    }

    open class func array(from: EntityValueList) -> [Product] {
        return ArrayConverter.convert(from.toArray(), [Product]())
    }

    open class var category: Property {
        get {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                return Product.category_
            }
        }
        set(value) {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                Product.category_ = value
            }
        }
    }

    open var category: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Product.category))
        }
        set(value) {
            self.setOptionalValue(for: Product.category, to: StringValue.of(optional: value))
        }
    }

    open class var categoryName: Property {
        get {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                return Product.categoryName_
            }
        }
        set(value) {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                Product.categoryName_ = value
            }
        }
    }

    open var categoryName: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Product.categoryName))
        }
        set(value) {
            self.setOptionalValue(for: Product.categoryName, to: StringValue.of(optional: value))
        }
    }

    open func copy() -> Product {
        return CastRequired<Product>.from(self.copyEntity())
    }

    open class var currencyCode: Property {
        get {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                return Product.currencyCode_
            }
        }
        set(value) {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                Product.currencyCode_ = value
            }
        }
    }

    open var currencyCode: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Product.currencyCode))
        }
        set(value) {
            self.setOptionalValue(for: Product.currencyCode, to: StringValue.of(optional: value))
        }
    }

    open class var dimensionDepth: Property {
        get {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                return Product.dimensionDepth_
            }
        }
        set(value) {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                Product.dimensionDepth_ = value
            }
        }
    }

    open var dimensionDepth: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: Product.dimensionDepth))
        }
        set(value) {
            self.setOptionalValue(for: Product.dimensionDepth, to: DecimalValue.of(optional: value))
        }
    }

    open class var dimensionHeight: Property {
        get {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                return Product.dimensionHeight_
            }
        }
        set(value) {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                Product.dimensionHeight_ = value
            }
        }
    }

    open var dimensionHeight: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: Product.dimensionHeight))
        }
        set(value) {
            self.setOptionalValue(for: Product.dimensionHeight, to: DecimalValue.of(optional: value))
        }
    }

    open class var dimensionUnit: Property {
        get {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                return Product.dimensionUnit_
            }
        }
        set(value) {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                Product.dimensionUnit_ = value
            }
        }
    }

    open var dimensionUnit: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Product.dimensionUnit))
        }
        set(value) {
            self.setOptionalValue(for: Product.dimensionUnit, to: StringValue.of(optional: value))
        }
    }

    open class var dimensionWidth: Property {
        get {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                return Product.dimensionWidth_
            }
        }
        set(value) {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                Product.dimensionWidth_ = value
            }
        }
    }

    open var dimensionWidth: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: Product.dimensionWidth))
        }
        set(value) {
            self.setOptionalValue(for: Product.dimensionWidth, to: DecimalValue.of(optional: value))
        }
    }

    open override var isProxy: Bool {
        return true
    }

    open class func key(productID: String?) -> EntityKey {
        return EntityKey().with(name: "ProductId", value: StringValue.of(optional: productID))
    }

    open class var longDescription: Property {
        get {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                return Product.longDescription_
            }
        }
        set(value) {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                Product.longDescription_ = value
            }
        }
    }

    open var longDescription: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Product.longDescription))
        }
        set(value) {
            self.setOptionalValue(for: Product.longDescription, to: StringValue.of(optional: value))
        }
    }

    open class var name: Property {
        get {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                return Product.name_
            }
        }
        set(value) {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                Product.name_ = value
            }
        }
    }

    open var name: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Product.name))
        }
        set(value) {
            self.setOptionalValue(for: Product.name, to: StringValue.of(optional: value))
        }
    }

    open var old: Product {
        return CastRequired<Product>.from(self.oldEntity)
    }

    open class var pictureUrl: Property {
        get {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                return Product.pictureUrl_
            }
        }
        set(value) {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                Product.pictureUrl_ = value
            }
        }
    }

    open var pictureUrl: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Product.pictureUrl))
        }
        set(value) {
            self.setOptionalValue(for: Product.pictureUrl, to: StringValue.of(optional: value))
        }
    }

    open class var price: Property {
        get {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                return Product.price_
            }
        }
        set(value) {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                Product.price_ = value
            }
        }
    }

    open var price: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: Product.price))
        }
        set(value) {
            self.setOptionalValue(for: Product.price, to: DecimalValue.of(optional: value))
        }
    }

    open class var productID: Property {
        get {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                return Product.productID_
            }
        }
        set(value) {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                Product.productID_ = value
            }
        }
    }

    open var productID: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Product.productID))
        }
        set(value) {
            self.setOptionalValue(for: Product.productID, to: StringValue.of(optional: value))
        }
    }

    open class var quantityUnit: Property {
        get {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                return Product.quantityUnit_
            }
        }
        set(value) {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                Product.quantityUnit_ = value
            }
        }
    }

    open var quantityUnit: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Product.quantityUnit))
        }
        set(value) {
            self.setOptionalValue(for: Product.quantityUnit, to: StringValue.of(optional: value))
        }
    }

    open class var shortDescription: Property {
        get {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                return Product.shortDescription_
            }
        }
        set(value) {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                Product.shortDescription_ = value
            }
        }
    }

    open var shortDescription: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Product.shortDescription))
        }
        set(value) {
            self.setOptionalValue(for: Product.shortDescription, to: StringValue.of(optional: value))
        }
    }

    open class var stockDetails: Property {
        get {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                return Product.stockDetails_
            }
        }
        set(value) {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                Product.stockDetails_ = value
            }
        }
    }

    open var stockDetails: Stock? {
        get {
            return CastOptional<Stock>.from(self.optionalValue(for: Product.stockDetails))
        }
        set(value) {
            self.setOptionalValue(for: Product.stockDetails, to: value)
        }
    }

    open class var supplierDetails: Property {
        get {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                return Product.supplierDetails_
            }
        }
        set(value) {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                Product.supplierDetails_ = value
            }
        }
    }

    open var supplierDetails: Supplier? {
        get {
            return CastOptional<Supplier>.from(self.optionalValue(for: Product.supplierDetails))
        }
        set(value) {
            self.setOptionalValue(for: Product.supplierDetails, to: value)
        }
    }

    open class var supplierID: Property {
        get {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                return Product.supplierID_
            }
        }
        set(value) {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                Product.supplierID_ = value
            }
        }
    }

    open var supplierID: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Product.supplierID))
        }
        set(value) {
            self.setOptionalValue(for: Product.supplierID, to: StringValue.of(optional: value))
        }
    }

    open class var updatedTimestamp: Property {
        get {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                return Product.updatedTimestamp_
            }
        }
        set(value) {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                Product.updatedTimestamp_ = value
            }
        }
    }

    open var updatedTimestamp: LocalDateTime? {
        get {
            return LocalDateTime.castOptional(self.optionalValue(for: Product.updatedTimestamp))
        }
        set(value) {
            self.setOptionalValue(for: Product.updatedTimestamp, to: value)
        }
    }

    open class var weight: Property {
        get {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                return Product.weight_
            }
        }
        set(value) {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                Product.weight_ = value
            }
        }
    }

    open var weight: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: Product.weight))
        }
        set(value) {
            self.setOptionalValue(for: Product.weight, to: DecimalValue.of(optional: value))
        }
    }

    open class var weightUnit: Property {
        get {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                return Product.weightUnit_
            }
        }
        set(value) {
            objc_sync_enter(Product.self)
            defer { objc_sync_exit(Product.self) }
            do {
                Product.weightUnit_ = value
            }
        }
    }

    open var weightUnit: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Product.weightUnit))
        }
        set(value) {
            self.setOptionalValue(for: Product.weightUnit, to: StringValue.of(optional: value))
        }
    }
}
