//
//  MCInputCurator.h
//  ChartKit
//
//  Created by Daniel Cascais on 4/25/13.
//
//

#pragma once

#include <stdlib.h>
#include <assert.h>

#include "MCGeometry.h"
#include "MCContext.h"
#include "MCInputDelegate.h"

typedef struct MCInputCurator* MCInputCuratorRef;

struct MCInputInfo
{
    // Start or end input being processed.
    MCSelectionInput input;
    
    // Position of the input being processed.
    MCPoint inputPosition;
    
    // Index of the category the input reflects.
    int categoryIndex;
    
    // Flags toggled on/off for each state.
    MCSelectionChange startFlags;
    MCSelectionChange endFlags;
    MCSelectionChange changeFlags;
    
};
typedef struct MCInputInfo MCInputInfo;

MCInputCuratorRef MCInputCuratorCreate(MCContextRef chartContext);

/**
 * @brief Releases the selection montroller context from memory.
 * @param context The selection montroller context reference to be released from memory.
 */
void MCInputCuratorFree(MCInputCuratorRef context);

/**
 * @brief Releases the chart context's internal memory usage to initial values (both data and state).
 * @details Called internally to release any malloced memory from the context.
 * @note This does not release the context from memory.
 * @param context The selection montroller context reference to be reset.
 */
void MCInputCuratorReset(MCInputCuratorRef context);

const MCSelectedState* MCInputCuratorGetSelectedState(MCInputCuratorRef context);
MCPlotSelectionState MCInputCuratorGetSelectedStateForSeriesAndCategory(MCInputCuratorRef context, int series, int category);
void MCInputCuratorSetDefaultCategorySelection(MCInputCuratorRef context);
void MCInputCuratorUpdateForDataChange(MCInputCuratorRef context);
void MCInputCuratorUpdateForChartTypeChange(MCInputCuratorRef context);
void MCInputCuratorUpdateForLayoutChange(MCInputCuratorRef context);
void MCInputCuratorClearSelection(MCInputCuratorRef context);
void MCInputCuratorResetSelection(MCInputCuratorRef context);
void MCInputCuratorUpdateSelection(MCInputCuratorRef context);
void MCInputCuratorUpdateForZoom(MCInputCuratorRef context);

void MCInputCuratorSetSeriesAndValueIndices(MCInputCuratorRef context, short int series, short int startIndex, short int endIndex);
void MCInputCuratorSetSeries(MCInputCuratorRef context, short int series);
short int MCInputCuratorGetSeries(MCInputCuratorRef context);

void MCInputCuratorSetStartIndex(MCInputCuratorRef context, short int startIndex);
short int MCInputCuratorGetStartIndex(MCInputCuratorRef context);

void MCInputCuratorSetEndIndex(MCInputCuratorRef context, short int endIndex);
short int MCInputCuratorGetEndIndex(MCInputCuratorRef context);

void MCInputCuratorSetSelectedValueIndices(MCInputCuratorRef context, short int startIndex, short int endIndex);

void MCInputCuratorSetStartInputPosition(MCInputCuratorRef context, MCPoint startInputPosition);
MCPoint MCInputCuratorGetStartInputPosition(MCInputCuratorRef context);

void MCInputCuratorSetEndInputPosition(MCInputCuratorRef context, MCPoint endInputPosition);
MCPoint MCInputCuratorGetEndInputPosition(MCInputCuratorRef context);

void MCInputCuratorSetInputPositions(MCInputCuratorRef context, MCPoint startInputPosition, MCPoint endInputPosition);
void MCInputCuratorSetSeriesAndInputPositions(MCInputCuratorRef context, short int series, MCPoint startInputPosition, MCPoint endInputPosition);

MCPoint MCInputCuratorGetStartPosition(MCInputCuratorRef context);
MCPoint MCInputCuratorGetEndPosition(MCInputCuratorRef context);

const MCSelectionListRef MCInputCuratorGetSelections(MCInputCuratorRef context);

MCSelectionEvents MCInputCuratorGetSelectionEventsForInput(const MCSelectedState* selectedState, MCSelectionInput input);
MCInputInfo MCInputCuratorGetInputInfoFromInputIndex(const MCSelectedState* selectedState, const int inputIndex);

//----------------------------------
// Selection mode
//----------------------------------
MCSelectionMode MCInputCuratorGetSelectionMode(MCInputCuratorRef context);
void MCInputCuratorSetSelectionMode(MCInputCuratorRef context, MCSelectionMode value);

//----------------------------------
// Default category selection mode
//----------------------------------
MCDefaultCategory MCInputCuratorGetDefaultCategory(MCInputCuratorRef context);
void MCInputCuratorSetDefaultCategory(MCInputCuratorRef context, MCDefaultCategory value);

//----------------------------------
// Input callback
//----------------------------------
MCInputDelegate* MCGetInputDelegate(MCInputCuratorRef context);
