//
//  MCGeometry.h
//
//  Created by Daniel Cascais on 8/10/11.
//  Copyright 2011 SAP SE. All rights reserved.
//

#ifndef MCGEOMETRY_H_
#define MCGEOMETRY_H_

#include <math.h>
#include <stdbool.h>
#include <CoreGraphics/CGGeometry.h>

/*
 *
 * Structs and types are defined to mantain same function signatures in
 * MCRenderParams and allow us to use the same code in iOS/Android/Flex.
 *
 */

/*
 * iOS Specific type definitions, maintaining their original implementation.
 */
#if (TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR || TARGET_OS_MAC)


typedef CGFloat MCFloat;
typedef CGPoint MCPoint;
typedef CGSize MCSize;
typedef CGRect MCRect;

#define MCRectZero CGRectZero
#define MCRectNull CGRectNull
#define MCRectIsNull CGRectIsNull

/*
 * Android/Flex usage. We define the types and structs to portable values and
 * mantaining the functionality and implementation based on the iOS definitions.
 */
#else

typedef float MCFloat;

struct MCPoint
{
    MCFloat x;
    MCFloat y;
};
typedef struct MCPoint MCPoint;

struct MCSize
{
    MCFloat width;
    MCFloat height;
};
typedef struct MCSize MCSize;

struct MCRect
{
    MCPoint origin;
    MCSize size;
};
typedef struct MCRect MCRect;

static const MCRect MCRectNull = {{INFINITY, INFINITY}, {0, 0}};

static inline bool MCRectIsNull(MCRect rect)
{
    return isnan(rect.origin.x) && isnan(rect.origin.y) && isnan(rect.size.width) && isnan(rect.size.height);
}

#endif

typedef unsigned char MCByte;

static const MCPoint MCPointNull = {INFINITY, INFINITY};

typedef struct MCEdgeInsets
{
    MCFloat top, left, bottom, right;  // specify amount to inset (positive) for each of the edges. values can be negative to 'outset'
} MCEdgeInsets;

static inline MCEdgeInsets MCEdgeInsetsMake(MCFloat top, MCFloat left, MCFloat bottom, MCFloat right)
{
    MCEdgeInsets insets = {top, left, bottom, right};
    return insets;
}

static inline MCRect MCEdgeInsetsInsetRect(MCRect rect, MCEdgeInsets insets)
{
    MCRect insetRect = rect;

    insetRect.origin.x    += insets.left;
    insetRect.origin.y    += insets.top;
    insetRect.size.width  -= (insets.left + insets.right);
    insetRect.size.height -= (insets.top  + insets.bottom);

    return insetRect;
}

static inline bool MCEdgeInsetsEqualToEdgeInsets(MCEdgeInsets insets1, MCEdgeInsets insets2)
{
    return insets1.left == insets2.left && insets1.top == insets2.top && insets1.right == insets2.right && insets1.bottom == insets2.bottom;
}

//------------------------------------------------------------------------------
//
// Functions used in non iOS platforms
//
//------------------------------------------------------------------------------

/* Return true if `point1' and `point2' are the same, false otherwise. */

static inline bool MCPointEqualToPoint(MCPoint point1, MCPoint point2)
{
    if ((isnan(point1.x) && isnan(point1.y)) && (isnan(point2.x) && isnan(point2.y)))
    {
        return true;
    }

    if ((isinf(point1.x) && isinf(point1.y)) && (isinf(point2.x) && isinf(point2.y)))
    {
        return true;
    }
    
    //RMP-8191 - Line chart can have nan points for y with a point for x.
    if ((isnan(point1.y) && isnan(point2.y)) && (point1.x == point2.x))
    {
        return true;
    }
    
    return point1.x == point2.x && point1.y == point2.y;
}

static inline bool MCPointIsNull(MCPoint point)
{
    return isinf(point.x) && isinf(point.y);
}

/* Return true if `size1' and `size2' are the same, false otherwise. */

static inline bool MCSizeEqualToSize(MCSize size1, MCSize size2)
{
    return size1.width == size2.width && size1.height == size2.height;
}

/* Return true if `rect1' and `rect2' are the same, false otherwise. */

