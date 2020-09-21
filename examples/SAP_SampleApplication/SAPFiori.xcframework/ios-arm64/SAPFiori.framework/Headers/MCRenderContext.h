//
//  MCRenderContext.h
//  ChartKit
//
//  Created by Daniel Cascais on 1/25/12.
//  Copyright (c) 2012 SAP SE. All rights reserved.
//

#pragma once

//------------------------------------------------------------------------------
//
// Includes
//
//------------------------------------------------------------------------------

#include <stdlib.h>
#include <string.h>

#include "MCOrientation.h"
#include "MCGeometry.h"
#include "MCColorPalettes.h"
#include "MCColorUtil.h"
#include "MCAxisContext.h"
#include "MCSelection.h"

#if (TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR || TARGET_API_MAC_OSX)

typedef CFStringRef MCStringRef;

#else 

typedef char* MCStringRef;

#endif

//------------------------------------------------------------------------------
//
// Enums
//
//------------------------------------------------------------------------------

typedef enum MCFontAlignment
{
	MC_FONT_ALIGNMENT_LEFT,
    MC_FONT_ALIGNMENT_RIGHT,
    MC_FONT_ALIGNMENT_CENTER,
    MC_FONT_ALIGNMENT_JUSTIFIED
    
} MCFontAlignment;


typedef enum MCLabelTruncationType
{
    MC_TRUNCATION_TYPE_END,
    MC_TRUNCATION_TYPE_START,
    MC_TRUNCATION_TYPE_MIDDLE

} MCLabelTruncationType;


typedef enum MCAxisLabelLayoutStyle
{
    // A default layout is selected based on the chart type.
    MC_AXIS_LABEL_LAYOUT_DEFAULT = 0,

    // All labels are rendered or none.
    MC_AXIS_LABEL_LAYOUT_ALL_OR_NOTHING,

    // First and last labels are rendered.
    MC_AXIS_LABEL_LAYOUT_RANGE

} MCAxisLabelLayoutStyle;


//------------------------------------------------------------------------------
//
// Structs
//
//------------------------------------------------------------------------------

/**
 * Defines MCContext as a pointer to a structure that
 * is not defined here and so is not accessible to the outside world. Almost like OOP :)
 */
typedef struct MCRenderContext* MCRenderContextRef;

/* Label. */

struct MCLabelProperties
{
    MCFloat fontSize;
    MCColor fontColor;
    bool shadowEnabled;
    MCColor shadowColor;
    MCFloat shadowRadius;
    MCFloat shadowOffsetX;
    MCFloat shadowOffsetY;
    MCFontAlignment alignment;
    MCFloat offsetFromAxis;
    bool hidden;
    bool truncationIsAllowed;
    MCLabelTruncationType truncationType;
    const char* truncationToken;
};
typedef struct MCLabelProperties MCLabelProperties;

/* Tick. */

struct MCTickProperties
{
    MCFloat axisThickness;
    unsigned int axisColor;
    bool axisHidden;
    MCFloat axisDashPhase;
    MCFloat axisDashPattern[2];
    
    MCFloat thickness;
    unsigned int color;
    bool hidden;
    MCFloat dashPhase;
    MCFloat dashPattern[2];
};
typedef struct MCTickProperties MCTickProperties;

/* Axis. */

struct MCAxisProperties
{
    MCLabelProperties titleLabel;
    MCLabelProperties tickLabels;
    MCTickProperties gridLines;

    MCAxisLabelLayoutStyle labelLayoutStyle;

    void *callbackInfo;
    MCStringRef (*createFormattedStringCallback) (double value, double range, void *info);
    MCStringRef (*createTitleStringCallback) (MCAxisContextRef axis, void *info);
};
typedef struct MCAxisProperties MCAxisProperties;



/* Closure that serves a callback that provides color values based on parameters */
struct MCColorClosure {
    void* (*colorCallback) (MCPlotData plotData, void *info);
    void *info;
};

typedef struct MCColorClosure MCColorClosure;

struct MCAlertClosure
{
    void* (*alertCallback) (int seriesIndex, int valueIndex, void* chartContext, void* scope);
    void* scope;
};

typedef struct MCAlertClosure MCAlertClosure;

//------------------------------------------------------------------------------
//
// Creational functions
//
//------------------------------------------------------------------------------

/**
 * @brief Create a new chart context reference. Returns null if there's not enough memory.
 * @details The chart context goes through the initialization process to have a proper setup.
 * @param chartType chart type that is to be used.
 * @return MCContextRef a pointer to the chart context.
 */
MCRenderContextRef MCRenderContextCreate(void);

/**
 * @brief Releases the chart context from memory.
 * @param context The chart context reference to be released from memory.
 */
void MCRenderContextFree(MCRenderContextRef context);

/**
 * @brief Releases the chart context's internal memory usage to initial values (both data and state).
 * @details Called internally to release any malloced memroy from the context.
 * @note This does not release the context from memory.
 * @param context The chart context reference to be reset.
 */
void MCRenderContextReset(MCRenderContextRef context);

//------------------------------------------------------------------------------
//
// Getter/Setter functions
//
//------------------------------------------------------------------------------

