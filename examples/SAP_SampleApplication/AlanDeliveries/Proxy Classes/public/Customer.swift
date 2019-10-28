// # Proxy Compiler 19.1.3-b8851a-20190408

import Foundation
import SAPOData

open class Customer: EntityValue {
    public required init(from decoder: Decoder) throws {
        try super.init(from: decoder)
    }

    private static var city_: Property = ESPMContainerMetadata.EntityTypes.customer.property(withName: "City")

    private static var country_: Property = ESPMContainerMetadata.EntityTypes.customer.property(withName: "Country")

    private static var customerID_: Property = ESPMContainerMetadata.EntityTypes.customer.property(withName: "CustomerId")

    private static var dateOfBirth_: Property = ESPMContainerMetadata.EntityTypes.customer.property(withName: "DateOfBirth")

    private static var emailAddress_: Property = ESPMContainerMetadata.EntityTypes.customer.property(withName: "EmailAddress")

    private static var firstName_: Property = ESPMContainerMetadata.EntityTypes.customer.property(withName: "FirstName")

    private static var houseNumber_: Property = ESPMContainerMetadata.EntityTypes.customer.property(withName: "HouseNumber")

    private static var lastName_: Property = ESPMContainerMetadata.EntityTypes.customer.property(withName: "LastName")

    private static var phoneNumber_: Property = ESPMContainerMetadata.EntityTypes.customer.property(withName: "PhoneNumber")

    private static var postalCode_: Property = ESPMContainerMetadata.EntityTypes.customer.property(withName: "PostalCode")

    private static var street_: Property = ESPMContainerMetadata.EntityTypes.customer.property(withName: "Street")

    private static var address_: Property = ESPMContainerMetadata.EntityTypes.customer.property(withName: "Address")

    private static var updatedTimestamp_: Property = ESPMContainerMetadata.EntityTypes.customer.property(withName: "UpdatedTimestamp")

    private static var salesOrders_: Property = ESPMContainerMetadata.EntityTypes.customer.property(withName: "SalesOrders")

    public init(withDefaults: Bool = true) {
        super.init(withDefaults: withDefaults, type: ESPMContainerMetadata.EntityTypes.customer)
    }

