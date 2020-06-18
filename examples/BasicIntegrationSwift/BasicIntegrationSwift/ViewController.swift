//
//  ViewController.swift
//  BasicIntegrationSwift
//
//  Created by Sergey Yuryev on 18.06.2020.
//  Copyright © 2020 Alan AI. All rights reserved.
//

import UIKit
import AlanSDK

class ViewController: UIViewController {
    
    /// Alan button
    fileprivate var button: AlanButton!
    
    /// Alan text panel
    fileprivate var text: AlanText!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Setup Alan Button and Text panel
        self.setupAlan()
    }

    fileprivate func setupAlan() {
        // Define project key
        let config = AlanConfig(key: "314203787ccd9370974f1bf6b6929c1b2e956eca572e1d8b807a3e2338fdd0dc/prod")
        
        //  Init Alan button
        self.button = AlanButton(config: config)
        
        // Init Alan text panel
        self.text = AlanText(frame: CGRect.zero)
        
        // Add button and text to the view
        self.view.addSubview(self.button)
        self.button.translatesAutoresizingMaskIntoConstraints = false
        self.view.addSubview(self.text)
        self.text.translatesAutoresizingMaskIntoConstraints = false
        
        // Aling button and text on the view
        let views = ["button" : self.button!, "text" : self.text!]
        let verticalButton = NSLayoutConstraint.constraints(withVisualFormat: "V:|-(>=0@299)-[button(64)]-40-|", options: NSLayoutConstraint.FormatOptions(), metrics: nil, views: views)
        let verticalText = NSLayoutConstraint.constraints(withVisualFormat: "V:|-(>=0@299)-[text(64)]-40-|", options: NSLayoutConstraint.FormatOptions(), metrics: nil, views: views)
        let horizontalButton = NSLayoutConstraint.constraints(withVisualFormat: "H:|-(>=0@299)-[button(64)]-20-|", options: NSLayoutConstraint.FormatOptions(), metrics: nil, views: views)
        let horizontalText = NSLayoutConstraint.constraints(withVisualFormat: "H:|-20-[text]-20-|", options: NSLayoutConstraint.FormatOptions(), metrics: nil, views: views)
        self.view.addConstraints(verticalButton + verticalText + horizontalButton + horizontalText)
    }
    
}

