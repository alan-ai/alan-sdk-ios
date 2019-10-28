// # Proxy Compiler 19.1.3-b8851a-20190408

import Foundation
import SAPOData

open class PurchaseOrderHeader: EntityValue {
    public required init(from decoder: Decoder) throws {
        try super.init(from: decoder)
    }

    private static var currencyCode_: Property = ESPMContainerMetadata.EntityTypes.purchaseOrderHeader.property(withName: "CurrencyCode")

    private static var grossAmount_: Property = ESPMContainerMetadata.EntityTypes.purchaseOrderHeader.property(withName: "GrossAmount")

    private static var netAmount_: Property = ESPMContainerMetadata.EntityTypes.purchaseOrderHeader.property(withName: "NetAmount")

    private static var purchaseOrderID_: Property = ESPMContainerMetadata.EntityTypes.purchaseOrderHeader.property(withName: "PurchaseOrderId")

    private static var supplierID_: Property = ESPMContainerMetadata.EntityTypes.purchaseOrderHeader.property(withName: "SupplierId")

    private static var taxAmount_: Property = ESPMContainerMetadata.EntityTypes.purchaseOrderHeader.property(withName: "TaxAmount")

    private static var items_: Property = ESPMContainerMetadata.EntityTypes.purchaseOrderHeader.property(withName: "Items")

    private static var supplierDetails_: Property = ESPMContainerMetadata.EntityTypes.purchaseOrderHeader.property(withName: "SupplierDetails")

    public init(withDefaults: Bool = true) {
        super.init(withDefaults: withDefaults, type: ESPMContainerMetadata.EntityTypes.purchaseOrderHeader)
    }

    open class func array(from: EntityValueList) -> [PurchaseOrderHeader] {
        return ArrayConverter.convert(from.toArray(), [PurchaseOrderHeader]())
    }

    open func copy() -> PurchaseOrderHeader {
        return CastRequired<PurchaseOrderHeader>.from(self.copyEntity())
    }

    open class var currencyCode: Property {
        get {
            objc_sync_enter(PurchaseOrderHeader.self)
            defer { objc_sync_exit(PurchaseOrderHeader.self) }
            do {
                return PurchaseOrderHeader.currencyCode_
            }
        }
        set(value) {
            objc_sync_enter(PurchaseOrderHeader.self)
            defer { objc_sync_exit(PurchaseOrderHeader.self) }
            do {
                PurchaseOrderHeader.currencyCode_ = value
            }
        }
    }

    open var currencyCode: String? {
        get {
            return StringValue.optional(self.optionalValue(for: PurchaseOrderHeader.currencyCode))
        }
        set(value) {
            self.setOptionalValue(for: PurchaseOrderHeader.currencyCode, to: StringValue.of(optional: value))
        }
    }

    open class var grossAmount: Property {
        get {
            objc_sync_enter(PurchaseOrderHeader.self)
            defer { objc_sync_exit(PurchaseOrderHeader.self) }
            do {
                return PurchaseOrderHeader.grossAmount_
            }
        }
        set(value) {
            objc_sync_enter(PurchaseOrderHeader.self)
            defer { objc_sync_exit(PurchaseOrderHeader.self) }
            do {
                PurchaseOrderHeader.grossAmount_ = value
            }
        }
    }

