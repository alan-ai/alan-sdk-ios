//
//  MCChart.h
//  ChartKit
//
//  Created by Daniel Cascais on 7/19/12.
//  Copyright (c) 2012 SAP SE. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>

#import "MCPlotLayer.h"
#import "MCType.h"
#import "MCGeometry.h"
#import "MCSelectionAdornment.h"
#import "MCAxisStyle.h"
#import "MCSelection.h"
#import "MCChartInteractionKind.h"

#pragma mark -
@protocol MCChartLayerDelegate;
@class MCAxisStyle;

@interface MCChartLayer : CAShapeLayer <MCPlotLayer>

@property (nonatomic, readonly) MCContextRef chartContext;
@property (nonatomic, assign) BOOL stickySelection;
@property (nonatomic, assign) unsigned int periodShadingColor;

- (void)hideAxisOverlayLabels:(BOOL)hidden;

/**
 * Sets secondary value axis series. The series indices added here are assigned
 * to the secondary value axis.
 */
- (void)setSecondaryValueAxisSeriesIndices:(unsigned int*)indices count:(unsigned int)count;

/**
 * Sets Waterfall chart sub-total indices. The column indices added here generate
 * a sub-total column at the given index.
 * Note: This is only supported by the Waterfall chart.
 */
- (void)setSubTotalIndices:(unsigned int*)indices count:(unsigned int)count;


#pragma mark Appearance

@property (nonatomic, strong) id <MCAxisStyle> valueAxisStyle;
@property (nonatomic, strong) id <MCAxisStyle> secondaryValueAxisStyle;
@property (nonatomic, strong) id <MCAxisStyle> categoryAxisStyle;

@property (nonatomic) CGImageRef backgroundImage;

@property (nonatomic) MCChartInteractionKind interactionKind;
@property (nonatomic) BOOL hidesExtremaDots;
@property (nonatomic) CGFloat extremaDotDiameter;
@property (nonatomic) BOOL hidesPlotShadow;
@property (nonatomic) CGFloat selectionDotDiameter;
@property (nonatomic) NSUInteger selectionDotStrokeColor;
@property (nonatomic) NSUInteger selectionDotFillColor;
@property (nonatomic) NSUInteger selectionTouchPositionColor;

@property (nonatomic, assign) MCFloat yAxisTickLabelVerticalOffset;
@property (nonatomic, assign) MCFloat yAxisTickLabelHorizontalOffset;
@property (nonatomic, assign) BOOL valueAxisLabelsHidden;


/**
 * Updates the coloration for a series using the current MCSeriesPalette for the series at the specified index.
 * minAlpha and maxAlpha are provided because series color values do not have an alpha channel.
 * This was introduced for Blink so that the series palette could be updated as the user's selected and deselected values.
 * BUT it could also be used to change the series palettes dynamically for any reason; such as Publishing features that allow you to change the palette at runtime.
 */
- (void)setColorPalette:(MCSeriesPalette*)palette forSeriesAtIndex:(NSUInteger)index minAlpha:(CGFloat)minAlpha maxAlpha:(CGFloat)maxAlpha;


#pragma mark Geometry

/*
 * Rect that indicates the inner plottable area of the chart. (Columns, lines, area, etc).
 * The plot frame is based on the insets.
 *  --------------------
 * |    Plot Inset      |
 * |    ------------    |
 * |   |            |   |
 * |   | Plot Frame |   |
 * |   |            |   |
 * |    ------------    |
 * |                    |
 *  --------------------
 */
@property (nonatomic, readwrite) MCEdgeInsets plotInsets;

/*
 * Rect that indicates the inner plottable area of the chart. (Columns, lines, area, etc).
 * The plot frame is based on the insets.
 *  --------------------
 * |    Plot Inset      |
 * |    ------------    |
 * |   |            |   |
 * |   | Plot Frame |   |
 * |   |            |   |
 * |    ------------    |
 * |                    |
 *  --------------------
 */
@property (nonatomic, readwrite) CGRect plotFrame;

