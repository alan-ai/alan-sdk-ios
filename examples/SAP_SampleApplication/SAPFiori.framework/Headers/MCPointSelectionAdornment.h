//
//  MCPointSelectionAdornment.h
//  ChartKit
//
//  Created by Daniel Cascais on 7/30/12.
//
//

#import "MCSelectionAdornment.h"


@interface MCPointSelectionAdornment : MCSelectionAdornment

@property (nonatomic) CGFloat lineWidth;

/**
 Returns a CAShapeLayer with a circular path.
 */
- (CALayer *)makeLayer;

/**
 The position of the adornment is set to the position of the value.
 */
- (void)updatePosition:(CALayer *)adornmentLayer;
- (void)setAdornmentPosition:(CALayer *)adornmentLayer;

/**
 Updates the fillColor property of the CAShapeLayer.
 */
- (void)updateColor:(CALayer *)adornmentLayer;
@end
