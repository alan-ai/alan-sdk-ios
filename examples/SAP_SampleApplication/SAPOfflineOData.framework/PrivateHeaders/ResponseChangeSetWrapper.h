//
//  ResponseChangeSetWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2017 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import "MemoryTrackerBase.h"

@class ResponseWrapper;

@interface ResponseChangeSetWrapper : OBJ_WRAPPER_BASE

@property NSMutableArray<ResponseWrapper *> * responses;

- (instancetype) init;

- (void) addResponse: (ResponseWrapper *) response;

// Perform the necessary operations to destroy responses that is held by a batch.
- (void) destroyChangeSetResponses;

@end
