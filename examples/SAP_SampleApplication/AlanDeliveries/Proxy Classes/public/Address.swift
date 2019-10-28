// # Proxy Compiler 19.1.3-b8851a-20190408

import Foundation
import SAPOData

open class Address: ComplexValue {
    public required init(from decoder: Decoder) throws {
        try super.init(from: decoder)
    }

    private static var houseNumber_: Property = ESPMContainerMetadata.ComplexTypes.address.property(withName: "HouseNumber")

    private static var street_: Property = ESPMContainerMetadata.ComplexTypes.address.property(withName: "Street")

    private static var city_: Property = ESPMContainerMetadata.ComplexTypes.address.property(withName: "City")

    private static var country_: Property = ESPMContainerMetadata.ComplexTypes.address.property(withName: "Country")

    private static var postalCode_: Property = ESPMContainerMetadata.ComplexTypes.address.property(withName: "PostalCode")

    public init(withDefaults: Bool = true) {
        super.init(withDefaults: withDefaults, type: ESPMContainerMetadata.ComplexTypes.address)
    }

    open class var city: Property {
        get {
            objc_sync_enter(Address.self)
            defer { objc_sync_exit(Address.self) }
            do {
                return Address.city_
            }
        }
        set(value) {
            objc_sync_enter(Address.self)
            defer { objc_sync_exit(Address.self) }
            do {
                Address.city_ = value
            }
        }
    }

    open var city: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Address.city))
        }
        set(value) {
            self.setOptionalValue(for: Address.city, to: StringValue.of(optional: value))
        }
    }

    open func copy() -> Address {
        return CastRequired<Address>.from(self.copyComplex())
    }

    open class var country: Property {
        get {
            objc_sync_enter(Address.self)
            defer { objc_sync_exit(Address.self) }
            do {
                return Address.country_
            }
        }
        set(value) {
            objc_sync_enter(Address.self)
            defer { objc_sync_exit(Address.self) }
            do {
                Address.country_ = value
            }
        }
    }

    open var country: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Address.country))
        }
        set(value) {
            self.setOptionalValue(for: Address.country, to: StringValue.of(optional: value))
        }
    }

    open class var houseNumber: Property {
        get {
            objc_sync_enter(Address.self)
            defer { objc_sync_exit(Address.self) }
            do {
                return Address.houseNumber_
            }
        }
        set(value) {
            objc_sync_enter(Address.self)
            defer { objc_sync_exit(Address.self) }
            do {
                Address.houseNumber_ = value
            }
        }
    }

    open var houseNumber: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Address.houseNumber))
        }
        set(value) {
            self.setOptionalValue(for: Address.houseNumber, to: StringValue.of(optional: value))
        }
    }

    open override var isProxy: Bool {
        return true
    }

    open var old: Address {
        return CastRequired<Address>.from(self.oldComplex)
    }

    open class var postalCode: Property {
        get {
            objc_sync_enter(Address.self)
            defer { objc_sync_exit(Address.self) }
            do {
                return Address.postalCode_
            }
        }
        set(value) {
            objc_sync_enter(Address.self)
            defer { objc_sync_exit(Address.self) }
            do {
                Address.postalCode_ = value
            }
        }
    }

    open var postalCode: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Address.postalCode))
        }
        set(value) {
            self.setOptionalValue(for: Address.postalCode, to: StringValue.of(optional: value))
        }
    }

    open class var street: Property {
        get {
            objc_sync_enter(Address.self)
            defer { objc_sync_exit(Address.self) }
            do {
                return Address.street_
            }
        }
        set(value) {
            objc_sync_enter(Address.self)
            defer { objc_sync_exit(Address.self) }
            do {
                Address.street_ = value
            }
        }
    }

    open var street: String? {
        get {
            return StringValue.optional(self.optionalValue(for: Address.street))
        }
        set(value) {
            self.setOptionalValue(for: Address.street, to: StringValue.of(optional: value))
        }
    }
}
