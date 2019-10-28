// # Proxy Compiler 19.1.3-b8851a-20190408

import Foundation
import SAPOData

open class ProductCategory: EntityValue {
    public required init(from decoder: Decoder) throws {
        try super.init(from: decoder)
    }

    private static var category_: Property = ESPMContainerMetadata.EntityTypes.productCategory.property(withName: "Category")

    private static var categoryName_: Property = ESPMContainerMetadata.EntityTypes.productCategory.property(withName: "CategoryName")

    private static var mainCategory_: Property = ESPMContainerMetadata.EntityTypes.productCategory.property(withName: "MainCategory")

    private static var mainCategoryName_: Property = ESPMContainerMetadata.EntityTypes.productCategory.property(withName: "MainCategoryName")

    private static var numberOfProducts_: Property = ESPMContainerMetadata.EntityTypes.productCategory.property(withName: "NumberOfProducts")

    private static var updatedTimestamp_: Property = ESPMContainerMetadata.EntityTypes.productCategory.property(withName: "UpdatedTimestamp")

    public init(withDefaults: Bool = true) {
        super.init(withDefaults: withDefaults, type: ESPMContainerMetadata.EntityTypes.productCategory)
    }

    open class func array(from: EntityValueList) -> [ProductCategory] {
        return ArrayConverter.convert(from.toArray(), [ProductCategory]())
    }

    open class var category: Property {
        get {
            objc_sync_enter(ProductCategory.self)
            defer { objc_sync_exit(ProductCategory.self) }
            do {
                return ProductCategory.category_
            }
        }
        set(value) {
            objc_sync_enter(ProductCategory.self)
            defer { objc_sync_exit(ProductCategory.self) }
            do {
                ProductCategory.category_ = value
            }
        }
    }

    open var category: String? {
        get {
            return StringValue.optional(self.optionalValue(for: ProductCategory.category))
        }
        set(value) {
            self.setOptionalValue(for: ProductCategory.category, to: StringValue.of(optional: value))
        }
    }

    open class var categoryName: Property {
        get {
            objc_sync_enter(ProductCategory.self)
            defer { objc_sync_exit(ProductCategory.self) }
            do {
                return ProductCategory.categoryName_
            }
        }
        set(value) {
            objc_sync_enter(ProductCategory.self)
            defer { objc_sync_exit(ProductCategory.self) }
            do {
                ProductCategory.categoryName_ = value
            }
        }
    }

    open var categoryName: String? {
        get {
            return StringValue.optional(self.optionalValue(for: ProductCategory.categoryName))
        }
        set(value) {
            self.setOptionalValue(for: ProductCategory.categoryName, to: StringValue.of(optional: value))
        }
    }

    open func copy() -> ProductCategory {
        return CastRequired<ProductCategory>.from(self.copyEntity())
    }

    open override var isProxy: Bool {
        return true
    }

    open class func key(category: String?) -> EntityKey {
        return EntityKey().with(name: "Category", value: StringValue.of(optional: category))
    }

    open class var mainCategory: Property {
        get {
            objc_sync_enter(ProductCategory.self)
            defer { objc_sync_exit(ProductCategory.self) }
            do {
                return ProductCategory.mainCategory_
            }
        }
        set(value) {
            objc_sync_enter(ProductCategory.self)
            defer { objc_sync_exit(ProductCategory.self) }
            do {
                ProductCategory.mainCategory_ = value
            }
        }
    }

    open var mainCategory: String? {
        get {
            return StringValue.optional(self.optionalValue(for: ProductCategory.mainCategory))
        }
        set(value) {
            self.setOptionalValue(for: ProductCategory.mainCategory, to: StringValue.of(optional: value))
        }
    }

    open class var mainCategoryName: Property {
        get {
            objc_sync_enter(ProductCategory.self)
            defer { objc_sync_exit(ProductCategory.self) }
            do {
                return ProductCategory.mainCategoryName_
            }
        }
        set(value) {
            objc_sync_enter(ProductCategory.self)
            defer { objc_sync_exit(ProductCategory.self) }
            do {
                ProductCategory.mainCategoryName_ = value
            }
        }
    }

    open var mainCategoryName: String? {
        get {
            return StringValue.optional(self.optionalValue(for: ProductCategory.mainCategoryName))
        }
        set(value) {
            self.setOptionalValue(for: ProductCategory.mainCategoryName, to: StringValue.of(optional: value))
        }
    }

    open class var numberOfProducts: Property {
        get {
            objc_sync_enter(ProductCategory.self)
            defer { objc_sync_exit(ProductCategory.self) }
            do {
                return ProductCategory.numberOfProducts_
            }
        }
        set(value) {
            objc_sync_enter(ProductCategory.self)
            defer { objc_sync_exit(ProductCategory.self) }
            do {
                ProductCategory.numberOfProducts_ = value
            }
        }
    }

    open var numberOfProducts: Int64? {
        get {
            return LongValue.optional(self.optionalValue(for: ProductCategory.numberOfProducts))
        }
        set(value) {
            self.setOptionalValue(for: ProductCategory.numberOfProducts, to: LongValue.of(optional: value))
        }
    }

    open var old: ProductCategory {
        return CastRequired<ProductCategory>.from(self.oldEntity)
    }

    open class var updatedTimestamp: Property {
        get {
            objc_sync_enter(ProductCategory.self)
            defer { objc_sync_exit(ProductCategory.self) }
            do {
                return ProductCategory.updatedTimestamp_
            }
        }
        set(value) {
            objc_sync_enter(ProductCategory.self)
            defer { objc_sync_exit(ProductCategory.self) }
            do {
                ProductCategory.updatedTimestamp_ = value
            }
        }
    }

    open var updatedTimestamp: LocalDateTime? {
        get {
            return LocalDateTime.castOptional(self.optionalValue(for: ProductCategory.updatedTimestamp))
        }
        set(value) {
            self.setOptionalValue(for: ProductCategory.updatedTimestamp, to: value)
        }
    }
}
