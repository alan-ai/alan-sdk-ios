//
//  CommonCrypto.h
//  SAPFoundation
//
//  Copyright © 2018 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE. The information contained herein may be changed
//  without prior notice.
//

#ifndef CommonCrypto_h
#define CommonCrypto_h

#import <Foundation/Foundation.h>

extern const NSErrorDomain _Nonnull CommonCryptoDomain;
extern const NSErrorDomain _Nonnull CommonCryptoUtilityDomain;
extern const NSErrorDomain _Nonnull CipherDomain;

typedef NS_ENUM(uint32_t, PseudoRandomAlgorithm) {
    algorithmSha256 = 3, // kCCPRFHmacAlgSHA256
    algorithmSha512 = 5  // kCCPRFHmacAlgSHA512
};

typedef NS_ENUM(int, DataIntegrityHashSize) {
    hashSha256 = 32, // CC_SHA256_DIGEST_LENGTH
    hashSha512 = 64  // CC_SHA512_DIGEST_LENGTH
};


@interface CommonCrypto : NSObject

+ (NSData* _Nonnull) keyDerivationPBKDFWithPassword:(NSString* _Nonnull)password salt:(NSString* _Nonnull)salt pseudoRandomAlgorithm:(PseudoRandomAlgorithm)pseudoRandomAlgorithm rounds:(uint)rounds length:(int)length error:(NSError* _Nullable __autoreleasing * _Nullable)error __attribute__((swift_error(nonnull_error)));

+ (NSData* _Nonnull) encryptData:(NSData* _Nonnull)data key:(NSData* _Nonnull)key initializationVector:(NSData* _Nonnull)initializationVector error:(NSError* _Nullable __autoreleasing * _Nullable)error __attribute__((swift_error(nonnull_error)));

+ (NSData* _Nonnull) decryptData:(NSData* _Nonnull)data key:(NSData* _Nonnull)key initializationVector:(NSData* _Nonnull)initializationVector error:(NSError* _Nullable __autoreleasing * _Nullable)error __attribute__((swift_error(nonnull_error)));

+ (NSData* _Nonnull) encryptData:(NSData* _Nonnull)data key:(NSData* _Nonnull)key integrityHashSize:(DataIntegrityHashSize)integrityHashSize error:(NSError* _Nullable __autoreleasing * _Nullable)error __attribute__((swift_error(nonnull_error)));

+ (NSData* _Nonnull) decryptData:(NSData* _Nonnull)data key:(NSData* _Nonnull)key integrityHashSize:(DataIntegrityHashSize)integrityHashSize error:(NSError* _Nullable __autoreleasing * _Nullable)error __attribute__((swift_error(nonnull_error)));

+ (NSData* _Nonnull) sha256FromData:(NSData* _Nonnull)data;

+ (NSData* _Nonnull) sha512FromData:(NSData* _Nonnull)data;

@end

#endif /* CommonCrypto_h */
