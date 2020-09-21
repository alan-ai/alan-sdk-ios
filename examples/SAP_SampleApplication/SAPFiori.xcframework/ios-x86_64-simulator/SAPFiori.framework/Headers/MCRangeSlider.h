//
//  MCRangeSlider.h
//  ChartKit
//
//  Created by Daniel Cascais on 1/2/13.
//
//

/*
 * Based on Joel's range slider and Jerry's initial gesture handling for range
 * scrolling.
 */

#import <UIKit/UIKit.h>
#import "MCChartLayer.h"
#import "MCContext.h"
#import "MCGeometry.h"

@interface MCRangeSlider : UIControl <UIGestureRecognizerDelegate, MCChartLayerDelegate>
{
	UIView* _trackCenter;
	UIView* _thumbLeft;
	UIView* _thumbRight;
    CGPoint _leftTouchDelta;
    CGPoint _rightTouchDelta;
    CGSize _currentSize;
    CAShapeLayer* _outlineShape;
    CAShapeLayer* _chartShape;
    CAShapeLayer* _chartHighlight;
    CAShapeLayer* _periodShadingShape;
    CAShapeLayer* _periodShadingHighlight;
    CALayer* _highlightChartMask;
    UILongPressGestureRecognizer* _centerTouch;
    // Array of CATextLayer
    NSMutableArray *_categoryAxisTextLayers;
    MCFloat _tickLabelFontSize;

}

typedef NS_ENUM(NSUInteger, MMRangeSliderDragMode)
{
    MMRangeSliderDragModeNone,
    MMRangeSliderDragModeLeft,
    MMRangeSliderDragModeCenter,
    MMRangeSliderDragModeRight
};

@property (nonatomic, assign) BOOL suppressValueChangeNotifications;
@property (nonatomic, assign) BOOL dataDidChange;
@property (nonatomic, assign) MMRangeSliderDragMode dragMode;
@property (nonatomic, assign) CGPoint lastDragLocation;

// style customization
// thumb images are required
@property (nonatomic, retain) UIImage *thumbImageLeft;
@property (nonatomic, retain) UIImage *thumbImageRight;

@property (nonatomic, assign) MCChartLayer *chartLayer;
@property (nonatomic, assign) MCContextRef chartContext;

// behavior
@property (nonatomic, assign) BOOL thumbsAreHardStops;
@property (nonatomic, assign) BOOL categoryAxisLabelsHidden;
@property (nonatomic, assign) BOOL showTopEdgeOutline;

// values
@property (nonatomic, assign) float minimumValue;
@property (nonatomic, assign) float maximumValue;
@property (nonatomic, assign) float leftValue;
@property (nonatomic, assign) float rightValue;
@property (nonatomic, assign) unsigned int chartFillColor;
@property (nonatomic, assign) unsigned int chartLineColor;

@property (nonatomic) MCEdgeInsets edgeInsets;

- (void)setLeftValue:(float)left rightValue:(float)right animated:(BOOL)animated;

@end
