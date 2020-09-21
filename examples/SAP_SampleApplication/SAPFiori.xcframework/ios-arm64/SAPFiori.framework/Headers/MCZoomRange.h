//
//  MCZoomRange.h
//  ChartKit
//
//  Created by Daniel Cascais on 10/26/12.
//
//

#pragma once

#include <stdlib.h>
#include <assert.h>

typedef struct MCZoomRange* MCZoomRangeRef;

MCZoomRangeRef MCZoomRangeCreate(void);
void MCZoomRangeFree(MCZoomRangeRef context);
void MCZoomRangeInit(MCZoomRangeRef context);
void MCZoomRangeGetRange(MCZoomRangeRef context, float* start, float* end);
void MCZoomRangeSetRange(MCZoomRangeRef context, float start, float end);
float MCZoomRangeGetStart(MCZoomRangeRef context);
void MCZoomRangeSetStart(MCZoomRangeRef context, float start);
float MCZoomRangeGetEnd(MCZoomRangeRef context);
void MCZoomRangeSetEnd(MCZoomRangeRef context, float end);
float MCZoomRangeGetTranslation(MCZoomRangeRef context);
float MCZoomRangeGetScale(MCZoomRangeRef context);
