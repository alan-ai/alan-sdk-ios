

<a name="KeychainStorage"></a>
# KeychainStorage
------------------
The Keychain Storage component provides secure storage of `Data` types.
See [Keychain Service](https://developer.apple.com/library/content/documentation/Security/Conceptual/keychainServConcepts/01introduction/introduction.html) for more information about Keychain.

**Note:**  This component is only using encryption mechanisms which are available in iOS.

## Usage
### Store Managing

The createStore, openStore and removeStore are class functions. The createStore and openStore functions return a `KeychainStorage` instance. The store instance can use the instance level functions to manipulate the store.
KeychainStorage can use a `Ciphering` protocol complient class which performs the encryption/decryption of the stored data. The default implementation of the `Ciphering` protocol is the `Cipher` class. By default the KeychainStorage doesn't use encyption so you have to pass an implementation of the `Ciphering` protocol to achieve encryption. 

#### Store Creation

The store fails to create if the name is not UTF-8 encoded string or the store already exists. After creation the store is already opened.
If the store is not shared the accessGroup parameter can be nil.

```swift
do {
    let cipher = try Cipher(password: <#password#>, salt: <#salt#>)
    let keychainStorage = try KeychainStorage.createStore(name: <#storeName#>, cipher: cipher, accessGroup: <#accessGroup#>)
} catch  {
    logger.error("An error occurred while creating the store.", error: error)
}
```

#### Opening Store

You must open the store before you can interact with it. The store fails to open if the store doesn't exists.
If the store is not shared the accessGroup parameter can be nil.

```swift
do {
    let keychainStorage = try KeychainStorage.openStore(name: <#storeName#>, cipher: cipher, accessGroup: <#accessGroup#>)
} catch  {
    logger.error("An error occurred while opening the store.", error: error)
}
```

#### Removing Store

Removing `Data` from the store can throw errors if the name is not UTF-8 encoded string or could not remove its stored data.
If the store is not shared the accessGroup parameter can be nil.

```swift
do {
    try KeychainStorage.removeStore(name: <#storeName#>, accessGroup: <#accessGroup#>)
} catch {
    logger.error("An error occurred while removing the store", error: error)
}
```

#### Changing `Cipher` on Store

Changing the `Cipher` on the store will encrypt all data with the new `Cipher`.
The change cipher can throw errors if the data can't encrypt with the new `Cipher`.

```swift
do {
    let cipher = try Cipher(password: <#password#>, salt: <#salt#>)
    let keychainStorage = try KeychainStorage.createStore(name: <#storeName#>, cipher: cipher, accessGroup: <#accessGroup#>)

    let newCipher = try Cipher(password: <#newPassword#>, salt: <#newSalt#>)

    try keychainStorage.changeCipher(to: newCipher)
} catch  {
    logger.error("An error occurred while changing the cipher.", error: error)
}
```

#### Access Group and App Group

The store sharing is based on the Keychain Access Group. The Keychain Access Group can be used via the App Groups.

The App Groups should be configured in the capabilities tab of the target in the Xcode. See [Configure app groups](https://help.apple.com/xcode/mac/current/#/dev8dd3880fe) for more information about configuration of App Groups. The configured App Group should be the same in all app where the content should be shared.

The App Group is the expected string in the KeychainStorage API where Access Group is necessary.

### Manipulating Store
A `KeychainStorage` has many methods to set and retrieve different data.

#### Reading from Store

The data will be decrypted with the `Cipher` of the store instance after reading from the Keychain.
Reading from store returns a `Data` object if successful, nil if the key doesn't exist and throws an error upon failure.

```swift
do {
    let data = try keychainStorage.data(for: key)
} catch {
    logger.error("An error occurred while reading from the store.", error: error)
}
```

#### Putting into Store

The data will be encrypted with the `Cipher` of the store instance.
Putting into store throws an error upon failure.

```swift
do {
    try keychainStorage.put(data: data, for: key)
} catch {
    logger.error("An error occurred while putting into the store.", error: error)
}
```

#### Removing from Store

Removing data from the store throws an error upon failure.

```swift
do {
    try keychainStorage.removeData(for: key)
} catch {
    logger.error("An error occurred while removing from the store.", error: error)
}
```

#### Removing all data from Store

Removing all existing data from the store throws an error upon failure.

```swift
do {
    try keychainStorage.removeAllData()
} catch {
    logger.error("An error occurred while removing all data from the store.", error: error)
}
```

#### Keys of the Store

Collect all keys of the stored data.
Returns a `Set` of `Strings` containing the existing keys in the store

```swift
do {
    let keys = try keychainStorage.keys()
} catch {
    logger.error("An error occurred while get all keys from the store.", error: error)
}
```

### Thread Safety
All instance methods are safe to use from multiple threads.

### DataStoring

The KeychainStorage implements the DataStoring protocol. It provides methods to open the store, as well as for changing the encryption method with a new `Cipher` instance.
Without `Cipher` the data in the store will not be encrypted.

### KeychainStorage component Logger ID
This component uses the following name prefix for logging:
*'SAP.Foundation.KeychainStorage'*
