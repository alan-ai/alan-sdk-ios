//
//  FUICPShiftReduceAction.h
//  CoreParse
//
//  Created by Tom Davie on 05/03/2011.
//  Copyright 2011 In The Beginning... All rights reserved.
//

#import <Foundation/Foundation.h>

#import "FUICPRule.h"

#import "FUICPGrammar.h"

@interface FUICPShiftReduceAction : NSObject <NSCoding>

+ (id)shiftAction:(NSUInteger)shiftLocation;
+ (id)reduceAction:(FUICPRule *)reduction;
+ (id)acceptAction;

- (id)initWithShift:(NSUInteger)shiftLocation;
- (id)initWithReductionRule:(FUICPRule *)reduction;

- (BOOL)isShiftAction;
- (BOOL)isReduceAction;
- (BOOL)isAccept;

- (NSUInteger)newState;
- (FUICPRule *)reductionRule;

- (NSString *)descriptionWithGrammar:(FUICPGrammar *)g;

- (BOOL)isEqualToShiftReduceAction:(FUICPShiftReduceAction *)object;

@end

@interface NSObject (FUICPIsShiftReduceAction)

- (BOOL)isShiftReduceAction;

@end
