//
//  MCGraphicslotLayer.h
//  ChartKit
//
//  Created by Daniel Cascais on 7/26/12.
//  Copyright (c) 2012 SAP SE. All rights reserved.
//

#import "MCPlotLayer.h"

@interface MCGraphicsPlotLayer : MCPlotLayer
/*
 This flag will aid the rendering Z layout for the columns and lines in the combo
 chart, making sure the selection adornment for the column is underneath the lines.
 */
@property (nonatomic, assign) BOOL isRenderingComboLines;
@property (nonatomic, assign) BOOL isUsingSwiftWrapper;
@property (nonatomic, assign) BOOL isRangeHighlight;
@end
