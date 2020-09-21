//
//  MCMemoryBitMask.h
//
//  Created by Daniel Cascais on 8/12/11.
//  Copyright 2011 SAP SE. All rights reserved.
//

#ifndef MC_MEMORY_FLAGS_H
#define MC_MEMORY_FLAGS_H

#include "MCBitMaskUtil.h"

//
// The flags for the bitmasks
//
typedef enum MCMemoryFlags
{
    MC_MEMORY_BIT_EMPTY                                 = 1 << 0,
    
    
    //
    // Series stats allocations
    //
    MC_MEMORY_BIT_DATA_SUM_PER_SERIES                   = 1 << 1,
    MC_MEMORY_BIT_DATA_SUM_PER_SERIES_ABSOLUTE          = 1 << 2,
    
    MC_MEMORY_BIT_DATA_MINIMUM_VALUE_PER_SERIES         = 1 << 3,
    MC_MEMORY_BIT_DATA_MAXIMUM_VALUE_PER_SERIES         = 1 << 4,
    MC_MEMORY_BIT_DATA_MEAN_PER_SERIES                  = 1 << 5,
    
    MC_MEMORY_BIT_SERIES_MIN_POSITION                   = 1 << 6,
	MC_MEMORY_BIT_SERIES_MAX_POSITION                   = 1 << 7,
    
    
    //
    // Data point stats allocations.
    //
    MC_MEMORY_BIT_DATA_SUM_PER_INDEX                    = 1 << 8,
    MC_MEMORY_BIT_DATA_SUM_OF_POSITIVE_VALUES_PER_INDEX = 1 << 9,
    MC_MEMORY_BIT_DATA_SUM_OF_NEGATIVE_VALUES_PER_INDEX = 1 << 10,
    
    MC_MEMORY_BIT_DATA_MINIMUM_VALUE_PER_INDEX_STACKED  = 1 << 11,
    MC_MEMORY_BIT_DATA_MAXIMUM_VALUE_PER_INDEX_STACKED  = 1 << 12,
    
    MC_MEMORY_BIT_DATA_MIN_MAX_VALUE_INDEXED            = 1 << 13,
    
    
    //
    // 2D data point plot allocations.
    //
    MC_MEMORY_BIT_ANGLE_POSITIONS                       = 1 << 14,
    MC_MEMORY_BIT_ELLIPSE_DATA                          = 1 << 15,
    MC_MEMORY_BIT_COLUMN_DATA                           = 1 << 16,
    MC_MEMORY_BIT_POINT_DATA                            = 1 << 17
    
}MCMemoryFlags;

