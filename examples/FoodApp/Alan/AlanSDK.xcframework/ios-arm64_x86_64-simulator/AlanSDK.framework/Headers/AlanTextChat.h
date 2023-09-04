//
//  AlanTextChat.h
//  AlanSDK
//
//  Created by Sergey Yuryev on 15.08.2023.
//  Copyright © 2023 Alan AI Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AlanTextChat : NSObject

/**
 Returns text chat enabled flag

 @return YES or NO for enabled flag
 */
- (BOOL)isEnabled;

/**
 Returns text chat audio output enabled flag

 @return YES or NO for enabled flag
 */

- (BOOL)isAudioOutputEnabled;
/**
 Set text chat audio output enabled flag

 @param enabled Audio output enabled flag
 */
- (void)setAudioOutputEnabled:(BOOL)enabled;

@end
