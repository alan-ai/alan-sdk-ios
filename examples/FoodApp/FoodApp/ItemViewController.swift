//
//  ItemViewController.swift
//  FoodApp
//
//  Created by Sergey Yuryev on 01/10/2019.
//  Copyright © 2019 Alan. All rights reserved.
//

import UIKit

class ItemViewController: UICollectionViewController, UICollectionViewDelegateFlowLayout {
    
    // MARK: - Vars
    
    /// Current items to display
    var items: [Item] = []
    
    /// Index that should be highlighted
    var highlightedIndex: IndexPath?
    
    // MARK: - View lifecycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        NotificationCenter.default.addObserver(self, selector: #selector(checkoutItemUpdate(_:)), name: .checkoutItems, object: nil)
    }
    
    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        collectionView.contentInset = UIEdgeInsets(top: 20, left: 0, bottom: 80, right: 0)
    }
    
    
    // MARK: - UICollectionView
    
    override func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return self.items.count
    }
    
    override func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "itemCell", for: indexPath)
        
        cell.contentView.layer.cornerRadius = 15
        cell.contentView.layer.masksToBounds = true
        
        if let h = self.highlightedIndex, h == indexPath {
            cell.contentView.layer.borderWidth = 6
            cell.contentView.layer.borderColor = UIColor.green.cgColor
        }
        else {
            cell.contentView.layer.borderWidth = 0
            cell.contentView.layer.borderColor = UIColor.clear.cgColor
        }
        
        let item = self.items[indexPath.row]
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
        if let button = cell.viewWithTag(3) as? UIButton {
            button.layer.cornerRadius = 15
            button.layer.masksToBounds = true
            button.addTarget(self, action: #selector(self.addItem(_:)), for: .touchUpInside)
        }
        if let button = cell.viewWithTag(4) as? UIButton {
            button.isHidden = itemsCount > 0 ? false : true
            button.layer.cornerRadius = 15
            button.layer.masksToBounds = true
            button.addTarget(self, action: #selector(self.removeItem(_:)), for: .touchUpInside)
        }
        if let label = cell.viewWithTag(5) as? UILabel {
            label.isHidden = itemsCount > 0 ? false : true
            label.text = "\(itemsCount)"
        }
        
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
        let size = CGSize(width: self.collectionView.bounds.width - 40 , height: 240)
        return size
    }
    
    
    // MARK: - Actions
    
    func highlight(name: String) {
        self.highlightedIndex = self.getIndexPath(name)
        DispatchQueue.main.async {
            self.collectionView.reloadData()
            DispatchQueue.main.async {
                if let indexPath = self.highlightedIndex {
                    self.collectionView.scrollToItem(at: indexPath, at: .top, animated: true)
                }
            }
        }
    }
    
    @objc func checkoutItemUpdate(_ notification: Notification) {
        DispatchQueue.main.async {
            self.collectionView.reloadData()
        }
    }
    
    @objc func addItem(_ sender: Any) {
        guard let button = sender as? UIButton else {
            return
        }
        let point = button.convert(CGPoint.zero, to: self.collectionView)
        if let indexPath = self.collectionView.indexPathForItem(at: point) {
            CheckoutManager.shared.addItem(self.items[indexPath.row])
        }
    }
    
    @objc func removeItem(_ sender: Any) {
         guard let button = sender as? UIButton else {
             return
         }
         let point = button.convert(CGPoint.zero, to: self.collectionView)
         if let indexPath = self.collectionView.indexPathForItem(at: point) {
             CheckoutManager.shared.removeItem(self.items[indexPath.row])
         }
    }
    
    
    // MARK: - Helpers
    
    fileprivate func getIndexPath(_ name: String) -> IndexPath? {
        let index = self.items.firstIndex(where: { (item) -> Bool in
            item.name.lowercased() == name.lowercased()
        })
        if let row = index {
            return IndexPath(row: row, section: 0)
        }
        return nil
    }
}
