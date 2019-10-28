//
//  StoreWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2017 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import "MemoryTrackerBase.h"

//The following two line plus the line at end of interaface for ignoring warnings during build.

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability-completeness"

#if __cplusplus

namespace lodata
{
    class Store;
}

#endif

@class ComplexTypeWrapper;
@class EntityTypeWrapper;
@class OfflineODataAtomicBool;
@class OfflineODataDelegateInternal;
@class OfflineODataLoggerInternal;
@class ResponseBatchWrapper;
@class ResponseWrapper;
@class RequestBatchWrapper;
@class RequestSingleWrapper;
@class StoreOptionsWrapper;
@class StreamWriterWrapper;

@interface StoreWrapper : OBJ_WRAPPER_BASE

@property (readonly) OfflineODataDelegateInternal* delegate;
@property (readonly) OfflineODataLoggerInternal* logger;

#if __cplusplus

- (instancetype) initWithCppStore:(lodata::Store * ) cppStore;

#endif

- (BOOL) openStore: (StoreOptionsWrapper *) storeOpts
                    withParams: (NSString*) params
                    delegate: (OfflineODataDelegateInternal*) delegate
                    logger: (OfflineODataLoggerInternal*) logger
					isCancelled:(OfflineODataAtomicBool *) isCancelled
                    error: (NSError *__autoreleasing*) error;

- (BOOL) refresh:(NSString *) refreshSubset
                mergeStreamParameters:(NSString *) parameters
				isCancelled:(OfflineODataAtomicBool *) isCancelled
                error:(NSError *__autoreleasing*) error;

- (BOOL) getRequestQueueIsEmpty:(NSError *__autoreleasing*) error NS_SWIFT_NOTHROW;

- (BOOL) getHasPendingRefresh:(NSError *__autoreleasing*) error NS_SWIFT_NOTHROW;

- (BOOL) getHasPendingFlush:(NSError *__autoreleasing*) error NS_SWIFT_NOTHROW;

- (BOOL) close:(NSError *__autoreleasing*) error;

- (ResponseWrapper *) executeRequest:(RequestSingleWrapper *) requestWrapper
                        error:(NSError *__autoreleasing*) error;

- (ResponseBatchWrapper *) executeBatchRequest:(RequestBatchWrapper *) requestBatchWrapper
                        error:(NSError *__autoreleasing*) error;

- (const char *) GetServiceRoot;

- (BOOL) flushQueuedRequests:(NSString *) mergeStreamParameters
				 isCancelled:(OfflineODataAtomicBool *) isCancelled
                       error:(NSError *__autoreleasing*) error;

- (BOOL) cancelDownload:(NSError *__autoreleasing*) error;

- (BOOL) cancelUpload:(NSError *__autoreleasing*) error;

- (BOOL) AddDefiningQuery:(const char *) reqName
                    url:(const char *) url
                    retrieveStreams:(BOOL) retrieveStreams
                    error:(NSError *__autoreleasing*) error;

- (BOOL) unregisterStreamRequest:(const char *) registerName
                   error:(NSError *__autoreleasing*) error;

- (NSString *) getEntitySetFromEntityType:(NSString *) entityTypeName
                    error:(NSError *__autoreleasing*) error;

- (const EntityTypeWrapper *) getEntityTypeByName:(NSString *) qualifiedEntityTypeName
											error:(NSError *__autoreleasing*) error;

- (const ComplexTypeWrapper *) getComplexTypeByName:(NSString *) qualifiedComplexTypeName
											  error:(NSError *__autoreleasing*) error;

- (NSString *) getSystemProxyStreamParams:(NSString *) authURL;

- (StreamWriterWrapper *) createStreamWriter: (RequestSingleWrapper *) request
                    error:(NSError *__autoreleasing*) error;

#if DEBUG
    - (void) setLODataTestCallbacks: (NSInteger (^ _Nonnull)(NSInteger, NSInteger))lodataTestCallback;
	- (void) clearTestCallbacks;
#endif

- (BOOL) pingServer: (NSString *) mergeStreamParameters
			  error:(NSError *__autoreleasing*) error;

- (BOOL) sendStore: (NSString *) mergeStreamParameters
             error: (NSError *__autoreleasing*) error;

- (NSString *) printRequestQueue: (NSError *__autoreleasing*) error;

- (NSString *) printDefiningRequests: (NSError *__autoreleasing*) error;

- (BOOL) undoPendingChanges: (NSString *) editLink
                      error: (NSError *__autoreleasing*) error;
@end
#pragma clang diagnostic pop

