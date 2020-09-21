//
//  FUICPShiftReduceParserProtectedMethods.h
//  CoreParse
//
//  Created by Tom Davie on 06/03/2011.
//  Copyright 2011 In The Beginning... All rights reserved.
//

#import <Foundation/Foundation.h>

#import "FUICPShiftReduceParser.h"

#import "FUICPShiftReduceActionTable.h"
#import "FUICPShiftReduceGotoTable.h"

@interface FUICPShiftReduceParser ()

@property (readwrite,retain) FUICPShiftReduceActionTable *actionTable;
@property (readwrite,retain) FUICPShiftReduceGotoTable *gotoTable;

- (BOOL)constructShiftReduceTables;

@end
