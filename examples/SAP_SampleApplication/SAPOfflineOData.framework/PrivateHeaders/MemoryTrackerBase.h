//
//  MemoryTrackerBase.h
//  SAPOfflineOData
//
//  Copyright © 2017 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import <Foundation/Foundation.h>

#if DEBUG
/// This is for tracking if there is any memory leak from Objective C/Swfit API side.
/// This should be invisible for release build.
@interface MemoryTrackerBase : NSObject

- (instancetype) init;

@end

#define OBJ_WRAPPER_BASE MemoryTrackerBase

#else

#define OBJ_WRAPPER_BASE NSObject

#endif
