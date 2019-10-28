//
//  StructuralTypeWrapper.h
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
    class ComplexTypeProperty;
    class StructuralType;
    class Property;
}

#endif

@class ComplexTypePropertyWrapper;

@interface StructuralTypeWrapper : OBJ_WRAPPER_BASE

#if __cplusplus

- (instancetype ) initWithCppStructuralType: (const lodata::StructuralType * ) cppStructuralType ;

- (const lodata::Property * ) getProperty : (NSString * ) propName ;

- (const lodata::ComplexTypeProperty * ) getCppComplexTypeProperty : (NSString * ) complexTypePropName ;

- (const lodata::StructuralType * ) getStructuralType;

#endif

- (NSString * ) getQualifiedName;

- (NSMutableArray *) getPropertyNames;

- (NSMutableArray *) getComplexTypePropertyNames;

- (const ComplexTypePropertyWrapper * ) getComplexTypeProperty: (NSString * ) complexTypePropName;

@end
