//
//  MCChartView.h
//  foo
//
//  Created by Brett Callaghan on 10/19/11.
//  Copyright (c) 2011 SAP SE. All rights reserved.
//


#import <UIKit/UIKit.h>
#import <UIKit/NSText.h>
#import "MCType.h"
#import "MCColorPalettes.h"
#import "MCChartDelegate.h"
#import "MCLayerProtocol.h"


// Selection of data points with a single touch.
// Comparison of data points with two touches.
// Swiping from one data set to another.
// Copy / paste. Definitely look at Joel's implementation.


enum {
    MCChartViewTypeDefault = 0, // MCLayer
    MCChartViewTypeDancing,     // MCDancingLayer
    MCChartViewTypeStatic,      // MCStaticLayer (uses MCDraw but implements all the methods it needs to integrate with MCView.)
    MCChartViewTypePie          // MCPieLayer
};
typedef NSUInteger MCChartViewType;


@class MCLayer;
@class MCSlider;


/*!
 @brief     Base chart view class that supports the interaction between the user and animatable chart layers.
 @details   The views animatable properties may or may not actually be animatable depending on the type/class of the chart layer.
 */
@interface MCChartView : UIView <MCChartDelegate>
{
@private
    UIEdgeInsets _edgeInsets;
    MCSlider *_slider;
    
    MCSeriesPalette *_seriesPalette;
    uint32_t _seriesPaletteCount;
    
    struct
    {
        uint32_t touchEnabled:1;
        uint32_t touchTracking:1;
        uint32_t secondaryTouchTracking:1;
        uint32_t sliderTracking:1;
        uint32_t allowsSeriesSelection:1;
        uint32_t allowSeriesDeselection:1;
        uint32_t delegateDataWillChange:1;
        uint32_t delegateDataDidChange:1;
        uint32_t delegateSelectedValuePositionWillChange:1;
        uint32_t delegateSelectedValuePositionDidChange:1;
        uint32_t delegateSelectedValueIndexWillChange:1;
        uint32_t delegateSelectedValueIndexDidChange:1;
        uint32_t delegateSelectedSeriesIndexWillChange:1;
        uint32_t delegateSelectedSeriesIndexDidChange:1;
    } _flags;
}
/**
 Allows you to conveniently specify which of the ChartKit layer implementations you would like to use for your chart.
 Each has different benefits/restrictions.
 */
+ (MCChartView *)viewWithType:(MCChartViewType)viewType;

@property (nonatomic, readonly, assign) MCSeriesPalette *seriesPalette;
@property (nonatomic, readonly, assign) uint32_t seriesPaletteCount;
/*!
 @brief     Chart layer belonging to the receiver.
 */
//@property (nonatomic, readonly) CALayer <MCLayer> *chartLayer;
@property (weak, nonatomic, readonly) MCLayer *chartLayer;

/*
 * Delegate for the selection methods:
 *
 * selectedSeriesIndexDidChange;
 * selectedValueIndexDidChange;
 * selectedValuePositionDidChange;
 * dataWillChange;
 * dataDidChange;
 */
@property (nonatomic, weak) id<MCChartDelegate> chartDelegate;

/*!
 @details   Default is YES. Setting this property to NO will disable the ability to change the selectedSeriesIndex (by tapping the slider's thumb).
 */
@property (nonatomic) BOOL allowsSeriesSelection;

/*!
 @details   Default is NO. Setting this property to YES will enable the ability to change the selectedSeriesIndex to -1 and deselecting (by tapping the slider's thumb).
 */
@property (nonatomic) BOOL allowSeriesDeselection;

@property (nonatomic) BOOL touchEnabled;

@property (nonatomic) UIEdgeInsets plotFrameEdgeInsets;


-(void)touchDown:(UITouch *)touch;
-(void)touchMoved:(UITouch *)touch;
-(void)touchUp:(UITouch *)touch;

-(void)secondaryTouchDown:(UITouch *)touch;
-(void)secondaryTouchMoved:(UITouch *)touch;
-(void)secondaryTouchUp:(UITouch *)touch;

#pragma mark Touch Input
-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event;
-(void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event;
-(void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event;
-(void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event;

#pragma mark -
#pragma mark Slider
#pragma mark -

/*!
 @brief     Slider used to change the selectedSeriesIndex and selectedValueIndex properties.
 @details   Tapping on the slider's thumb will change the selectedSeriesIndex unless allowsSeriesSelection set to NO. Moving the slider will change the selectedValueIndex. The slider does not have to be in the view's hierarchy.
 */
@property (nonatomic, strong) IBOutlet MCSlider *slider;


// TODO: Should we provide sliderOrigin and sliderWidth?

/*!
 @brief     Suggested slider origin based on the chart's plot frame and the slider's thumb image.
 @details   You should invoke this method after adding your slider to the view hierarchy and assigning it to the receiver.
 */
@property (nonatomic, readonly) CGFloat sliderOrigin;

/*!
 @brief     Suggested slider width based on the chart's plot frame and the slider's thumb image.
 @details   You should invoke this method after adding your slider to the view hierarchy and assigning it to the receiver.
 */
@property (nonatomic, readonly) CGFloat sliderWidth;

/*!
 @details Utility method that snaps the selection highlight or slider thumb to the selected position. Mostly used for setup situations, where
 everything is out of sync, and a quick snap is needed.
 */
- (void)snapSelectionPositionToClosestValue;

@end
