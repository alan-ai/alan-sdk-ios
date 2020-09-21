/*
 *  MCContext.h
 *
 *  Created by Daniel Cascais on 3/10/11.
 *  Copyright 2011 SAP SE. All rights reserved.
 *
 */

#pragma once

//#define ROAMBI_DEPRECATED // Uncomment to enable deprecated functionality.

//------------------------------------------------------------------------------
//
// Includes
//
//------------------------------------------------------------------------------

#include "MCAxisContext.h"
#include "MCAxisUtil.h"
#include "MCType.h"
#include "MCOrientation.h"
#include "MCMathUtils.h"
#include "MCMemoryBitMask.h"
#include "MCRenderContext.h"
#include "MCValuePlotData.h"
#include "MCComparison.h"
#include "MCZoomRange.h"
#include "MCInputDelegate.h"
#include "MCRange.h"

#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//------------------------------------------------------------------------------
//
// Structs
//
//------------------------------------------------------------------------------

/**
 * Defines MCContext as a pointer to a structure that
 * is not defined here and so is not accessible to the outside world. Almost like OOP :)
 */
typedef struct MCContext* MCContextRef;

struct MCMinMax
{
    double min;
    double max;
};
typedef struct MCMinMax MCMinMax;

struct MCDataCallbacks
{
    int (*seriesCount)(void*);
    int (*seriesLength)(void*, int series);
    double (*value)(void*, int series, int index);
    double (*dimensionValue)(void*, int series, int index, int axis);
};
typedef struct MCDataCallbacks MCDataCallbacks;


//------------------------------------------------------------------------------
//
// Creational functions
//
//------------------------------------------------------------------------------

/**
 * @brief Create a new chart context reference. Returns null if there's not enough memory.
 * @details The chart context goes through the initialization process to have a proper setup.
 * @return MCContextRef a pointer to the chart context.
 */
MCContextRef MCContextCreate(void);

/**
 * @brief Releases the chart context from memory.
 * @param context The chart context reference to be released from memory.
 */
void MCContextFree(MCContextRef context);

/**
 * @brief Releases the chart context's internal memory usage to initial values (both data and state).
 * @details Called internally to release any malloced memroy from the context.
 * @note This does not release the context from memory.
 * @param context The chart context reference to be reset.
 */
void MCContextReset(MCContextRef context);

/**
 * @brief Resets any data calculations to initial values.
 * @details Called internally to release any malloced memroy from the context.
 * @note This does not release the context from memory.
 * @param context The chart context reference to be reset.
 */
void MCContextResetData(MCContextRef context);

/**
 * @brief Resets any state settings to initial values.
 * @details Called internally to release any malloced memroy from the context.
 * @note This does not release the context from memory.
 * @param context The chart context reference to be reset.
 */
void MCContextResetState(MCContextRef context);


//------------------------------------------------------------------------------
//
// Data functions
//
//------------------------------------------------------------------------------

void MCContextSetDataWithCallbacks(MCContextRef context, void* dataContext, MCDataCallbacks callbacks);
void MCContextSetDataWithCallbacksForChartTypeChange(MCContextRef context, void* dataContext, MCDataCallbacks dataCallbacks);

/*
 * @param context The chart context to which the data is assigned.
 * @param seriesCount The amount of series the data contains.
 * @param seriesValueCounts Array containing the amount of values each series has.
 * @param data 2D array of data structs.
 * @param dataType Type of data struct provided.
 */
void MCContextSetData(MCContextRef context, unsigned int seriesCount, unsigned int* seriesValueCounts, const void** data);

/**
 * @brief Fetches the corresponding data value from given series and data index.
 * @details Returns correct value if the data is current (has beend copied or the pointer hasn't been freed or modified).
 * Otherwise it will return NAN or whatever a modified pointer would have at the given indices.
 * @param context The chart context from which to fetch the value.
 * @param seriesIndex Index of the series from which to fetch the value.
 * @param valueIndex Index of the data point in the series from which to fetch the value.
 */
double MCContextGetDataValueFromSeriesAtIndex(MCContextRef context, int seriesIndex, int valueIndex, MCAxis axis);

bool MCContextSeriesHasValidValues(MCContextRef context, int seriesIndex);

