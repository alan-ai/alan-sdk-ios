//
//  ComplexTypePropertyWrapper.h
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
}

#endif

@class ComplexTypeWrapper;

@interface ComplexTypePropertyWrapper : OBJ_WRAPPER_BASE

#if __cplusplus

- (instancetype) initWithCppComplexTypeProperty: (const lodata::ComplexTypeProperty * ) cppComplexTypeProperty ;

- (const lodata::ComplexTypeProperty *) getComplexTypeProperty;

#endif

- (const ComplexTypeWrapper *) getComplexTypeWrapper;

- (NSString *) getName;

@end
