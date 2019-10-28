//
//  CheckoutViewController.swift
//  FoodApp
//
//  Created by Sergey Yuryev on 02/10/2019.
//  Copyright © 2019 Alan. All rights reserved.
//

import UIKit

class CheckoutViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    

    // MARK: - Outlets
    
    /// Checkout table
    @IBOutlet weak var tableView: UITableView!
    
    
    // MARK: - Vars
    
    
    // MARK: - View lifecycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }

    
    // MARK: - UITableView
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return CheckoutManager.shared.getItems().count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "checkoutCell", for: indexPath)
        
        let item = CheckoutManager.shared.getItems()[indexPath.row]
        let imageName = item.imageName
        let name = item.name
        let itemsCount = CheckoutManager.shared.itemCount(item)
        
        if let imageView = cell.viewWithTag(1) as? UIImageView {
            imageView.image = UIImage(named: imageName)
            imageView.contentMode = .scaleAspectFill
            imageView.clipsToBounds = true
        }
        if let textLabel = cell.viewWithTag(2) as? UILabel {
            textLabel.text = name
        }
        if let textLabel = cell.viewWithTag(3) as? UILabel {
            textLabel.text = "\(itemsCount)"
        }
        
        return cell
    }

}
