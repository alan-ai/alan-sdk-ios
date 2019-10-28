//
//  MCSelection.h
//  ChartKit
//
//  Created by Cascais, Daniel on 5/30/18.
//  Copyright © 2018 SAP SE. All rights reserved.
//

#pragma once

#include "MCValuePlotData.h"

extern unsigned int MCSelectionIdCounter;

/*
 Selection mode used to toggle the selection strategy.
 */
typedef enum MCSelectionMode
{
    MCSelectionModeDisabled     = 0,
    MCSelectionModeSingleSeries = 1,
    MCSelectionModeAllSeries    = 2
    
} MCSelectionMode;

/*
 Default category.
 */
typedef enum MCDefaultCategory
{
    MCDefaultCategoryIndex = 0,
    MCDefaultCategoryFirst = 1,
    MCDefaultCategoryLast  = 2
    
} MCDefaultCategory;

/*
 Used to define the current state of each selected value.
 */
typedef enum MCSelectionState
{
    // Nothing has changed.
    MCSelectionStateNone    = 0,
    MCSelectionStateStart   = 1,
    MCSelectionStateChange  = 2,
    MCSelectionStateEnd     = 3
    
} MCSelectionState;

/*
 Defines what input location a selection is associated to.
 */
typedef enum MCSelectionInput
{
    MCSelectionInputNone    = 0,
    MCSelectionInputStart   = 1,
    MCSelectionInputEnd     = 2
    
} MCSelectionInput;

typedef enum MCSelectionEvent
{
    /*
     Events for individual selections (MCSelection).
     */
    MCSelectionEventNone              = 0,
    MCSelectionEventBegan             = 1 << 0,
    MCSelectionEventPositionChanged   = 1 << 1,
    MCSelectionEventValueChanged      = 1 << 2,
    MCSelectionEventSeriesChanged     = 1 << 3,
    MCSelectionEventEnded             = 1 << 4,
    
    /*
     Global events.
     */
    MCSelectionEventDataChanged       = 1 << 5,
    MCSelectionEventLayoutChanged     = 1 << 6
} MCSelectionEvent;

typedef MCSelectionEvent MCSelectionEvents;

typedef enum {
    // There is no active selection (all series/values are in the same coloration state).
    MCPlotSelectionStateNormal,
    // Selected state for a series.
    MCPlotSelectionStateSelected,
    // Highlighted selection for an individual value.
    MCPlotSelectionStateHighlighted,
    // State for any series that is not selected or interacted with.
    MCPlotSelectionStateDisabled
    
} MCPlotSelectionState;

/*
 Selection item containing all information regarding the represented selection.
 */
typedef struct
{
    /*
     Id to help idetify the selection struct for selection manipulations.
     */
    unsigned int id;
    
    /*
     Plot information of the selected value:
     value(s) : Value(s) represented in the plot.
     pos : X and Y position of the value(s) represented in the plot.
     series : Series in the data the represented value(s) belong to.
     index : Category index the represented value(s) belong to.
     isCorrupt : Flag indicating if the value(s) is plottable.
     rect : For ellipse & rect plot data. Contains the bounds of the plotted value(s).
     */
    MCPlotData info;
    
    /*
     Current state of the selection.
     Will indicate in what part of a selection  sequence the selection is at.
     None, start, change, end.
     */
    MCSelectionState state;
    
    /*
     Events associated with the selection, which have triggered updates.
     */
    MCSelectionEvent events;
    
    /*
     Indicates what input the selection is associated with.
     */
    MCSelectionInput input;
    
    /*
     Indicates the selection input position it is associated with.
     */
    MCPoint inputPosition;
    
} MCSelection;

static inline MCSelection MCSelectionMakeNull()
{
    MCSelection selection;
    selection.id = 0;
    selection.info = MCPlotDataNull;
    selection.state = MCSelectionStateNone;
    selection.events = MCSelectionEventNone;
    selection.input = MCSelectionInputNone;
    selection.inputPosition = MCPointNull;
    
    return selection;
}

static inline MCSelection MCSelectionMakeEmpty()
{
    MCSelection selection = MCSelectionMakeNull();
    selection.id = MCSelectionIdCounter++;
    
    return selection;
}
