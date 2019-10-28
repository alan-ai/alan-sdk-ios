//
//  AlanButton.h
//  AlanSDK
//
//  Copyright © 2019 Alan AI Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@class AlanConfig;

/**
 AlanButton
 This class provides a view with voice button
 
 Usage:
 
 1. Create AlanButton class as usual UIView
 2. Place AlanButton to some place in your application
 3. AlanButton will handle tap actions to start and stop recording
 */
@interface AlanButton : UIView

/**
 Creates new AlanButton instance

 @param config AlanConfig object for configuration
 @return AlanButton object with given parameters
 */
- (instancetype)initWithConfig:(AlanConfig *)config;

/**
 Plays text via Alan

 @param textString Text to be played
 */
- (void)playText:(NSString *)textString;

/**
 Sends voice synchronized data event

 @param data Data event to be send
 */
- (void)playData:(NSDictionary *)data;

/**
 Set visual state of an application
 
 @param data Data with visual state description
 */
- (void)setVisual:(NSDictionary *)data;

/**
 Calls specific method from Alan Base
 
 @param method Method name
 @param params Method params
 @param callback Callback to handle result
 */
- (void)call:(NSString *)method withParams:(NSDictionary*)params callback:(void(^)(NSError *error, NSString *object))callback;

/**
 * Activate Alan voice button
 */
- (void)activate;

/**
 * Deactivate Alan voice button
 */
- (void)deactivate;

/// Indicator that Alan voice button is activated
@property (readonly) BOOL isActivated;

@end