//----------------------------------
// firstLineCapDiameter
//----------------------------------
MCFloat MCGetFirstLineCapDiameter(MCRenderContextRef context);
void MCSetFirstLineCapDiameter(MCRenderContextRef context, MCFloat value);

//----------------------------------
// lastLineCapDiameter
//----------------------------------
MCFloat MCGetLastLineCapDiameter(MCRenderContextRef context);
void MCSetLastLineCapDiameter(MCRenderContextRef context, MCFloat value);

//----------------------------------
// normalSeriesAlpha
//----------------------------------
/*
 Normal series alpha is used for normal series coloring conditions. Nothing is selected or selection is disabled.
 */
MCFloat MCGetNormalSeriesAlpha(MCRenderContextRef context);
void MCSetNormalSeriesAlpha(MCRenderContextRef context, MCFloat value);

//----------------------------------
// selectedSeriesAlpha
//----------------------------------
/*
 Selected series alpha is used for the series when selected.
 */
MCFloat MCGetSelectedSeriesAlpha(MCRenderContextRef context);
void MCSetSelectedSeriesAlpha(MCRenderContextRef context, MCFloat value);

//----------------------------------
// highlightedSeriesAlpha
//----------------------------------
/*
 Highlighted series alpha is used when the series index is selected but there are no selections on the series.
 */
MCFloat MCGetHighlightedSeriesAlpha(MCRenderContextRef context);
void MCSetHighlighteSeriesAlpha(MCRenderContextRef context, MCFloat value);

//----------------------------------
// disabledSeriesAlpha
//----------------------------------
/*
 Disabled series alpha is used when there is another series that's selected or highlighted.
 */
MCFloat MCGetDisabledSeriesAlpha(MCRenderContextRef context);
void MCSetDisabledSeriesAlpha(MCRenderContextRef context, MCFloat value);

//----------------------------------
// selectionDotDiameter
//----------------------------------
MCFloat MCGetSelectionDotDiameter(MCRenderContextRef context);
void MCSetSelectionDotDiameter(MCRenderContextRef context, MCFloat value);

//----------------------------------
// selectionDotStrokeColor
//----------------------------------
unsigned int MCGetSelectionDotStrokeColor(MCRenderContextRef context);
void MCSetSelectionDotStrokeColor(MCRenderContextRef context, unsigned int colorValue);

//----------------------------------
// selectionDotFillColor
//----------------------------------
unsigned int MCGetSelectionDotFillColor(MCRenderContextRef context);
void MCSetSelectionDotFillColor(MCRenderContextRef context, unsigned int colorValue);

//----------------------------------
// seriesDotDiameter
//----------------------------------

MCFloat MCGetSeriesDotDiameter(MCRenderContextRef context);
void MCSetSeriesDotDiameter(MCRenderContextRef context, MCFloat value);

//----------------------------------
// seriesDotIsHidden
//----------------------------------

bool MCGetSeriesDotIsHidden(MCRenderContextRef context);
void MCSetSeriesDotIsHidden(MCRenderContextRef context, bool value);

//----------------------------------
// seriesDotGap
//----------------------------------

MCFloat MCGetSeriesDotGap(MCRenderContextRef context);
void MCSetSeriesDotGap(MCRenderContextRef context, MCFloat value);

//----------------------------------
// selectedSeriesLineThickness
//----------------------------------

MCFloat MCGetSelectedSeriesLineThickness(MCRenderContextRef context);
void MCSetSelectedSeriesLineThickness(MCRenderContextRef context, MCFloat value);

//----------------------------------
// seriesLineThickness
//----------------------------------

MCFloat MCGetSeriesLineThickness(MCRenderContextRef context);
void MCSetSeriesLineThickness(MCRenderContextRef context, MCFloat value);

//----------------------------------
// selectionTouchPositionColor
//----------------------------------
unsigned int MCGetSelectionTouchPositionColor(MCRenderContextRef context);
void MCSetSelectionTouchPositionColor(MCRenderContextRef context, unsigned int colorValue);

//----------------------------------
// frame
//----------------------------------
MCRect MCGetFrame(MCRenderContextRef context);
void MCSetFrame(MCRenderContextRef context, MCRect frame);

//----------------------------------
// origin
//----------------------------------
MCPoint MCGetOrigin(MCRenderContextRef context);
void MCSetOrigin(MCRenderContextRef context, MCPoint size);

//----------------------------------
// size
//----------------------------------
MCSize MCGetSize(MCRenderContextRef context);
void MCSetSize(MCRenderContextRef context, MCSize size);

//----------------------------------
// x
//----------------------------------
MCFloat MCGetX(MCRenderContextRef context);
void MCSetX(MCRenderContextRef context, MCFloat x);

//----------------------------------
// y
//----------------------------------
MCFloat MCGetY(MCRenderContextRef context);
void MCSetY(MCRenderContextRef context, MCFloat y);

//----------------------------------
// width
//----------------------------------
MCFloat MCGetWidth(MCRenderContextRef context);
void MCSetWidth(MCRenderContextRef context, MCFloat width);

