//
//  ManagerWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2017 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import "MemoryTrackerBase.h"

@class StoreOptionsWrapper;
@class StoreWrapper;

@interface ManagerWrapper : OBJ_WRAPPER_BASE

+ (StoreWrapper * ) createStore;

+ (BOOL) removeStore:(StoreOptionsWrapper *) storeOpts
			   error:(NSError *__autoreleasing*) error;

+ (NSString *) getLibraryVersion;

@end
