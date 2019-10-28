//
//  EntityTypeWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2017 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import "StructuralTypeWrapper.h"

#if __cplusplus

namespace lodata
{
    class EntityType;
    class NavigationProperty;
}

#endif

@class NavigationPropertyWrapper;

@interface EntityTypeWrapper : StructuralTypeWrapper

#if __cplusplus

- (instancetype ) initWithCppEntityType: (const lodata::EntityType * ) cppEntityType;

- (const lodata::NavigationProperty * ) getNavigationProperty: (NSString * ) navPropName;

- (const lodata::EntityType * ) getEntityType;

#endif

- (NSMutableArray<NavigationPropertyWrapper *> * ) getNavigationProperties;

- (const NavigationPropertyWrapper * ) getNavigationPropertyWrapper: (NSString * ) navPropName;

@end
