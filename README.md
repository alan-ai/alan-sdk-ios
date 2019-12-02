# Alan iOS SDK

[Alan Platform](https://alan.app/) • [Alan Studio](https://studio.alan.app/register) • [Docs](https://alan.app/docs/intro.html) • [FAQ](https://alan.app/docs/additional/faq.html) •
[Blog](https://alan.app/blog/) • [Twitter](https://twitter.com/alanvoiceai)

[![GitHub release (latest by date)](https://img.shields.io/github/v/release/alan-ai/alan-sdk-ios)](https://github.com/alan-ai/alan-sdk-ios/releases)

Create a voice script for your application in [Alan Studio](https://studio.alan.app/register) and then add it to your app.

## Setup
1. Download Alan iOS SDK framework [here](https://github.com/alan-ai/alan-sdk-ios/releases)
2. Copy framework to your project
3. Add framework to "Embedded Binaries" (General tab for your target)
4. Add framework to "Linked Frameworks and Libraries" (General tab for your target)
5. Add NSMicrophoneUsageDescription key to Info.plist of your application (must be added to microphone access)

## Integrate into Swift
1. Simply import AlanSDK
```swift
import AlanSDK
```
2. Define AlanButton variable
```swift
fileprivate var button: AlanButton!
```
3. Setup AlanButton
```swift
let config = AlanConfig(key: "YOUR_KEY_FROM_ALAN_STUDIO_HERE")
self.button = AlanButton(config: config)
```
4. Layout button the same way as any UIView in your app


## Integrate into Objective C
1. Simply import AlanSDK
```objective-c
@import AlanSDK;
```
2. Define AlanButton variable
```objective-c
@property (nonatomic) AlanButton* button;
```
3. Setup AlanButton in viewDidLoad
```objective-c
AlanConfig* config = [[AlanConfig alloc] initWithKey:@"YOUR_KEY_FROM_ALAN_STUDIO_HERE"];
self.button = [[AlanButton alloc] initWithConfig:config];
```
4. Layout button the same way as any UIView in your app

### AlanConfig

Object that describes parameters which will be provided for AlanButton.

1. Create new AlanConfig instance with given project key:

```
- (instancetype)initWithKey:(NSString *)key;
```

|**Name**  | **Type** | **Description** |
|--|--|--|
| key  | NSString | Project key from Alan Studio |

### AlanButton

This class provides a view with voice button and instance methods to communicate with Alan Studio

#### Create new AlanButton instance with given config object:

```
- (instancetype)initWithConfig:(AlanConfig *)config;
```

|**Name**  | **Type** | **Description** |
|--|--|--|
| config  | AlanConfig | AlanConfig object for configuration which is described above |

#### Play text via Alan:

```
- (void)playText:(NSString *)textString;
```

|**Name**  | **Type** | **Description** |
|--|--|--|
| textString  | NSString | Text to be played |

#### Send voice synchronized data event:

```
- (void)playData:(NSDictionary *)data;
```

|**Name**  | **Type** | **Description** |
|--|--|--|
| data  | NSDictionary | Data event to be send |

#### Set visual state of an application:

```
- (void)setVisual:(NSDictionary *)data;
```

|**Name**  | **Type** | **Description** |
|--|--|--|
| data  | NSDictionary | Data with visual state description |

#### Call a function from Alan Studio:

```
- (void)call:(NSString *)method withParams:(NSDictionary*)params callback:(void(^)(NSError *error, NSString *object))callback;
```

|**Name**  | **Type** | **Description** |
|--|--|--|
| method  | NSString | Function name |
| params  | NSDictionary | Function params |
| callback  | (void(^)(NSError *error, NSString *object)) | Callback to handle result |

#### Handle events from AlanSDK. 
Add observer for notification with name "kAlanSDKEventNotification":



## Links
1. Alan iOS SDK [documentation](https://alan.app/docs/integrations/ios.html#download)
2. Integration info Swift [documentation](https://alan.app/docs/integrations/ios.html#integrate-into-swift)
3. Integration info Objective-C [documentation](https://alan.app/docs/integrations/ios.html#integrate-into-objective-c)

## Other platforms:
* [Native Android](https://github.com/alan-ai/alan-sdk-android)
* [Web](https://github.com/alan-ai/alan-sdk-web)
* [Cordova](https://github.com/alan-ai/alan-sdk-cordova)
* [ReactNative](https://github.com/alan-ai/alan-sdk-reactnative)
* [Flutter](https://pub.dev/packages/alan_voice)

## Have questions?
If you have any questions or if something is missing in the documentation, please [contact us](mailto:support@alan.app), or tweet us [@alanvoiceai](https://twitter.com/alanvoiceai). We love hearing from you!).
