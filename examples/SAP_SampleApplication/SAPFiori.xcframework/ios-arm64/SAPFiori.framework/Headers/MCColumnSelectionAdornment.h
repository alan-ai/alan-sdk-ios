//
//  MCColumnSelectionAdornment.h
//  ChartKit
//
//  Created by Daniel Cascais on 8/16/12.
//
//

#import "MCSelectionAdornment.h"

@interface MCColumnSelectionAdornment : MCSelectionAdornment

/**
 Returns a CAShapeLayer with a circular path.
 */
- (CALayer *)makeLayer;

/**
 The position of the adornment is set to the position of the value.
 */
//- (void)updatePosition:(CALayer *)adornmentLayer;

/**
 The size of the adornment is set to the required size.
 */
- (void)updateSize:(CALayer *)adornmentLayer;

/**
 Updates the fillColor property of the CAShapeLayer.
 */
- (void)updateColor:(CALayer *)adornmentLayer;

@end
