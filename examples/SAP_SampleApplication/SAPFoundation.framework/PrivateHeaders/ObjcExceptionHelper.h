//
//  ObjcExceptionHelper.h
//  SAPFoundation
//
//  Copyright © 2018 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE. The information contained herein may be changed
//  without prior notice.
//

#ifndef ObjcExceptionHelper_h
#define ObjcExceptionHelper_h

#endif /* ObjcExceptionHelper_h */

static NSString * const OBJC_EXCEPTION_KEY = @"objc_exception";

@interface ObjcExceptionHelper : NSObject

+ (BOOL)exceptionTry:(void (^)(void))closure error:(NSError **)error;

@end