/**
 * @brief Fetches the corresponding value position from given series and value index.
 * @details Returns value position. If indices are out of bounds, the closest valid position is returned.
 * @param context The chart context from which to get the value position.
 * @param seriesIndex Index of the series from which to get the value position.
 * @param valueIndex Index of the data point in the series from which to get the position.
 */
MCPoint MCContextGetClosestValuePositionFromIndices(MCContextRef context, int seriesIndex, int valueIndex);

MCPoint MCContextGetClosestValuePositionFromPositionInSeries(MCContextRef context, MCPoint position, int seriesIndex, MCAxis axis);

MCPlotData MCContextGetClosestPlotData(MCContextRef context, MCPoint position);
MCPlotData MCContextGetClosestPlotDataInSeries(MCContextRef context, MCPoint position, int series);
MCPlotData MCContextGetPlotDataFromIndices(MCContextRef context, int series, int index);
MCPoint* MCContextGetPositionFromSeriesAtIndex(MCContextRef context, int seriesIndex, int valueIndex);

//------------------------------------------------------------------------------
//
// Getter/Setter functions
//
//------------------------------------------------------------------------------

//----------------------------------
// Adjust to nice values
//----------------------------------
/**
 * @brief Sets flag to adjust or not adjust the chart scale to nice values.
 * @param context The chart context where the flag is to be set.
 * @param adjust Flag to be set.
 */
void MCContextSetAdjustScaleToNiceValues(MCContextRef context, bool adjust);

/**
 * @brief Gets the flag indicating if adjusted scale is used or not.
 * @param context The chart context from which to retrieve the flag.
 */
bool MCContextGetAdjustScaleToNiceValues(MCContextRef context);

//----------------------------------
// Data min value
//----------------------------------
/**
 * @brief Gets the minimum from the data.
 * @param context The chart context from which to retrieve the value.
 */
double MCContextGetDataMinValue(MCContextRef context);

//----------------------------------
// Data max value
//----------------------------------
/**
 * @brief Gets the maximum value in from the data.
 * @param context The chart context from which to retrieve the value.
 */
double MCContextGetDataMaxValue(MCContextRef context);

//----------------------------------
// Series min value
//----------------------------------
/**
 * @brief Gets the minimum value in a series.
 * @param context The chart context from which to retrieve the value.
 * @param seriesIndex series from which to retrieve the value.
 */
double MCContextGetMinValueFromSeries(MCContextRef context, unsigned int seriesIndex);

//----------------------------------
// Series max value
//----------------------------------
/**
 * @brief Gets the maximum value in a series.
 * @param context The chart context from which to retrieve the value.
 * @param seriesIndex series from which to retrieve the value.
 */
double MCContextGetMaxValueFromSeries(MCContextRef context, unsigned int seriesIndex);

//----------------------------------
// Explicit min value
//----------------------------------
/**
 * @brief Gets the explicit minimum value given to the chart context. Default value is NAN.
 * @param context The chart context from which to retrieve the explicit min.
 */
double MCContextGetExplicitMinValue(MCContextRef context);

/**
 * @brief Sets the explicit minimum value. Default value is NAN.
 * @param context The chart context that receives the explicit min.
 * @param value The new explicit min value.
 */
void MCContextSetExplicitMinValue(MCContextRef context, double value);

//----------------------------------
// Explicit max value
//----------------------------------
/**
 * @brief Gets the explicit maximum value given to the chart context. Default value is NAN.
 * @param context The chart context from which to retrieve the explicit max.
 */
double MCContextGetExplicitMaxValue(MCContextRef context);

/**
 * @brief Sets the explicit maximum value. Default value is NAN.
 * @param context The chart context that receives the explicit max.
 * @param value The new explicit max value.
 */
void MCContextSetExplicitMaxValue(MCContextRef context, double value);

//----------------------------------
// Explicit range value
//----------------------------------
/**
 * @brief Gets the explicit range. Default value is NAN. This value is calculated when either explicit min and max are set.
 * @param context The chart context from which to retrieve the explicit range.
 */
double MCContextGetExplicitValueRange(MCContextRef context);

