//
//  FUICPLR1Parser.h
//  CoreParse
//
//  Created by Tom Davie on 12/03/2011.
//  Copyright 2011 In The Beginning... All rights reserved.
//

#import <Foundation/Foundation.h>

#import "FUICPShiftReduceParser.h"

/**
 * The FUICPLR1Parser class is a concrete implementation of FUICPParser based on the left-to-right parsing method with a one symbol lookahead.
 * 
 * The LR1 parser is the slowest parser type available in CoreParse, but covers the largest set of grammars.  LR1 parsers may consume significant amounts of memory.
 */
@interface FUICPLR1Parser : FUICPShiftReduceParser

@end
