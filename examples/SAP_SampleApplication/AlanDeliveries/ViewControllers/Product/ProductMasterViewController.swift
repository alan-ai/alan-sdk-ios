//
// AlanDeliveries
//
// Created by SAP Cloud Platform SDK for iOS Assistant application on 24/04/19
//

import Foundation
import SAPCommon
import SAPFiori
import SAPFoundation
import SAPOData

class ProductMasterViewController: FUIFormTableViewController, SAPFioriLoadingIndicator, ProductViewDelegate {
    var espmContainer: ESPMContainer<OnlineODataProvider>!
    public var loadEntitiesBlock: ((_ completionHandler: @escaping ([Product]?, Error?) -> Void) -> Void)?
    private var entities: [Product] = [Product]()
    private var allEntities: [Product] = [Product]()
    private var entityImages = [Int: UIImage]()
    private let logger = Logger.shared(named: "ProductMasterViewControllerLogger")
    private let okTitle = NSLocalizedString("keyOkButtonTitle",
                                            value: "OK",
                                            comment: "XBUT: Title of OK button.")
    var loadingIndicator: FUILoadingIndicatorView?

    var highlightedId: String?
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        if let window = UIApplication.shared.keyWindow {
            window.productViewDelegate = nil
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        if let window = UIApplication.shared.keyWindow {
            window.setVisual(["screen": "Product"])
            window.productViewDelegate = self
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.edgesForExtendedLayout = []
        // Add refreshcontrol UI
        self.refreshControl?.addTarget(self, action: #selector(self.refresh), for: UIControl.Event.valueChanged)
        self.tableView.addSubview(self.refreshControl!)
        // Cell height settings
        self.tableView.rowHeight = UITableView.automaticDimension
        self.tableView.estimatedRowHeight = 98
        self.updateTable()
    }

    var preventNavigationLoop = false
    var entitySetName: String?

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        self.clearsSelectionOnViewWillAppear = self.splitViewController!.isCollapsed
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    // MARK: - Table view data source

    override func tableView(_: UITableView, numberOfRowsInSection _: Int) -> Int {
        return self.entities.count
    }

    override func tableView(_: UITableView, canEditRowAt _: IndexPath) -> Bool {
        return true
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let product = self.entities[indexPath.row]
        let cell = CellCreationHelper.objectCellWithNonEditableContent(tableView: tableView, indexPath: indexPath, key: "ProductId", value: "\(product.productID!)")
        cell.preserveDetailImageSpacing = true
        cell.headlineText = product.name
        cell.footnoteText = product.productID
        let backgroundView = UIView()
        backgroundView.backgroundColor = UIColor.white
        
        if let image = image(for: indexPath, product: product) {
            cell.detailImage = image
            cell.detailImageView.contentMode = .scaleAspectFit
        }
        if let hid = self.highlightedId, let current = product.productID, hid == current {
            backgroundView.backgroundColor = UIColor(red: 235 / 255, green: 245 / 255, blue: 255 / 255, alpha: 1.0)
        }
        cell.backgroundView = backgroundView
        return cell
    }

    override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCell.EditingStyle, forRowAt indexPath: IndexPath) {
        if editingStyle != .delete {
            return
        }
        let currentEntity = self.entities[indexPath.row]
        self.espmContainer.deleteEntity(currentEntity) { error in
            if let error = error {
                self.logger.error("Delete entry failed.", error: error)
                AlertHelper.displayAlert(with: NSLocalizedString("keyErrorDeletingEntryTitle", value: "Delete entry failed", comment: "XTIT: Title of deleting entry error pop up."), error: error, viewController: self)
            } else {
                self.entities.remove(at: indexPath.row)
                tableView.deleteRows(at: [indexPath], with: .fade)
            }
        }
    }

    // MARK: - Data accessing
    
    func highlightProductId(_ id: String?) {
        self.highlightedId = id
        DispatchQueue.main.async {
            self.tableView.reloadData()
            self.logger.info("Alan: Table updated successfully!")
        }
    }

    internal func showProductCategory(_ category: String) {
        if category == "All" {
            self.entityImages.removeAll()
            self.entities.removeAll()
            self.entities.append(contentsOf: self.allEntities)
        }
        else {
            let filtered = self.allEntities.filter {
                if let c = $0.category, c == category {
                    return true
                }
                return false
            }
            self.entityImages.removeAll()
            self.entities.removeAll()
            self.entities.append(contentsOf: filtered)
        }
        DispatchQueue.main.async {
            let range = NSMakeRange(0, self.tableView.numberOfSections)
            let sections = NSIndexSet(indexesIn: range)
            self.tableView.reloadSections(sections as IndexSet, with: .automatic)
            self.logger.info("Alan: Table updated successfully!")
        }
        
    }
    
    internal func showProductCard(_ id: String) {
        var index = 0
        for entry in self.allEntities {
            if let entryId = entry.productID {
                if entryId == id {
                    let indexPath = IndexPath(row: index, section: 0)
                    self.tableView.selectRow(at: indexPath, animated: true, scrollPosition: .none)
                    self.performSegue(withIdentifier: "showDetail", sender: self)
                }
                index += 1
            }
        }
    }
    
    internal func showProductIds(_ ids: [String]) {
        let filtered = self.allEntities.filter {
            if let productId = $0.productID, ids.contains(productId) {
                return true
            }
            return false
        }
        self.entityImages.removeAll()
        self.entities.removeAll()
        self.entities.append(contentsOf: filtered)
        DispatchQueue.main.async {
            let range = NSMakeRange(0, self.tableView.numberOfSections)
            let sections = NSIndexSet(indexesIn: range)
            self.tableView.reloadSections(sections as IndexSet, with: .automatic)
            self.logger.info("Alan: Table updated successfully!")
        }
    }
    
    
    func requestEntities(completionHandler: @escaping (Error?) -> Void) {
        self.loadEntitiesBlock!() { entities, error in
            if let error = error {
                completionHandler(error)
                return
            }
            
            self.entities = entities!
            self.allEntities.append(contentsOf: entities!)
            
            let encoder = JSONEncoder()
            if let encodedEntityValue = try? encoder.encode(self.entities) {
                if let json = String(data: encodedEntityValue, encoding: .utf8) {
                    print(json)
                    if let window = UIApplication.shared.keyWindow {
                        window.call(method: "script::updateProductEntities", params: ["json": json] , callback: { (error, result) in
                        })
                    }
                }
            }
            
            completionHandler(nil)
        }
    }

    // MARK: - Segues

    override func prepare(for segue: UIStoryboardSegue, sender _: Any?) {
        if segue.identifier == "showDetail" {
            // Show the selected Entity on the Detail view
            guard let indexPath = self.tableView.indexPathForSelectedRow else {
                return
            }
            self.logger.info("Showing details of the chosen element.")
            let selectedEntity = self.entities[indexPath.row]
            let detailViewController = segue.destination as! ProductDetailViewController
            detailViewController.entity = selectedEntity
            detailViewController.navigationItem.leftItemsSupplementBackButton = true
            detailViewController.navigationItem.title = self.entities[(self.tableView.indexPathForSelectedRow?.row)!].productID ?? ""
            detailViewController.allowsEditableCells = false
            detailViewController.tableUpdater = self
            detailViewController.preventNavigationLoop = self.preventNavigationLoop
            detailViewController.espmContainer = self.espmContainer
            detailViewController.entitySetName = self.entitySetName
        } else if segue.identifier == "addEntity" {
            // Show the Detail view with a new Entity, which can be filled to create on the server
            self.logger.info("Showing view to add new entity.")
            let dest = segue.destination as! UINavigationController
            let detailViewController = dest.viewControllers[0] as! ProductDetailViewController
            detailViewController.title = NSLocalizedString("keyAddEntityTitle", value: "Add Entity", comment: "XTIT: Title of add new entity screen.")
            let doneButton = UIBarButtonItem(barButtonSystemItem: .done, target: detailViewController, action: #selector(detailViewController.createEntity))
            detailViewController.navigationItem.rightBarButtonItem = doneButton
            let cancelButton = UIBarButtonItem(title: NSLocalizedString("keyCancelButtonToGoPreviousScreen", value: "Cancel", comment: "XBUT: Title of Cancel button."), style: .plain, target: detailViewController, action: #selector(detailViewController.cancel))
            detailViewController.navigationItem.leftBarButtonItem = cancelButton
            detailViewController.allowsEditableCells = true
            detailViewController.tableUpdater = self
            detailViewController.espmContainer = self.espmContainer
            detailViewController.entitySetName = self.entitySetName
        }
    }

    // MARK: - Image loading

    private func image(for indexPath: IndexPath, product: Product) -> UIImage? {
        if let image = self.entityImages[indexPath.row] {
            return image
        } else {
            espmContainer.downloadMedia(entity: product, completionHandler: { data, error in
                if let error = error {
                    self.logger.error("Download media failed. Error: \(error)", error: error)
                    return
                }
                guard let data = data else {
                    self.logger.info("Media data is empty.")
                    return
                }
                if let image = UIImage(data: data) {
                    // store the downloaded image
                    self.entityImages[indexPath.row] = image
                    // update the cell
                    DispatchQueue.main.async {
                        self.tableView.beginUpdates()
                        if let cell = self.tableView.cellForRow(at: indexPath) as? FUIObjectTableViewCell {
                            cell.detailImage = image
                            cell.detailImageView.contentMode = .scaleAspectFit
                        }
                        self.tableView.endUpdates()
                    }
                }
            })
            return nil
        }
    }

    // MARK: - Table update

    func updateTable() {
        self.showFioriLoadingIndicator()
        DispatchQueue.global().async {
            self.loadData {
                self.hideFioriLoadingIndicator()
            }
        }
    }

    private func loadData(completionHandler: @escaping () -> Void) {
        self.requestEntities { error in
            defer {
                completionHandler()
            }
            if let error = error {
                AlertHelper.displayAlert(with: NSLocalizedString("keyErrorLoadingData", value: "Loading data failed!", comment: "XTIT: Title of loading data error pop up."), error: error, viewController: self)
                self.logger.error("Could not update table. Error: \(error)", error: error)
                return
            }
            DispatchQueue.main.async {
                self.tableView.reloadData()
                self.logger.info("Table updated successfully!")
            }
        }
    }

    @objc func refresh() {
        DispatchQueue.global().async {
            self.loadData {
                DispatchQueue.main.async {
                    self.refreshControl?.endRefreshing()
                }
            }
        }
    }
}

extension ProductMasterViewController: EntitySetUpdaterDelegate {
    func entitySetHasChanged() {
        self.updateTable()
    }
}