//
// The bitmasks for the different chart combinations
//
typedef enum MCMemoryBitMasks
{
    MC_BIT_MASK_EMPTY                              = MC_MEMORY_BIT_EMPTY,
    
    MC_BIT_MASK_LINE                               = MC_MEMORY_BIT_POINT_DATA |
                                                     MC_MEMORY_BIT_DATA_MINIMUM_VALUE_PER_SERIES |
                                                     MC_MEMORY_BIT_DATA_MAXIMUM_VALUE_PER_SERIES |
                                                     MC_MEMORY_BIT_DATA_MIN_MAX_VALUE_INDEXED,
    
    MC_BIT_MASK_LINE_STACKED                       = MC_BIT_MASK_EMPTY,
    
    MC_BIT_MASK_LINE_ONE_HUNDRED_PERCENT_STACKED   = MC_BIT_MASK_EMPTY,
    
    MC_BIT_MASK_LINE_STEP                          = MC_MEMORY_BIT_POINT_DATA |
                                                     MC_MEMORY_BIT_DATA_MINIMUM_VALUE_PER_SERIES |
                                                     MC_MEMORY_BIT_DATA_MAXIMUM_VALUE_PER_SERIES |
                                                     MC_MEMORY_BIT_DATA_MIN_MAX_VALUE_INDEXED,

    MC_BIT_MASK_AREA                               = MC_MEMORY_BIT_POINT_DATA |
                                                     MC_MEMORY_BIT_SERIES_MIN_POSITION |
                                                     MC_MEMORY_BIT_SERIES_MAX_POSITION |
                                                     MC_MEMORY_BIT_DATA_MINIMUM_VALUE_PER_SERIES |
                                                     MC_MEMORY_BIT_DATA_MAXIMUM_VALUE_PER_SERIES |
                                                     MC_MEMORY_BIT_DATA_MIN_MAX_VALUE_INDEXED,

    MC_BIT_MASK_AREA_STACKED                       = MC_MEMORY_BIT_POINT_DATA |
                                                     MC_MEMORY_BIT_SERIES_MIN_POSITION |
                                                     MC_MEMORY_BIT_SERIES_MAX_POSITION |
                                                     MC_MEMORY_BIT_DATA_MINIMUM_VALUE_PER_SERIES |
                                                     MC_MEMORY_BIT_DATA_MAXIMUM_VALUE_PER_SERIES |
                                                     MC_MEMORY_BIT_DATA_MIN_MAX_VALUE_INDEXED,

    MC_BIT_MASK_AREA_ONE_HUNDRED_PERCENT_STACKED   = MC_BIT_MASK_EMPTY,

    MC_BIT_MASK_AREA_STEP                          = MC_MEMORY_BIT_POINT_DATA |
                                                     MC_MEMORY_BIT_SERIES_MIN_POSITION |
                                                     MC_MEMORY_BIT_SERIES_MAX_POSITION |
                                                     MC_MEMORY_BIT_DATA_MINIMUM_VALUE_PER_SERIES |
                                                     MC_MEMORY_BIT_DATA_MAXIMUM_VALUE_PER_SERIES |
                                                     MC_MEMORY_BIT_DATA_MIN_MAX_VALUE_INDEXED,

    MC_BIT_MASK_COLUMN_CLUSTERED                   = MC_MEMORY_BIT_COLUMN_DATA |
                                                     MC_MEMORY_BIT_SERIES_MIN_POSITION |
                                                     MC_MEMORY_BIT_SERIES_MAX_POSITION |
                                                     MC_MEMORY_BIT_DATA_MINIMUM_VALUE_PER_SERIES |
                                                     MC_MEMORY_BIT_DATA_MAXIMUM_VALUE_PER_SERIES |
                                                     MC_MEMORY_BIT_DATA_MIN_MAX_VALUE_INDEXED,

    MC_BIT_MASK_COLUMN_STACKED                     = MC_MEMORY_BIT_COLUMN_DATA |
                                                     MC_MEMORY_BIT_DATA_MINIMUM_VALUE_PER_SERIES |
                                                     MC_MEMORY_BIT_DATA_MAXIMUM_VALUE_PER_SERIES |
                                                     MC_MEMORY_BIT_DATA_MINIMUM_VALUE_PER_INDEX_STACKED |
                                                     MC_MEMORY_BIT_DATA_MAXIMUM_VALUE_PER_INDEX_STACKED |
                                                     MC_MEMORY_BIT_DATA_SUM_OF_POSITIVE_VALUES_PER_INDEX |
                                                     MC_MEMORY_BIT_DATA_SUM_OF_NEGATIVE_VALUES_PER_INDEX |
                                                     MC_MEMORY_BIT_DATA_SUM_PER_INDEX,
    
    MC_BIT_MASK_COLUMN_ONE_HUNDRED_PERCENT_STACKED = MC_BIT_MASK_EMPTY,

    MC_BIT_MASK_STACKED_BAR_VS_TARGET_VALUE        = MC_MEMORY_BIT_COLUMN_DATA,
    
    MC_BIT_MASK_BAR_STACKED_SINGLE                 = MC_MEMORY_BIT_POINT_DATA |
                                                     MC_MEMORY_BIT_DATA_SUM_PER_SERIES_ABSOLUTE,
    
    MC_BIT_MASK_BAR_COMPARE                        = MC_MEMORY_BIT_POINT_DATA,
    
    MC_BIT_MASK_BAR_DATA_VALUE                     = MC_MEMORY_BIT_POINT_DATA,
    
    MC_BIT_MASK_SCATTER                            = MC_MEMORY_BIT_ELLIPSE_DATA,
    
    MC_BIT_MASK_BUBBLE                             = MC_MEMORY_BIT_ELLIPSE_DATA,
    
    MC_BIT_MASK_WATERFALL                          = MC_MEMORY_BIT_COLUMN_DATA |
                                                     MC_MEMORY_BIT_DATA_MINIMUM_VALUE_PER_SERIES |
                                                     MC_MEMORY_BIT_DATA_MAXIMUM_VALUE_PER_SERIES |
                                                     MC_MEMORY_BIT_DATA_SUM_PER_SERIES,
    
	MC_BIT_MASK_PARETO                             = MC_MEMORY_BIT_COLUMN_DATA |
                                                     MC_MEMORY_BIT_POINT_DATA |
                                                     MC_MEMORY_BIT_SERIES_MIN_POSITION |
                                                     MC_MEMORY_BIT_SERIES_MAX_POSITION |
                                                     MC_MEMORY_BIT_DATA_MINIMUM_VALUE_PER_SERIES |
                                                     MC_MEMORY_BIT_DATA_MAXIMUM_VALUE_PER_SERIES |
                                                     MC_MEMORY_BIT_DATA_MIN_MAX_VALUE_INDEXED,

    MC_BIT_MASK_PIE                                = MC_MEMORY_BIT_ANGLE_POSITIONS |
                                                     MC_MEMORY_BIT_DATA_SUM_PER_SERIES_ABSOLUTE
    
}MCMemoryBitMasks;

