// # Proxy Compiler 19.1.3-b8851a-20190408

import Foundation
import SAPOData

open class SalesOrderHeader: EntityValue {
    public required init(from decoder: Decoder) throws {
        try super.init(from: decoder)
    }

    private static var createdAt_: Property = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "CreatedAt")

    private static var currencyCode_: Property = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "CurrencyCode")

    private static var customerID_: Property = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "CustomerId")

    private static var grossAmount_: Property = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "GrossAmount")

    private static var lifeCycleStatus_: Property = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "LifeCycleStatus")

    private static var lifeCycleStatusName_: Property = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "LifeCycleStatusName")

    private static var netAmount_: Property = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "NetAmount")

    private static var salesOrderID_: Property = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "SalesOrderId")

    private static var taxAmount_: Property = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "TaxAmount")

    private static var items_: Property = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "Items")

    private static var customerDetails_: Property = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "CustomerDetails")

    public init(withDefaults: Bool = true) {
        super.init(withDefaults: withDefaults, type: ESPMContainerMetadata.EntityTypes.salesOrderHeader)
    }

    open class func array(from: EntityValueList) -> [SalesOrderHeader] {
        return ArrayConverter.convert(from.toArray(), [SalesOrderHeader]())
    }

    open func copy() -> SalesOrderHeader {
        return CastRequired<SalesOrderHeader>.from(self.copyEntity())
    }

    open class var createdAt: Property {
        get {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                return SalesOrderHeader.createdAt_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                SalesOrderHeader.createdAt_ = value
            }
        }
    }

    open var createdAt: LocalDateTime? {
        get {
            return LocalDateTime.castOptional(self.optionalValue(for: SalesOrderHeader.createdAt))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderHeader.createdAt, to: value)
        }
    }

    open class var currencyCode: Property {
        get {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                return SalesOrderHeader.currencyCode_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                SalesOrderHeader.currencyCode_ = value
            }
        }
    }

    open var currencyCode: String? {
        get {
            return StringValue.optional(self.optionalValue(for: SalesOrderHeader.currencyCode))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderHeader.currencyCode, to: StringValue.of(optional: value))
        }
    }

    open class var customerDetails: Property {
        get {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                return SalesOrderHeader.customerDetails_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                SalesOrderHeader.customerDetails_ = value
            }
        }
    }

    open var customerDetails: Customer? {
        get {
            return CastOptional<Customer>.from(self.optionalValue(for: SalesOrderHeader.customerDetails))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderHeader.customerDetails, to: value)
        }
    }

    open class var customerID: Property {
        get {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                return SalesOrderHeader.customerID_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                SalesOrderHeader.customerID_ = value
            }
        }
    }

    open var customerID: String? {
        get {
            return StringValue.optional(self.optionalValue(for: SalesOrderHeader.customerID))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderHeader.customerID, to: StringValue.of(optional: value))
        }
    }

    open class var grossAmount: Property {
        get {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                return SalesOrderHeader.grossAmount_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                SalesOrderHeader.grossAmount_ = value
            }
        }
    }

    open var grossAmount: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: SalesOrderHeader.grossAmount))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderHeader.grossAmount, to: DecimalValue.of(optional: value))
        }
    }

    open override var isProxy: Bool {
        return true
    }

    open class var items: Property {
        get {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                return SalesOrderHeader.items_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                SalesOrderHeader.items_ = value
            }
        }
    }

    open var items: [SalesOrderItem] {
        get {
            return ArrayConverter.convert(EntityValueList.castRequired(self.requiredValue(for: SalesOrderHeader.items)).toArray(), [SalesOrderItem]())
        }
        set(value) {
            SalesOrderHeader.items.setEntityList(in: self, to: EntityValueList.fromArray(ArrayConverter.convert(value, [EntityValue]())))
        }
    }

    open class func key(salesOrderID: String?) -> EntityKey {
        return EntityKey().with(name: "SalesOrderId", value: StringValue.of(optional: salesOrderID))
    }

    open class var lifeCycleStatus: Property {
        get {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                return SalesOrderHeader.lifeCycleStatus_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                SalesOrderHeader.lifeCycleStatus_ = value
            }
        }
    }

    open var lifeCycleStatus: String? {
        get {
            return StringValue.optional(self.optionalValue(for: SalesOrderHeader.lifeCycleStatus))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderHeader.lifeCycleStatus, to: StringValue.of(optional: value))
        }
    }

    open class var lifeCycleStatusName: Property {
        get {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                return SalesOrderHeader.lifeCycleStatusName_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                SalesOrderHeader.lifeCycleStatusName_ = value
            }
        }
    }

    open var lifeCycleStatusName: String? {
        get {
            return StringValue.optional(self.optionalValue(for: SalesOrderHeader.lifeCycleStatusName))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderHeader.lifeCycleStatusName, to: StringValue.of(optional: value))
        }
    }

    open class var netAmount: Property {
        get {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                return SalesOrderHeader.netAmount_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                SalesOrderHeader.netAmount_ = value
            }
        }
    }

    open var netAmount: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: SalesOrderHeader.netAmount))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderHeader.netAmount, to: DecimalValue.of(optional: value))
        }
    }

    open var old: SalesOrderHeader {
        return CastRequired<SalesOrderHeader>.from(self.oldEntity)
    }

    open class var salesOrderID: Property {
        get {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                return SalesOrderHeader.salesOrderID_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                SalesOrderHeader.salesOrderID_ = value
            }
        }
    }

    open var salesOrderID: String? {
        get {
            return StringValue.optional(self.optionalValue(for: SalesOrderHeader.salesOrderID))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderHeader.salesOrderID, to: StringValue.of(optional: value))
        }
    }

    open class var taxAmount: Property {
        get {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                return SalesOrderHeader.taxAmount_
            }
        }
        set(value) {
            objc_sync_enter(SalesOrderHeader.self)
            defer { objc_sync_exit(SalesOrderHeader.self) }
            do {
                SalesOrderHeader.taxAmount_ = value
            }
        }
    }

    open var taxAmount: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: SalesOrderHeader.taxAmount))
        }
        set(value) {
            self.setOptionalValue(for: SalesOrderHeader.taxAmount, to: DecimalValue.of(optional: value))
        }
    }
}
