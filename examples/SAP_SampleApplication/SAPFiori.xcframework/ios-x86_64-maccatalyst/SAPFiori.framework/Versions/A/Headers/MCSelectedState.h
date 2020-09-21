//
//  MCSelectedState.h
//  ChartKit
//
//  Created by Daniel Cascais on 5/6/13.
//
//

#ifndef ChartKit_MCSelectedState_h
#define ChartKit_MCSelectedState_h

#include "MCGeometry.h"
#include "MCBitMaskUtil.h"
#include "MCSelectionList.h"

typedef enum MCSelectionChange
{
    // Nothing has changed.
    MCStale                             = 1 << 0,

    // Series.
    MCSeriesChanged                     = 1 << 1,

    // Value indices.
    MCStartIndexChanged                 = 1 << 2,
    MCEndIndexChanged                   = 1 << 3,
    MCIndicesChanged                    = MCStartIndexChanged | MCEndIndexChanged,
    
    // Selection
    MCSelectionChanged                  = MCSeriesChanged | MCStartIndexChanged | MCEndIndexChanged,

    // Start input location
    MCHorizontalStartInputChanged       = 1 << 4,
    MCVerticalStartInputChanged         = 1 << 5,
    MCStartInputChanged                 = MCHorizontalStartInputChanged | MCVerticalStartInputChanged,

    // End input location
    MCHorizontalEndInputChanged         = 1 << 6,
    MCVerticalEndInputChanged           = 1 << 7,
    MCEndInputChanged                   = MCHorizontalEndInputChanged | MCVerticalEndInputChanged,

    MCInputChanged                      = MCStartInputChanged | MCEndInputChanged,

    // Selected start value position
    MCHorizontalStartPositionChanged    = 1 << 8,
    MCVerticalStartPositionChanged      = 1 << 9,
    MCStartPositionChanged              = MCHorizontalStartPositionChanged | MCVerticalStartPositionChanged,

    // Selected end value position
    MCHorizontalEndPositionChanged      = 1 << 10,
    MCVerticalEndPositionChanged        = 1 << 11,
    MCEndPositionChanged                = MCHorizontalEndPositionChanged | MCVerticalEndPositionChanged,

    MCDataChanged                       = 1 << 12,
    MCLayoutChanged                     = 1 << 13,
    
    MCStartSelectionBegan               = 1 << 14,
    MCStartSelectionChanged             = 1 << 15,
    MCStartSelectionEnded               = 1 << 16,
    
    MCEndSelectionBegan                 = 1 << 17,
    MCEndSelectionChanged               = 1 << 18,
    MCEndSelectionEnded                 = 1 << 19,
    MCChartTypeChanged                  = 1 << 20,
    
    MCSelectionCleared                  = MCStartSelectionEnded | MCEndSelectionEnded,

    MCAllChanges                        = MCSeriesChanged |
                                          MCIndicesChanged |
                                          MCSelectionChanged |
                                          MCInputChanged |
                                          MCStartPositionChanged |
                                          MCEndPositionChanged |
                                          MCDataChanged |
                                          MCLayoutChanged
} MCSelectionChange;

typedef struct
{
    MCSelectionChange change;

    //
    // Current state
    //
    short int series;
    short int startIndex;
    short int endIndex;

    // Indicates the user touches or slider positions.
    MCPoint startInputPosition;
    MCPoint endInputPosition;

    /*
     Read only. Indicates actual selected position. These positions are updated
     based on the inputs (series, start & end index and input positions).
     */
    MCPoint startPosition;
    MCPoint endPosition;

    //
    // Previous state
    //
    short int previousSeries;
    short int previousStartIndex;
    short int previousEndIndex;

    // Indicates the user touches or slider positions.
    MCPoint previousStartInputPosition;
    MCPoint previousEndInputPosition;

    /*
     Read only. Indicates actual selected position. These positions are updated
     based on the inputs (series, start & end index and input positions).
     */
    MCPoint previousStartPosition;
    MCPoint previousEndPosition;
    
    MCSelectionListRef selections;
    bool selectionsBegan;
    bool selectionsChanged;
    MCSelectionListRef selectionsEnded;

} MCSelectedState;

