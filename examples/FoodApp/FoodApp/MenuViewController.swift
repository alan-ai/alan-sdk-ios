//
//  MenuViewController.swift
//  FoodApp
//
//  Created by Sergey Yuryev on 01/10/2019.
//  Copyright © 2019 Alan. All rights reserved.
//

import UIKit

class MenuViewController: UICollectionViewController, UICollectionViewDelegateFlowLayout {
    
    // MARK: - Vars
    
    fileprivate var items: [Item] = []

    
    // MARK: - View lifecycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.items = menuItems
    }
    
    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        collectionView.contentInset = UIEdgeInsets(top: 20, left: 0, bottom: 80, right: 0)
    }
    
    
    // MARK: - Navigation
    
    func showCategory(_ name: String) {
        if let indexPath = self.getIndexPath(name) {
            self.performSegue(withIdentifier: "showItems", sender: indexPath)
        }
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if let identifier = segue.identifier, identifier == "showItems" {
            if let vc = segue.destination as? ItemViewController, let indexPath = sender as? IndexPath {
               vc.title = self.items[indexPath.row].name
               vc.items = self.items[indexPath.row].subitems
            }
        }
    }
    
    
    // MARK: - UICollectionView
    
    override func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return self.items.count
    }
    
    override func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "menuCell", for: indexPath)
        
        if let imageView = cell.viewWithTag(1) as? UIImageView {
            imageView.image = UIImage(named: self.items[indexPath.row].imageName)
            imageView.contentMode = .scaleAspectFill
            imageView.clipsToBounds = true
        }
        
        if let textLabel = cell.viewWithTag(2) as? UILabel {
            textLabel.text = self.items[indexPath.row].name
        }
        
        cell.contentView.layer.cornerRadius = 15
        cell.contentView.layer.masksToBounds = true
        
        return cell
    }
    
    override func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        self.performSegue(withIdentifier: "showItems", sender: indexPath)
    }
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
        let size = CGSize(width: self.collectionView.bounds.width - 40 , height: 240)
        return size
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
