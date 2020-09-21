//
//  MCPlotData.h
//
//  Created by Daniel Cascais on 7/8/11.
//  Copyright 2011 SAP SE. All rights reserved.
//

#pragma once

#include <assert.h>

#include "MCContext.h"
#include "MCGeometry.h"

typedef struct MCColumnChartPlotData* MCColumnChartPlotDataRef;

//------------------------------------------------------------------------------
//
// Plot data context
//
//------------------------------------------------------------------------------

/**
 * @brief Create plot data for any column based chart.
 * @details The plot data created contains all the plot information needed to render a column based chart, including category and axis data.
 * @warning If the chart context provided doesn't have the chart type set to a column based chart, things may go wrong.
 * @param chartContext Chart context from which the plot data is created.
 * @param renderContext Render parameters struct to use for the plot data calculations.
 * @return Column chart plot data context.
 */
MCColumnChartPlotDataRef MCColumnChartPlotDataContextCreate(MCContextRef chartContext);

/**
 * @brief Releases provided MCColumnChartPlotDataRef.
 * @note Accepts null MCColumnChartPlotDataRef.
 * @param context Plot data context that is to be released from memory.
 */
void MCColumnChartPlotDataContextFree(MCColumnChartPlotDataRef context);

/**
 * @brief Get the column plot data in CGRect format.
 * @details The returned CGRect 2D array contains all the series and their respective columns.
 * @param context Plot data context from which the column bounds are retrieved.
 * @return 2D CGRect array.
 */
CGRect** MCColumnChartPlotDataContextGetAllColumnsBounds(MCColumnChartPlotDataRef context);

/**
 * @brief Retrieve the amount of series that are represented in the chart.
 * @param context Plot data context from which the series count is retrieved.
 * @return Unsigned int with series count.
 */
unsigned int MCColumnChartPlotDataContextGetSeriesCounts(MCColumnChartPlotDataRef context);

/**
 * @brief Retrieve the amount of columns each series has in the chart.
 * @param context Plot data context from which the column counts are retrieved.
 * @return Unsigned int array of column counts.
 */
unsigned int* MCColumnChartPlotDataContextGetColumnCountsInSeries(MCColumnChartPlotDataRef context);

/**
 * @brief Gets value axis tick information for the chart.
 * @param context Plot data context from which the value axis tick data is retrieved.
 * @return MCAxisTickData with the value axis information.
 */
MCAxisContextRef MCColumnChartPlotDataContextGetValueAxisTickData(MCColumnChartPlotDataRef context);

/**
 * @brief Gets category axis tick information for the chart.
 * @param context Plot data context from which the category axis tick data is retrieved.
 * @return MCAxisTickData with the category axis information.
 */
MCAxisContextRef MCColumnChartPlotDataContextGetCategoryAxisTickData(MCColumnChartPlotDataRef context);

//------------------------------------------------------------------------------
//
// Plot data
//
//------------------------------------------------------------------------------

CGRect MCPlotProceduresGetClusteredColumnFrame(MCContextRef chartContext, unsigned int seriesIndex, unsigned int valueIndex, bool treatAsParetoColumn, bool flipped);
CGRect MCPlotProceduresGetStackedColumnFrame(MCContextRef chartContext, unsigned int seriesIndex, unsigned int valueIndex, bool flipped);

void MCPlotGetLineData(MCContextRef context);
