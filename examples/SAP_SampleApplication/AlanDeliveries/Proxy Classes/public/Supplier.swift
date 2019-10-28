// # Proxy Compiler 19.1.3-b8851a-20190408

import Foundation
import SAPOData

open class Supplier: EntityValue {
    public required init(from decoder: Decoder) throws {
        try super.init(from: decoder)
    }

    private static var city_: Property = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "City")

    private static var country_: Property = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "Country")

    private static var emailAddress_: Property = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "EmailAddress")

    private static var houseNumber_: Property = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "HouseNumber")

    private static var phoneNumber_: Property = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "PhoneNumber")

    private static var postalCode_: Property = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "PostalCode")

    private static var street_: Property = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "Street")

    private static var supplierID_: Property = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "SupplierId")

    private static var supplierName_: Property = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "SupplierName")

    private static var address_: Property = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "Address")

    private static var updatedTimestamp_: Property = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "UpdatedTimestamp")

    private static var products_: Property = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "Products")

    private static var purchaseOrders_: Property = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "PurchaseOrders")

    public init(withDefaults: Bool = true) {
        super.init(withDefaults: withDefaults, type: ESPMContainerMetadata.EntityTypes.supplier)
    }

    open class var address: Property {
        get {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                return Supplier.address_
            }
        }
        set(value) {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                Supplier.address_ = value
            }
        }
    }

    open var address: Address? {
        get {
            return CastOptional<Address>.from(self.optionalValue(for: Supplier.address))
        }
        set(value) {
            self.setOptionalValue(for: Supplier.address, to: value)
        }
    }

    open class func array(from: EntityValueList) -> [Supplier] {
        return ArrayConverter.convert(from.toArray(), [Supplier]())
    }

    open class var city: Property {
        get {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                return Supplier.city_
            }
        }
        set(value) {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                Supplier.city_ = value
            }
        }
    }

    open var city: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Supplier.city))
        }
        set(value) {
            self.setOptionalValue(for: Supplier.city, to: StringValue.of(optional: value))
        }
    }

    open func copy() -> Supplier {
        return CastRequired<Supplier>.from(self.copyEntity())
    }

    open class var country: Property {
        get {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                return Supplier.country_
            }
        }
        set(value) {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                Supplier.country_ = value
            }
        }
    }

    open var country: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Supplier.country))
        }
        set(value) {
            self.setOptionalValue(for: Supplier.country, to: StringValue.of(optional: value))
        }
    }

    open class var emailAddress: Property {
        get {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                return Supplier.emailAddress_
            }
        }
        set(value) {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                Supplier.emailAddress_ = value
            }
        }
    }

    open var emailAddress: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Supplier.emailAddress))
        }
        set(value) {
            self.setOptionalValue(for: Supplier.emailAddress, to: StringValue.of(optional: value))
        }
    }

    open class var houseNumber: Property {
        get {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                return Supplier.houseNumber_
            }
        }
        set(value) {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                Supplier.houseNumber_ = value
            }
        }
    }

    open var houseNumber: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Supplier.houseNumber))
        }
        set(value) {
            self.setOptionalValue(for: Supplier.houseNumber, to: StringValue.of(optional: value))
        }
    }

    open override var isProxy: Bool {
        return true
    }

    open class func key(supplierID: String?) -> EntityKey {
        return EntityKey().with(name: "SupplierId", value: StringValue.of(optional: supplierID))
    }

    open var old: Supplier {
        return CastRequired<Supplier>.from(self.oldEntity)
    }

    open class var phoneNumber: Property {
        get {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                return Supplier.phoneNumber_
            }
        }
        set(value) {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                Supplier.phoneNumber_ = value
            }
        }
    }

    open var phoneNumber: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Supplier.phoneNumber))
        }
        set(value) {
            self.setOptionalValue(for: Supplier.phoneNumber, to: StringValue.of(optional: value))
        }
    }

    open class var postalCode: Property {
        get {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                return Supplier.postalCode_
            }
        }
        set(value) {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                Supplier.postalCode_ = value
            }
        }
    }

    open var postalCode: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Supplier.postalCode))
        }
        set(value) {
            self.setOptionalValue(for: Supplier.postalCode, to: StringValue.of(optional: value))
        }
    }

    open class var products: Property {
        get {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                return Supplier.products_
            }
        }
        set(value) {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                Supplier.products_ = value
            }
        }
    }

    open var products: [Product] {
        get {
            return ArrayConverter.convert(EntityValueList.castRequired(self.requiredValue(for: Supplier.products)).toArray(), [Product]())
        }
        set(value) {
            Supplier.products.setEntityList(in: self, to: EntityValueList.fromArray(ArrayConverter.convert(value, [EntityValue]())))
        }
    }

    open class var purchaseOrders: Property {
        get {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                return Supplier.purchaseOrders_
            }
        }
        set(value) {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                Supplier.purchaseOrders_ = value
            }
        }
    }

    open var purchaseOrders: [PurchaseOrderHeader] {
        get {
            return ArrayConverter.convert(EntityValueList.castRequired(self.requiredValue(for: Supplier.purchaseOrders)).toArray(), [PurchaseOrderHeader]())
        }
        set(value) {
            Supplier.purchaseOrders.setEntityList(in: self, to: EntityValueList.fromArray(ArrayConverter.convert(value, [EntityValue]())))
        }
    }

    open class var street: Property {
        get {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                return Supplier.street_
            }
        }
        set(value) {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                Supplier.street_ = value
            }
        }
    }

    open var street: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Supplier.street))
        }
        set(value) {
            self.setOptionalValue(for: Supplier.street, to: StringValue.of(optional: value))
        }
    }

    open class var supplierID: Property {
        get {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                return Supplier.supplierID_
            }
        }
        set(value) {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                Supplier.supplierID_ = value
            }
        }
    }

    open var supplierID: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Supplier.supplierID))
        }
        set(value) {
            self.setOptionalValue(for: Supplier.supplierID, to: StringValue.of(optional: value))
        }
    }

    open class var supplierName: Property {
        get {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                return Supplier.supplierName_
            }
        }
        set(value) {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                Supplier.supplierName_ = value
            }
        }
    }

    open var supplierName: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Supplier.supplierName))
        }
        set(value) {
            self.setOptionalValue(for: Supplier.supplierName, to: StringValue.of(optional: value))
        }
    }

    open class var updatedTimestamp: Property {
        get {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                return Supplier.updatedTimestamp_
            }
        }
        set(value) {
            objc_sync_enter(Supplier.self)
            defer { objc_sync_exit(Supplier.self) }
            do {
                Supplier.updatedTimestamp_ = value
            }
        }
    }

    open var updatedTimestamp: LocalDateTime? {
        get {
            return LocalDateTime.castOptional(self.optionalValue(for: Supplier.updatedTimestamp))
        }
        set(value) {
            self.setOptionalValue(for: Supplier.updatedTimestamp, to: value)
        }
    }
}
