//
//  MCSelectionList.h
//  ChartKit
//
//  Created by Cascais, Daniel on 5/23/18.
//  Copyright © 2018 SAP SE. All rights reserved.
//

#pragma once
#include "MCSelection.h"

// Initial capacity of the list.
#define MC_LIST_INITIAL_CAPACITY 16
// Max capacity increment.
#define MC_LIST_MAX_CAPACITY_INCREMENT 1024

/**
 * Iterate over the list, using the provided `unsigned int index` and `MCSelection selection`
 * variables as containers.
 */
#define MCSelectionListIterate(list, index, selection) \
for (index = 0, selection = list->data[0]; index < list->count; selection = list->data[++index])

/*
 List context.
 
 Dynamic array that lets you add selections without knowing the final selection count.
 Memory is internally managed.
 */
typedef struct MCSelectionList* MCSelectionListRef;

/*
 Creates a list reference.
 */
MCSelectionListRef MCSelectionListCreate(void);

/*
 Free the list and its internal components from memory.
 */
void MCSelectionListFree(MCSelectionListRef context);

/*
 Clear all selections from the array.
 */
void MCSelectionListRemoveAllSelections(MCSelectionListRef context);

/*
 Reserve capacity if the amount of selections to be handled is known.
 */
void MCSelectionListReserveCapacity(MCSelectionListRef context, unsigned int count);

/*
 Get the number of selections in the list.
 */
unsigned int MCSelectionListGetCount(MCSelectionListRef context);

/*
 Retrieve the raw data stored in the array.
 */
MCSelection* MCSelectionListGetRawData(MCSelectionListRef context);

/*
 Get selection from the specified index.
 */
MCSelection MCSelectionListGetSelectionAtIndex(MCSelectionListRef context, unsigned int index);
MCSelection* MCSelectionListGetSelectionPointerAtIndex(MCSelectionListRef context, unsigned int index);
/*
 Add an selection to the end of the list.
 */
void MCSelectionListAppendSelection(MCSelectionListRef context, MCSelection selection);

/*
 Insert selection into spefified index, shifts following selections up by one.
 */
void MCSelectionListInsertSelectionAtIndex(MCSelectionListRef context, unsigned int index, MCSelection selection);

/*
 Remove last selection of the list.
 */
MCSelection MCSelectionListRemoveLastSelection(MCSelectionListRef context);

/*
 Remove selection from specified index, shifts following selections down by one.
 */
MCSelection MCSelectionListRemoveSelectionAtIndex(MCSelectionListRef context, unsigned int index);

/*
 Remove all selections that have specified selection state.
 */
void MCSelectionListRemoveSelectionsWithSelectionState(MCSelectionListRef context, MCSelectionState selectionState);

/*
 Replaces selection at index with new selection.
 */
void MCSelectionListReplaceSelectionAtIndex(MCSelectionListRef context, unsigned int index, MCSelection selection);
