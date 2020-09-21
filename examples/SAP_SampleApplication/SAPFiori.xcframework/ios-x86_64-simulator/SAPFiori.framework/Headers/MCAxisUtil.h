/*
 *  AxisUtil.h
 *
 *  Created by Daniel Cascais on 3/24/11.
 *  Copyright 2011 SAP SE. All rights reserved.
 *
 */

#include <stdbool.h>
#include "MCAxisContext.h"
#include "MCValuePlotData.h"
#include "MCMathUtils.h"
#include <assert.h>

#pragma once

struct MinMaxValues
{
    double min;
    double max;
};

struct MinMaxIndices
{
    int min;
    int max;
};

//double* range_and_step (double range, double steps);
//MCAxisContextRef loose_label(double min, double max, double ntick);
//double nicenum (double x, bool round);
//double getNiceNumber(double x, bool round);

struct MinMaxValues MCAxisUtilFindMinMaxValues(double* values, unsigned int length);
struct MinMaxIndices MCAxisUtilFindMinMaxIndices(double* values, unsigned int length);

void MCAxisUtilExtended(MCAxisContextRef context, double dmin, double dmax, double m, double* Q, bool loose, bool fudgeRange, double* w, unsigned int qLength, bool adjustToNiceValues);
double* MCAxisUtilSequenceFromToByStepSize(double from, double to, double by);
double* MCAxisUtilSequenceFromToByLength(double from, double to, double length, bool round);

double* MCAxisUtilSequenceFromToByLengthAndSkipLeftOrRightMostValues(double from, double to, double length, bool skipLeft, bool skipRight);

unsigned int MCAxisUtilGetNumFracDigits(double num);

MCBasePlotData MCAxisUtilFindClosestAxisPositionFromPointData(const MCPoint* key,
                                                              unsigned int seriesCount,
                                                              MCPointData** positions,
                                                              unsigned int* positionCounts,
                                                              MCAxis axis,
                                                              MCFloat scale,
                                                              MCFloat translation);

MCBasePlotData MCAxisUtilFindClosestAxisPositionFromRectData(const MCPoint* key,
                                                             unsigned int seriesCount,
                                                             MCRectData** positions,
                                                             unsigned int* positionCounts,
                                                             MCAxis axis,
                                                             MCFloat scale,
                                                             MCFloat translation);

MCBasePlotData MCAxisUtilFindClosestAxisPositionFromEllipseData(const MCPoint* key,
                                                                unsigned int seriesCount,
                                                                MCEllipseData** positions,
                                                                unsigned int* positionCounts,
                                                                MCAxis axis,
                                                                MCFloat scale,
                                                                MCFloat translation);

unsigned int MCAxisUtilFindClosestPositionIndexWithStridez(MCFloat key, MCFloat* positions, unsigned int positionCount, MCFloat scale, MCFloat translation, const size_t stride);

unsigned int MCAxisUtilFindClosestPositionIndexFromPoints(const MCPoint* key, MCPointData* positions, unsigned int positionCount, MCFloat scale, MCFloat translation);
unsigned int MCAxisUtilFindClosestPositionIndexFromRects(const MCPoint* key, MCRectData* positions, unsigned int positionCount, MCFloat scale, MCFloat translation);
unsigned int MCAxisUtilFindClosestPositionIndexFromEllipses(const MCPoint* key, MCEllipseData* positions, unsigned int positionCount, MCFloat scale, MCFloat translation);

double MCAxisUtilGetOptimalSpacing(double original);
void MCAxisUtilGenerateLinearSymetricTickData(MCAxisContextRef context, unsigned int steps, unsigned int tickCount);
void MCAxisUtilGenerateClusteredTickData(MCAxisContextRef context, unsigned int dataCount, float columnGapFraction);

//------------------------------------------------------------------------------
//
// MAPPING FUNCTIONS
//
//------------------------------------------------------------------------------

float MCGetLinearValueToPixelMap(float pixels, float numericRange, float numericValue)__CG_DEPRECATED;
float MCGetLinearPixelToValueMap(float pixels, float numericRange, float pixelValue)__CG_DEPRECATED;

float MCGetClusteredValueToPixelMap(float pixels, float numericRange, float numericValue, float seriesCount, float seriesIndex)__CG_DEPRECATED;
float MCGetClusteredPixelToValueMap(float pixels, float numericRange, float pixelValue, unsigned int seriesCount, unsigned int seriesIndex)__CG_DEPRECATED;
