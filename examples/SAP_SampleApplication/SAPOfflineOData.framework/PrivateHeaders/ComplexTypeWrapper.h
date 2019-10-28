//
//  ComplexTypeWrapper.h
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
    class ComplexType;
}

#endif

@interface ComplexTypeWrapper : StructuralTypeWrapper

#if __cplusplus

- (instancetype) initWithCppComplexType: (const lodata::ComplexType * ) cppComplexType;

- (const lodata::ComplexType *) getComplexType;

#endif

@end
