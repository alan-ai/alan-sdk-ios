//
//  MCChartDelegate.h
//  ChartKit
//
//  Created by Daniel Cascais on 2/24/12.
//  Copyright (c) 2012 SAP SE. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MCChartLayer;

@protocol MCChartDelegate <NSObject>

@optional

- (void) selectedSeriesIndexWillChange;
- (void) selectedSeriesIndexDidChange;

- (void) selectedValueIndexWillChange;
- (void) selectedValueIndexDidChange;

- (void) selectedValuePositionWillChange;
- (void) selectedValuePositionDidChange;

- (void) secondarySelectedValueIndexWillChange;
- (void) secondarySelectedValueIndexDidChange;

- (void) secondarySelectedValuePositionWillChange;
- (void) secondarySelectedValuePositionDidChange;

- (void) dataWillChange;
- (void) dataDidChange;

- (int) colorValueForSelectionIndex:(int)index;
- (int) colorValueForSecondarySelectionIndex:(int)index;
@end
