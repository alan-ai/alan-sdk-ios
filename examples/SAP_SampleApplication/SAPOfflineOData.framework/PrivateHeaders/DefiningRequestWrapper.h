//
//  DefiningRequestWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2017 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import "MemoryTrackerBase.h"

@interface DefiningRequestWrapper : OBJ_WRAPPER_BASE

- (instancetype) init:(NSString *) name url:(NSString *) url retrieveStreams:(bool)retrieveStreams;

- (NSString *) getName;
- (NSString *) getUrl;
- (bool) getRetrieveStreams;
@end
