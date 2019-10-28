//
//  UtilityFunctionsWrapper.h
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
    class Property;
    class Value;
}

#endif

@class EntitySetWrapper;
@class EntityTypeWrapper;
@class NavigationPropertyWrapper;
@class PropertyWrapper;

__attribute__((visibility("default"))) @interface UtilityFunctionsWrapper : OBJ_WRAPPER_BASE

+ (const EntitySetWrapper * ) getNextEntitySetWrapper : (const EntitySetWrapper * )currentSetWrapper
                                            navPropWrapper : (const NavigationPropertyWrapper *) navPropWrapper;

+ (const EntityTypeWrapper * ) getEntityTypeWrapper : (const EntitySetWrapper * ) currentSetWrapper
                                            navPropWrapper : (const NavigationPropertyWrapper *) navPropWrapper;

+ (NSString *) getRequestStatusIDString: (int) id;

+ (NSString *) getRequestTypeString: (int) id;

#if __cplusplus

+ (const PropertyWrapper *) convertToPropertyWrapper : ( const lodata::Property * ) prop value:( const lodata::Value * ) value;

#endif

@end
