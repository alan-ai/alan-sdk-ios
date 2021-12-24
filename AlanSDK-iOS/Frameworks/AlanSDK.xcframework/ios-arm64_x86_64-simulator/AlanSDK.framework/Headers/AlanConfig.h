//
//  AlanConfig.h
//  AlanSDK
//
//  Copyright © 2019 Alan AI Inc. All rights reserved.
//  Alan Studio - https://studio.alan.app
//

#import <Foundation/Foundation.h>

/**
 AlanConfig
 Describes parameters which will be provided for AlanButton
 
 Usage:
 
 1. Create AlanConfig with one of listed methods
 2. Create AlanButton with -initWithConfig: and provide created AlanConfig object
 */
@interface AlanConfig: NSObject

/**
 Given project key. Read only
 */
@property (nonatomic, strong, readonly, nonnull) NSString* key;

/**
 Given host. Read only
 */
@property (nonatomic, strong, readonly, nullable) NSString* host;

/**
 Given dialogId. Read only
 */
@property (nonatomic, strong, readonly, nullable) NSString* dialogId;

/**
 Given platform name. Read only
 */
@property (nonatomic, strong, readonly, nullable) NSString* platform;

/**
 Given platform version. Read only
 */
@property (nonatomic, strong, readonly, nullable) NSString* platformVersion;

/**
 Given data object which passed to Alan Studio project. Read only
 */
@property (nonatomic, strong, readonly, nullable) NSDictionary* dataObject;

/**
 Indicates that button is draggable over a screen.
 */
@property (nonatomic, readonly) BOOL isButtonDraggable;


/**
 Creates AlanConfig object with key

 @param key Project key
 @return AlanConfig object
 */
- (nonnull instancetype)initWithKey:(nonnull NSString *)key;

/**
 Creates AlanConfig object with key
 
 @param key Project key
 @param platform Plarform/plugin name
 @param platformVersion Plarform/plugin version
 @return AlanConfig object
 */
- (nonnull instancetype)initWithKey:(nonnull NSString *)key platform:(nullable NSString*)platform platformVersion:(nullable NSString*)platformVersion;

/**
 Creates AlanConfig object with key and data object

 @param key Project key
 @param dataObject Given data object which will be passed to Alan Studio project
 @return AlanConfig object
 */
- (nonnull instancetype)initWithKey:(nonnull NSString *)key dataObject:(nullable NSDictionary *)dataObject;

/**
 Creates AlanConfig object with key and draggable option flag

 @param key Project key
 @param isButtonDraggable Indicates that button is draggable over a screen
 @return AlanConfig object
 */
- (nonnull instancetype)initWithKey:(nonnull NSString *)key isButtonDraggable:(BOOL)isButtonDraggable;

/**
 Creates AlanConfig object with key, draggable option flag and given data

 @param key Project key
 @param isButtonDraggable Indicates that button is draggable over a screen
 @param dataObject Given data object which will be passed to Alan Studio project
 @return AlanConfig object
 */
- (nonnull instancetype)initWithKey:(nonnull NSString *)key isButtonDraggable:(BOOL)isButtonDraggable dataObject:(nullable NSDictionary *)dataObject;

/**
 Creates AlanConfig object with key and host

 @param key Project key
 @param host Host to connect
 @return AlanConfig object
 */
- (nonnull instancetype)initWithKey:(nonnull NSString *)key host:(nullable NSString *)host;

/**
 Creates AlanConfig object with key, host and given data

 @param key Project key
 @param host Host to connect
 @param dataObject Given data object which will be passed to Alan Studio project
 @return AlanConfig object
 */
- (nonnull instancetype)initWithKey:(nonnull NSString *)key host:(nullable NSString *)host dataObject:(nullable NSDictionary *)dataObject;

/**
 Creates AlanConfig object with key, host and given data
 
 @param key Project key
 @param host Host to connect
 @param dataObject Given data object which will be passed to Alan Studio project
 @param platform Plarform/plugin name
 @param platformVersion Plarform/plugin version
 @return AlanConfig object
 */
- (nonnull instancetype)initWithKey:(nonnull NSString *)key host:(nullable NSString *)host dataObject:(nullable NSDictionary *)dataObject platform:(nullable NSString*)platform platformVersion:(nullable NSString*)platformVersion;

/**
 Creates AlanConfig object with key, host, dialogId and given data

 @param key Project key
 @param host Host to connect
 @param dataObject Given data object which will be passed to Alan Studio project
 @param dialogId Dialog Id
 @return AlanConfig object
 */
- (nonnull instancetype)initWithKey:(nonnull NSString *)key host:(nullable NSString *)host dataObject:(nullable NSDictionary *)dataObject dialogId:(nullable NSString *)dialogId;

/**
 Creates AlanConfig object with key, host, dialogId and given data
 
 @param key Project key
 @param host Host to connect
 @param dataObject Given data object which will be passed to Alan Studio project
 @param dialogId Dialog Id
 @param platform Plarform/plugin name
 @param platformVersion Plarform/plugin version
 @return AlanConfig object
 */
- (nonnull instancetype)initWithKey:(nonnull NSString *)key host:(nullable NSString *)host dataObject:(nullable NSDictionary *)dataObject dialogId:(nullable NSString *)dialogId platform:(nullable NSString*)platform platformVersion:(nullable NSString*)platformVersion;

/**
 Creates AlanConfig object with key, host and draggable option flag

 @param key Project key
 @param host Host to connect
 @param isButtonDraggable Indicates that button is draggable over a screen
 @return AlanConfig object
 */
- (nonnull instancetype)initWithKey:(nonnull NSString *)key host:(nullable NSString *)host isButtonDraggable:(BOOL)isButtonDraggable;

/**
 Creates AlanConfig object with key, host, given data and draggable option flag

 @param key Project key
 @param host Host to connect
 @param isButtonDraggable Indicates that button is draggable over a screen
 @param dataObject Given data object which will be passed to Alan Studio project
 @return AlanConfig object
 */
- (nonnull instancetype)initWithKey:(nonnull NSString *)key host:(nullable NSString *)host isButtonDraggable:(BOOL)isButtonDraggable dataObject:(nullable NSDictionary *)dataObject;

@end
