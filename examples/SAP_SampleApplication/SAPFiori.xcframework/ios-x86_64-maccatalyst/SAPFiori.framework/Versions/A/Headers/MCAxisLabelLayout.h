//
//  MCAxisLabelPlotProcedures.hpp
//  ChartKit
//
//  Created by Callaghan, Brett on 10/26/17.
//
//

#ifndef MCAxisLabelLayout_h
#define MCAxisLabelLayout_h


// TODO: MOST of the functionality in MCAxisLabelLayout isn't specific to iOS. Deccouple the two, so this may be used more generally.
#include <CoreFoundation/CoreFoundation.h>
#include <CoreGraphics/CoreGraphics.h>

#include "MCContext.h"


typedef void* MCLabelLayoutRef;


/**
 Creates a default layout for the category axis labels.

 This layout takes an all or nothing approach to label layout.
 * If one label doesn't fit in the designated frame, all labels are hidden.
 * Labels are never allowed to overlap.
 * Labels are not allowed to exceed the bounds of the layout's frame.
 * Labels may be truncated if truncationIsAllowed is set to true.
 */
extern MCLabelLayoutRef MCLabelLayoutCreateCategoryAxisLayout(MCContextRef chartContext);


/**
 Creates a category axis layout object where only the first and last values are labeled.
 * Leftmost label is aligned to the left edge of the frame.
 * Rightmost label is aligned to the right edge of the frame.
 */
extern MCLabelLayoutRef MCLabelLayoutCreateCategoryRangeLayout(MCContextRef chartContext);


/**
 Creates a vertical category axis layout object for vertical bar charts.
 */
extern MCLabelLayoutRef MCLabelLayoutCreateVerticalCategoryAxisLayout(MCContextRef chartContext);


/**
 Creates a horizontal numeric axis layout object for vertical bar charts.
 */
extern MCLabelLayoutRef MCLabelLayoutCreateHorizontalValueAxisLayout(MCContextRef chartContext);


/**
 Destroys the layout object, freeing all memory allocated throughout it's lifetime.
 */
extern void MCLabelLayoutDestroy(MCLabelLayoutRef);


/**
 Informs the layout that it needs to be updated.
 */
extern void MCLabelLayoutSetNeedsLayout(MCLabelLayoutRef);


/**
 Returns the frame, relative to the chart frame, where labels will be displayed.
 */
extern MCRect MCLabelLayoutGetFrame(MCLabelLayoutRef layout);


/**
 Returns the number of labels to be displayed.
 */
extern unsigned int MCLabelLayoutGetLabelCount(MCLabelLayoutRef layout);


/**
 Returns the frame for the label at the given index.
 */
extern MCRect MCLabelLayoutGetLabelFrame(MCLabelLayoutRef layout, unsigned int labelIndex);


/**
 Returns the string that should be displayed in the label.
 */
extern CFAttributedStringRef MCLabelLayoutGetLabelAttributedString(MCLabelLayoutRef layout, unsigned int labelIndex);


/**
 Returns the value for the label at the given index or NAN.
 */
extern double MCLabelLayoutGetLabelValue(MCLabelLayoutRef layout, unsigned int labelIndex);


/**
 Returns the size of the given string for the layout object.
 */
extern MCSize MCLabelLayoutGetSizeOfString(MCLabelLayoutRef layout, const char* string);


/**
 Provides a label height based on the font specified by MCLabelProperties, which is the sum of the ascent and descent for the specified font family, size, and weight.
 */
extern MCFloat MCLabelLayoutGetLabelHeight(MCLabelLayoutRef layout);


/**
 Returns the position of the tick or gridline for the label.
 */
extern MCPoint MCLabelLayoutGetTickPosition(MCLabelLayoutRef layout, unsigned int labelIndex);


/**
 Returns the maximum width for the labels.
 */
extern MCFloat MCLabelLayoutGetMaxLabelWidth(MCLabelLayoutRef layout);


#pragma mark - CoreGraphics

/**
 Draws labels into the given graphics context (iOS and macOS).
 */
void MCAxisLabelLayoutDrawCategoryAxisLabels(CGContextRef graphicsContext, MCContextRef chartContext);


#endif /* MCAxisLabelLayout_h */
