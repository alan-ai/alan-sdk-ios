//
//  MCPlotLayer.h
//  ChartKit
//
//  Created by Daniel Cascais on 7/19/12.
//  Copyright (c) 2012 SAP SE. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>

#import "MCData.h"
#import "MCPlotProcedures.h"
#import "MCInputCurator.h"

@protocol MCPlotLayer <MCData>

/**
 * Type of chart to be rendered.
 */
@property (nonatomic, readwrite) MCType type;
-(void) setData2:(const void**)data seriesCount:(unsigned)seriesCount valueCounts:(unsigned*)valueCounts;
@end

@interface MCPlotLayer : CAShapeLayer <MCPlotLayer>
{
    MCContextRef _chartContext;
}

/**
 * Underlying chart context that drives the chart rendering.
 * The chart context is typcially assigned to the layer by MCChartLayer, although
 * it can take a chartContext from anywhere.
 */
@property (nonatomic, assign) MCContextRef chartContext;

- (CGPathRef)getSeriesPath:(NSUInteger)series normalized:(BOOL)normalized;

/**
 * Gets called by the setBounds. Instead of overriding setBounds and potentially
 * interfering with the superclass implementations, we use this one to add our
 * behavior.
 */
//- (void) setChartBounds:(CGRect)bounds;



@property (nonatomic) CGImageRef backgroundImage;

@property (nonatomic, assign) MCFloat yAxisTickLabelVerticalOffset;
@property (nonatomic, assign) MCFloat yAxisTickLabelHorizontalOffset;

@property (nonatomic, assign) BOOL valueAxisLabelsHidden;
@property (nonatomic, readonly) CGMutablePathRef periodShadingPath;
@property (nonatomic, assign) unsigned int periodShadingColor;

- (void)updateColorsForSeriesAtIndex:(NSUInteger)index minAlpha:(CGFloat)minAlpha maxAlpha:(CGFloat)maxAlpha;

/**
 Executed BEFORE any of the following methods are executed:
 - (void)setData:(const void**)data seriesCount:(unsigned int)seriesCount valueCounts:(unsigned int*)valueCounts;
 - (void)setData:(void*)dataContext callbacks:(MCDataCallbacks)callbacks;
 - (void)setData2:(const void**)data seriesCount:(unsigned)seriesCount valueCounts:(unsigned*)valueCounts;
 Default implementation does nothing. Subclasses may override.
 */
- (void)willSetData;


/**
 Executed AFTER any of the following methods are executed:
 - (void)setData:(const void**)data seriesCount:(unsigned int)seriesCount valueCounts:(unsigned int*)valueCounts;
 - (void)setData:(void*)dataContext callbacks:(MCDataCallbacks)callbacks;
 - (void)setData2:(const void**)data seriesCount:(unsigned)seriesCount valueCounts:(unsigned*)valueCounts;
 Default implementation does nothing. Subclasses may override.
 */
- (void)didSetData;
@end
