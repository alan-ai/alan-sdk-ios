//
//  MCRange.h
//  ChartKit
//
//  Created by Daniel Cascais on 8/30/13.
//
//

#pragma once

#include <stdbool.h>


#if (TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR || TARGET_OS_MAC)
#include <CoreFoundation/CFBase.h>
typedef CFRange MCRange;

#else

typedef struct _MCRange
{
    unsigned int location;
    unsigned int length;
} MCRange;

typedef MCRange *MCRangePointer;

#endif

static inline MCRange MCRangeMake(unsigned int loc, unsigned int len)
{
    MCRange r;
    r.location = loc;
    r.length = len;
    return r;
}

static inline CFIndex MCMaxRange(MCRange range)
{
    return (range.location + range.length);
}

static inline bool MCLocationInRange(unsigned int loc, MCRange range)
{
    return (!(loc < range.location) && (loc - range.location) < range.length) ? true : false;
}

static inline bool MCEqualRanges(MCRange range1, MCRange range2)
{
    return (range1.location == range2.location && range1.length == range2.length);
}

//FOUNDATION_EXPORT MCRange NSUnionRange(MCRange range1, MCRange range2);
//FOUNDATION_EXPORT MCRange NSIntersectionRange(MCRange range1, MCRange range2);
//FOUNDATION_EXPORT NSString *NSStringFromRange(MCRange range);
//FOUNDATION_EXPORT MCRange MCRangeFromString(NSString *aString);
