//
//  MCLayerProtocol.h
//  ChartKit
//
//  Created by Brett Callaghan on 4/4/12.
//  Copyright (c) 2012 SAP SE. All rights reserved.
//
//  TODO: Use NSUInteger instead of int. (NSNotFound instead of -1).
//

#import <Foundation/Foundation.h>

#import "MCContext.h"
#import "MCChartDelegate.h"


/** Protocol that all ChartKit layer implementations conform to.
 There are currently two; MCDancingLayer and MCLayer.
 There are pros and cons to each that warrant the availability of both for a developer.
 MCLayer is CoreGraphics based and MCDancingLayer is implemented using CAShapeLayer.
 
 These different implementations should be merged. In which case this protocol would no longer be helpful. This would require that we decouple the manner in which the plot is rendered from the rest of the functionality. (Axis labels, etc).
 */
@protocol MCLayer <NSObject>

/** Underlying chart context that drives the chart rendering.
 */
@property (nonatomic, readonly) MCContextRef chartContext;

/** Delegate for selection.
 selectedSeriesIndexDidChange;
 selectedValueIndexDidChange;
 selectedValuePositionDidChange;
 dataWillChange;
 dataDidChange;
 */
@property (assign) id <MCChartDelegate> chartDelegate;

/** Index of the selected series.
 */
@property (nonatomic, readwrite) int selectedSeriesIndex;

/** Index of the selected value in the selected series.
 */
@property (nonatomic, readwrite) int selectedValueIndex;

/** Index of the secondary selected value in the selected series.
 */
@property (nonatomic, readwrite) int secondarySelectedValueIndex;

/** Sets the chart data and triggers a data transition.
 */
- (void)setData:(const double**)data seriesCount:(unsigned int)seriesCount seriesLengths:(unsigned int*)dataCounts;

/** Number of series.
 */
@property (nonatomic, readonly) unsigned int seriesCount;

/** Type of chart to be rendered.
 */
@property (nonatomic, readwrite) MCType type;

/** Rect that indicates the inner plottable area of the chart. (Columns, lines, area, etc).
 The plot frame is based on the insets.
  --------------------
 |                    |
 |    ------------    |
 |   |            |   |
 |   | Plot Frame |   |
 |   |            |   |
 |    ------------    |
 |                    |
  --------------------
 */
@property (nonatomic) MCRect plotFrame;

/** Provides the position of a value with the specified indexes.
 The result is a point within the receivers coordinate space.
 */
- (CGPoint)positionOfValueAtIndex:(NSUInteger)index seriesIndex:(NSUInteger)seriesIndex;
@end
