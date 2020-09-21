/*
 *  MCPlotProcedures.h
 *
 *  Created by Daniel Cascais on 4/1/11.
 *  Copyright 2011 SAP SE. All rights reserved.
 *
 */

#pragma once

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <CoreGraphics/CGColorSpace.h>
#include <CoreGraphics/CGColor.h>
#include <CoreGraphics/CGContext.h>
#include <CoreFoundation/CFNumber.h>
#include <CoreFoundation/CFAttributedString.h>
#include <CoreText/CTStringAttributes.h>
#include <CoreText/CTFont.h>
#include <CoreText/CTLine.h>

#include "MCContext.h"
#include "MCAxisContext.h"

#include "MCColorPalettes.h"
#include "MCColorUtil.h"

#include "MCRenderContext.h"
#include "MCPlotData.h"

extern const unsigned int MC_LINE_DASH_PATTERN_PHASE_OFFSET;

//------------------------------------------------------------------------------
//
// Plot formulas
//
//------------------------------------------------------------------------------

/*
 *  LINEAR DISTRIBUTION
 *
 *  pixels / range = scale
 *  scale * value = pixelPosition
 *
 *  (pixels / range) * value = pixelPosition
 *
 */

/*
 *  LINEAR CLUSTERED DISTRIBUTION
 *
 *  pixels / range = scale
 *  scale * value = pixelPosition
 *
 *  (pixels / range) * value = pixelPosition
 *
 */

//------------------------------------------------------------------------------
//
// Functions
//
//------------------------------------------------------------------------------

#define X_POSITION_LINEAR(width, range, value) (((width / range) * value))
#define Y_POSITION_LINEAR(height, range, value) (((height / range) * value))

#define DOT_DIAMETER 6.0f
#define DOT_DIAMETER_SELECTED_SERIES 8.0f
#define DOT_DIAMETER_SELECTED_DATA_POINT 9.0f

#define DOT_RADIUS 3.0f
#define DOT_RADIUS_SELECTED_SERIES 4.0f
#define DOT_RADIUS_SELECTED_DATA_POINT 4.5f

void MCPlotProceduresFlipOrigin(CGContextRef context);

//------------------------------------------------------------------------------
//
// Plot render procedures
//
//------------------------------------------------------------------------------

void MCDebugDrawOriginBoundsAndPlotFrame(CGContextRef graphicsContext, MCContextRef chartContext);

void MCDrawChart(CGContextRef graphicsContext, bool clearGraphicsContext, MCContextRef chartContext);
void MCDrawCategoryAxisTicks(CGContextRef context, MCContextRef chartContext);
void MCDrawValueAxisTicks(CGContextRef context, MCContextRef chartContext);

void MCDrawLineChart(CGContextRef graphicsContext, MCContextRef chartContext, int seriesIndexToDraw, int seriesIndexToSkip);
void MCDrawAreaChart(CGContextRef context, MCContextRef chartContext, int seriesIndexToDraw, int seriesIndexToSkip);
void MCDrawColumnChartClusteredByIndex(CGContextRef graphicsContext, MCContextRef chartContext, int seriesIndexToDraw, int seriesIndexToSkip, bool drawSelectionOnly, bool treatAsParetoColumn);
//void MCPlotProceduresDrawBarClusteredChartInContext(CGContextRef graphicsContext, MCContextRef chartContext, int seriesIndexToDraw, int seriesIndexToSkip, bool treatAsParetoBar);
void MCDrawColumnChartStackedByIndex(CGContextRef context, MCContextRef chartContext, int seriesIndexToDraw, int seriesIndexToSkip, bool drawSelectionOnly, bool drawSecondarySelectionOnly);
void MCDrawSingleStackedBarChart(CGContextRef graphicsContext, MCContextRef chartContext);
void MCDrawStackedBarVsTargetValueChart(CGContextRef graphicsContext, MCContextRef chartContext);
void MCDrawDataBarChart(CGContextRef graphicsContext, MCContextRef chartContext);
void MCDrawScatterChart(CGContextRef graphicsContext, MCContextRef chartContext, int seriesIndexToDraw, int seriesIndexToSkip);
void MCDrawComboChart(CGContextRef context, MCContextRef chartContext, int seriesIndexToDraw, int seriesIndexToSkip, bool drawSelectionOnly);
void MCDrawPieChart(CGContextRef graphicsContext, MCContextRef chartContext);
void MCDrawEllipseBasedCharts(CGContextRef graphicsContext, MCContextRef chartContext, int seriesIndexToDraw, int seriesIndexToSkip);
CFStringRef MCCreateFormattedStringForTickValueWithinAxisForChartContext(MCContextRef chartContext, MCAxisProperties categoryAxis, double tickValue);