//
// Fetch the bit mask used for the specific chart type 
//
static inline uint32 MCMemoryBitMaskGetChartMask(MCType chartType)
{
    MCMemoryBitMasks memoryAllocationBitmask = MC_BIT_MASK_EMPTY;
    
    //
    // Set the corresponding flags for the bitmask. This will be used in other
    // memory handilngs for allocation, reallocation and freeing.
    //
    switch (chartType)
    {
        case MC_TYPE_LINE:
        {
            memoryAllocationBitmask = MC_BIT_MASK_LINE;
            
            break;
        }
            
//        case MC_TYPE_LINE_STACKED:
//        {
//            break;
//        }
            
//        case MC_TYPE_LINE_ONE_HUNDRED_PERCENT_STACKED:
//        {
//            break;
//        }
            
//        case MC_TYPE_LINE_STEP:
//        {
//            memoryAllocationBitmask = MC_BIT_MASK_LINE_STEP;
//            
//            break;
//        }
            
        case MC_TYPE_AREA:
        {
            memoryAllocationBitmask = MC_BIT_MASK_AREA;
            
            break;
        }
            
//        case MC_TYPE_AREA_STACKED:
//        {
//            break;
//        }
            
//        case MC_TYPE_AREA_ONE_HUNDRED_PERCENT_STACKED:
//        {
//            break;
//        }
            
//        case MC_TYPE_AREA_STEP:
//        {
//            memoryAllocationBitmask = MC_BIT_MASK_AREA_STEP;
//            
//            break;
//        }

        case MC_TYPE_TRENDS_VIEW:
        {
            memoryAllocationBitmask = MC_BIT_MASK_AREA;

            break;
        }
            
        case MC_TYPE_COLUMN_CLUSTERED:
        {
            memoryAllocationBitmask = MC_BIT_MASK_COLUMN_CLUSTERED;
            
            break;
        }
            
        case MC_TYPE_COLUMN_STACKED:
        {
            memoryAllocationBitmask = MC_BIT_MASK_COLUMN_STACKED;
            
            break;
        }
            
//        case MC_TYPE_COLUMN_ONE_HUNDRED_PERCENT_STACKED:
//        {
//            break;
//        }
        case MC_TYPE_STACKED_BAR_VS_TARGET_VALUE:
        {
            memoryAllocationBitmask = MC_BIT_MASK_STACKED_BAR_VS_TARGET_VALUE;
            break;
        }
            
        case MC_TYPE_BAR_STACKED_SINGLE:
        {
            memoryAllocationBitmask = MC_BIT_MASK_BAR_STACKED_SINGLE;
            
            break;
        }
            
        case MC_TYPE_BAR_COMPARE:
        {
            memoryAllocationBitmask = MC_BIT_MASK_BAR_COMPARE;
            
            break;
        }
            
        case MC_TYPE_BAR_DATA_VALUE:
        {
            memoryAllocationBitmask = MC_BIT_MASK_BAR_DATA_VALUE;
            break;
        }
            
        case MC_TYPE_SCATTER:
        {
            memoryAllocationBitmask = MC_BIT_MASK_SCATTER;
            
            break;
        }
            
        case MC_TYPE_BUBBLE:
        {
            memoryAllocationBitmask = MC_BIT_MASK_BUBBLE;
            
            break;
        }
            
        case MC_TYPE_PARETO:
        {
            memoryAllocationBitmask = MC_BIT_MASK_PARETO;
            
            break;
        }
            
        case MC_TYPE_WATERFALL:
        {
            memoryAllocationBitmask = MC_BIT_MASK_WATERFALL;
            break;
        }
            
        case MC_TYPE_PIE:
        {
            memoryAllocationBitmask = MC_BIT_MASK_PIE;
            
            break;
        }

        default:
        {
            memoryAllocationBitmask = MC_BIT_MASK_EMPTY;
            break;
        }
    }
    
    return memoryAllocationBitmask;
}

#endif