    open var grossAmount: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: PurchaseOrderHeader.grossAmount))
        }
        set(value) {
            self.setOptionalValue(for: PurchaseOrderHeader.grossAmount, to: DecimalValue.of(optional: value))
        }
    }

    open override var isProxy: Bool {
        return true
    }

    open class var items: Property {
        get {
            objc_sync_enter(PurchaseOrderHeader.self)
            defer { objc_sync_exit(PurchaseOrderHeader.self) }
            do {
                return PurchaseOrderHeader.items_
            }
        }
        set(value) {
            objc_sync_enter(PurchaseOrderHeader.self)
            defer { objc_sync_exit(PurchaseOrderHeader.self) }
            do {
                PurchaseOrderHeader.items_ = value
            }
        }
    }

    open var items: [PurchaseOrderItem] {
        get {
            return ArrayConverter.convert(EntityValueList.castRequired(self.requiredValue(for: PurchaseOrderHeader.items)).toArray(), [PurchaseOrderItem]())
        }
        set(value) {
            PurchaseOrderHeader.items.setEntityList(in: self, to: EntityValueList.fromArray(ArrayConverter.convert(value, [EntityValue]())))
        }
    }

    open class func key(purchaseOrderID: String?) -> EntityKey {
        return EntityKey().with(name: "PurchaseOrderId", value: StringValue.of(optional: purchaseOrderID))
    }

    open class var netAmount: Property {
        get {
            objc_sync_enter(PurchaseOrderHeader.self)
            defer { objc_sync_exit(PurchaseOrderHeader.self) }
            do {
                return PurchaseOrderHeader.netAmount_
            }
        }
        set(value) {
            objc_sync_enter(PurchaseOrderHeader.self)
            defer { objc_sync_exit(PurchaseOrderHeader.self) }
            do {
                PurchaseOrderHeader.netAmount_ = value
            }
        }
    }

    open var netAmount: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: PurchaseOrderHeader.netAmount))
        }
        set(value) {
            self.setOptionalValue(for: PurchaseOrderHeader.netAmount, to: DecimalValue.of(optional: value))
        }
    }

    open var old: PurchaseOrderHeader {
        return CastRequired<PurchaseOrderHeader>.from(self.oldEntity)
    }

    open class var purchaseOrderID: Property {
        get {
            objc_sync_enter(PurchaseOrderHeader.self)
            defer { objc_sync_exit(PurchaseOrderHeader.self) }
            do {
                return PurchaseOrderHeader.purchaseOrderID_
            }
        }
        set(value) {
            objc_sync_enter(PurchaseOrderHeader.self)
            defer { objc_sync_exit(PurchaseOrderHeader.self) }
            do {
                PurchaseOrderHeader.purchaseOrderID_ = value
            }
        }
    }

    open var purchaseOrderID: String? {
        get {
            return StringValue.optional(self.optionalValue(for: PurchaseOrderHeader.purchaseOrderID))
        }
        set(value) {
            self.setOptionalValue(for: PurchaseOrderHeader.purchaseOrderID, to: StringValue.of(optional: value))
        }
    }

    open class var supplierDetails: Property {
        get {
            objc_sync_enter(PurchaseOrderHeader.self)
            defer { objc_sync_exit(PurchaseOrderHeader.self) }
            do {
                return PurchaseOrderHeader.supplierDetails_
            }
        }
        set(value) {
            objc_sync_enter(PurchaseOrderHeader.self)
            defer { objc_sync_exit(PurchaseOrderHeader.self) }
            do {
                PurchaseOrderHeader.supplierDetails_ = value
            }
        }
    }

    open var supplierDetails: Supplier? {
        get {
            return CastOptional<Supplier>.from(self.optionalValue(for: PurchaseOrderHeader.supplierDetails))
        }
        set(value) {
            self.setOptionalValue(for: PurchaseOrderHeader.supplierDetails, to: value)
        }
    }

    open class var supplierID: Property {
        get {
            objc_sync_enter(PurchaseOrderHeader.self)
            defer { objc_sync_exit(PurchaseOrderHeader.self) }
            do {
                return PurchaseOrderHeader.supplierID_
            }
        }
        set(value) {
            objc_sync_enter(PurchaseOrderHeader.self)
            defer { objc_sync_exit(PurchaseOrderHeader.self) }
            do {
                PurchaseOrderHeader.supplierID_ = value
            }
        }
    }

    open var supplierID: String? {
        get {
            return StringValue.optional(self.optionalValue(for: PurchaseOrderHeader.supplierID))
        }
        set(value) {
            self.setOptionalValue(for: PurchaseOrderHeader.supplierID, to: StringValue.of(optional: value))
        }
    }

    open class var taxAmount: Property {
        get {
            objc_sync_enter(PurchaseOrderHeader.self)
            defer { objc_sync_exit(PurchaseOrderHeader.self) }
            do {
                return PurchaseOrderHeader.taxAmount_
            }
        }
        set(value) {
            objc_sync_enter(PurchaseOrderHeader.self)
            defer { objc_sync_exit(PurchaseOrderHeader.self) }
            do {
                PurchaseOrderHeader.taxAmount_ = value
            }
        }
    }

    open var taxAmount: BigDecimal? {
        get {
            return DecimalValue.optional(self.optionalValue(for: PurchaseOrderHeader.taxAmount))
        }
        set(value) {
            self.setOptionalValue(for: PurchaseOrderHeader.taxAmount, to: DecimalValue.of(optional: value))
        }
    }
}
