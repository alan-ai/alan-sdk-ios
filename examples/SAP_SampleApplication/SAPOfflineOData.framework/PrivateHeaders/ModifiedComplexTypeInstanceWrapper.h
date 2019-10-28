//
//  ModifiedComplexTypeInstanceWrapper.h
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
    class ComplexTypeInstance;
}

#endif

@class ArenaAllocatorWrapper;
@class ComplexTypeWrapper;

@interface ModifiedComplexTypeInstanceWrapper : ModifiedTypeInstanceWrapper

- (instancetype) init: (const ComplexTypeWrapper *) complexTypeWrapper allocator: (ArenaAllocatorWrapper *) allocator;

#if __cplusplus
- (lodata::ComplexTypeInstance *) getComplexTypeInstance;
#endif

@end