//----------------------------------
// height
//----------------------------------
MCFloat MCGetHeight(MCRenderContextRef context);
void MCSetHeight(MCRenderContextRef context, MCFloat height);

//----------------------------------
// plotInsets
//----------------------------------
MCEdgeInsets MCGetPlotInsets(MCRenderContextRef context);
void MCSetPlotInsets(MCRenderContextRef context, MCEdgeInsets insets);

//----------------------------------
// plotFrame
//----------------------------------
MCRect MCGetPlotFrame(MCRenderContextRef context);

//----------------------------------
// plotSize
//----------------------------------
MCSize MCGetPlotSize(MCRenderContextRef context);

//----------------------------------
// plotWidth
//----------------------------------
MCFloat MCGetPlotWidth(MCRenderContextRef context);

//----------------------------------
// plotHeight
//----------------------------------
MCFloat MCGetPlotHeight(MCRenderContextRef context);

//----------------------------------
// orientation
//----------------------------------
MCOrientation MCGetOrientation(MCRenderContextRef context);
void MCSetOrientation(MCRenderContextRef context, MCOrientation orientation);

//----------------------------------
// shadowEnabled
//----------------------------------
bool MCGetShadowEnabled(MCRenderContextRef context);
void MCSetShadowEnabled(MCRenderContextRef context, bool enabled);

//----------------------------------
// stepEnabled
//----------------------------------
bool MCGetStepEnabled(MCRenderContextRef context);
void MCSetStepEnabled(MCRenderContextRef context, bool enabled);

//----------------------------------
// shadowColor
//----------------------------------
unsigned int MCGetShadowColor(MCRenderContextRef context);
void MCSetShadowColor(MCRenderContextRef context, unsigned int color);

//----------------------------------
// shadowOffsetX
//----------------------------------
MCFloat MCGetShadowOffsetX(MCRenderContextRef context);
void MCSetShadowOffsetX(MCRenderContextRef context, MCFloat offset);

//----------------------------------
// shadowOffsetY
//----------------------------------
MCFloat MCGetShadowOffsetY(MCRenderContextRef context);
void MCSetShadowOffsetY(MCRenderContextRef context, MCFloat offset);

//----------------------------------
// shadowRadius
//----------------------------------
MCFloat MCGetShadowRadius(MCRenderContextRef context);
void MCSetShadowRadius(MCRenderContextRef context, MCFloat radius);

//----------------------------------
// accessibilityIntent
//----------------------------------
bool MCGetAccessibilityIntent(MCRenderContextRef context);
void MCSetAccessibilityIntent(MCRenderContextRef context, bool accessibilityIntent);

//----------------------------------
// valueAxisProperties
//----------------------------------
MCAxisProperties *MCGetValueAxisProperties(MCRenderContextRef context);

//----------------------------------
// secondaryValueAxisProperties
//----------------------------------
MCAxisProperties *MCGetSecondaryValueAxisProperties(MCRenderContextRef context);

//----------------------------------
// categoryAxisProperties
//----------------------------------
MCAxisProperties *MCGetCategoryAxisProperties(MCRenderContextRef context);

//----------------------------------
// palette
//----------------------------------
MCPalette* MCGetPalette(MCRenderContextRef context);
void MCSetPalette(MCRenderContextRef context, MCPalette* palette);

//----------------------------------
// seriesPalettesCount
//----------------------------------
unsigned int MCGetSeriesPalettesCount(MCRenderContextRef context);

//----------------------------------
// seriesPalettes
//----------------------------------
MCSeriesPalette* MCGetSeriesPalettes(MCRenderContextRef context);
void MCSetSeriesPalettes(MCRenderContextRef context, unsigned int count, MCSeriesPalette* palettes);
void MCSetSeriesPalettesFree(MCRenderContextRef context, unsigned int count, MCSeriesPalette* palettes, bool freeWhenDone);

//----------------------------------
// seriesPalette
//----------------------------------
MCSeriesPalette MCGetSeriesPaletteAtIndex(MCRenderContextRef context, unsigned int index);

//----------------------------------
// trendColorCoding
//----------------------------------
MCTrendColorCoding MCGetTrendColorCoding(MCRenderContextRef context);
void MCSetTrendColorCoding(MCRenderContextRef context, MCTrendColorCoding trendColorCoding);

//----------------------------------
// trendColorGood
//----------------------------------
unsigned int MCGetTrendColorGood(MCRenderContextRef context);
void MCSetTrendColorGood(MCRenderContextRef context, unsigned int color);

//----------------------------------
// trendColorBad
//----------------------------------
unsigned int MCGetTrendColorBad(MCRenderContextRef context);
void MCSetTrendColorBad(MCRenderContextRef context, unsigned int color);

//----------------------------------
// trendColorNeutral
//----------------------------------
unsigned int MCGetTrendColorNeutral(MCRenderContextRef context);
void MCSetTrendColorNeutral(MCRenderContextRef context, unsigned int color);

//----------------------------------
// color callback
//----------------------------------
MCColorClosure* MCGetColorClosure(MCRenderContextRef context);

//----------------------------------
// alert callback
//----------------------------------
MCAlertClosure* MCGetAlertClosure(MCRenderContextRef context);

