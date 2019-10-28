//
//  FUICPLR1Item.h
//  CoreParse
//
//  Created by Tom Davie on 12/03/2011.
//  Copyright 2011 In The Beginning... All rights reserved.
//

#import <Foundation/Foundation.h>

#import "FUICPItem.h"
#import "FUICPGrammarSymbol.h"

@interface FUICPLR1Item : FUICPItem
{}

@property (readonly,retain) FUICPGrammarSymbol *terminal;

+ (id)lr1ItemWithRule:(FUICPRule *)rule position:(NSUInteger)position terminal:(FUICPGrammarSymbol *)terminal;
- (id)initWithRule:(FUICPRule *)rule position:(NSUInteger)position terminal:(FUICPGrammarSymbol *)terminal;

@end

@interface NSObject (FUICPIsLR1Item)

- (BOOL)isLR1Item;

@end
