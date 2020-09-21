//
//  MCTextLayoutBitMask.h
//  ChartKit
//
//  Created by Daniel Cascais on 11/6/11.
//  Copyright (c) 2011 SAP SE. All rights reserved.
//

#ifndef ChartKit_MCTextLayoutBitMask_h
#define ChartKit_MCTextLayoutBitMask_h

#include "MCBitMaskUtil.h"

//
// The flags for the bitmasks
//
typedef enum MCTextFlag
{
    //
    // No labels
    //
    MC_TEXT_BIT_EMPTY                            = 0x00000,
    
    
    //
    // Axes titles.
    //
    MC_TEXT_BIT_VALUE_AXIS_TITLE                 = 0x00001,
    MC_TEXT_BIT_SECONDARY_VALUE_AXIS_TITLE       = 0x00002,
    MC_TEXT_BIT_CATEGORY_AXIS_TITLE              = 0x00004,
    
    //
    // Axes tick labels.
    //
    MC_TEXT_BIT_VALUE_AXIS_TICK_LABELS           = 0x00008,
    MC_TEXT_BIT_SECONDARY_VALUE_AXIS_TICK_LABELS = 0x00010,
    MC_TEXT_BIT_CATEGORY_AXIS_TICK_LABELS        = 0x00020,
    
    //
    // Axes tick marks.
    //
    MC_TEXT_BIT_VALUE_AXIS_TICK_MARKS            = 0x00040,
    MC_TEXT_BIT_SECONDARY_VALUE_AXIS_TICK_MARKS  = 0x00080,
    MC_TEXT_BIT_CATEGORY_AXIS_TICK_MARKS         = 0x00100,
    
    //
    // Data labels.
    //
    MC_TEXT_BIT_TITLE                            = 0x00200,
    MC_TEXT_BIT_SUB_TITLE                        = 0x00400,
    
    MC_TEXT_BIT_VALUE                            = 0x00800,
	MC_TEXT_BIT_SUB_VALUE                        = 0x01000,
    
    
    //
    // Dual axis magnitude helper labels.
    //
	MC_TEXT_BIT_DUAL_AXIS_LEFT_INDICATOR         = 0x02000,
    MC_TEXT_BIT_DUAL_AXIS_RIGHT_INDICATOR        = 0x04000,
    
    MC_TEXT_BIT_DUAL_AXIS_LEFT_MAGNITUDE         = 0x08000,
    MC_TEXT_BIT_DUAL_AXIS_RIGHT_MAGNITUDE        = 0x10000
    
}MCTextFlag;


//
// The bitmasks for the different chart setups.
//
typedef enum MCTextBitMask
{
    //
    // With this, no textfields or tick marks will be created.
    //
    MC_TEXT_BIT_MASK_EMPTY =                    MC_TEXT_BIT_EMPTY,
    
    //
    // Will create this mask when needed
    //
    MC_BIT_MASK_CARD_CHART =                    MC_TEXT_BIT_MASK_EMPTY,
    
    //
    // Will create this mask when needed
    //
    MC_BIT_MASK_CARD_CHART_VIEWTRON =           MC_TEXT_BIT_MASK_EMPTY,
    
    //
    // This mask shows what's needed for the dual axis setup. Other logic applies.
    //
    MC_BIT_MASK_CARD_CHART_DUAL_AXIS =          MC_TEXT_BIT_CATEGORY_AXIS_TITLE |
                                                MC_TEXT_BIT_VALUE_AXIS_TICK_LABELS |
                                                MC_TEXT_BIT_SECONDARY_VALUE_AXIS_TICK_LABELS |
                                                MC_TEXT_BIT_CATEGORY_AXIS_TICK_LABELS |
                                                MC_TEXT_BIT_VALUE_AXIS_TICK_MARKS |
                                                MC_TEXT_BIT_SECONDARY_VALUE_AXIS_TICK_MARKS |
                                                MC_TEXT_BIT_TITLE |
                                                MC_TEXT_BIT_DUAL_AXIS_LEFT_INDICATOR |
                                                MC_TEXT_BIT_DUAL_AXIS_RIGHT_INDICATOR |
                                                MC_TEXT_BIT_DUAL_AXIS_LEFT_MAGNITUDE |
                                                MC_TEXT_BIT_DUAL_AXIS_RIGHT_MAGNITUDE,
    
    //
    //
    //
    MC_BIT_MASK_CARD_CHART_VIEWTRON_DUAL_AXIS = MC_TEXT_BIT_VALUE_AXIS_TITLE |
                                                MC_TEXT_BIT_SECONDARY_VALUE_AXIS_TITLE |
                                                MC_TEXT_BIT_CATEGORY_AXIS_TITLE |
                                                MC_TEXT_BIT_VALUE_AXIS_TICK_LABELS |
                                                MC_TEXT_BIT_SECONDARY_VALUE_AXIS_TICK_LABELS |
                                                MC_TEXT_BIT_TITLE |
                                                MC_TEXT_BIT_SUB_TITLE|
                                                MC_TEXT_BIT_SUB_VALUE,
    
    //
    //
    //
    MC_BIT_MASK_CARD_CHART_DUAL_AXIS_POD =      MC_TEXT_BIT_VALUE_AXIS_TITLE |
                                                MC_TEXT_BIT_SECONDARY_VALUE_AXIS_TITLE |
                                                MC_TEXT_BIT_CATEGORY_AXIS_TITLE |
                                                MC_TEXT_BIT_VALUE_AXIS_TICK_LABELS |
                                                MC_TEXT_BIT_SECONDARY_VALUE_AXIS_TICK_LABELS |
                                                MC_TEXT_BIT_CATEGORY_AXIS_TICK_LABELS |
                                                MC_TEXT_BIT_VALUE_AXIS_TICK_MARKS |
                                                MC_TEXT_BIT_SECONDARY_VALUE_AXIS_TICK_MARKS |
                                                MC_TEXT_BIT_TITLE |
                                                MC_TEXT_BIT_SUB_TITLE|
                                                MC_TEXT_BIT_SUB_VALUE |
                                                MC_TEXT_BIT_DUAL_AXIS_LEFT_INDICATOR |
                                                MC_TEXT_BIT_DUAL_AXIS_RIGHT_INDICATOR |
                                                MC_TEXT_BIT_DUAL_AXIS_LEFT_MAGNITUDE |
                                                MC_TEXT_BIT_DUAL_AXIS_RIGHT_MAGNITUDE,
    
    //
    // 
    //
    MC_BIT_MASK_TRENDS_COMPARE =                MC_TEXT_BIT_VALUE_AXIS_TICK_LABELS |
                                                MC_TEXT_BIT_CATEGORY_AXIS_TICK_LABELS,
    
    //
    // Will create this mask when needed
    //
    MC_BIT_MASK_BLINK =                         MC_TEXT_BIT_MASK_EMPTY,
    
    //
    // Will create this mask when needed
    //
    MC_BIT_MASK_PODS =                          MC_TEXT_BIT_MASK_EMPTY
    
}MCTextBitMask;

#endif
