//
//  EntityTypeInstanceWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2017 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import "TypeInstanceWrapper.h"

#if __cplusplus

namespace lodata
{
    class EntityTypeInstance;
    class EntityType;
    class ArenaAllocator;
    class ModifiedEntityTypeInstance;
}

#endif

@class EntityTypeWrapper;
@class InlineEntitiesInfo;

@interface EntityTypeInstanceWrapper : TypeInstanceWrapper

#if __cplusplus

- (instancetype ) initWithCppEntityInstance:( const lodata::EntityTypeInstance * ) cppEntityTypeInstance;

#endif

- (InlineEntitiesInfo* ) getInlineEntities: (EntityTypeWrapper * ) entityTypeWrapper navPropName : ( NSString * ) propertyName;

-(NSString * ) getMediaContentType;

-(NSString * ) getMediaETag;

-(NSString * ) getMediaEditLink;

-(NSString * ) getMediaReadLink;

-(NSString * ) getServerMediaReadLink;

-(NSString * ) getServerMediaEditLink;

-(bool) getIsLocal;

-(bool) getHasPendingChanges;

-(bool) getHasRelativesWithPendingChangesIsSet;

-(bool) getHasRelativesWithPendingChanges;

-(bool) getHasLocalRelativesIsSet;

-(bool) getHasLocalRelatives;

-(bool) getInErrorState;

-(bool) getIsDeleteError;

-(bool) getMediaStreamIsOffline;

-(NSString *) getEditLink;

-(NSString *) getReadLink;

-(NSString *) getEntityID;

-(NSString *) getETag;

@end

@interface InlineEntitiesInfo : OBJ_WRAPPER_BASE

@property Boolean isMultiple;

@property NSMutableArray* multiEntities;

@property EntityTypeInstanceWrapper * singleEntity;

- (instancetype ) init;

@end
