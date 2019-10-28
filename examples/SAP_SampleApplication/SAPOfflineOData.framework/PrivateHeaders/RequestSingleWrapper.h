//
//  RequestSingleWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2017 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import "EnumerationDef.h"
#import "MemoryTrackerBase.h"

#if __cplusplus

namespace lodata
{
    class RequestSingle;
}

#endif

@class ArenaAllocatorWrapper;

@interface RequestSingleWrapper : OBJ_WRAPPER_BASE

@property NSString * requestURL;

@property MethodObjC  method;

@property NSObject * payload;

- (instancetype) init;

- (instancetype) initWithUrl:( NSString *) url method:( MethodObjC ) method;

- (void) setUrl:( NSString *) url method:(MethodObjC) method;

- (BOOL) setHeader:(NSString *)name value:(NSString *)value
            error:(NSError *__autoreleasing*) error;

- (void) setPayload:(NSObject * ) payload;

- (ArenaAllocatorWrapper *) getArenaAllocatorWrapper;

#if __cplusplus

- (lodata::RequestSingle * ) getCppRequest;

#endif

- (void ) destory;

@end
