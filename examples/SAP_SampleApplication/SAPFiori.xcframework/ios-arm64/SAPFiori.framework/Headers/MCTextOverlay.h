//
//  MCTextOverlay.h
//  ChartKit
//
//  Created by Daniel Cascais on 10/18/11.
//  Copyright (c) 2011 SAP SE. All rights reserved.
//

//------------------------------------------------------------------------------
//
// Imports/Includes
//
//------------------------------------------------------------------------------

#import <QuartzCore/QuartzCore.h>

#import "MCContext.h"
#import "MCRenderContext.h"
#import "MCTextLayoutBitMask.h"
#import "MCColorUtil.h"

//------------------------------------------------------------------------------
//
// Declaration
//
//------------------------------------------------------------------------------

@interface MCTextOverlay : NSObject <CALayerDelegate>
{
    //
    // TextLayers
    //
    CATextLayer *_valueAxisTitleTextLayer;
    CATextLayer *_secondaryValueAxisTitleTextLayer;
    CATextLayer *_categoryAxisTitleTextLayer;
    
    // Array of CATextLayer
    NSMutableArray *_valueAxisTextLayers;
    // Array of CATextLayer
    NSMutableArray *_secondaryValueAxisTextLayers;
    // Array of CATextLayer
    NSMutableArray *_categoryAxisTextLayers;
    
    CATextLayer *_titleTextLayer;
    CATextLayer *_subTitleTextLayer;
    CATextLayer *_valueTextLayer;
    CATextLayer *_subValueTextLayer;
    
    CATextLayer *_dualAxisLeftMagnitudeTextLayer;
    CATextLayer *_dualAxisRightMagnitudeTextLayer;
    
    //
    // Hidden
    //
    BOOL _valueAxisTitleHidden;
    BOOL _secondaryValueAxisTitleHidden;
    BOOL _categoryAxisTitleHidden;
    
    BOOL _valueAxisLabelsHidden;
    BOOL _secondaryValueAxisLabelsHidden;
    BOOL _categoryAxisLabelsHidden;
    
    BOOL _titleHidden;
    BOOL _subTitleHidden;
    BOOL _valueHidden;
    BOOL _subValueHidden;
    
    BOOL _dualAxisLeftRightIndicatorHidden;
    BOOL _dualAxisLeftMagnitudeHidden;
    BOOL _dualAxisRightMagnitudeHidden;
    
    //
    // Colors
    //
    CGColorRef _valueAxisTitleColor;
    CGColorRef _secondaryValueAxisTitleColor;
    CGColorRef _categoryAxisTitleColor;
    
    CGColorRef _valueAxisLabelsColor;
    CGColorRef _secondaryValueAxisLabelsColor;
    CGColorRef _categoryAxisLabelsColor;
    
    CGColorRef _titleColor;
    CGColorRef _subTitleColor;
    CGColorRef _valueColor;
    CGColorRef _subValueColor;
    
    CGColorRef _dualAxisLeftIndicatorColor;
    CGColorRef _dualAxisRightIndicatorColor;
    CGColorRef _dualAxisLeftMagnitudeColor;
    CGColorRef _dualAxisRightMagnitudeColor;
    
    CGColorRef _valueAxesGridLineColor;
    CGColorRef _categoryAxisGridLineColor;
    
    //
    // Grid lines
    //
    // Array of CALayer
    NSMutableArray *_valueAxisGridLines;
    // Array of CALayer
    NSMutableArray *_categoryAxisGridLines;
    
    //
    // Etc.
    //
    MCTextBitMask _bitmask;
    
    CALayer *_superLayer;
    CALayer *_topmostLayer;
    CGFloat _tickLabelFontSize;
    CALayer *_plotLayer;
    
    CALayer *_dualAxisleftRightColorIndicator;
}

@property MCTextBitMask bitmask;
@property (nonatomic, strong) CALayer *plotLayer;
@property (nonatomic, strong) CALayer *valueAxisTitleTextLayer;
@property (nonatomic, strong) CALayer *secondaryValueAxisTitleTextLayer;
@property (nonatomic, strong) CALayer *categoryAxisTitleTextLayer;
@property (nonatomic, strong) CALayer *titleTextLayer;

//
// String
//
@property (nonatomic, strong) NSString *valueAxisTitle;
@property (nonatomic, strong) NSString *secondaryValueAxisTitle;
@property (nonatomic, strong) NSString *categoryAxisTitle;

@property (nonatomic, strong) NSString *valueAxisMagnitudeIndicator;
@property (nonatomic, strong) NSString *secondaryValueAxisMagnitudeIndicator;