static inline MCSelectedState MCSelectedStateInit()
{
    MCSelectedState state;
    state.change = MCStale;

    //
    // Current state
    //
    state.series = -1;
    state.startIndex = -1;
    state.endIndex = -1;
    state.startInputPosition = MCPointNull;
    state.endInputPosition = MCPointNull;
    state.startPosition = MCPointNull;
    state.endPosition = MCPointNull;

    //
    // Previous state
    //
    state.previousSeries = -1;
    state.previousStartIndex = -1;
    state.previousEndIndex = -1;
    state.previousStartInputPosition = MCPointNull;
    state.previousEndInputPosition = MCPointNull;
    state.previousStartPosition = MCPointNull;
    state.previousEndPosition = MCPointNull;
    
    state.selections = NULL;
    state.selectionsEnded = NULL;

    return state;
}

static inline void MCSelectedStateAppendChange(uint32 *currentChanges, uint32 newChange)
{
    if (MCBitMaskCheckIfFlagIsSet(newChange, MCStale))
    {
        *currentChanges = MCStale;
    }

	*currentChanges = MCBitMaskAppendFlags(MCBitMaskClearFlags(*currentChanges, MCStale), newChange);
}

static inline void MCSelectedStateRemoveChange(uint32 *currentChanges, uint32 changeToBeRemoved)
{
    if (MCBitMaskCheckIfFlagIsSet(*currentChanges, changeToBeRemoved))
    {
        *currentChanges = MCBitMaskClearFlags(*currentChanges, changeToBeRemoved);
    }
}

static inline void MCLogSelectionChangeEnum()
{
    printf("\n");
    printf("\nMCStale: \t\t\t\t\t\t\t    %i", MCStale);
    printf("\nMCSeriesChanged: \t\t\t\t\t    %i", MCSeriesChanged);
    printf("\nMCStartIndexChanged: \t\t\t\t    %i", MCStartIndexChanged);
    printf("\nMCEndIndexChanged: \t\t\t\t\t    %i", MCEndIndexChanged);
    printf("\nMCIndicesChanged: \t\t\t\t\t   %i", MCIndicesChanged);
    printf("\nMCHorizontalStartInputChanged: \t\t   %i", MCHorizontalStartInputChanged);
    printf("\nMCVerticalStartInputChanged: \t\t   %i", MCVerticalStartInputChanged);
    printf("\nMCStartInputChanged: \t\t\t\t   %i", MCStartInputChanged);
    printf("\nMCHorizontalEndInputChanged: \t\t   %i", MCHorizontalEndInputChanged);
    printf("\nMCVerticalEndInputChanged: \t\t\t  %i", MCVerticalEndInputChanged);
    printf("\nMCEndInputChanged: \t\t\t\t\t  %i", MCEndInputChanged);
    printf("\nMCHorizontalStartPositionChanged: \t  %i", MCHorizontalStartPositionChanged);
    printf("\nMCVerticalStartPositionChanged: \t  %i", MCVerticalStartPositionChanged);
    printf("\nMCStartPositionChanged: \t\t\t  %i", MCStartPositionChanged);
    printf("\nMCHorizontalEndPositionChanged: \t %i", MCHorizontalEndPositionChanged);
    printf("\nMCVerticalEndPositionChanged: \t\t %i", MCVerticalEndPositionChanged);
    printf("\nMCEndPositionChanged: \t\t\t\t %i", MCEndPositionChanged);
    printf("\nMCDataChanged: \t\t\t\t\t\t %i", MCDataChanged);
    printf("\nMCLayoutChanged: \t\t\t\t\t %i", MCLayoutChanged);
    printf("\nMCAllChanges: \t\t\t\t\t\t%i", MCAllChanges);
}

