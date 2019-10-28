//
//  NUIStyleSheet.h
//  ParseTest
//
//  Created by Tony Mann on 1/14/14.
//  Copyright (c) 2014 Tom Benner. All rights reserved.
//

#import "FUICPParser.h"


@interface NUIStyleSheet : NSObject <FUICPParseResult>

@property NSArray *ruleSets;
@property NSArray *definitions;

@end
