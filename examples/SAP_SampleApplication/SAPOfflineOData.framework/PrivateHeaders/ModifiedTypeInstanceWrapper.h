//
//  ModifiedTypeInstanceWrapper.h
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

@class ArenaAllocatorWrapper;
@class ComplexTypePropertyWrapper;
@class ModifiedComplexTypeInstanceWrapper;
@class PropertyWrapper;
@class StructuralTypeWrapper;

@interface ModifiedTypeInstanceWrapper : OBJ_WRAPPER_BASE

#if __cplusplus

- (instancetype ) initWithCppInstance: (lodata::TypeInstance * ) cppeInstance structuralType: (const StructuralTypeWrapper *) structuralType allocator: (ArenaAllocatorWrapper *) allocator;

#endif

- (BOOL) setPropertyValue: (const PropertyWrapper *) propValue error:(NSError *__autoreleasing*) error;

- (void) setComplexPropertyValue: (const ComplexTypePropertyWrapper *) complexTypePropertyWrapper complexTypeInstanceWrapper: (ModifiedComplexTypeInstanceWrapper *) complexTypeInstanceWrapper;

@end
