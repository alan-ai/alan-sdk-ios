//
//  ResponseWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2017 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import "EnumerationDef.h"
#import "MemoryTrackerBase.h"

#if __cplusplus

namespace lodata
{
    class Response;
}

#endif

@class ComplexTypeResultWrapper;
@class EntitySetResultWrapper;
@class EntityTypeResultWrapper;
@class PropertyResultWrapper;
@class StreamInstanceWrapper;

@interface ResponseWrapper : OBJ_WRAPPER_BASE

#if __cplusplus

- (instancetype) initWithCppResponse:( lodata::Response * ) cppResponse;

#endif

- (const NSString *) getMetadataDocument;

- (ResponseTypeObjC) getResponseType;

- (NSString *) getHeader:(NSString * ) name;

- (const EntitySetResultWrapper *) getEntitySetResultWrapper;

- (const EntityTypeResultWrapper *) getEntityTypeResultWrapper;

- (const StreamInstanceWrapper *) getStreamInstanceWrapper ;

- (const PropertyResultWrapper *) getPropertyResultWrapper ;

- (const ComplexTypeResultWrapper *) getComplexTypeResultWrapper ;

// Return the count in the result of a request with $count option.
// This method is currently not used since HCPOData DataQuery does not support $count yet.
// Just leave it here for future development.
- (UInt64) getCount;

- (int) getStatusCode;

- (bool) hasError;

- (bool) getStoredModification;

- (int) getErrorCode;

- (const NSString *) getErrorMessage;

// Perform the necessary operations to destroy a response that is held by a batch.
- (void) destroyBatchResponse;

@end
