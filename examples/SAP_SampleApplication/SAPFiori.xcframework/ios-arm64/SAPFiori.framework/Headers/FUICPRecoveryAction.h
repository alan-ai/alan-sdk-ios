//
//  FUICPRecoveryAction.h
//  CoreParse
//
//  Created by Thomas Davie on 05/02/2012.
//  Copyright (c) 2012 In The Beginning... All rights reserved.
//

#import <Foundation/Foundation.h>

#import "FUICPToken.h"

typedef enum
{
    FUICPRecoveryTypeAddToken    = 0,
    FUICPRecoveryTypeRemoveToken    ,
    FUICPRecoveryTypeBail
} FUICPRecoveryType;

/**
 * Represents an action to take to recover from an error.
 */
@interface FUICPRecoveryAction : NSObject

/**
 * The type of recovery action to take.  May be FUICPRecoveryTypeAddToken or FUICPRecoveryTypeRemoveToken.
 */
@property (readwrite, assign) FUICPRecoveryType recoveryType;

/**
 * The token to insert in the token streem if a FUICPRecoveryTypeAddToken action is taken.
 */
@property (readwrite, retain) FUICPToken *additionalToken;

/**
 * Allocates an initialises a new FUICPRecoveryAction asking the parser to add a new token to the token stream.
 *
 * @param token The token to add to the stream.
 * @return A new recovery action.
 */
+ (id)recoveryActionWithAdditionalToken:(FUICPToken *)token;

/**
 * Allocates an initialises a new FUICPRecoveryAction asking the parser to delete an offending token from the token stream.
 *
 * @return A new recovery action.
 */
+ (id)recoveryActionDeletingCurrentToken;

/**
 * Allocates and initialise a new FUICPRecovery action asking the parser to stop immediately.
 */
+ (id)recoveryActionStop;

/**
 * Initialises a FUICPRecoveryAction asking the parser to add a new token to the token stream.
 *
 * @param token The token to add to the stream.
 * @return An initialised recovery action.
 */
- (id)initWithAdditionalToken:(FUICPToken *)token;

/**
 * Initialises a FUICPRecoveryAction asking the parser to delete an offending token from the token stream.
 *
 * @return An initialised recovery action.
 */
- (id)initWithDeleteAction;

/**
 * Initialises a FUICPRecoveryAction asking the parser to stop immediately.
 */
- (id)initWithStopAction;

@end