//----------------------------------
// Generate Area Data Map For Range Slider
//----------------------------------
/**
 * @brief Flag that indicates wether an area chart should be drawn in a range slider even though the chart type is different.
 */
void MCContextSetGenerateAreaDataMapForRangeSlider(MCContextRef context, bool value);
bool MCContextGetGenerateAreaDataMapForRangeSlider(MCContextRef context);

//----------------------------------
// Fudge Y Axis Range
//----------------------------------
/**
 * @brief Flag that indicates wether the Y Axis should be adjusted to better fit the available space.
 * By default, all column based charts have this enabled and all line based don't.
 */
void MCContextSetFudgeYAxisRange(MCContextRef context, bool value);
bool MCContextGetFudgeYAxisRange(MCContextRef context);

//----------------------------------
// Period shading
//----------------------------------

/**
 * @brief periodOffset shifts the period phase to the right by its value
 */
int MCContextGetPeriodShadingSize(MCContextRef context);
void MCContextSetPeriodShadingSize(MCContextRef context, int value);

int MCContextGetPeriodShadingOffset(MCContextRef context);
void MCContextSetPeriodShadingOffset(MCContextRef context, int value);

/**
 * @brief Utility function to set the period shading parameters in one go.
 * @param context The chart context that receives the period shading settings.
 * @param size The size of the period shading (how many data points should be shaded).
 * @param offset The offset of the first shading index.
 */
void MCContextSetPeriodShading(MCContextRef context, int size, int offset);

void MCContextSetPeriodShadingRanges(MCContextRef context, MCRange* ranges, size_t count);
MCRange* MCContextGetPeriodShadingRanges(MCContextRef context);
MCRect* MCGeneratePeriodShading(MCContextRef context, bool fromRanges);

//----------------------------------
// Standard deviation enabled
//----------------------------------
bool MCContextGetStandardDeviationEnabled(MCContextRef context);
void MCContextSetStandardDeviationEnabled(MCContextRef context, bool value);

//----------------------------------
// Standard deviation
//----------------------------------
double MCContextGetStandardDeviation(MCContextRef context);
void MCContextSetStandardDeviation(MCContextRef context, double value);

//----------------------------------
// Mean
//----------------------------------
double MCContextGetMean(MCContextRef context);
void MCContextSetMean(MCContextRef context, double value);

//----------------------------------
// renderContext
//----------------------------------
MCRenderContextRef MCContextGetRenderContext(MCContextRef context);

//----------------------------------
// Value selection rendering enabled
//----------------------------------
bool MCContextGetValueSelectionRenderingEnabled(MCContextRef context);
void MCContextSetValueSelectionRenderingEnabled(MCContextRef context, bool value);

//----------------------------------
// Selection mode
//----------------------------------
MCSelectionMode MCContextGetSelectionMode(MCContextRef context);
void MCContextSetSelectionMode(MCContextRef context, MCSelectionMode value);

//----------------------------------
// Default category selection mode
//----------------------------------
MCDefaultCategory MCContextGetDefaultCategory(MCContextRef context);
void MCContextSetDefaultCategory(MCContextRef context, MCDefaultCategory value);


//------------------------------------------------------------------------------
//
// Axis functions
//
//------------------------------------------------------------------------------

bool MCContextIsCorrupt(MCContextRef context);

MCAxisContextRef MCContextGetValueAxis(MCContextRef context);
MCAxisContextRef MCContextGetCategoryAxis(MCContextRef context);

MCAxisContextRef MCContextGetSecondaryValueAxis(MCContextRef context);

MCType MCContextGetChartType(MCContextRef context);
void MCContextSetChartType(MCContextRef context, MCType chartType);
MCDataType MCContextGetDataType(MCContextRef context);

MCPointData** MCContextGetPointData(MCContextRef context);
MCPieWedgeData** MCContextGetPieWedgeData(MCContextRef context);
MCEllipseData** MCContextGetEllipseData(MCContextRef context);
MCRectData** MCContextGetRectData(MCContextRef context);

/**
 Safely (with NULL and bounds checking) provides access to rects for column and stacked column charts.
 
 The rect provided is normalized with respect to the bounds of the plot frame (so it doesn't take into account the positions of labels etc).
 */