static inline bool MCRectEqualToRect(MCRect rect1, MCRect rect2)
{
    return MCPointEqualToPoint(rect1.origin, rect2.origin) && MCSizeEqualToSize(rect1.size, rect2.size);
}

/* Make a point from `(x, y)'. */

static inline MCPoint MCPointMake(MCFloat x, MCFloat y);

/* Make a size from `(width, height)'. */

static inline MCSize MCSizeMake(MCFloat width, MCFloat height);

/* Make a rect from `(x, y; width, height)'. */

static inline MCRect MCRectMake(MCFloat x, MCFloat y, MCFloat width, MCFloat height);
static inline MCRect MCRectMakeIntegralRound(MCFloat x, MCFloat y, MCFloat width, MCFloat height);
static inline MCRect MCRectMakeIntegralFloor(MCFloat x, MCFloat y, MCFloat width, MCFloat height);
static inline MCRect MCRectMakeIntegralCeil(MCFloat x, MCFloat y, MCFloat width, MCFloat height);

static inline MCPoint MCPointMake(MCFloat x, MCFloat y)
{
    MCPoint p; p.x = x; p.y = y; return p;
}

static inline MCSize MCSizeMake(MCFloat width, MCFloat height)
{
    MCSize size; size.width = width; size.height = height; return size;
}

static inline MCRect MCRectMake(MCFloat x, MCFloat y, MCFloat width, MCFloat height)
{
    MCRect rect;
    rect.origin.x = x; rect.origin.y = y;
    rect.size.width = width; rect.size.height = height;
    return rect;
}

static inline MCRect MCRectMakeIntegralRound(MCFloat x, MCFloat y, MCFloat width, MCFloat height)
{
    MCRect rect;
    rect.origin.x = roundf(x); rect.origin.y = roundf(y);
    rect.size.width = roundf(width); rect.size.height = roundf(height);
    return rect;
}

static inline MCRect MCRectMakeIntegralFloor(MCFloat x, MCFloat y, MCFloat width, MCFloat height)
{
    MCRect rect;
    rect.origin.x = floorf(x); rect.origin.y = floorf(y);
    rect.size.width = floorf(width); rect.size.height = floorf(height);
    return rect;
}

static inline MCRect MCRectMakeIntegralCeil(MCFloat x, MCFloat y, MCFloat width, MCFloat height)
{
    MCRect rect;
    rect.origin.x = ceilf(x); rect.origin.y = ceilf(y);
    rect.size.width = ceilf(width); rect.size.height = ceilf(height);
    return rect;
}
//static inline bool MCRectIsNull(MCRect rect);

//static inline bool __MCPointEqualToPoint(MCPoint point1, MCPoint point2)
//{
//    return point1.x == point2.x && point1.y == point2.y;
//}
//#define MCPointEqualToPoint __MCPointEqualToPoint
//
//static inline bool __MCSizeEqualToSize(MCSize size1, MCSize size2)
//{
//    return size1.width == size2.width && size1.height == size2.height;
//}
//#define MCSizeEqualToSize __MCSizeEqualToSize
//
//static inline bool __MCSizeEqualToRect(MCRect rect1, MCRect rect2)
//{
//    return __MCPointEqualToPoint(rect1.origin, rect2.origin) && __MCSizeEqualToSize(rect1.size, rect2.size);
//}
//#define MCSizeEqualToRect __MCSizeEqualToRect

//static inline MCEdgeInsets MCEdgeInsetsMake(MCFloat top, MCFloat left, MCFloat bottom, MCFloat right)
//{
//    MCEdgeInsets insets = {top, left, bottom, right};
//    return insets;
//}
//
//static inline MCRect MCEdgeInsetsInsetRect(MCRect rect, MCEdgeInsets insets)
//{
//    rect.origin.x    += insets.left;
//    rect.origin.y    += insets.top;
//    rect.size.width  -= (insets.left + insets.right);
//    rect.size.height -= (insets.top  + insets.bottom);
//    
//    return rect;
//}
//
//static inline bool MCEdgeInsetsEqualToEdgeInsets(MCEdgeInsets insets1, MCEdgeInsets insets2)
//{
//    return insets1.left == insets2.left && insets1.top == insets2.top && insets1.right == insets2.right && insets1.bottom == insets2.bottom;
//}

#endif /* MCGEOMETRY_H_ */
