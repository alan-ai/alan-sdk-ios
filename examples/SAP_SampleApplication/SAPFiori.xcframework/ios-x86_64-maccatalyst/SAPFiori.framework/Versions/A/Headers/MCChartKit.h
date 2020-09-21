//
//  ChartKit.h
//  ChartKit
//
//  Created by Jerry Jones on 8/31/11.
//  Copyright (c) 2011 SAP SE. All rights reserved.
//

#ifndef ChartKit_MCChartKit_h
#define ChartKit_MCChartKit_h

#include <stdint.h>

#include "MCAxisContext.h"
#include "MCAxisType.h"
#include "MCAxisUtil.h"
#include "MCContext.h"
#include "MCMemoryBitMask.h"
#include "MCType.h"
#include "MCGeometry.h"
#include "MCOrientation.h"
#include "MCPlotData.h"
#include "MCRenderContext.h"
#include "MCColorPalettes.h"
#include "MCColorUtil.h"
#include "MCLineSimplificationUtil.h"
#include "MCMathUtils.h"


/*
 iOS
 */
#ifdef __OBJC__

    // iOS 10 turns these informal protocols into real protocols.  We have to provide them in iOS 9 and earlier.
    #if 100000 > __IPHONE_OS_VERSION_MAX_ALLOWED
    #ifndef CALayerDelegate
    //#warning Not iOS 10.  Using protocol shims
    #define CALayerDelegate NSObject
    #define CAAnimationDelegate NSObject
    #endif
    #endif

    #import "MCAxisStyle.h"
    #import "MCAxisLabelLayout.h"
    #import "MCSelection.h"

    // CoreGraphics
    #import "MCPlotProcedures.h"
    #import "MCCoreGraphicsUtils.h"

    // CoreAnimation
    #import "MCChartLayer.h"
    #import "MCGraphicsPlotLayer.h"
    #import "MCSelectionAdornment.h"
    #import "MCPointSelectionAdornment.h"
    #import "MCColumnSelectionAdornment.h"
    #import "MCLaserSelectionAdornment.h"
    #import "MCStackedColumnSelectionAdornment.h"
    #import "MCBubbleSelectionAdornment.h"
    #import "MCTouchPositionSelectionAdornment.h"
    #import "MCCrosshairSelectionAdornment.h"

    // UIKit
    #import "MCChartView_v2.h"
    #import "MCSlider.h"
    #import "MCRangeSlider.h"

    // Extra
    #import "MMAbbreviatedNumberFormatter.h"
#endif


/*
 iOS Deprecated
 */
#ifdef __OBJC__

    // CoreAnimation
    #import "MCChartDelegate.h"
    #import "MCLayerProtocol.h"
    #import "MCLayer.h"
    #import "MCDancingLayer.h"
    #import "MCTextOverlay.h"

    // UIKit
    #import "MCChartView.h"
#endif

#endif
