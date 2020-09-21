//
//  MCDancingLayer.h
//  ChartKit
//
//  Created by Daniel Cascais on 2/16/12.
//  Copyright (c) 2012 SAP SE. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>

#import "MCLayerProtocol.h"
#import "MCContext.h"
#import "MCChartLayer.h"

// Ten series is the max, but some charts require two paths and shapes.
#define MAX_SERIES_SHAPE_COUNT 20

// One for primary and secondary value axis and one for category axis.
#define MAX_AXIS_TICK_SHAPE_COUNT 3

// We need to set the same duration for all transitions.
// For some reason, the implicit gradient animation is
// not 0.25f as other implicit animations.
#define TRANSITION_DURATION 0.25f

@interface MCDancingLayer : MCChartLayer <MCLayer>
{
    BOOL _selectedValuePositionChanged;
    BOOL _selectedValueIndexChanged;
	int _previousSelectedValueIndex;
    BOOL _selectedSeriesIndexChanged;
    
    BOOL _secondarySelectedValueIndexChanged;
    
    MCContextRef _chartContext;
    NSMutableArray* _seriesShapeLayers;
    NSMutableArray* _seriesGradientLayers;
    NSMutableArray* _axesTickShapeLayers;
    
    CFMutableDictionaryRef _axesTickPaths;
    
    CFMutableDictionaryRef _seriesPaths;
    
    CFMutableDictionaryRef _gradientLocations;
    
    CFMutableArrayRef _snapshotGradientPatternInfos;
    
    CAShapeLayer* _selectionOverlay;
    CAGradientLayer* _selectionGradient;
    CGMutablePathRef* _selectionPath;
    CFMutableArrayRef _dashPattern;
    
    MCType _chartType;
    
    /*
     * Used to store the frame and bound values assigned to this layer. We
     * override the default implementation to avoid blending. These values are
     * used to properly render the chart dimensions.
     */
//    CGRect _frame;
    CGRect _bounds;
    CGRect _lastLayoutBounds;
    
    unsigned int* _previousDataCounts;
    
    BOOL _selectionHidden;
    BOOL _animateDataChange;
    
    //
    //
    //
    
    // Array of CATextLayer
    NSMutableArray *_valueAxisTextLayers;
    // Array of CATextLayer
    NSMutableArray *_secondaryValueAxisTextLayers;
    // Array of CATextLayer
    NSMutableArray *_categoryAxisTextLayers;
    
    CGColorRef _axisLabelsColor;
    CGFloat _tickLabelFontSize;
    
    CALayer *_adornmentLayer;
    CALayer *_trendStartDot;
    CALayer *_trendEndDot;
}

@property (nonatomic, readwrite) BOOL screenshotFriendly;

@property (nonatomic) CGColorRef selectionOverlayColor;

// Array of NSString.
@property (nonatomic, strong) NSArray *categoryAxisLabels;

@property (nonatomic, readwrite) CGFloat selectedPosition;
@property (nonatomic, readwrite) BOOL animateDataChange;

@property (nonatomic) CGColorRef axisLabelsColor;

@property (nonatomic) CGColorRef gridLinesColor;

@property (nonatomic, strong) CALayer *adornmentLayer;

//
// Formatter properties
//

@property (nonatomic, strong) NSArray *seriesFormatters;
@property (nonatomic, strong) NSNumberFormatter* valueAxisLabelFormatter;
@property (nonatomic, strong) NSNumberFormatter* secondaryValueAxisLabelFormatter;
@property (nonatomic, strong) NSNumberFormatter* categoryAxisLabelFormatter;

@property (nonatomic, strong) NSString *valueAxisMagnitudeIndicator;
@property (nonatomic, strong) NSString *secondaryValueAxisMagnitudeIndicator;

@property (nonatomic, assign) BOOL disableExplicitAnimations;

@property (nonatomic, assign) BOOL categoryAxisLabelsHidden;
@property (nonatomic, assign) BOOL secondaryValueAxisLabelsHidden;


/* When true the layer and its sublayers are not displayed. Defaults to
 * false. Animatable. */

@property (nonatomic, readwrite) BOOL selectionHidden;

/*
 * Create new tick paths to use as "to" value for the transition.
 */
-(void)createPathsForAxesTicks;

/*
 * Creates series specific shape layers if they haven't already been created.
 * Then sets up the colors and assigns the new paths for the series shape.
 */
-(void)createShapeLayersForAxes;

/*
 * Create new series paths to use as "to" value for the transition.
 */
-(void)createPathsForSeries;

/*
 * Creates gradient locations specific to each series.
 */
-(void)createGradientLocationsForSeries;

/*
 * Creates series specific gradient layers if they haven't already been created.
 * Then sets the colors and assigns the new locations for the gradient colors.
 */
-(void)createGradientLayersForSeries;

/*
 * Creates series specific shape layers if they haven't already been created.
 * Then sets up the colors and assigns the new paths for the series shape.
 */
-(void)createShapeLayersForSeries;

/*
 * Sets up and initiates the animation for the data change. This includes axes
 * ticks (grid lines) and series shapes. The animation performs a transition
 * between the old and the new data set and their corresponding shapes.
 */
-(void)transitionData;

-(void)removeAllAnimationsFromSublayers;

/*
 * Creates a shape layer with the required setup for a chart series rendering.
 */
-(CAShapeLayer*)createShapeLayer;
-(void)setupShapeLayerAtSeriesIndex:(unsigned int)index;

/*
 * Creates a gradient layer used by the series rendering that have gradient
 * fill (area and column based series).
 */
-(CAGradientLayer*)createGradientLayer;
-(void)assignGradientColorsToLayerAtSeriesIndex:(unsigned int)index;

/*
 * Creates a color specific to the series index, based on the charts palette.
 */
-(CGColorRef)newStrokeColorForSeriesIndex:(unsigned int)index;

-(void)clearChart;

-(void)adjustSelection;
-(void)adjustSelectionForColumns;
-(void)adjustSelectionForLine;
-(void)adjustTrendDots:(BOOL)animated;
-(CGPoint)getSnapPosition;

@end
