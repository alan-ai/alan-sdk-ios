//
//  MCAxisStyle.h
//  ChartKit
//
//  Created by Daniel Cascais on 7/19/12.
//  Copyright (c) 2012 SAP SE. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MCRenderContext.h"


@protocol MCAxisStyle <NSObject>

// Axis grid
@property (nonatomic) float lineThickness;
@property (nonatomic) int lineColorValue;
@property (nonatomic) float gridLineThickness;
@property (nonatomic) int gridLineColorValue;
@property (nonatomic) BOOL gridLinesHidden;
@property (nonatomic) BOOL axisLineHidden;

// Axis labels
@property (nonatomic) float labelFontSize;
@property (nonatomic) int labelFontColorValue;
@property (nonatomic) BOOL labelShadowEnabled;
@property (nonatomic) int labelShadowColorValue;
@property (nonatomic) float labelShadowRadius;
@property (nonatomic) float labelShadowOffsetX;
@property (nonatomic) float labelShadowOffsetY;
@property (nonatomic) MCFontAlignment labelAlignment;
@property (nonatomic) float labelOffsetFromAxis;
@property (nonatomic) BOOL labelsHidden;

@property (nonatomic) float titleFontSize;
@property (nonatomic) int titleFontColorValue;
@property (nonatomic) BOOL titleShadowEnabled;
@property (nonatomic) int titleShadowColorValue;
@property (nonatomic) float titleShadowRadius;
@property (nonatomic) float titleShadowOffsetX;
@property (nonatomic) float titleShadowOffsetY;
@property (nonatomic) MCFontAlignment titleAlignment;
@property (nonatomic) float titleOffsetFromAxis;
@property (nonatomic) BOOL titleHidden;

@end


@interface MCAxisStyle : NSObject <MCAxisStyle>
- (id)initWithAxisProperties:(MCAxisProperties *)properties;
@end