bool MCContextGetRect(MCContextRef context, unsigned int seriesIndex, unsigned int index, MCRect* rect);
MCRect MCContextGetScaledBar(MCContextRef context, unsigned int seriesIndex, unsigned int index, bool integral);

float MCContextGetSeriesMinPosition(MCContextRef context, unsigned int seriesIndex);
float MCContextGetSeriesMaxPosition(MCContextRef context, unsigned int seriesIndex);

unsigned int MCContextGetSeriesCount(MCContextRef context);
unsigned int MCContextGetSeriesMaxValueCount(MCContextRef context);
unsigned int MCContextGetSeriesIndexWithMaxValueCount(MCContextRef context);
bool MCContextGetDataHasPositiveValues(MCContextRef context);
bool MCContextGetDataHasNegativeValues(MCContextRef context);
unsigned int MCContextGetValueCountForSeries(MCContextRef context, unsigned int index);
unsigned int* MCContextGetValueCountsPerSeries(MCContextRef context);
bool MCContextGetSeriesAndCategoryInBounds(MCContextRef context, int series, int category);
double MCContextGetDataSumPerIndex(MCContextRef context, unsigned int index);

int MCContextGetTrendStartIndex(MCContextRef context);
void MCContextSetTrendStartIndex(MCContextRef context, int index);
int MCContextGetTrendEndIndex(MCContextRef context);
void MCContextSetTrendEndIndex(MCContextRef context, int index);

float MCContextGetTargetValuePosition(MCContextRef context);
double MCContextGetTargetValue(MCContextRef context);
void MCContextSetTargetValue(MCContextRef context, double value);

int MCContextGetSelectedEndValueIndex(MCContextRef context);
void MCContextSetSelectedEndValueIndex(MCContextRef context, int index);

//
// Selection closure
//
MCInputDelegate* MCContextGetInputDelegate(MCContextRef context);

//
// Color closure
//

MCColorClosure* MCContextGetColorClosure(MCContextRef context);

//
// Alert closure
//

MCAlertClosure* MCContextGetAlertClosure(MCContextRef context);

//
// Comparison
//
void MCContextSetComparison(MCContextRef context, MCComparison comparison);
MCComparison MCContextGetComparison(MCContextRef context);

MCBasePlotData MCContextGetClosestPositionDataFromPosition(MCContextRef context, MCPoint position);

//
// Value axis
//
double MCContextGetValueAxisBaselineValue(MCContextRef context);
float MCContextGetValueAxisBaselinePosition(MCContextRef context);
bool MCContextGetValueAxisBaseLineClampedAtZero(MCContextRef context);
void MCContextSetValueAxisBaseLineClampedAtZero(MCContextRef context, bool value);
void MCContextSetDesiredYAxisTickCount(MCContextRef context, unsigned int value);
unsigned int MCContextGetDesiredYAxisTickCount(MCContextRef context);
void MCContextSetColumnGapFraction(MCContextRef context, MCFloat value);
MCFloat MCContextGetColumnGapFraction(MCContextRef context);


//
// Value axis alternative
//
bool MCContextGetSecondaryValueAxisEnabled(MCContextRef context);
void MCContextSetSecondaryValueAxisEnabled(MCContextRef context, bool value);
double MCContextGetSecondaryValueAxisBaselineValue(MCContextRef context);
float MCContextGetSecondaryValueAxisBaselinePosition(MCContextRef context);
bool MCContextGetSecondaryValueAxisBaselineClampedAtZero(MCContextRef context);
void MCContextSetSecondaryValueAxisBaselineClampedAtZero(MCContextRef context, bool value);
unsigned int* MCContextGetSecondaryValueAxisSeriesIndices(MCContextRef context);
void MCContextSetSecondaryValueAxisSeriesIndices(MCContextRef context, unsigned int* indices, unsigned int length);
unsigned int MCContextGetSecondaryValueAxisSeriesIndicesLength(MCContextRef context);

/**
 * @brief Gets the waterfall chart sub-total indices.
 * @param context The chart context from which to retrieve the indices.
 */
unsigned int* MCContextGetSubTotalIndices(MCContextRef context);

