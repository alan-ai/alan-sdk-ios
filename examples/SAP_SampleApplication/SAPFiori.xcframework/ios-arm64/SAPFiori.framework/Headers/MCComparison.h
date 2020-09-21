//
//  MCComparison.h
//  ChartKit
//
//  Created by Daniel Cascais on 9/28/12.
//
//

#pragma once

#include <math.h>

typedef enum MCComparisonType
{
    MCComparisonNone,       // default comparison.
    MCComparisonVsOffset,   // Compares against current index offset (-1 = previous).
    MCComparisonVsIndex,    // Compares against the value of a fixed index.
    MCComparisonVsValue,    // Compares against an explicit value.
    MCComparisonEndVsStart, // Compares end value against start value with dual selection.
    MCComparisonVsSeries    // Compares against same index in specified series.
} MCComparisonType;

struct MCComparison
{
    MCComparisonType type;  // Type of comparison we are using.
    int index;              // Value index to compare.
    int series;             // Series index to compare.
    int offset;             // Value offset to compare.
    double value;           // Value to compare.
    //unsigned int dimension; // Data dimension to compare.
};
typedef struct MCComparison MCComparison;

/*
 * Populate comparison struct with defaults.
 */
static inline void MCComparisonInit(MCComparison* comparison);
static inline void MCComparisonInit(MCComparison* comparison)
{
    comparison->type = MCComparisonNone;
    comparison->index = -1;
    comparison->series = -1;
    comparison->offset = -1;
    comparison->value = NAN;
    //comparison->dimension = 0;
}

/**
 * @brief Creates offset comparison for current series.
 * @param offset Steps to offset comparison from selected value index.
 * @return MCComparison struct with corresponding type and offset.
 */
inline MCComparison MCComparisonMakeWithOffset(int offset)
{
    MCComparison comparison;
    
    MCComparisonInit(&comparison);
    comparison.type = MCComparisonVsOffset;
    comparison.offset = offset;
    
    return comparison;
}

/**
 * @brief Creates index comparison for current series.
 * @param index Comparison value index.
 * @return MCComparison struct with corresponding type and index.
 */
inline MCComparison MCComparisonMakeWithIndex(int index)
{
    MCComparison comparison;
    
    MCComparisonInit(&comparison);
    comparison.type = MCComparisonVsIndex;
    comparison.index = index;
    
    return comparison;
}

/**
 * @brief Creates value comparison.
 * @param value Value to compare to.
 * @return MCComparison struct with corresponding type and value.
 */
inline MCComparison MCComparisonMakeWithValue(double value)
{
    MCComparison comparison;
    
    MCComparisonInit(&comparison);
    comparison.type = MCComparisonVsValue;
    comparison.value = value;
    
    return comparison;
}

/**
 * @brief Creates dual selection comparison (end vs. start).
 * @return MCComparison struct with corresponding type.
 */
inline MCComparison MCComparisonMakeEndVsStart()
{
    MCComparison comparison;
    
    MCComparisonInit(&comparison);
    comparison.type = MCComparisonEndVsStart;
    
    return comparison;
}

/**
 * @brief Creates comparison with specified series and current index.
 * @param series Series index to fetch comparison value from. If -1, current series is used.
 * @return MCComparison struct with corresponding type and series.
 */
inline MCComparison MCComparisonMakeWithSeries(int series)
{
    MCComparison comparison;
    
    MCComparisonInit(&comparison);
    comparison.type = MCComparisonVsSeries;
    comparison.series = series;
    
    return comparison;
}

