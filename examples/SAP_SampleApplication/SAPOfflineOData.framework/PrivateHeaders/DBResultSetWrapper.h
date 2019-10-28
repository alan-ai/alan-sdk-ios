//
//  DBResultSetWrapper.h
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
    class DBConnection;
}

#endif

@interface DBResultSetWrapper : OBJ_WRAPPER_BASE

#if __cplusplus
- (instancetype) init: (NSString *) sql
			   withConnection: (lodata::DBConnection *) cppDBConnection;
#endif

- (bool) next;

- (void) close;

- (int32_t) getInt32: (NSInteger) columnIndex;

- (int64_t) getInt64: (NSInteger) columnIndex;

- (NSString *) getString: (NSInteger) columnIndex;

- (bool) isNull: (NSInteger) columnIndex;

@end
