//
//  AlanSDK.h
//  AlanSDK
//
//  Copyright © 2019 Alan AI Inc. All rights reserved.
//

#import "AlanConfig.h"
#import "AlanButton.h"
#import "AlanText.h"
#import "AlanHint.h"
#import "AlanLog.h"

/// AlanButton states
typedef NS_ENUM(NSInteger, AlanSDKButtonState) {
    AlanSDKButtonStateOffline,
    AlanSDKButtonStateConnecting,
    AlanSDKButtonStateOnline,
    AlanSDKButtonStateIdle,
    AlanSDKButtonStateListen,
    AlanSDKButtonStateProcess,
    AlanSDKButtonStateReply,
    AlanSDKButtonStateNoPermission,
};

//! Project version number for AlanSDK.
FOUNDATION_EXPORT double AlanSDKVersionNumber;

//! Project version string for AlanSDK.
FOUNDATION_EXPORT const unsigned char AlanSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <AlanSDK/PublicHeader.h>