void MCDrawStandardDeviation(CGContextRef graphicsContext, MCContextRef chartContext);
void MCDrawPeriodShading(CGContextRef graphicsContext, MCContextRef chartContext);
void MCDrawGloss(CGContextRef graphicsContext, CGRect rect, bool isHorizontal, bool hasShadow, bool hasTopHighlight, bool hasBottomHighlight);

void MCDrawSelection(CGContextRef context, MCContextRef chartContext);
void MCDrawChartLabels(CGContextRef graphicsContext, MCContextRef chartContext);
void MCDrawCategoryAxisTickLabels(CGContextRef graphicsContext, MCContextRef chartContext);
void MCDrawValueAxisTickLabels(CGContextRef graphicsContext, MCContextRef chartContext);
void MCDrawSecondaryValueAxisTickLabels(CGContextRef graphicsContext, MCContextRef chartContext);

void MCDrawValueAxisTitle(CGContextRef graphicsContext, MCContextRef chartContext);
void MCDrawSecondaryValueAxisTitle(CGContextRef graphicsContext, MCContextRef chartContext);
void MCDrawCategoryAxisTitle(CGContextRef graphicsContext, MCContextRef chartContext);

void MCGenerateLinePaths(MCContextRef chartContext, CGMutablePathRef* paths);
void MCGenerateColumnPaths(MCContextRef chartContext, CGMutablePathRef* paths, bool drawSelectionOnly, bool drawSecondarySelection);
void MCGenerateStackedColumnPaths(MCContextRef chartContext, CGMutablePathRef* paths, bool drawSelectionOnly, bool drawSecondarySelection);
void MCGenerateAreaPaths_v2(MCContextRef chartContext, CGMutablePathRef* paths, unsigned int previousSeriesCount, unsigned int* previousDataCounts);
void MCGenerateAreaPaths(MCContextRef chartContext, CGMutablePathRef* paths, unsigned int previousSeriesCount, unsigned int* previousDataCounts, CFMutableArrayRef dashPattern);
//CGMutablePathRef MCTestForAnimatableArea(MCContextRef chartContext);

typedef struct
{
    // First 8 are for positive colors, last 8 for negative colors.
    CGFloat components[16];

} MCPlotGradient;

void MCPlotGradientForSeriesState(MCContextRef chartContext, MCPlotSelectionState state, unsigned int seriesIndex, MCPlotGradient* gradient);

/**
 Consolidates logic that defines gradients used to color or overlay values for a given state.
 
 TODO: This should be used by CoreGraphics and CoreAnimation rendering routines (plot, adornments, CGGraphicsContext drawing, etc).
 */
void MCPlotGradientForValueState(MCContextRef chartContext, MCPlotSelectionState state, unsigned int seriesIndex, MCPlotGradient* gradient);

/**
 Consolidates logic on how gradients are applied to the plot for various chart types.
 
 Including:
 - Mapping of colors from a MCSeriesPalette to gradient color components.
 - Manner in which transparency should be applied.
 - Selection and deselection states.
 
 TODO: This should be used by CoreGraphics and CoreAnimation rendering routines (plot, adornments, CGGraphicsContext drawing, etc).
 */
void MCPlotGradientForSeries(MCContextRef chartContext, unsigned int seriesIndex, MCPlotGradient* gradient);


/**
 ChartKit caches "normalized" plot data where rect values mapped to coordinate and size values between 0...1.
 
 This function will provide a rect for the given series/value index in the chart's real coordinate space.
 
 This is useful for computing frames for adornments in clustered, stacked, combo or waterfall charts.
 
 It is also bulletproof in that it checks for every possible error condition and returns false if any occur ... which should prevent some of the crashes we see when state becomes "corrupted".
 */
bool MCPlotRectForSeriesAndValue(MCContextRef chartContext, int seriesIndex, int valueIndex, MCRect* rect);
