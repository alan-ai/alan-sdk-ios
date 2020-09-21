//
//  MCData.h
//  ChartKit
//
//  Created by Daniel Cascais on 7/19/12.
//  Copyright (c) 2012 SAP SE. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MCData <NSObject>

/**
 * Number of series.
 */
@property (nonatomic, readonly) unsigned int seriesCount;

/**
 * Sets the chart data and triggers a sequence of updates to selection and
 * transitions that vary depending on the chart.
 */
- (void)setData:(const void**)data seriesCount:(unsigned int)seriesCount valueCounts:(unsigned int*)valueCounts;
- (void)setData:(void*)dataContext callbacks:(MCDataCallbacks)callbacks;

/**
 * Sets the secondary series indices. The indices added here will shift the
 * corresponding series to the righ most value axis and will have its range
 * calculated based on their values.
 */
- (void) setSecondarySeries:(unsigned int*)indices seriesCount:(unsigned int)seriesCount;

- (void)getZoomRangeStartValue:(CGFloat*)start endValue:(CGFloat*)end;
- (void)setZoomRangeStartValue:(CGFloat)start endValue:(CGFloat)end adjustYScale:(BOOL)adjustYScale resetYScale:(BOOL)resetYScale animated:(BOOL)animated;

/**
 * Returns value count in a specific series. NOTE: It is common to have chart
 * data where the series have different amounts of data points. So this might
 * come handy.
 */
- (unsigned int) getValueCountForSeries:(unsigned int)index;

@end

@interface MCData : NSObject <MCData>

@end

