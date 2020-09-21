//
//  MCAxisContext.h
//
//  Created by Daniel Cascais on 6/1/11.
//  Copyright 2011 SAP SE. All rights reserved.
//

#pragma once

//------------------------------------------------------------------------------
//
// Includes
//
//------------------------------------------------------------------------------

#include <stdbool.h>

#include "MCAxisType.h"

typedef enum MCAxis
{
    MCXAxis = 1 << 0,
    MCYAxis = 1 << 1,
    MCZAxis = 1 << 2,
    MCWAxis = 1 << 3,
    
    MCCategoryAxis          = MCXAxis,
    MCValueAxis             = MCYAxis,
    MCSecondaryValueAxis    = 1 << 4,
    MCSizeAxis              = MCZAxis,
    MCRadiusAxis            = MCZAxis,
    MCDiameterAxis          = MCZAxis,
    MCValueAxes             = MCValueAxis | MCSecondaryValueAxis,
    MCAllAxes               = MCCategoryAxis | MCValueAxes
    
} MCAxis;


//------------------------------------------------------------------------------
//
// Structs
//
//------------------------------------------------------------------------------

/**
 * Definition of MCAxisContext as a pointer to a structure that is not defined
 * here and so is not accessible to the outside world.
 *
 * A structure to represent an axis and its tick data.
 */
typedef struct MCAxisContext* MCAxisContextRef;

//------------------------------------------------------------------------------
//
// Functions
//
//------------------------------------------------------------------------------

/**
 * @brief Create a context reference for the different axis types used in the charts.
 * @param axisType Indicates what kind of axis is to be created.
 * @return MCAxisContextRef axis context reference.
 */
MCAxisContextRef MCAxisContextCreate(MCAxisType axisType);

/**
 * @brief Frees axis context from memory.
 * @param context Axis context to be freed from memory.
 */
void MCAxisContextFree(MCAxisContextRef context);

/**
 * @brief Resets axis context.
 * @param context Axis context to be reset.
 */
void MCAxisContextReset(MCAxisContextRef context);

/**
 * @brief Initiates the axis context with default values.
 * @param axisType Indicates what kind of axis is to be initiated.
 */
void MCAxisContextInit(MCAxisContextRef context);

/*
 * The actual plottable min/max.
 * This is the smallest value between tick min and data min, and the biggest
 * value between tick max and data max.
 */
double MCAxisContextGetPlotMinimum(MCAxisContextRef context);
void MCAxisContextSetPlotMinimum(MCAxisContextRef context, double value);

double MCAxisContextGetPlotMaximum(MCAxisContextRef context);
void MCAxisContextSetPlotMaximum(MCAxisContextRef context, double value);

double MCAxisGetPlotBaselineValue(MCAxisContextRef context);
float MCAxisGetPlotBaselinePosition(MCAxisContextRef context);

/*
 * The min/max represented by the tick marks.
 */
double MCAxisContextGetTickMinimum(MCAxisContextRef context);
void MCAxisContextSetTickMinimum(MCAxisContextRef context, double value);

double MCAxisContextGetTickMaximum(MCAxisContextRef context);
void MCAxisContextSetTickMaximum(MCAxisContextRef context, double value);

/*
 * The min/max values in the data.
 */
double MCAxisContextGetDataMinimum(MCAxisContextRef context);
void MCAxisContextSetDataMinimum(MCAxisContextRef context, double value);

double MCAxisContextGetDataMaximum(MCAxisContextRef context);
void MCAxisContextSetDataMaximum(MCAxisContextRef context, double value);

/*
 * The range between plot min and plot max.
 */
double MCAxisContextGetPlotRange(MCAxisContextRef context);
void MCAxisContextSetPlotRange(MCAxisContextRef context, double value);

/*
 * The range between tick min and tick max.
 */
double MCAxisContextGetTickRange(MCAxisContextRef context);
void MCAxisContextSetTickRange(MCAxisContextRef context, double value);

/*
 * The range between data min and data max.
 */
double MCAxisContextGetDataRange(MCAxisContextRef context);
void MCAxisContextSetDataRange(MCAxisContextRef context, double value);

/*
 * The normalized plot range scale.
 */
float MCAxisContextGetPlotScale(MCAxisContextRef context);
void MCAxisContextSetPlotScale(MCAxisContextRef context, float value);

/*
 * The normalized tick range scale.
 */
float MCAxisContextGetTickScale(MCAxisContextRef context);
void MCAxisContextSetTickScale(MCAxisContextRef context, float value);

/*
 * The normalized data range scale.
 */
float MCAxisContextGetDataScale(MCAxisContextRef context);
void MCAxisContextSetDataScale(MCAxisContextRef context, float value);

/*
 *  The normalized size of the tick distance from one tick mark to another.
 */
double MCAxisContextGetTickStepSize(MCAxisContextRef context);
void MCAxisContextSetTickStepSize(MCAxisContextRef context, double value);

/*
 *  Array of tick values that are to be represented.
 */
double* MCAxisContextGetTickValues(MCAxisContextRef context);

/*
 *  Array of tick positions of the tick values that are to be represented.
 */
float* MCAxisContextGetTickPositions(MCAxisContextRef context);

void MCAxisContextCreateTickValuesAndPositionsWithSize(MCAxisContextRef context, unsigned int size);

/*
 *  Amount of ticks that are to be represented.
 */
unsigned int MCAxisContextGetTickCount(MCAxisContextRef context);

void MCAxisContextCreateTicks(MCAxisContextRef context, double rangeStart, double rangeEnd, unsigned int desiredTickCount, bool looseLabels, bool fudgeRange, bool adjustToNiceValues);
