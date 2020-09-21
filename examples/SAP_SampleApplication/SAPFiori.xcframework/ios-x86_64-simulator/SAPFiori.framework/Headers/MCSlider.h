//
//  MCSlider.h
//  Testbed-iOS
//
//  Created by Brett Callaghan on 10/20/11.
//  Copyright (c) 2011 SAP SE. All rights reserved.
//

#import <UIKit/UIKit.h>


/*!
 @details   There are two primary reasons why we might have to implement our own slider class.
            1) Joel was frustrated with flickering issues when changing the thumb image as the selected series changes. In the CataList card charts the color of the thumb matches the series color. If Apple hasn't fixed this bug yet, we'll have to address it in this class for the CataList.
            2) It is easier to reliably determine the center point of the thumb (it's position) with our own slider.
 */
@interface MCSlider : UISlider

/*!
 @brief     Size of the thumb image.
 @details   This method returns the size of the currentThumbImage. If currentThumbImage is nil the size of Apple's default thumb is returned... this is pretty much the only reason this method exists.
 */
@property (nonatomic, readonly) CGSize thumbSize;

/*!
 @brief     Position of the thumb.
 @details   Use in charting to position a needle overlay directly over the center of the thumb.
 */
@property (nonatomic) CGPoint thumbPosition;

@end
