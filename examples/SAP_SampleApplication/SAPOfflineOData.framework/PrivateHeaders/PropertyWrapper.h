//
//  PropertyWrapper.h
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

@interface PropertyWrapper : OBJ_WRAPPER_BASE

@property NSString * propertyName;

@property int32_t id;

@property EdmTypeObjC type;

@property bool booleanValue;

@property uint8_t uByteValue;

@property int8_t byteValue;

@property double doubleValue;

@property float floatValue;

@property NSData * guidValue;

@property int8_t int8Value;

@property int16_t int16Value;

@property int32_t int32Value;

@property int64_t int64Value;

@property NSString * stringValue;

@property bool isNull;

@property bool isNullable;

@property int32_t scale;

@property NSData * binaryValue;

@property NSNumber * singleValue;

@property NSString * timeValue;

@end
