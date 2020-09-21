//
//  MCBitMaskUtil.h
//  ChartKit
//
//  Created by Daniel Cascais on 11/6/11.
//  Copyright (c) 2011 SAP SE. All rights reserved.
//

#ifndef ChartKit_MCBitMaskUtil_h
#define ChartKit_MCBitMaskUtil_h

typedef unsigned int uint32;

// Append flags to the target flags.
static inline uint32 MCBitMaskAppendFlags(uint32 targetFlags, uint32 flagsToAppend)
{
	return targetFlags |= flagsToAppend;
}

// Clear flags from the target flags.
static inline uint32 MCBitMaskClearFlags(uint32 targetFlags, uint32 flagsToClear)
{
	return targetFlags &= ~flagsToClear;
}

// Check if specific flag is set in the bitmask
static inline bool MCBitMaskCheckIfFlagIsSet(uint32 targetFlags, uint32 flagToCheck)
{
    return (targetFlags & flagToCheck);
}

#endif
