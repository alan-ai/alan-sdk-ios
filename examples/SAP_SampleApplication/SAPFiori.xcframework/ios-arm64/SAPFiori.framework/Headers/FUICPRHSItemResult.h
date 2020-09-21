//
//  FUICPRHSItemResult.h
//  CoreParse
//
//  Created by Thomas Davie on 23/10/2011.
//  Copyright (c) 2011 In The Beginning... All rights reserved.
//

#import <Foundation/Foundation.h>

#import "FUICPParser.h"

@interface FUICPRHSItemResult : NSObject <FUICPParseResult>

@property (readwrite, retain) NSMutableArray *contents;
@property (readwrite, assign) BOOL shouldCollapse;
@property (readwrite, copy  ) NSSet *tagNames;
@property (readwrite, copy  ) NSDictionary *tagValues;

@end

@interface NSObject (FUICPIsRHSItemResult)

- (BOOL)isRHSItemResult;

@end
