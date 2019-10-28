//
//  StoreOptionsWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2017 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import "MemoryTrackerBase.h"

@interface StoreOptionsWrapper : OBJ_WRAPPER_BASE

@property(nonatomic,copy)          NSString*               serviceRoot;
@property(nonatomic,copy)          NSString*               storeName;
@property(nonatomic,copy)          NSString*               storePath;
@property(nonatomic,copy)          NSString*               storeEncryptionKey;
@property(nonatomic,copy)          NSString*               host;
@property(nonatomic,assign)        NSInteger               port;
@property(nonatomic,copy)          NSString*               urlSuffix;
@property(nonatomic,copy)          NSString*               extraStreamParms;
@property(nonatomic,assign)        bool                    enableHttps;
@property(nonatomic,assign)        bool                    enableRepeatableRequests;
@property(nonatomic,assign)        NSInteger               pageSize;
@property(nonatomic,readonly)      NSMutableDictionary*    customHeaders;
@property(nonatomic,readonly)      NSMutableDictionary*    customCookies;
@property(nonatomic,readonly)      NSMutableDictionary*    definingRequests;
@property(nonatomic,assign)        bool                    serverSupportsBind;
@property(nonatomic,assign)        int32_t                 timeout;
@property(nonatomic,assign)        bool                    enableRequestQueueOptimization;
@property(nonatomic,assign)        bool                    enableTransactionBuilder;
@property(nonatomic,assign)        bool                    enableUndoLocalCreation;
@property(nonatomic,assign)        bool                    enableIndividualErrorArchiveDeletion;
@end
