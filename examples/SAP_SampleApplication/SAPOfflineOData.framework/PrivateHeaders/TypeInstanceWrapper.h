//
//  TypeInstanceWrapper.h
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
    class ArenaAllocator;
    class TypeInstance;
}

#endif

@class ComplexTypeInstanceWrapper;
@class ComplexTypePropertyWrapper;
@class PropertyWrapper;
@class StructuralTypeWrapper;

@interface TypeInstanceWrapper : OBJ_WRAPPER_BASE

#if __cplusplus

- (instancetype ) initWithCppInstance: (const lodata::TypeInstance * ) cppStructureInstance;

#endif

- (NSMutableArray * ) getPropertyWrapperList : (StructuralTypeWrapper * ) structuralTypeWrapper error: (NSError *__autoreleasing*) error;

- (NSMutableArray * ) getComplexPropertyWrapperList : (StructuralTypeWrapper * ) structuralTypeWrapper;

@end

@interface ComplexTypeInstanceAndProperty : OBJ_WRAPPER_BASE

@property const ComplexTypeInstanceWrapper * complexTypeInstanceWrapper;

@property const ComplexTypePropertyWrapper * complexTypePropertyWrapper;

- (instancetype ) init;

@end