/**
 * @brief Sets the waterfall chart sub-total indices.
 * @param context The chart context to which the values are added.
 * @param indices The sub-total indices.
 * @param length The sub-total index count.
 */
void MCContextSetSubTotalIndices(MCContextRef context, unsigned int* indices, unsigned int length);

/**
 * @brief Gets the sub-total indices array length.
 * @param context The chart context from which to retrieve the value.
 */
unsigned int MCContextGetSubTotalIndicesLength(MCContextRef context);

/**
 * @brief Finds if an index is part of the sub-total index array.
 * @param context The chart context from which to retrieve the value.
 * @param index The searched index.
 * @return True if the index is part of the sub-total index array. False if not.
 */
bool MCContextIsSubTotalIndex(MCContextRef context, unsigned int index);

/**
 * @brief Finds if an index is part of the column index array for combo chart (MC_TYPE_PARETO).
 * @param context The chart context from which to retrieve the value.
 * @param index The searched index.
 * @return True if the index is part of the column index array for combo chart. False if not.
 */
bool MCContextIsColumnIndexInComboChart(MCContextRef context, unsigned int index);

const MCSelectedState* MCContextGetSelectedState(MCContextRef context);
MCPlotSelectionState MCContextGetSelectedStateForSeriesAndCategory(MCContextRef context, int series, int category);
void MCContextUpdateSelection(MCContextRef context);
int MCContextGetSelectedSeriesIndex(MCContextRef context);
void MCContextSetSelectedSeriesAndValueIndices(MCContextRef context, short int series, short int startIndex, short int endIndex);
void MCContextSetSelectedSeriesIndex(MCContextRef context, int index);
int MCContextGetSelectedValueIndex(MCContextRef context);
void MCContextSetSelectedValueIndex(MCContextRef context, int index);

void MCContextClearSelection(MCContextRef context);
void MCContextSetInputPositions(MCContextRef context, MCPoint start, MCPoint end);
void MCContextSetSeriesAndInputPositions(MCContextRef context, short int series, MCPoint start, MCPoint end);
void MCContextSetSelectedValueIndices(MCContextRef context, short int startIndex, short int endIndex);

MCPoint MCContextGetStartPosition(MCContextRef context);
MCPoint MCContextGetEndPosition(MCContextRef context);

MCPoint MCContextGetStartInputPosition(MCContextRef context);
void MCContextSetStartInputPosition(MCContextRef context, MCPoint position);
MCPoint MCContextGetEndInputPosition(MCContextRef context);
void MCContextSetEndInputPosition(MCContextRef context, MCPoint position);

//------------------------------------------------------------------------------
//
// Render Context Getter/Setter functions
//
//------------------------------------------------------------------------------

//----------------------------------
// firstLineCapDiameter
//----------------------------------
MCFloat MCContextGetFirstLineCapDiameter(MCContextRef context);
void MCContextSetFirstLineCapDiameter(MCContextRef context, MCFloat value);

//----------------------------------
// lastLineCapDiameter
//----------------------------------
MCFloat MCContextGetLastLineCapDiameter(MCContextRef context);
void MCContextSetLastLineCapDiameter(MCContextRef context, MCFloat value);

//----------------------------------
// normalSeriesAlpha
//----------------------------------
/*
 Normal series alpha is used for normal series coloring conditions. Nothing is selected or selection is disabled.
 */
MCFloat MCContextGetNormalSeriesAlpha(MCContextRef context);
void MCContextSetNormalSeriesAlpha(MCContextRef context, MCFloat value);

//----------------------------------
// selectedSeriesAlpha
//----------------------------------
/*
 Selected series alpha is used for the series when selected.
 */
MCFloat MCContextGetSelectedSeriesAlpha(MCContextRef context);
void MCContextSetSelectedSeriesAlpha(MCContextRef context, MCFloat value);

//----------------------------------
// highlightedSeriesAlpha
//----------------------------------
/*
 Highlighted series alpha is used when the series index is selected but there are no selections on the series.
 */
MCFloat MCContextGetHighlightedSeriesAlpha(MCContextRef context);
void MCContextSetHighlighteSeriesAlpha(MCContextRef context, MCFloat value);

