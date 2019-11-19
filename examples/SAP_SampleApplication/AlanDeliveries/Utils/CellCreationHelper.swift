//
// AlanDeliveries
//
// Created by SAP Cloud Platform SDK for iOS Assistant application on 24/04/19
//

import Foundation
import SAPFiori
import SAPOData
import UIKit

class CellCreationHelper {
    // MARK: - Creating cells

    static func objectCellWithNonEditableContent(tableView: UITableView, indexPath: IndexPath, key: String, value: String) -> FUIObjectTableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: FUIObjectTableViewCell.reuseIdentifier, for: indexPath as IndexPath) as! FUIObjectTableViewCell
        cell.headlineText = value
        cell.footnoteText = key
        cell.accessoryType = .disclosureIndicator
        return cell
    }

    static func cellForDefault(tableView: UITableView, indexPath: IndexPath, editingIsAllowed: Bool = false) -> FUITextFieldFormCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: FUITextFieldFormCell.reuseIdentifier, for: indexPath) as! FUITextFieldFormCell
        cell.textLabel!.text = ""
        cell.textLabel!.numberOfLines = 0
        cell.textLabel!.lineBreakMode = NSLineBreakMode.byWordWrapping
        cell.keyName = "default"
        cell.isEditable = editingIsAllowed
        return cell
    }

    static func cellForProperty(tableView: UITableView, indexPath: IndexPath, entity: EntityValue, property: Property, value: String, editingIsAllowed: Bool = false, changeHandler: @escaping ((String) -> Bool)) -> UITableViewCell {
        let cell: UITableViewCell!

        if property.dataType.isBasic {
            // The property is a key or we are creating new entity
            if !property.isKey || entity.isNew {
                // .. that CAN be edited
                cell = self.formCellWithEditableContent(tableView: tableView, indexPath: indexPath, property: property, with: value, editingIsAllowed: editingIsAllowed, changeHandler: changeHandler)
            } else {
                // .. that CANNOT be edited
                cell = self.formCellWithNonEditableContent(tableView: tableView, indexPath: indexPath, for: property.name, with: value)
            }
        } else {
            // A complex property
            cell = self.formCellWithNonEditableContent(tableView: tableView, indexPath: indexPath, for: property.name, with: "...")
        }
        return cell
    }

    private static func formCellWithEditableContent(tableView: UITableView, indexPath: IndexPath, property: Property, with value: String, editingIsAllowed: Bool = true, changeHandler: @escaping ((String) -> Bool)) -> FUITextFieldFormCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: FUITextFieldFormCell.reuseIdentifier, for: indexPath) as! FUITextFieldFormCell

        cell.keyName = property.name
        cell.value = value
        cell.isTrackingLiveChanges = true
        cell.isEditable = editingIsAllowed

        if !property.isOptional {
            cell.valueTextField.placeholder = NSLocalizedString("keyRequiredPlaceholder", value: "Required", comment: "XSEL: Placeholder text for required but currently empty textfield.")
        }

        cell.onChangeHandler = { (newValue) -> Void in
            let isNewValueValid = changeHandler(newValue)
            if !isNewValueValid {
                cell.valueTextField.textColor = UIColor.red
            } else {
                cell.valueTextField.textColor = UIColor.gray
            }
        }

        return cell
    }

    private static func formCellWithNonEditableContent(tableView: UITableView, indexPath: IndexPath, for key: String, with value: String) -> FUITextFieldFormCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: FUITextFieldFormCell.reuseIdentifier, for: indexPath) as! FUITextFieldFormCell
        cell.keyName = key
        cell.value = value
        cell.isEditable = false
        return cell
    }

    // MARK: - Parsing default values

    static func defaultValueFor(_ property: Property) -> Double {
        if let defaultValue = property.defaultValue {
            return Double(defaultValue.toString())!
        } else {
            return Double()
        }
    }

    static func defaultValueFor(_ property: Property) -> BigDecimal {
        if let defaultValue = property.defaultValue {
            return (defaultValue as! DecimalValue).value
        } else {
            return BigDecimal.fromDouble(Double())
        }
    }

    static func defaultValueFor(_ property: Property) -> Int {
        if let defaultValue = property.defaultValue {
            return Int(defaultValue.toString())!
        } else {
            return Int()
        }
    }

    static func defaultValueFor(_ property: Property) -> BigInteger {
        if let defaultValue = property.defaultValue {
            return BigInteger(defaultValue.toString())
        } else {
            return BigInteger.fromInt(Int())
        }
    }

    static func defaultValueFor(_ property: Property) -> Int64 {
        if let defaultValue = property.defaultValue {
            return Int64(defaultValue.toString())!
        } else {
            return Int64()
        }
    }

    static func defaultValueFor(_ property: Property) -> Float {
        if let defaultValue = property.defaultValue {
            return Float(defaultValue.toString())!
        } else {
            return Float()
        }
    }

    static func defaultValueFor(_ property: Property) -> LocalDateTime {
        if let defaultValue = property.defaultValue {
            return LocalDateTime.parse(defaultValue.toString())!
        } else {
            return LocalDateTime.now()
        }
    }

    static func defaultValueFor(_ property: Property) -> GlobalDateTime {
        if let defaultValue = property.defaultValue {
            return GlobalDateTime.parse(defaultValue.toString())!
        } else {
            return GlobalDateTime.now()
        }
    }

    static func defaultValueFor(_ property: Property) -> GuidValue {
        if let defaultValue = property.defaultValue {
            return GuidValue.parse(defaultValue.toString())!
        } else {
            return GuidValue.random()
        }
    }

    static func defaultValueFor(_ property: Property) -> String {
        if let defaultValue = property.defaultValue {
            return defaultValue.toString()
        } else {
            return ""
        }
    }

    static func defaultValueFor(_ property: Property) -> Bool {
        if let defaultValue = property.defaultValue {
            return Bool(defaultValue.toString()) ?? false
        } else {
            return Bool()
        }
    }
}
