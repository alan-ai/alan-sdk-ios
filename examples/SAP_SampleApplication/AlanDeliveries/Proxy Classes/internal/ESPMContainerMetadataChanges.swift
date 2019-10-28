// # Proxy Compiler 19.1.3-b8851a-20190408

import Foundation
import SAPOData

internal class ESPMContainerMetadataChanges {
    static func merge(metadata: CSDLDocument) {
        metadata.hasGeneratedProxies = true
        ESPMContainerMetadata.document = metadata
        ESPMContainerMetadataChanges.merge1(metadata: metadata)
        try! ESPMContainerFactory.registerAll()
    }

    private static func merge1(metadata: CSDLDocument) {
        Ignore.valueOf_any(metadata)
        if !ESPMContainerMetadata.ComplexTypes.address.isRemoved {
            ESPMContainerMetadata.ComplexTypes.address = metadata.complexType(withName: "ESPM.Address")
        }
        if !ESPMContainerMetadata.EntityTypes.customer.isRemoved {
            ESPMContainerMetadata.EntityTypes.customer = metadata.entityType(withName: "ESPM.Customer")
        }
        if !ESPMContainerMetadata.EntityTypes.product.isRemoved {
            ESPMContainerMetadata.EntityTypes.product = metadata.entityType(withName: "ESPM.Product")
        }
        if !ESPMContainerMetadata.EntityTypes.productCategory.isRemoved {
            ESPMContainerMetadata.EntityTypes.productCategory = metadata.entityType(withName: "ESPM.ProductCategory")
        }
        if !ESPMContainerMetadata.EntityTypes.productText.isRemoved {
            ESPMContainerMetadata.EntityTypes.productText = metadata.entityType(withName: "ESPM.ProductText")
        }
        if !ESPMContainerMetadata.EntityTypes.purchaseOrderHeader.isRemoved {
            ESPMContainerMetadata.EntityTypes.purchaseOrderHeader = metadata.entityType(withName: "ESPM.PurchaseOrderHeader")
        }
        if !ESPMContainerMetadata.EntityTypes.purchaseOrderItem.isRemoved {
            ESPMContainerMetadata.EntityTypes.purchaseOrderItem = metadata.entityType(withName: "ESPM.PurchaseOrderItem")
        }
        if !ESPMContainerMetadata.EntityTypes.salesOrderHeader.isRemoved {
            ESPMContainerMetadata.EntityTypes.salesOrderHeader = metadata.entityType(withName: "ESPM.SalesOrderHeader")
        }
        if !ESPMContainerMetadata.EntityTypes.salesOrderItem.isRemoved {
            ESPMContainerMetadata.EntityTypes.salesOrderItem = metadata.entityType(withName: "ESPM.SalesOrderItem")
        }
        if !ESPMContainerMetadata.EntityTypes.stock.isRemoved {
            ESPMContainerMetadata.EntityTypes.stock = metadata.entityType(withName: "ESPM.Stock")
        }
        if !ESPMContainerMetadata.EntityTypes.supplier.isRemoved {
            ESPMContainerMetadata.EntityTypes.supplier = metadata.entityType(withName: "ESPM.Supplier")
        }
        if !ESPMContainerMetadata.EntitySets.customers.isRemoved {
            ESPMContainerMetadata.EntitySets.customers = metadata.entitySet(withName: "Customers")
        }
        if !ESPMContainerMetadata.EntitySets.productCategories.isRemoved {
            ESPMContainerMetadata.EntitySets.productCategories = metadata.entitySet(withName: "ProductCategories")
        }
        if !ESPMContainerMetadata.EntitySets.productTexts.isRemoved {
            ESPMContainerMetadata.EntitySets.productTexts = metadata.entitySet(withName: "ProductTexts")
        }
        if !ESPMContainerMetadata.EntitySets.products.isRemoved {
            ESPMContainerMetadata.EntitySets.products = metadata.entitySet(withName: "Products")
        }
        if !ESPMContainerMetadata.EntitySets.purchaseOrderHeaders.isRemoved {
            ESPMContainerMetadata.EntitySets.purchaseOrderHeaders = metadata.entitySet(withName: "PurchaseOrderHeaders")
        }
        if !ESPMContainerMetadata.EntitySets.purchaseOrderItems.isRemoved {
            ESPMContainerMetadata.EntitySets.purchaseOrderItems = metadata.entitySet(withName: "PurchaseOrderItems")
        }
        if !ESPMContainerMetadata.EntitySets.salesOrderHeaders.isRemoved {
            ESPMContainerMetadata.EntitySets.salesOrderHeaders = metadata.entitySet(withName: "SalesOrderHeaders")
        }
        if !ESPMContainerMetadata.EntitySets.salesOrderItems.isRemoved {
            ESPMContainerMetadata.EntitySets.salesOrderItems = metadata.entitySet(withName: "SalesOrderItems")
        }
        if !ESPMContainerMetadata.EntitySets.stock.isRemoved {
            ESPMContainerMetadata.EntitySets.stock = metadata.entitySet(withName: "Stock")
        }
        if !ESPMContainerMetadata.EntitySets.suppliers.isRemoved {
            ESPMContainerMetadata.EntitySets.suppliers = metadata.entitySet(withName: "Suppliers")
        }
        if !ESPMContainerMetadata.ActionImports.generateSamplePurchaseOrders.isRemoved {
            ESPMContainerMetadata.ActionImports.generateSamplePurchaseOrders = metadata.dataMethod(withName: "GenerateSamplePurchaseOrders")
        }
        if !ESPMContainerMetadata.ActionImports.generateSampleSalesOrders.isRemoved {
            ESPMContainerMetadata.ActionImports.generateSampleSalesOrders = metadata.dataMethod(withName: "GenerateSampleSalesOrders")
        }
        if !ESPMContainerMetadata.ActionImports.resetSampleData.isRemoved {
            ESPMContainerMetadata.ActionImports.resetSampleData = metadata.dataMethod(withName: "ResetSampleData")
        }
        if !ESPMContainerMetadata.ActionImports.updateSalesOrderStatus.isRemoved {
            ESPMContainerMetadata.ActionImports.updateSalesOrderStatus = metadata.dataMethod(withName: "UpdateSalesOrderStatus")
        }
        if !Address.houseNumber.isRemoved {
            Address.houseNumber = ESPMContainerMetadata.ComplexTypes.address.property(withName: "HouseNumber")
        }
        if !Address.street.isRemoved {
            Address.street = ESPMContainerMetadata.ComplexTypes.address.property(withName: "Street")
        }
        if !Address.city.isRemoved {
            Address.city = ESPMContainerMetadata.ComplexTypes.address.property(withName: "City")
        }
        if !Address.country.isRemoved {
            Address.country = ESPMContainerMetadata.ComplexTypes.address.property(withName: "Country")
        }
        if !Address.postalCode.isRemoved {
            Address.postalCode = ESPMContainerMetadata.ComplexTypes.address.property(withName: "PostalCode")
        }
        if !Customer.city.isRemoved {
            Customer.city = ESPMContainerMetadata.EntityTypes.customer.property(withName: "City")
        }
        if !Customer.country.isRemoved {
            Customer.country = ESPMContainerMetadata.EntityTypes.customer.property(withName: "Country")
        }
        if !Customer.customerID.isRemoved {
            Customer.customerID = ESPMContainerMetadata.EntityTypes.customer.property(withName: "CustomerId")
        }
        if !Customer.dateOfBirth.isRemoved {
            Customer.dateOfBirth = ESPMContainerMetadata.EntityTypes.customer.property(withName: "DateOfBirth")
        }
        if !Customer.emailAddress.isRemoved {
            Customer.emailAddress = ESPMContainerMetadata.EntityTypes.customer.property(withName: "EmailAddress")
        }
        if !Customer.firstName.isRemoved {
            Customer.firstName = ESPMContainerMetadata.EntityTypes.customer.property(withName: "FirstName")
        }
        if !Customer.houseNumber.isRemoved {
            Customer.houseNumber = ESPMContainerMetadata.EntityTypes.customer.property(withName: "HouseNumber")
        }
        if !Customer.lastName.isRemoved {
            Customer.lastName = ESPMContainerMetadata.EntityTypes.customer.property(withName: "LastName")
        }
        if !Customer.phoneNumber.isRemoved {
            Customer.phoneNumber = ESPMContainerMetadata.EntityTypes.customer.property(withName: "PhoneNumber")
        }
        if !Customer.postalCode.isRemoved {
            Customer.postalCode = ESPMContainerMetadata.EntityTypes.customer.property(withName: "PostalCode")
        }
        if !Customer.street.isRemoved {
            Customer.street = ESPMContainerMetadata.EntityTypes.customer.property(withName: "Street")
        }
        if !Customer.address.isRemoved {
            Customer.address = ESPMContainerMetadata.EntityTypes.customer.property(withName: "Address")
        }
        if !Customer.updatedTimestamp.isRemoved {
            Customer.updatedTimestamp = ESPMContainerMetadata.EntityTypes.customer.property(withName: "UpdatedTimestamp")
        }
        if !Customer.salesOrders.isRemoved {
            Customer.salesOrders = ESPMContainerMetadata.EntityTypes.customer.property(withName: "SalesOrders")
        }
        if !Product.category.isRemoved {
            Product.category = ESPMContainerMetadata.EntityTypes.product.property(withName: "Category")
        }
        if !Product.categoryName.isRemoved {
            Product.categoryName = ESPMContainerMetadata.EntityTypes.product.property(withName: "CategoryName")
        }
        if !Product.currencyCode.isRemoved {
            Product.currencyCode = ESPMContainerMetadata.EntityTypes.product.property(withName: "CurrencyCode")
        }
        if !Product.dimensionDepth.isRemoved {
            Product.dimensionDepth = ESPMContainerMetadata.EntityTypes.product.property(withName: "DimensionDepth")
        }
        if !Product.dimensionHeight.isRemoved {
            Product.dimensionHeight = ESPMContainerMetadata.EntityTypes.product.property(withName: "DimensionHeight")
        }
        if !Product.dimensionUnit.isRemoved {
            Product.dimensionUnit = ESPMContainerMetadata.EntityTypes.product.property(withName: "DimensionUnit")
        }
        if !Product.dimensionWidth.isRemoved {
            Product.dimensionWidth = ESPMContainerMetadata.EntityTypes.product.property(withName: "DimensionWidth")
        }
        if !Product.longDescription.isRemoved {
            Product.longDescription = ESPMContainerMetadata.EntityTypes.product.property(withName: "LongDescription")
        }
        if !Product.name.isRemoved {
            Product.name = ESPMContainerMetadata.EntityTypes.product.property(withName: "Name")
        }
        if !Product.pictureUrl.isRemoved {
            Product.pictureUrl = ESPMContainerMetadata.EntityTypes.product.property(withName: "PictureUrl")
        }
        if !Product.price.isRemoved {
            Product.price = ESPMContainerMetadata.EntityTypes.product.property(withName: "Price")
        }
        if !Product.productID.isRemoved {
            Product.productID = ESPMContainerMetadata.EntityTypes.product.property(withName: "ProductId")
        }
        if !Product.quantityUnit.isRemoved {
            Product.quantityUnit = ESPMContainerMetadata.EntityTypes.product.property(withName: "QuantityUnit")
        }
        if !Product.shortDescription.isRemoved {
            Product.shortDescription = ESPMContainerMetadata.EntityTypes.product.property(withName: "ShortDescription")
        }
        if !Product.supplierID.isRemoved {
            Product.supplierID = ESPMContainerMetadata.EntityTypes.product.property(withName: "SupplierId")
        }
        if !Product.updatedTimestamp.isRemoved {
            Product.updatedTimestamp = ESPMContainerMetadata.EntityTypes.product.property(withName: "UpdatedTimestamp")
        }
        if !Product.weight.isRemoved {
            Product.weight = ESPMContainerMetadata.EntityTypes.product.property(withName: "Weight")
        }
        if !Product.weightUnit.isRemoved {
            Product.weightUnit = ESPMContainerMetadata.EntityTypes.product.property(withName: "WeightUnit")
        }
        if !Product.stockDetails.isRemoved {
            Product.stockDetails = ESPMContainerMetadata.EntityTypes.product.property(withName: "StockDetails")
        }
        if !Product.supplierDetails.isRemoved {
            Product.supplierDetails = ESPMContainerMetadata.EntityTypes.product.property(withName: "SupplierDetails")
        }
        if !ProductCategory.category.isRemoved {
            ProductCategory.category = ESPMContainerMetadata.EntityTypes.productCategory.property(withName: "Category")
        }
        if !ProductCategory.categoryName.isRemoved {
            ProductCategory.categoryName = ESPMContainerMetadata.EntityTypes.productCategory.property(withName: "CategoryName")
        }
        if !ProductCategory.mainCategory.isRemoved {
            ProductCategory.mainCategory = ESPMContainerMetadata.EntityTypes.productCategory.property(withName: "MainCategory")
        }
        if !ProductCategory.mainCategoryName.isRemoved {
            ProductCategory.mainCategoryName = ESPMContainerMetadata.EntityTypes.productCategory.property(withName: "MainCategoryName")
        }
        if !ProductCategory.numberOfProducts.isRemoved {
            ProductCategory.numberOfProducts = ESPMContainerMetadata.EntityTypes.productCategory.property(withName: "NumberOfProducts")
        }
        if !ProductCategory.updatedTimestamp.isRemoved {
            ProductCategory.updatedTimestamp = ESPMContainerMetadata.EntityTypes.productCategory.property(withName: "UpdatedTimestamp")
        }
        if !ProductText.id.isRemoved {
            ProductText.id = ESPMContainerMetadata.EntityTypes.productText.property(withName: "Id")
        }
        if !ProductText.language.isRemoved {
            ProductText.language = ESPMContainerMetadata.EntityTypes.productText.property(withName: "Language")
        }
        if !ProductText.longDescription.isRemoved {
            ProductText.longDescription = ESPMContainerMetadata.EntityTypes.productText.property(withName: "LongDescription")
        }
        if !ProductText.name.isRemoved {
            ProductText.name = ESPMContainerMetadata.EntityTypes.productText.property(withName: "Name")
        }
        if !ProductText.productID.isRemoved {
            ProductText.productID = ESPMContainerMetadata.EntityTypes.productText.property(withName: "ProductId")
        }
        if !ProductText.shortDescription.isRemoved {
            ProductText.shortDescription = ESPMContainerMetadata.EntityTypes.productText.property(withName: "ShortDescription")
        }
        if !PurchaseOrderHeader.currencyCode.isRemoved {
            PurchaseOrderHeader.currencyCode = ESPMContainerMetadata.EntityTypes.purchaseOrderHeader.property(withName: "CurrencyCode")
        }
        if !PurchaseOrderHeader.grossAmount.isRemoved {
            PurchaseOrderHeader.grossAmount = ESPMContainerMetadata.EntityTypes.purchaseOrderHeader.property(withName: "GrossAmount")
        }
        if !PurchaseOrderHeader.netAmount.isRemoved {
            PurchaseOrderHeader.netAmount = ESPMContainerMetadata.EntityTypes.purchaseOrderHeader.property(withName: "NetAmount")
        }
        if !PurchaseOrderHeader.purchaseOrderID.isRemoved {
            PurchaseOrderHeader.purchaseOrderID = ESPMContainerMetadata.EntityTypes.purchaseOrderHeader.property(withName: "PurchaseOrderId")
        }
        if !PurchaseOrderHeader.supplierID.isRemoved {
            PurchaseOrderHeader.supplierID = ESPMContainerMetadata.EntityTypes.purchaseOrderHeader.property(withName: "SupplierId")
        }
        if !PurchaseOrderHeader.taxAmount.isRemoved {
            PurchaseOrderHeader.taxAmount = ESPMContainerMetadata.EntityTypes.purchaseOrderHeader.property(withName: "TaxAmount")
        }
        if !PurchaseOrderHeader.items.isRemoved {
            PurchaseOrderHeader.items = ESPMContainerMetadata.EntityTypes.purchaseOrderHeader.property(withName: "Items")
        }
        if !PurchaseOrderHeader.supplierDetails.isRemoved {
            PurchaseOrderHeader.supplierDetails = ESPMContainerMetadata.EntityTypes.purchaseOrderHeader.property(withName: "SupplierDetails")
        }
        if !PurchaseOrderItem.currencyCode.isRemoved {
            PurchaseOrderItem.currencyCode = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "CurrencyCode")
        }
        if !PurchaseOrderItem.grossAmount.isRemoved {
            PurchaseOrderItem.grossAmount = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "GrossAmount")
        }
        if !PurchaseOrderItem.itemNumber.isRemoved {
            PurchaseOrderItem.itemNumber = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "ItemNumber")
        }
        if !PurchaseOrderItem.netAmount.isRemoved {
            PurchaseOrderItem.netAmount = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "NetAmount")
        }
        if !PurchaseOrderItem.productID.isRemoved {
            PurchaseOrderItem.productID = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "ProductId")
        }
        if !PurchaseOrderItem.purchaseOrderID.isRemoved {
            PurchaseOrderItem.purchaseOrderID = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "PurchaseOrderId")
        }
        if !PurchaseOrderItem.quantity.isRemoved {
            PurchaseOrderItem.quantity = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "Quantity")
        }
        if !PurchaseOrderItem.quantityUnit.isRemoved {
            PurchaseOrderItem.quantityUnit = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "QuantityUnit")
        }
        if !PurchaseOrderItem.taxAmount.isRemoved {
            PurchaseOrderItem.taxAmount = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "TaxAmount")
        }
        if !PurchaseOrderItem.header.isRemoved {
            PurchaseOrderItem.header = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "Header")
        }
        if !PurchaseOrderItem.productDetails.isRemoved {
            PurchaseOrderItem.productDetails = ESPMContainerMetadata.EntityTypes.purchaseOrderItem.property(withName: "ProductDetails")
        }
        if !SalesOrderHeader.createdAt.isRemoved {
            SalesOrderHeader.createdAt = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "CreatedAt")
        }
        if !SalesOrderHeader.currencyCode.isRemoved {
            SalesOrderHeader.currencyCode = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "CurrencyCode")
        }
        if !SalesOrderHeader.customerID.isRemoved {
            SalesOrderHeader.customerID = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "CustomerId")
        }
        if !SalesOrderHeader.grossAmount.isRemoved {
            SalesOrderHeader.grossAmount = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "GrossAmount")
        }
        if !SalesOrderHeader.lifeCycleStatus.isRemoved {
            SalesOrderHeader.lifeCycleStatus = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "LifeCycleStatus")
        }
        if !SalesOrderHeader.lifeCycleStatusName.isRemoved {
            SalesOrderHeader.lifeCycleStatusName = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "LifeCycleStatusName")
        }
        if !SalesOrderHeader.netAmount.isRemoved {
            SalesOrderHeader.netAmount = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "NetAmount")
        }
        if !SalesOrderHeader.salesOrderID.isRemoved {
            SalesOrderHeader.salesOrderID = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "SalesOrderId")
        }
        if !SalesOrderHeader.taxAmount.isRemoved {
            SalesOrderHeader.taxAmount = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "TaxAmount")
        }
        if !SalesOrderHeader.items.isRemoved {
            SalesOrderHeader.items = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "Items")
        }
        if !SalesOrderHeader.customerDetails.isRemoved {
            SalesOrderHeader.customerDetails = ESPMContainerMetadata.EntityTypes.salesOrderHeader.property(withName: "CustomerDetails")
        }
        if !SalesOrderItem.currencyCode.isRemoved {
            SalesOrderItem.currencyCode = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "CurrencyCode")
        }
        if !SalesOrderItem.deliveryDate.isRemoved {
            SalesOrderItem.deliveryDate = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "DeliveryDate")
        }
        if !SalesOrderItem.grossAmount.isRemoved {
            SalesOrderItem.grossAmount = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "GrossAmount")
        }
        if !SalesOrderItem.itemNumber.isRemoved {
            SalesOrderItem.itemNumber = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "ItemNumber")
        }
        if !SalesOrderItem.netAmount.isRemoved {
            SalesOrderItem.netAmount = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "NetAmount")
        }
        if !SalesOrderItem.productID.isRemoved {
            SalesOrderItem.productID = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "ProductId")
        }
        if !SalesOrderItem.quantity.isRemoved {
            SalesOrderItem.quantity = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "Quantity")
        }
        if !SalesOrderItem.quantityUnit.isRemoved {
            SalesOrderItem.quantityUnit = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "QuantityUnit")
        }
        if !SalesOrderItem.salesOrderID.isRemoved {
            SalesOrderItem.salesOrderID = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "SalesOrderId")
        }
        if !SalesOrderItem.taxAmount.isRemoved {
            SalesOrderItem.taxAmount = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "TaxAmount")
        }
        if !SalesOrderItem.header.isRemoved {
            SalesOrderItem.header = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "Header")
        }
        if !SalesOrderItem.productDetails.isRemoved {
            SalesOrderItem.productDetails = ESPMContainerMetadata.EntityTypes.salesOrderItem.property(withName: "ProductDetails")
        }
        if !Stock.lotSize.isRemoved {
            Stock.lotSize = ESPMContainerMetadata.EntityTypes.stock.property(withName: "LotSize")
        }
        if !Stock.minStock.isRemoved {
            Stock.minStock = ESPMContainerMetadata.EntityTypes.stock.property(withName: "MinStock")
        }
        if !Stock.productID.isRemoved {
            Stock.productID = ESPMContainerMetadata.EntityTypes.stock.property(withName: "ProductId")
        }
        if !Stock.quantity.isRemoved {
            Stock.quantity = ESPMContainerMetadata.EntityTypes.stock.property(withName: "Quantity")
        }
        if !Stock.quantityLessMin.isRemoved {
            Stock.quantityLessMin = ESPMContainerMetadata.EntityTypes.stock.property(withName: "QuantityLessMin")
        }
        if !Stock.updatedTimestamp.isRemoved {
            Stock.updatedTimestamp = ESPMContainerMetadata.EntityTypes.stock.property(withName: "UpdatedTimestamp")
        }
        if !Stock.productDetails.isRemoved {
            Stock.productDetails = ESPMContainerMetadata.EntityTypes.stock.property(withName: "ProductDetails")
        }
        if !Supplier.city.isRemoved {
            Supplier.city = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "City")
        }
        if !Supplier.country.isRemoved {
            Supplier.country = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "Country")
        }
        if !Supplier.emailAddress.isRemoved {
            Supplier.emailAddress = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "EmailAddress")
        }
        if !Supplier.houseNumber.isRemoved {
            Supplier.houseNumber = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "HouseNumber")
        }
        if !Supplier.phoneNumber.isRemoved {
            Supplier.phoneNumber = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "PhoneNumber")
        }
        if !Supplier.postalCode.isRemoved {
            Supplier.postalCode = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "PostalCode")
        }
        if !Supplier.street.isRemoved {
            Supplier.street = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "Street")
        }
        if !Supplier.supplierID.isRemoved {
            Supplier.supplierID = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "SupplierId")
        }
        if !Supplier.supplierName.isRemoved {
            Supplier.supplierName = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "SupplierName")
        }
        if !Supplier.address.isRemoved {
            Supplier.address = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "Address")
        }
        if !Supplier.updatedTimestamp.isRemoved {
            Supplier.updatedTimestamp = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "UpdatedTimestamp")
        }
        if !Supplier.products.isRemoved {
            Supplier.products = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "Products")
        }
        if !Supplier.purchaseOrders.isRemoved {
            Supplier.purchaseOrders = ESPMContainerMetadata.EntityTypes.supplier.property(withName: "PurchaseOrders")
        }
    }
}