//----------------------------------
// disabledSeriesAlpha
//----------------------------------
/*
 Disabled series alpha is used when there is another series that's selected or highlighted.
 */
MCFloat MCContextGetDisabledSeriesAlpha(MCContextRef context);
void MCContextSetDisabledSeriesAlpha(MCContextRef context, MCFloat value);

//----------------------------------
// selectionDotDiameter
//----------------------------------
MCFloat MCContextGetSelectionDotDiameter(MCContextRef context);
void MCContextSetSelectionDotDiameter(MCContextRef context, MCFloat value);

//----------------------------------
// selectionDotStrokeColor
//----------------------------------
unsigned int MCContextGetSelectionDotStrokeColor(MCContextRef context);
void MCContextSetSelectionDotStrokeColor(MCContextRef context, unsigned int colorValue);

//----------------------------------
// selectionDotFillColor
//----------------------------------
unsigned int MCContextGetSelectionDotFillColor(MCContextRef context);
void MCContextSetSelectionDotFillColor(MCContextRef context, unsigned int colorValue);

//----------------------------------
// selectionTouchPositionColor
//----------------------------------
unsigned int MCContextGetSelectionTouchPositionColor(MCContextRef context);
void MCContextSetSelectionTouchPositionColor(MCContextRef context, unsigned int colorValue);

//----------------------------------
// frame
//----------------------------------
MCRect MCContextGetFrame(MCContextRef context);
void MCContextSetFrame(MCContextRef context, MCRect frame);

//----------------------------------
// origin
//----------------------------------
MCPoint MCContextGetOrigin(MCContextRef context);
void MCContextSetOrigin(MCContextRef context, MCPoint origin);

//----------------------------------
// size
//----------------------------------
MCSize MCContextGetSize(MCContextRef context);
void MCContextSetSize(MCContextRef context, MCSize size);

//----------------------------------
// x
//----------------------------------
MCFloat MCContextGetX(MCContextRef context);
void MCContextSetX(MCContextRef context, MCFloat x);

//----------------------------------
// y
//----------------------------------
MCFloat MCContextGetY(MCContextRef context);
void MCContextSetY(MCContextRef context, MCFloat y);

//----------------------------------
// width
//----------------------------------
MCFloat MCContextGetWidth(MCContextRef context);
void MCContextSetWidth(MCContextRef context, MCFloat width);

//----------------------------------
// height
//----------------------------------
MCFloat MCContextGetHeight(MCContextRef context);
void MCContextSetHeight(MCContextRef context, MCFloat height);

//----------------------------------
// plotInsets
//----------------------------------
MCEdgeInsets MCContextGetPlotInsets(MCContextRef context);
void MCContextSetPlotInsets(MCContextRef context, MCEdgeInsets insets);

//----------------------------------
// plotFrame
//----------------------------------
MCRect MCContextGetPlotFrame(MCContextRef context);

//----------------------------------
// plotSize
//----------------------------------
MCSize MCContextGetPlotSize(MCContextRef context);

//----------------------------------
// plotWidth
//----------------------------------
MCFloat MCContextGetPlotWidth(MCContextRef context);

//----------------------------------
// plotHeight
//----------------------------------
MCFloat MCContextGetPlotHeight(MCContextRef context);

//----------------------------------
// orientation
//----------------------------------
MCOrientation MCContextGetOrientation(MCContextRef context);
void MCContextSetOrientation(MCContextRef context, MCOrientation orientation);

//----------------------------------
// stepEnabled
//----------------------------------
bool MCContextGetStepEnabled(MCContextRef context);
void MCContextSetStepEnabled(MCContextRef context, bool enabled);

//----------------------------------
// shadowEnabled
//----------------------------------
bool MCContextGetShadowEnabled(MCContextRef context);
void MCContextSetShadowEnabled(MCContextRef context, bool enabled);

//----------------------------------
// shadowColor
//----------------------------------
unsigned int MCContextGetShadowColor(MCContextRef context);
void MCContextSetShadowColor(MCContextRef context, unsigned int color);

//----------------------------------
// shadowOffsetX
//----------------------------------
MCFloat MCContextGetShadowOffsetX(MCContextRef context);
void MCContextSetShadowOffsetX(MCContextRef context, MCFloat offset);

