//
//  ComplexTypeResultWrapper.h
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
    class ComplexTypeResult;
}

#endif

@class ComplexTypeInstanceWrapper;
@class ComplexTypePropertyWrapper;

@interface ComplexTypeResultWrapper : OBJ_WRAPPER_BASE

#if __cplusplus

- (instancetype ) initWithCppComplexTypeResult: (const lodata::ComplexTypeResult * ) cppComplexTypeResult;

#endif

- (const ComplexTypePropertyWrapper *) getComplexTypePropertyWrapper;

- (const ComplexTypeInstanceWrapper *) getComplexTypeInstanceWrapper;

@end
