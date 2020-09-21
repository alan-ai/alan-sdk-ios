//
//  FUICPItem.h
//  CoreParse
//
//  Created by Tom Davie on 06/03/2011.
//  Copyright 2011 In The Beginning... All rights reserved.
//

#import <Foundation/Foundation.h>

#import "FUICPRule.h"
#import "FUICPGrammarSymbol.h"

@interface FUICPItem : NSObject <NSCopying>
{}

@property (readonly,retain) FUICPRule *rule;
@property (readonly,assign) NSUInteger position;

+ (id)itemWithRule:(FUICPRule *)rule position:(NSUInteger)position;
- (id)initWithRule:(FUICPRule *)rule position:(NSUInteger)position;

- (FUICPGrammarSymbol *)nextSymbol;
- (NSArray *)followingSymbols;

- (id)itemByMovingDotRight;

- (BOOL)isEqualToItem:(FUICPItem *)item;

@end

@interface NSObject (FUICPIsItem)

- (BOOL)isItem;

@end
