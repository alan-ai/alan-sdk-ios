//
//  MCChartView.h
//  MeLLmoChartKit
//
//  Created by Brett Callaghan on 10/19/11.
//  Copyright (c) 2011 SAP SE. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MCType.h"
#import "MCColorPalettes.h"
#import "MCChartDelegate.h"
#import "MCLayerProtocol.h"
#import "MCChartLayer.h"
#import "MCRangeSlider.h"
#import "MCAxisStyle.h"
#import "MCChartInteractionKind.h"


@class MCChartLayer;
@class MCSlider;
@class MCSelectionManager;
/**
 Base chart view class that supports the interaction between the user and animatable chart layers.
 */
@interface MCChartView_v2 : UIView <MCChartDelegate>
{
@protected
	MCSelectionManager* _selectionManager;
}

@property (nonatomic, readonly, strong) MCSelectionManager* selectionManager;

@property (nonatomic) MCChartInteractionKind interactionKind;
@property (nonatomic, readonly, assign) MCSeriesPalette *seriesPalette;
@property (nonatomic, readonly, assign) uint32_t seriesPaletteCount;

/**
 Use this property rather than the corresponding MCChartLayer property.
 The view needs to be able to set up gesture recognizers, etc appropriate to the chart type.
 */
@property (nonatomic) MCType type;

/**
 Instance of MCChartLayer backing the view.
 */
@property (nonatomic, weak, readonly) MCChartLayer* chartLayer; // n8: this has to be weak or we get TONS of leaks.  I can't explain it.

/**
 When dancing plot layer is used and a new x axis range has been selected, this flag indicates wether the y axis range should adjust to the data within the new range.
 Default is YES.
 */
@property (nonatomic) BOOL yAxisRangeLocked;

/**
 Setting this property to NO will disable the ability to change the selectedSeriesIndex.
 Default is YES.
 Tapping the slider's thumb will change the selected series.
 */
@property (nonatomic) BOOL allowsSeriesSelection;

/**
 Setting this property to YES enables the ability to put the chart in a state in which no series is selected.
 Default is NO.
 When there is no selected series, -[MCChartLayer selectedSeriesIndex] returns -1.
 */
@property (nonatomic) BOOL allowsSeriesDeselection;

/**
 Setting this property changes the default deselected series opacity.
 Default is 35% opacity (0.35f).
 */
@property (nonatomic) CGFloat disabledSeriesAlpha;

/**
 If the last series is selected and allowsSeriesDeselection is set to YES all series are deselected. If allowsSeriesDeselection is set to NO, the first series is selected.
 
 If allowsSeriesSelection is set to NO, this method will not change selection.
 */
- (void)selectNextSeries;

//RMP-7191 - To fix bug in flow for pie not being selected correct index
- (void)selectPieStartValue:(NSUInteger)startValueIndex;

/**
 Steps through the value start selection.
 */
 
- (void)selectNextStartValue;

/**
 Steps through the value end selection.
 */
- (void)selectNextEndValue;

@property (nonatomic) BOOL touchEnabled;

@property (nonatomic) UIEdgeInsets plotFrameEdgeInsets;

/**
 * Sets secondary value axis series. The series indices added here are assigned
 * to the secondary value axis.
 */
- (void)setSecondaryValueAxisSeriesIndices:(unsigned int*)indices count:(unsigned int)count;

/**
 * Sets Waterfall chart sub-total indices. The column indices added here generate
 * a sub-total column at the given index.
 * Note: This is only supported by the Waterfall chart.
 */
- (void)setSubTotalIndices:(unsigned int*)indices count:(unsigned int)count;

- (void)setZoomRangeStartValue:(CGFloat)start endValue:(CGFloat)end adjustYScale:(BOOL)adjustYScale resetYScale:(BOOL)resetYScale animated:(BOOL)animated;

- (void)zoomAndSetSelectedPosition:(MCPoint)position;
- (void)zoomAndSetSelectedPositions:(MCPoint)positionA and:(MCPoint)positionB;

#pragma mark Touch Input

- (void)touchesBegan:(UIGestureRecognizer*)recognizer;
- (void)touchesMoved:(UIGestureRecognizer*)recognizer;
- (void)touchesEnded:(UIGestureRecognizer*)recognizer;
- (void)touchesCancelled:(UIGestureRecognizer*)recognizer;

#pragma mark Slider

/*!
 @brief     Slider used to change the selectedSeriesIndex and selectedValueIndex properties.
 @details   Tapping on the slider's thumb will change the selectedSeriesIndex unless allowsSeriesSelection set to NO. Moving the slider will change the selectedValueIndex. The slider does not have to be in the view's hierarchy.
 */
