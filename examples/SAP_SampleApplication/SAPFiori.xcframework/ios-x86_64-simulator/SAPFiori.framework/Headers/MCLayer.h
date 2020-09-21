//
//  MCLayer.h
//  ChartSandbox
//
//  Created by Daniel Cascais on 6/21/11.
//  Copyright 2011 SAP SE. All rights reserved.
//

//------------------------------------------------------------------------------
//
// Imports/Includes
//
//------------------------------------------------------------------------------

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>
#import <UIKit/UIGeometry.h>

#import "MCLayerProtocol.h"
#import "MCContext.h"
#import "MCTextOverlay.h"
#import "MCChartDelegate.h"


//------------------------------------------------------------------------------
//
// Declaration
//
//------------------------------------------------------------------------------

extern NSString * const MCLayerSelectionTickledNotification;

@interface MCLayer : CALayer <MCLayer, CALayerDelegate>
{

@protected
    MCContextRef _chartContext;

    unsigned int _layerCount;
    CALayer *_plotLayer;
    CALayer *_selectionOverlay;
    CALayer *_secondarySelectionOverlay;
    CALayer *_adornmentLayer;
    CALayer *_secondaryAdornmentLayer;
    MCTextOverlay* _textOverlay;
    
    unsigned int _renderedSelectedSeriesIndex;
    int _selectionColorValue;
    int _secondarySelectionColorValue;
    struct {
        unsigned int selectedDataPositionChanged:1;
        unsigned int selectedDataIndexChanged:1;
        unsigned int selectedSeriesIndexChanged:1;
        
        unsigned int secondarySelectedDataPositionChanged:1;
        unsigned int secondarySelectedDataIndexChanged:1;
        unsigned int sublayersCreated:1;
        
        unsigned int selectionTickled:1;
    } _flags;
}

//------------------------------------------------------------------------------
//
// Properties
//
//------------------------------------------------------------------------------

@property MCTextBitMask textLayoutState;

//@property (nonatomic) CGColorRef selectionOverlayColor;
//@property (nonatomic) CGColorRef secondarySelectionOverlayColor;

@property (nonatomic, readonly) MCTextOverlay *textOverlay;

@property (nonatomic, readonly) double selectedValue;
@property (nonatomic, readwrite) CGFloat selectedPosition;

@property (nonatomic, readonly) double secondarySelectedValue;
@property (nonatomic, readwrite) CGFloat secondarySelectedPosition;

@property (nonatomic, readwrite) BOOL categoryAxisLineHidden;
@property (nonatomic, readwrite) BOOL valueAxisLineHidden;
@property (nonatomic, readwrite) BOOL categoryAxisTickMarksHidden;
@property (nonatomic, readwrite) BOOL valueAxisTickMarksHidden;

@property (nonatomic, readwrite) int selectionColorValue;
@property (nonatomic, readwrite) int secondarySelectionColorValue;

@property (nonatomic, readwrite) int laserColorValue;
@property (nonatomic, readwrite) int secondaryLaserColorValue;

//------------------------------------------------------------------------------
//
// Methods
//
//------------------------------------------------------------------------------

+ (id)layerWithChartType:(MCType)type;

- (void) setSecondarySeriesIndices:(unsigned int*)secondarySeriesIndices seriesCount:(unsigned int)seriesCount;
- (void) setSelectedSeries:(int)seriesIndex valueIndex:(int)valueIndex;
- (void) setLaserLayerColor:(CGColorRef)color;

/**
 * @brief Resets both chart series and data point selection.
 * @note If this method is called, the series and data point selection are reset to -1.
 */
- (void) resetSelection;
- (void) tickleSelection;

- (void) setPeriodShading:(int)size offset:(int) offset;

/*!
 @brief   Selects the value at the given point within the receiver's coordinate space.
 */
-(void)selectValueAtPoint:(CGPoint)point;
-(void)selectSecondaryValueAtPoint:(CGPoint)point;
-(void)delegateSelectedValueIndexDidChange;
-(void)delegateSecondarySelectedValueIndexDidChange;
@end
