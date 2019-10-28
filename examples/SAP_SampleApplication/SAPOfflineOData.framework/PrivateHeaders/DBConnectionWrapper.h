//
//  DBConnectionWrapper.h
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

@class DBResultSetWrapper;

@interface DBConnectionWrapper : OBJ_WRAPPER_BASE

#if __cplusplus
- (instancetype) init: (lodata::DBConnection *) cppDBConnection;
#endif

- (void) close;

- (DBResultSetWrapper *) executeQuery: (NSString *) sql
								error: (NSError *__autoreleasing*) error;

- (BOOL) commit: (NSError *__autoreleasing*) error;

- (BOOL) rollback: (NSError *__autoreleasing*) error;

@end
