//
//  ModifiedEntityTypeInstanceWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2017 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import "ModifiedTypeInstanceWrapper.h"

#if __cplusplus

namespace lodata
{
    class ModifiedEntityTypeInstance;
}

#endif

@class ArenaAllocatorWrapper;
@class EntityTypeWrapper;
@class InlineEntitiesInfo;
@class NavigationPropertyWrapper;

@interface ModifiedEntityTypeInstanceWrapper : ModifiedTypeInstanceWrapper

- (instancetype) init: (NSString *) editLink etag: (NSString *) etag entityTypeWrapper: (const EntityTypeWrapper *) entityTypeWrapper allocator: (ArenaAllocatorWrapper *) allocator;

- (void) addDeepInsert: (const NavigationPropertyWrapper *) navProp entity: (ModifiedEntityTypeInstanceWrapper*) entity;

- (void) addBind: (const NavigationPropertyWrapper *) navProp entityID: (NSString *) entityID;

- (void) setEntityID: ( const NSString * ) entityID;

#if __cplusplus
- (lodata::ModifiedEntityTypeInstance *) getModifiedEntityTypeInstance;
#endif

@end
