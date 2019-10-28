//
//  AlanLog.h
//  AlanSDK
//
//  Copyright © 2019 Alan AI Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AlanLog : NSObject

/**
 * Enable Alan debug mode logging
 */
+ (void)setEnableLogging:(BOOL)flag;

/**
* Check Alan debug mode logging
*/
+ (BOOL)isEnableLogging;

@end