// Array of NSString.
@property (nonatomic, strong) NSArray *seriesTitles;
// Array of NSString.
@property (nonatomic, strong) NSArray *categoryAxisLabels;

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *subTitle;
@property (nonatomic, strong) NSString *value;
@property (nonatomic, strong) NSString *subValue;

@property (nonatomic, strong) NSString *dualAxisLeftMagnitude;
@property (nonatomic, strong) NSString *dualAxisRightMagnitude;

//
// Hidden
//
@property (nonatomic) BOOL valueAxisTitleHidden;
@property (nonatomic) BOOL secondaryValueAxisTitleHidden;
@property (nonatomic) BOOL categoryAxisTitleHidden;

@property (nonatomic) BOOL valueAxisMagnitudeIndicatorHidden;
@property (nonatomic) BOOL secondaryValueAxisMagnitudeIndicatorHidden;

@property (nonatomic) BOOL valueAxisLabelsHidden;
@property (nonatomic) BOOL secondaryValueAxisLabelsHidden;
@property (nonatomic) BOOL categoryAxisLabelsHidden;

@property (nonatomic) BOOL titleHidden;
@property (nonatomic) BOOL subTitleHidden;
@property (nonatomic) BOOL valueHidden;
@property (nonatomic) BOOL subValueHidden;

@property (nonatomic) BOOL dualAxisLeftRightIndicatorHidden;
@property (nonatomic) BOOL dualAxisLeftMagnitudeHidden;
@property (nonatomic) BOOL dualAxisRightMagnitudeHidden;

//
// Colors
//
@property (nonatomic) CGColorRef valueAxisTitleColor;
@property (nonatomic) CGColorRef secondaryValueAxisTitleColor;
@property (nonatomic) CGColorRef categoryAxisTitleColor;

@property (nonatomic) CGColorRef valueAxisLabelsColor;
@property (nonatomic) CGColorRef secondaryValueAxisLabelsColor;
@property (nonatomic) CGColorRef categoryAxisLabelsColor;

@property (nonatomic) CGColorRef titleColor;
@property (nonatomic) CGColorRef subTitleColor;
@property (nonatomic) CGColorRef valueColor;
@property (nonatomic) CGColorRef subValueColor;

@property (nonatomic) CGColorRef dualAxisLeftIndicatorColor;
@property (nonatomic) CGColorRef dualAxisRightIndicatorColor;
@property (nonatomic) CGColorRef dualAxisLeftMagnitudeColor;
@property (nonatomic) CGColorRef dualAxisRightMagnitudeColor;

@property (nonatomic) CGColorRef valueAxesGridLineColor;
@property (nonatomic) CGColorRef categoryAxisGridLineColor;

@property MCContextRef chartContext;

//
// Formatter properties
//

@property (nonatomic, strong) NSArray *seriesFormatters;
@property (nonatomic, strong) NSArray *valueFormatters;

@property (nonatomic, strong) NSNumberFormatter* valueAxisTitleFormatter;
@property (nonatomic, strong) NSNumberFormatter* valueAxisLabelFormatter;

@property (nonatomic, strong) NSNumberFormatter* secondaryValueAxisTitleFormatter;
@property (nonatomic, strong) NSNumberFormatter* secondaryValueAxisLabelFormatter;

@property (nonatomic, strong) NSNumberFormatter* categoryAxisTitleFormatter;
@property (nonatomic, strong) NSNumberFormatter* categoryAxisLabelFormatter;

//------------------------------------------------------------------------------
//
// Methods
//
//------------------------------------------------------------------------------

- (id)initWithBitmask:(MCTextBitMask) textBitmask andLayer:(CALayer *) layer;

- (void)createGridLinesFromBitmask;
- (void)createTextFieldsFromBitmask;

- (void)layoutSublayers;

- (void)createValueAxisGridLines;
- (void)createCategoryAxisGridLines;

- (void)createValueAxisLabels;

- (void)createSecondaryValueAxisLabels;

- (void)createCategoryAxisLabels;

- (void)createMagnitudeIndicatorsAndAxisLabelFormatters;
- (NSString *) getMagnitudeIndicatorAndScaleFromValue:(double_t)value isPercent:(BOOL)isPercent scale:(double *)scale;
- (NSString *)abbreviatedStringFromDouble:(double_t)num includeSuffix:(BOOL)useSuffix withFormatter:(NSNumberFormatter *)formatter;
- (void)layoutForSmallChart:(int)fontSize;
@end
