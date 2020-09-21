//
//  CommonCryptoWrapper.h
//  SAPFiori
//
//  Copyright © 2016 - 2017 SAP SE or an SAP affiliate company. All rights reserved.
//

#ifndef CommonCryptoWrapper_h
#define CommonCryptoWrapper_h

#import <Foundation/Foundation.h>

@interface SAPFioriCommonCryptoWrapper : NSObject

+ (NSString *) createDerivedPasscode: (NSData*)data withPasscode: (NSString *)passcode;

@end


#endif /* CommonCryptoWrapper_h */
