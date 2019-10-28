//
//  UIWindow+Alan.swift
//  MyDeliveries
//
//  Created by Sergey Yuryev on 22/04/2019.
//  Copyright © 2019 SAP. All rights reserved.
//

import UIKit
import AlanSDK

public final class ObjectAssociation<T: Any> {
    
    private let policy: objc_AssociationPolicy
    
    public init(policy: objc_AssociationPolicy = .OBJC_ASSOCIATION_RETAIN_NONATOMIC) {
        self.policy = policy
    }
    
    public subscript(index: AnyObject) -> T? {
        get { return objc_getAssociatedObject(index, Unmanaged.passUnretained(self).toOpaque()) as! T? }
        set { objc_setAssociatedObject(index, Unmanaged.passUnretained(self).toOpaque(), newValue, policy) }
    }
    
}

protocol ProductViewDelegate {
    func highlightProductId(_ id: String?)
    func showProductCategory(_ category: String)
    func showProductIds(_ ids: [String])
    func showProductCard(_ id: String)
}

protocol NavigateViewDelegate {
    func navigateCategory(_ category: String)
    func navigateBack()
}

extension UIWindow {
    
    private static let navigateDelegate = ObjectAssociation<NavigateViewDelegate>()
    private static let productDelegate = ObjectAssociation<ProductViewDelegate>()
    private static let associationAlanButton = ObjectAssociation<AlanButton>()
    private static let associationAlanText = ObjectAssociation<AlanText>()
    
    var navigateViewDelegate: NavigateViewDelegate? {
        get {
            return UIWindow.navigateDelegate[self]
        }
        set {
            UIWindow.navigateDelegate[self] = newValue
        }
    }
    
    var productViewDelegate: ProductViewDelegate? {
        get {
            return UIWindow.productDelegate[self]
        }
        set {
            UIWindow.productDelegate[self] = newValue
        }
    }
    
    var alanButton: AlanButton? {
        get {
            return UIWindow.associationAlanButton[self]
        }
        set {
            UIWindow.associationAlanButton[self] = newValue
        }
    }
    
    var alanText: AlanText? {
        get {
            return UIWindow.associationAlanText[self]
        }
        set {
            UIWindow.associationAlanText[self] = newValue
        }
    }
    
    func moveAlanToFront() {
        if let button = self.alanButton {
            self.bringSubviewToFront(button)
        }
        if let text = self.alanText {
            self.bringSubviewToFront(text)
        }
    }
    
    func setVisual(_ data: [String: Any]) {
        print("setVisual: \(data)");
        if let button = self.alanButton {
            button.setVisual(data)
        }
    }
    
    func playText(_ text: String) {
        if let button = self.alanButton {
            button.playText(text)
        }
    }
    
    func playData(_ data: [String: String]) {
        if let button = self.alanButton {
            button.playData(data)
        }
    }
    
    func call(method: String, params: [String: Any], callback:@escaping ((Error?, String?) -> Void)) {
        if let button = self.alanButton {
            button.call(method, withParams: params, callback: callback)
        }
    }
    
    func addAlan() {
        let buttonSpace: CGFloat = 20
        let buttonWidth: CGFloat = 64
        let buttonHeight: CGFloat = 64
        let textWidth: CGFloat = self.frame.maxX - buttonSpace * 2
        let textHeight: CGFloat = 64
        
        let config = AlanConfig(key: "78db842d8d49d133dcb0c8c4bf42500a2e956eca572e1d8b807a3e2338fdd0dc/prod", isButtonDraggable: false)

        self.alanButton = AlanButton(config: config)
        if let button = self.alanButton {
            let safeHeight = self.frame.maxY - self.safeAreaLayoutGuide.layoutFrame.maxY
            let realX = self.frame.maxX - buttonWidth - buttonSpace
            let realY = self.frame.maxY - safeHeight - buttonHeight - buttonSpace
            
            button.frame = CGRect(x: realX, y: realY, width: buttonWidth, height: buttonHeight)
            self.addSubview(button)
            self.bringSubviewToFront(button)
        }
        
        self.alanText = AlanText(frame: CGRect.zero)
        if let text = self.alanText {
            let safeHeight = self.frame.maxY - self.safeAreaLayoutGuide.layoutFrame.maxY
            let realX = self.frame.minX + buttonSpace
            let realY = self.frame.maxY - safeHeight - textHeight - buttonSpace
            
            text.frame = CGRect(x: realX, y: realY, width: textWidth, height: textHeight)
            self.addSubview(text)
            self.bringSubviewToFront(text)
            
            text.layer.shadowColor = UIColor.black.cgColor
            text.layer.shadowOffset = CGSize(width: 0, height: 0)
            text.layer.shadowOpacity = 0.3
            text.layer.shadowRadius = 4.0
            
            for subview in text.subviews {
                if let s = subview as? UILabel {
                    s.backgroundColor = UIColor.white
                }
            }
        }
        
        NotificationCenter.default.addObserver(self, selector: #selector(self.handleEvent(_:)), name:NSNotification.Name(rawValue: "kAlanSDKEventNotification"), object:nil)
    }
    
    @objc func handleEvent(_ notification: Notification) {
        guard let userInfo = notification.userInfo else {
            return
        }
        guard let event = userInfo["onEvent"] as? String else {
            return
        }
        guard event == "command" else {
            return
        }
        guard let jsonString = userInfo["jsonString"] as? String else {
            return
        }
        guard let data = jsonString.data(using: .utf8) else {
            return
        }
        guard let unwrapped = try? JSONSerialization.jsonObject(with: data, options: [])  else {
            return
        }
        guard let d = unwrapped as? [String: Any] else {
            return
        }
        guard let json = d["data"] as? [String: Any] else {
            return
        }
        guard let command = json["command"] as? String else {
            return
        }
        
        if command == "showProductCategory" {
            if let value = json["value"] as? String {
                if let d = self.productViewDelegate {
                    d.showProductCategory(value)
                }
            }
        }
        else if command == "showProductIds" {
            if let value = json["value"] as? [String] {
                if let d = self.productViewDelegate {
                    d.showProductIds(value)
                }
            }
        }
        else if command == "showProductCard" {
            if let p = self.productViewDelegate {
                DispatchQueue.main.async {
                    if let value = json["value"] as? String {
                        p.showProductCard(value)
                    }
                }
            }
            else if let d = self.navigateViewDelegate {
                d.navigateCategory("Product")
                DispatchQueue.main.asyncAfter(deadline: .now() + 2, execute: {
                    if let value = json["value"] as? String {
                        if let p = self.productViewDelegate {
                            p.showProductCard(value)
                        }
                    }
                })
            }
        }
        else if command == "highlightProductId" {
            if let value = json["value"] as? String {
                if let d = self.productViewDelegate {
                    d.highlightProductId(value)
                }
            }
            else {
                if let d = self.productViewDelegate {
                    d.highlightProductId(nil)
                }
            }
        }
        else if command == "navigate" {
            if let value = json["screen"] as? String {
                if let d = self.navigateViewDelegate {
                    d.navigateCategory(value)
                }
            }
        }
        else if command == "goBack" {
            if let d = self.navigateViewDelegate {
                d.navigateBack()
            }
        }
    }
}