@property (nonatomic, strong) IBOutlet MCSlider *slider;

/*!
 @brief     Range slider used to pan and zoom the visible area of the chart.
 @details   Moving the slider will change the start and end position of the zoom area. The slider does not have to be in the view's hierarchy.
 */
@property (nonatomic, strong) IBOutlet MCRangeSlider *rangeSlider;

/*!
 @brief     Suggested slider origin based on the chart's plot frame and the slider's thumb image.
 @details   You should invoke this method after adding your slider to the view hierarchy and assigning it to the receiver.
 */
@property (nonatomic, readonly) CGFloat sliderOrigin;

/*!
 @brief     Suggested slider width based on the chart's plot frame and the slider's thumb image.
 @details   You should invoke this method after adding your slider to the view hierarchy and assigning it to the receiver.
 */
@property (nonatomic, readonly) CGFloat sliderWidth;

/*!
 @details Utility method that snaps the selection highlight or slider thumb to the selected position. Mostly used for setup situations, where
 everything is out of sync, and a quick snap is needed.
 */
- (void)snapSelectionPositionToClosestValue;

- (CGPathRef)getSeriesPath:(NSUInteger)series normalized:(BOOL)normalized;

/**
 * Sets the chart data and triggers a sequence of updates to selection and
 * transitions that vary depending on the chart.
 */
- (void)setData:(const void**)data seriesCount:(unsigned int)seriesCount valueCounts:(unsigned int*)valueCounts;
- (void)setData:(void*)dataContext callbacks:(MCDataCallbacks)callbacks;


#pragma mark UIAppearance

/*
 Axis Lines
 */
- (void)setLineThickness:(CGFloat)thickness forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;
- (void)setLineColorValue:(NSUInteger)colorValue forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;
- (void)setGridLineThickness:(CGFloat)thickness forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;
- (void)setGridLineColorValue:(NSUInteger)colorValue forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;
- (void)setGridLinesHidden:(NSNumber *)hidden forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;

/*
 Axis Labels
 */
- (void)setLabelFontSize:(CGFloat)fontSize forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;
- (void)setLabelFontColorValue:(NSUInteger)colorValue forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;
- (void)setLabelShadowEnabled:(NSNumber *)enabled forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;
- (void)setLabelShadowColorValue:(NSUInteger)colorValue forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;
- (void)setLabelShadowRadius:(CGFloat)shadowRadius forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;
- (void)setLabelShadowOffset:(CGSize)shadowOffset forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;
- (void)setLabelAlignment:(NSTextAlignment)textAlignment forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;
- (void)setLabelOffsetFromAxis:(CGFloat)offset forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;
- (void)setLabelsHidden:(NSNumber *)hidden forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;

/*
 Title Labels
 */
- (void)setTitleFontSize:(CGFloat)fontSize forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;
- (void)setTitleFontColorValue:(NSUInteger)colorValue forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;
- (void)setTitleShadowEnabled:(NSNumber *)enabled forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;
- (void)setTitleShadowColorValue:(NSUInteger)colorValue forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;
- (void)setTitleShadowRadius:(CGFloat)shadowRadius forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;
- (void)setTitleShadowOffset:(CGSize)shadowOffset forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;
- (void)setTitleAlignment:(NSTextAlignment)textAlignment forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;
- (void)setTitleOffsetFromAxis:(CGFloat)offset forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;
- (void)setTitleHidden:(NSNumber *)hidden forAxis:(MCAxis)axis UI_APPEARANCE_SELECTOR;

- (void)setExtremaDotsHidden:(NSNumber *)hidden UI_APPEARANCE_SELECTOR;
- (void)setExtremaDotDiameter:(CGFloat)diameter UI_APPEARANCE_SELECTOR;
- (void)setSelectionDotDiameter:(CGFloat)diameter UI_APPEARANCE_SELECTOR;
- (void)setPlotShadowHidden:(NSNumber *)hidden UI_APPEARANCE_SELECTOR;

- (void)setSelectionDotStrokeColor:(NSUInteger)colorValue UI_APPEARANCE_SELECTOR;
- (void)setSelectionDotFillColor:(NSUInteger)colorValue UI_APPEARANCE_SELECTOR;
- (void)setSelectionTouchPositionColor:(NSUInteger)colorValue UI_APPEARANCE_SELECTOR;

-(void)rangeSliderSetLeftValue:(MCFloat)leftValue rightValue:(MCFloat)rightValue animated:(BOOL)animated;
@end
