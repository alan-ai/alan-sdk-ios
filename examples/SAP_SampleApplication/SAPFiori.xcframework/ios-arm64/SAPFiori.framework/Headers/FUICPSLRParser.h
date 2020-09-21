//
//  FUICPSLRParser.h
//  CoreParse
//
//  Created by Tom Davie on 06/03/2011.
//  Copyright 2011 In The Beginning... All rights reserved.
//

#import <Foundation/Foundation.h>

#import "FUICPShiftReduceParser.h"

/**
 * The FUICPSLRParser class is a concrete implementation of FUICPParser based on the simple left-to-right parsing method.
 * 
 * The SLR parser is the fastest parser type available in CoreParse, but covers the smallest set of grammars.
 */
@interface FUICPSLRParser : FUICPShiftReduceParser

@end