    open class var address: Property {
        get {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                return Customer.address_
            }
        }
        set(value) {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                Customer.address_ = value
            }
        }
    }

    open var address: Address? {
        get {
            return CastOptional<Address>.from(self.optionalValue(for: Customer.address))
        }
        set(value) {
            self.setOptionalValue(for: Customer.address, to: value)
        }
    }

    open class func array(from: EntityValueList) -> [Customer] {
        return ArrayConverter.convert(from.toArray(), [Customer]())
    }

    open class var city: Property {
        get {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                return Customer.city_
            }
        }
        set(value) {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                Customer.city_ = value
            }
        }
    }

    open var city: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Customer.city))
        }
        set(value) {
            self.setOptionalValue(for: Customer.city, to: StringValue.of(optional: value))
        }
    }

    open func copy() -> Customer {
        return CastRequired<Customer>.from(self.copyEntity())
    }

    open class var country: Property {
        get {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                return Customer.country_
            }
        }
        set(value) {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                Customer.country_ = value
            }
        }
    }

    open var country: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Customer.country))
        }
        set(value) {
            self.setOptionalValue(for: Customer.country, to: StringValue.of(optional: value))
        }
    }

    open class var customerID: Property {
        get {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                return Customer.customerID_
            }
        }
        set(value) {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                Customer.customerID_ = value
            }
        }
    }

    open var customerID: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Customer.customerID))
        }
        set(value) {
            self.setOptionalValue(for: Customer.customerID, to: StringValue.of(optional: value))
        }
    }

    open class var dateOfBirth: Property {
        get {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                return Customer.dateOfBirth_
            }
        }
        set(value) {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                Customer.dateOfBirth_ = value
            }
        }
    }

    open var dateOfBirth: LocalDateTime? {
        get {
            return LocalDateTime.castOptional(self.optionalValue(for: Customer.dateOfBirth))
        }
        set(value) {
            self.setOptionalValue(for: Customer.dateOfBirth, to: value)
        }
    }

    open class var emailAddress: Property {
        get {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                return Customer.emailAddress_
            }
        }
        set(value) {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                Customer.emailAddress_ = value
            }
        }
    }

    open var emailAddress: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Customer.emailAddress))
        }
        set(value) {
            self.setOptionalValue(for: Customer.emailAddress, to: StringValue.of(optional: value))
        }
    }

    open class var firstName: Property {
        get {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                return Customer.firstName_
            }
        }
        set(value) {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                Customer.firstName_ = value
            }
        }
    }

    open var firstName: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Customer.firstName))
        }
        set(value) {
            self.setOptionalValue(for: Customer.firstName, to: StringValue.of(optional: value))
        }
    }

    open class var houseNumber: Property {
        get {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                return Customer.houseNumber_
            }
        }
        set(value) {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                Customer.houseNumber_ = value
            }
        }
    }

    open var houseNumber: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Customer.houseNumber))
        }
        set(value) {
            self.setOptionalValue(for: Customer.houseNumber, to: StringValue.of(optional: value))
        }
    }

    open override var isProxy: Bool {
        return true
    }

    open class func key(customerID: String?) -> EntityKey {
        return EntityKey().with(name: "CustomerId", value: StringValue.of(optional: customerID))
    }

    open class var lastName: Property {
        get {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                return Customer.lastName_
            }
        }
        set(value) {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                Customer.lastName_ = value
            }
        }
    }

    open var lastName: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Customer.lastName))
        }
        set(value) {
            self.setOptionalValue(for: Customer.lastName, to: StringValue.of(optional: value))
        }
    }

    open var old: Customer {
        return CastRequired<Customer>.from(self.oldEntity)
    }

    open class var phoneNumber: Property {
        get {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                return Customer.phoneNumber_
            }
        }
        set(value) {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                Customer.phoneNumber_ = value
            }
        }
    }

    open var phoneNumber: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Customer.phoneNumber))
        }
        set(value) {
            self.setOptionalValue(for: Customer.phoneNumber, to: StringValue.of(optional: value))
        }
    }

    open class var postalCode: Property {
        get {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                return Customer.postalCode_
            }
        }
        set(value) {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                Customer.postalCode_ = value
            }
        }
    }

    open var postalCode: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Customer.postalCode))
        }
        set(value) {
            self.setOptionalValue(for: Customer.postalCode, to: StringValue.of(optional: value))
        }
    }

    open class var salesOrders: Property {
        get {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                return Customer.salesOrders_
            }
        }
        set(value) {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                Customer.salesOrders_ = value
            }
        }
    }

    open var salesOrders: [SalesOrderHeader] {
        get {
            return ArrayConverter.convert(EntityValueList.castRequired(self.requiredValue(for: Customer.salesOrders)).toArray(), [SalesOrderHeader]())
        }
        set(value) {
            Customer.salesOrders.setEntityList(in: self, to: EntityValueList.fromArray(ArrayConverter.convert(value, [EntityValue]())))
        }
    }

    open class var street: Property {
        get {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                return Customer.street_
            }
        }
        set(value) {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                Customer.street_ = value
            }
        }
    }

    open var street: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Customer.street))
        }
        set(value) {
            self.setOptionalValue(for: Customer.street, to: StringValue.of(optional: value))
        }
    }

    open class var updatedTimestamp: Property {
        get {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                return Customer.updatedTimestamp_
            }
        }
        set(value) {
            objc_sync_enter(Customer.self)
            defer { objc_sync_exit(Customer.self) }
            do {
                Customer.updatedTimestamp_ = value
            }
        }
    }

    open var updatedTimestamp: LocalDateTime? {
        get {
            return LocalDateTime.castOptional(self.optionalValue(for: Customer.updatedTimestamp))
        }
        set(value) {
            self.setOptionalValue(for: Customer.updatedTimestamp, to: value)
        }
    }
}
