//
//  FUICPWhiteSpaceRecogniser.h
//  CoreParse
//
//  Created by Tom Davie on 12/02/2011.
//  Copyright 2011 In The Beginning... All rights reserved.
//

#import <Foundation/Foundation.h>

#import "FUICPTokenRecogniser.h"

/**
 * The FUICPWhiteSpaceRecogniser class attempts to recognise white space on the input string.
 * 
 * This recogniser produces FUICPWhiteSpaceTokens.
 */
@interface FUICPWhiteSpaceRecogniser : NSObject <FUICPTokenRecogniser>

///---------------------------------------------------------------------------------------
/// @name Creating and Initialising a WhiteSpace Recogniser
///---------------------------------------------------------------------------------------

/**
 * Creates a whitespace recogniser.
 *
 * @return Returns a FUICPWhiteSpaceRecogniser.
 */
+ (id)whiteSpaceRecogniser;

@end
