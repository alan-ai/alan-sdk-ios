//
//  EntitySetResultWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2017 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import "MemoryTrackerBase.h"

#if __cplusplus

namespace lodata
{
    class EntitySetResult;
}

#endif

@class EntitySetWrapper;
@class EntityTypeWrapper;

@interface EntitySetResultWrapper : OBJ_WRAPPER_BASE

#if __cplusplus

- (instancetype ) initWithCppEntitySetResult: (const lodata::EntitySetResult * ) cppEntitySetResult;

#endif

- (NSMutableArray *) getEntityTypeInstanceList;

- (const EntitySetWrapper *) getEntitySetWrapper;

- (const EntityTypeWrapper *) getEntityTypeWrapper;

- (const NSString *) getNextLink;

- (UInt32) getNumberOfEntityTypeInstance;

- (bool) hasInlinecount;

- (UInt64) getInlinecount;

@end
