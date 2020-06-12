//
//  AlanSDK.h
//  AlanSDK
//
//  Copyright © 2019 Alan AI Inc. All rights reserved.
//  Alan Studio - https://studio.alan.app
//

#import "AlanConfig.h"
#import "AlanButton.h"
#import "AlanText.h"
#import "AlanHint.h"
#import "AlanLog.h"

/// AlanButton states
typedef NS_ENUM(NSInteger, AlanSDKButtonState) {
    /// Offline
    AlanSDKButtonStateOffline,
    /// Connecting
    AlanSDKButtonStateConnecting,
    /// Online (connected)
    AlanSDKButtonStateOnline,
    /// Idle
    AlanSDKButtonStateIdle,
    /// Listen
    AlanSDKButtonStateListen,
    /// Process
    AlanSDKButtonStateProcess,
    /// Reply
    AlanSDKButtonStateReply,
    /// No mic permission
    AlanSDKButtonStateNoPermission,
};

//! Project version number for AlanSDK.
FOUNDATION_EXPORT double AlanSDKVersionNumber;

//! Project version string for AlanSDK.
FOUNDATION_EXPORT const unsigned char AlanSDKVersionString[];
