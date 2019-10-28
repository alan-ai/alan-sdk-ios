//
//  MCLaserSelectionAdornment.h
//  ChartKit
//
//  Created by Daniel Cascais on 8/2/12.
//
//

#import "MCSelectionAdornment.h"

extern MCFloat _laserThickness;

@interface MCLaserSelectionAdornment : MCSelectionAdornment

/**
 The position of the adornment is set to the position of the value.
 */
- (void)updatePosition:(CALayer *)adornmentLayer;

/**
 The size of the adornment is set to the required size.
 */
- (void)updateSize:(CALayer *)adornmentLayer;

/**
 Default returns YES if selection.touchIndex == 0.
 */
@property (nonatomic, readonly) BOOL respondsToStartValuePositionChange;

/**
 Default returns YES if selection.touchIndex == 1.
 */
@property (nonatomic, readonly) BOOL respondsToEndValuePositionChange;

- (CALayer *)makeLaserLayerWithColorValue:(int)colorValue vertical:(BOOL)vertical;
- (void)changeLaserColor:(CALayer*)laser color:(int)colorValue;
@end