static inline void MCPrintMCSelectedState(MCSelectedState* state)
{
    printf("\n");
    
    printf("\nMCStale: \t\t\t\t\t\t\t %s", MCBitMaskCheckIfFlagIsSet(state->change, MCStale) ? "true" : "false");
    printf("\nMCSeriesChanged: \t\t\t\t\t %s", MCBitMaskCheckIfFlagIsSet(state->change, MCSeriesChanged) ? "true" : "false");
    printf("\nMCStartIndexChanged: \t\t\t\t %s", MCBitMaskCheckIfFlagIsSet(state->change, MCStartIndexChanged) ? "true" : "false");
    printf("\nMCEndIndexChanged: \t\t\t\t\t %s", MCBitMaskCheckIfFlagIsSet(state->change, MCEndIndexChanged) ? "true" : "false");
    printf("\nMCIndicesChanged: \t\t\t\t\t %s", MCBitMaskCheckIfFlagIsSet(state->change, MCIndicesChanged) ? "true" : "false");
    printf("\nMCHorizontalStartInputChanged: \t\t %s", MCBitMaskCheckIfFlagIsSet(state->change, MCHorizontalStartInputChanged) ? "true" : "false");
    printf("\nMCVerticalStartInputChanged: \t\t %s", MCBitMaskCheckIfFlagIsSet(state->change, MCVerticalStartInputChanged) ? "true" : "false");
    printf("\nMCStartInputChanged: \t\t\t\t %s", MCBitMaskCheckIfFlagIsSet(state->change, MCStartInputChanged) ? "true" : "false");
    printf("\nMCHorizontalEndInputChanged: \t\t %s", MCBitMaskCheckIfFlagIsSet(state->change, MCHorizontalEndInputChanged) ? "true" : "false");
    printf("\nMCVerticalEndInputChanged: \t\t\t %s", MCBitMaskCheckIfFlagIsSet(state->change, MCVerticalEndInputChanged) ? "true" : "false");
    printf("\nMCEndInputChanged: \t\t\t\t\t %s", MCBitMaskCheckIfFlagIsSet(state->change, MCEndInputChanged) ? "true" : "false");
    printf("\nMCHorizontalStartPositionChanged: \t %s", MCBitMaskCheckIfFlagIsSet(state->change, MCHorizontalStartPositionChanged) ? "true" : "false");
    printf("\nMCVerticalStartPositionChanged: \t %s", MCBitMaskCheckIfFlagIsSet(state->change, MCVerticalStartPositionChanged) ? "true" : "false");
    printf("\nMCStartPositionChanged: \t\t\t %s", MCBitMaskCheckIfFlagIsSet(state->change, MCStartPositionChanged) ? "true" : "false");
    printf("\nMCHorizontalEndPositionChanged: \t %s", MCBitMaskCheckIfFlagIsSet(state->change, MCHorizontalEndPositionChanged) ? "true" : "false");
    printf("\nMCVerticalEndPositionChanged: \t\t %s", MCBitMaskCheckIfFlagIsSet(state->change, MCVerticalEndPositionChanged) ? "true" : "false");
    printf("\nMCEndPositionChanged: \t\t\t\t %s", MCBitMaskCheckIfFlagIsSet(state->change, MCEndPositionChanged) ? "true" : "false");
    printf("\nMCDataChanged: \t\t\t\t\t\t %s", MCBitMaskCheckIfFlagIsSet(state->change, MCDataChanged) ? "true" : "false");
    printf("\nMCLayoutChanged: \t\t\t\t\t %s", MCBitMaskCheckIfFlagIsSet(state->change, MCLayoutChanged) ? "true" : "false");
    printf("\nMCAllChanges: \t\t\t\t\t\t %s", MCBitMaskCheckIfFlagIsSet(state->change, MCAllChanges) ? "true" : "false");
}

#endif