@property (nonatomic, readwrite) CGFloat plotRotation;
@property (nonatomic, readwrite) CGFloat snapAngle;
@property (nonatomic, readwrite) CGFloat currentAngle;
@property (nonatomic, readwrite) CGFloat angularVelocity;
@property (nonatomic, readwrite) BOOL disableActionsForPlotFrame;
- (float)snap:(BOOL)animated;

/**
 * Provides the position of a value with the specified indices.
 * The result is a point within the receivers coordinate space.
 */
- (CGPoint)positionOfValueAtIndex:(NSInteger)index seriesIndex:(NSInteger)seriesIndex;


#pragma mark Adornments

/**
 Use this method to register custom adornment classes.
 To create a custom adornment class you must subclass MCSelectionAdornment or one of its subclasses: MCPointSelectionAdornment, MCColumnSelectionAdornment, MCLaserSelectionAdornment or MCStackedColumnSelectionAdornment.
 */
- (void)registerClass:(Class)adornmentClass forAdornmentType:(MCSelectionAdornmentType)adornmentType;

@property (nonatomic, readwrite) MCComparison selectionComparison;

/**
 If YES the chart displays a laser for line and area charts. Default is NO.
 */
@property (nonatomic) BOOL laserEnabled;


#pragma mark Selection

/**
 * Index of the selected series.
 */
@property (nonatomic, readwrite) int selectedSeriesIndex;

//@property (nonatomic, readonly) NSArray *selections; // Array of MCSelection objects.

/**
 * Indices of the selected values.
 */
@property (nonatomic, readonly) int *selectedValueIndices;

//I added in old method that was previously replaced to fix bug in new card where switching between series didn't update the chart to look properly
- (void)setSelectedValueIndices:(int)start end:(int)end;
- (void)setSelectedSeriesAndValueIndices:(int)series start:(int)start end:(int)end;

- (CGPathRef)getSeriesPath:(NSUInteger)series normalized:(BOOL)normalized;

/**
 */
- (void)setInputPositions:(MCPoint)start end:(MCPoint)end;
- (void)clearSelection;
- (void)setSelectedPositions:(MCPoint *)positions count:(NSUInteger)positionsCount;

- (void)setZoomRangeStartValue:(CGFloat)start endValue:(CGFloat)end adjustYScale:(BOOL)adjustYScale resetYScale:(BOOL)resetYScale animated:(BOOL)animated;

- (CGMutablePathRef)getPeriodShadingPath;


#pragma mark Delegate

/**
 Dubbed "chartDelegate" because CALayer already has a "delegate" property.
 */
@property (nonatomic, weak) id <MCChartLayerDelegate> chartDelegate;

@end

#pragma mark -

@protocol MCChartLayerDelegate <NSObject>
@optional
- (void)chartLayer:(MCChartLayer *)chartLayer willSelectSeries:(NSInteger)seriesIndex;
- (void)chartLayer:(MCChartLayer *)chartLayer didSelectSeries:(NSInteger)seriesIndex;

- (void)chartLayer:(MCChartLayer *)chartLayer willSelectValue:(MCSelection)selection;
- (void)chartLayer:(MCChartLayer *)chartLayer didSelectValue:(MCSelection)selection;

- (void)chartLayerDataWillChange:(MCChartLayer *)chartLayer;
- (void)chartLayerDataDidChange:(MCChartLayer *)chartLayer;


- (NSString *)chartLayer:(MCChartLayer *)chartLayer stringForAxis:(MCAxis)axis labelWithValue:(double)value;
- (NSString *)chartLayer:(MCChartLayer *)chartLayer stringForCategoryAxisLabelAtIndex:(NSUInteger)index;

- (NSString *)chartLayer:(MCChartLayer *)chartLayer stringForTitleOfAxis:(MCAxis)axis;

- (CGColorRef)chartLayer:(MCChartLayer *)chartLayer colorForSelection:(MCPlotData)plotData chartContext:(MCContextRef)chartContext;
@end
