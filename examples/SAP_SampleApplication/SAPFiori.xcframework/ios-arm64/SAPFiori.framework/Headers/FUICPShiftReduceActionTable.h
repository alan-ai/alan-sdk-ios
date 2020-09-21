//
//  FUICPShiftReduceActionTable.h
//  CoreParse
//
//  Created by Tom Davie on 05/03/2011.
//  Copyright 2011 In The Beginning... All rights reserved.
//

#import <Foundation/Foundation.h>

@class FUICPShiftReduceAction;

#import "FUICPToken.h"
#import "FUICPGrammar.h"

@interface FUICPShiftReduceActionTable : NSObject <NSCoding>
{}

- (id)initWithCapacity:(NSUInteger)capacity;

- (BOOL)setAction:(FUICPShiftReduceAction *)action forState:(NSUInteger)state name:(NSString *)token;

- (FUICPShiftReduceAction *)actionForState:(NSUInteger)state token:(FUICPToken *)token;
- (NSSet *)acceptableTokenNamesForState:(NSUInteger)state;

- (NSString *)descriptionWithGrammar:(FUICPGrammar *)g;

@end
