//
//  FUICPLALR1Parser.h
//  CoreParse
//
//  Created by Tom Davie on 05/03/2011.
//  Copyright 2011 In The Beginning... All rights reserved.
//

#import <Foundation/Foundation.h>

#import "FUICPParser.h"

/**
 * The FUICPShiftReduceParser is a further abstract class based on FUICPParser.  This implements the parts of a parser in common between all shift/reduce type parsers.
 *
 * @warning Note that to create a parser you should use one of FUICPShiftReduceParser's subclasses.
 */
@interface FUICPShiftReduceParser : FUICPParser <NSCoding>

@end