//----------------------------------
// shadowOffsetY
//----------------------------------
MCFloat MCContextGetShadowOffsetY(MCContextRef context);
void MCContextSetShadowOffsetY(MCContextRef context, MCFloat offset);

//----------------------------------
// shadowRadius
//----------------------------------
MCFloat MCContextGetShadowRadius(MCContextRef context);
void MCContextSetShadowRadius(MCContextRef context, MCFloat radius);

//----------------------------------
// accessibilityIntent
//----------------------------------

bool MCContextGetAccessibilityIntent(MCContextRef context);
void MCContextSetAccessibilityIntent(MCContextRef context, bool accessibilityIntent);

//----------------------------------
// valueAxisProperties
//----------------------------------
MCAxisProperties *MCContextGetValueAxisProperties(MCContextRef context);

//----------------------------------
// secondaryValueAxisProperties
//----------------------------------
MCAxisProperties *MCContextGetSecondaryValueAxisProperties(MCContextRef context);

//----------------------------------
// categoryAxisProperties
//----------------------------------
MCAxisProperties *MCContextGetCategoryAxisProperties(MCContextRef context);

//----------------------------------
// palette
//----------------------------------
MCPalette* MCContextGetPalette(MCContextRef context);
void MCContextSetPalette(MCContextRef context, MCPalette* palette);

//----------------------------------
// seriesPalettesCount
//----------------------------------
unsigned int MCContextGetSeriesPalettesCount(MCContextRef context);

//----------------------------------
// seriesPalettes
//----------------------------------
MCSeriesPalette* MCContextGetSeriesPalettes(MCContextRef context);
void MCContextSetSeriesPalettes(MCContextRef context, unsigned int count, MCSeriesPalette* palettes);
void MCContextSetSeriesPalettesFree(MCContextRef context, unsigned int count, MCSeriesPalette* palettes, bool freeWhenDone);

//----------------------------------
// seriesPalette
//----------------------------------
MCSeriesPalette MCContextGetSeriesPaletteAtIndex(MCContextRef context, unsigned int index);
MCSeriesPalette* MCContextGetPaletteForSeriesAtIndex(MCContextRef context, unsigned int seriesIndex);

//----------------------------------
// trendColorCoding
//----------------------------------
MCTrendColorCoding MCContextGetTrendColorCoding(MCContextRef context);
void MCContextSetTrendColorCoding(MCContextRef context, MCTrendColorCoding trendColorCoding);

//----------------------------------
// Zoom
//----------------------------------
float MCContextFindClosestZoomedXPositionFromSeries(MCContextRef context, float target, unsigned int seriesIndex);
MCRange MCContextGetZoomedIndexRange(MCContextRef context);
/*
 Note for non line based charts (this):
 If you need accuracy or are not using line based charts, use MCContextGetZoomedIndexRange, which is slower.
 If you need an approximation and require speed (range shifting in charts), use this.
 */
MCRange MCContextGetApproximateZoomedIndexRange(MCContextRef context);
unsigned int MCContextGetStartZoomIndex(MCContextRef context);
unsigned int MCContextGetEndZoomIndex(MCContextRef context);
unsigned int MCContextGetClosestIndexToXPosition(MCContextRef context, float target);
MCPoint MCContextScaleZoomedPoint(MCContextRef context, MCPoint target, bool inverted, bool scaleYAxis);
MCPoint MCContextNormalizeZoomedPoint(MCContextRef context, MCPoint target, bool inverted, bool scaleYAxis);
void MCContextGetZoomRange(MCContextRef context, float* start, float* end);
void MCContextAdjustZoomRangeForNewData(MCContextRef context);
void MCContextSetZoomRange(MCContextRef context, float start, float end, bool adjustYScale, bool resetYScale);
float MCContextGetZoomScale(MCContextRef context);
float MCContextGetZoomTranslation(MCContextRef context);
float MCContextGetZoomScaleY(MCContextRef context);
float MCContextGetZoomTranslationY(MCContextRef context);
void MCContextGetMinMaxInRange(MCContextRef context, unsigned int start, unsigned int end, double* min, double* max);




