//
//  MCSelectionAdornment.h
//  ChartKit
//
//  Created by Daniel Cascais on 7/19/12.
//  Copyright (c) 2012 SAP SE. All rights reserved.
//
//  Add updatesColorOnSeriesChange property. If NO, updateColor: will not be sent for the adornment.
//

#import <QuartzCore/CALayer.h>
#import <UIKit/UIKit.h>

#import "MCContext.h"
#import "MCSelection.h"

/**
 Standard adornment types.
 */
typedef enum : NSUInteger
{
    MCSelectionAdornmentTypeUnknown = 0,
    
    /**
     Point selection in line charts.
     */
	MCSelectionAdornmentTypePoint,
    
    /**
     Bubble selection in bubble charts.
     */
    MCSelectionAdornmentTypeBubble,
    
    /**
     Column selection in vertical bar charts.
     */
	MCSelectionAdornmentTypeColumn,
    
    /**
     Column segment in stacked column charts.
     */
    MCSelectionAdornmentTypeStackedColumn,
    
    /**
     "Laser" that moves with the position of a slider or a touch event.
     */
	MCSelectionAdornmentTypeLaser,

    /**
     "Crosshair" that moves with the position of a slider or a touch event.
     */
	MCSelectionAdornmentTypeCrosshair,
    
    /**
     Adornment to highlight the region between two values.
     */
    MCSelectionAdornmentTypeRangeHighlight,
    
    /**
     Adornment to highlight a slice of the pie.
     */
    MCSelectionAdornmentTypePie
    
} MCSelectionAdornmentType;


/**
 Flags to indicate the manner in which properties are updated given an event.
 */
typedef enum : NSUInteger
{
    MCSelectionAdornmentNoAnimation                     = 0,
    
    /*
     Position
     */
    MCSelectionAdornmentAnimatePositionOnPositionChange = 1 << 0,
    MCSelectionAdornmentAnimatePositionOnValueChange    = 1 << 1,
    MCSelectionAdornmentAnimatePositionOnSeriesChange   = 1 << 2,
    MCSelectionAdornmentAnimatePositionOnDataChange     = 1 << 3,
    
    /*
     Size
     */
    MCSelectionAdornmentAnimateSizeOnValueChange        = 1 << 4,
    MCSelectionAdornmentAnimateSizeOnSeriesChange       = 1 << 5,
    MCSelectionAdornmentAnimateSizeOnDataChange         = 1 << 6,
    
    /*
     Coloration
     */
    MCSelectionAdornmentAnimateColorOnValueChange       = 1 << 7,
    MCSelectionAdornmentAnimateColorOnSeriesChange      = 1 << 8,
    MCSelectionAdornmentAnimateColorOnDataChange        = 1 << 9,
    
    MCSelectionAdornmentAnimateGradientOnValueChange    = 1 << 10,
    MCSelectionAdornmentAnimateGradientOnSeriesChange   = 1 << 11,
    MCSelectionAdornmentAnimateGradientOnDataChange     = 1 << 12,
    
    MCSelectionAdornmentBelowPlot                       = 1 << 13
} MCSelectionAdornmentBehavior;


/**
 Bitmask of MCSelectionAdornmentBehavior enum values.
 */
typedef NSUInteger MCSelectionAdornmentBehaviors;


/**
 Default behaviors for the various selection adornment types.
 */
typedef enum : NSUInteger
{
    MCPointSelectionAdornmentBehaviors          = MCSelectionAdornmentAnimatePositionOnSeriesChange | MCSelectionAdornmentAnimateColorOnValueChange | MCSelectionAdornmentAnimateColorOnSeriesChange,
    MCColumnSelectionAdornmentBehaviors         = MCSelectionAdornmentNoAnimation,
    MCDancingColumnSelectionAdornmentBehaviors  = MCSelectionAdornmentAnimatePositionOnDataChange | MCSelectionAdornmentAnimateSizeOnDataChange | MCSelectionAdornmentAnimateColorOnDataChange | MCSelectionAdornmentAnimateGradientOnDataChange,
    MCLaserSelectionAdornmentBehaviors          = MCSelectionAdornmentAnimateColorOnValueChange | MCSelectionAdornmentAnimateColorOnSeriesChange,
    MCBubbleSelectionAdornmentBehaviors         = MCSelectionAdornmentNoAnimation,
    MCColumnUnderlaySelectionAdornmentBehaviors = MCSelectionAdornmentNoAnimation | MCSelectionAdornmentBelowPlot,
} MCSelectionAdornmentDefaultBehaviors;


/*
 Adornment subclasses may respond to one or more of these update methods.
 The MCSelectionAdornment base class looks for implementations of these methods and if they don't exist avoids setting up transaction blocks and invoking them.
 The methods have been selected to correspond with MCSelectionAdornmentBehavior update flags.
 */
@protocol MCSelectionAdornment <NSObject>
@optional
- (void)updatePosition:(CALayer *)adornmentLayer;
- (void)updateSize:(CALayer *)adornmentLayer;
- (void)updateColor:(CALayer *)adornmentLayer;
@end


#pragma mark -
@class MCChartLayer;

@interface MCSelectionAdornment : NSObject <MCSelectionAdornment, CALayerDelegate>

// Designated initializer.
- (id)initWithChartContext:(MCContextRef)chartContext selection:(MCSelection)selection;

- (id)initWithChartContext:(MCContextRef)chartContext;

@property (nonatomic, readonly) MCContextRef chartContext;

/**
 The layer for the adornment.
 */
@property (nonatomic, readonly, strong) CALayer *layer;

- (BOOL)isCorrupt;
/*
 Subclasses must update the properties of their layer for the given event.
 Always invoke super.
 */
- (void)update:(MCSelectionEvents)events;


#pragma mark Responsiveness / Behaviours

- (BOOL)respondsToEvents:(MCSelectionEvents)events;

/**
 Default is YES.
 */
@property (nonatomic, readonly) BOOL respondsToDataChange;

/**
 Default is YES.
 */
@property (nonatomic, readonly) BOOL respondsToSeriesChange;

/**
 Default is YES.
 */
@property (nonatomic, readonly) BOOL respondsToValueIndexChange;

/**
 Default is NO.
 */
@property (nonatomic, readonly) BOOL respondsToTouchPositionChange;

/*
 */
@property (nonatomic, readwrite) MCSelectionAdornmentBehaviors behaviors;


#pragma mark - Public

/**
 Subclasses override to provide an appropriate layer for the adornment.
 This is invoked once when the layer property is first accessed.
 Default returns nil.
 */
- (CALayer *)makeLayer;

@property (nonatomic, readwrite) MCSelection selection;
@end
