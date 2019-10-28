//
//  EntityTypeResultWrapper.h
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
    class EntityTypeResult;
}

#endif

@class EntitySetWrapper;
@class EntityTypeWrapper;
@class EntityTypeInstanceWrapper;

@interface EntityTypeResultWrapper : OBJ_WRAPPER_BASE

#if __cplusplus

- (instancetype ) initWithCppEntityTypeResult:(const lodata::EntityTypeResult * ) cppEntityTypeResult;

#endif

- (const EntityTypeWrapper *) getEntityTypeWrapper;

- (const EntitySetWrapper *) getEntitySetWrapper;

- (const EntityTypeInstanceWrapper *) getEntityTypeInstanceWrapper;

@end
