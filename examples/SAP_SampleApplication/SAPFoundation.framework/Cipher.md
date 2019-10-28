

<a name="Cipher"></a>
# Cipher
----------------

Provides an encrypting / decrypting interface for the application.

## Usage

In order to use the Cipher component, you need to have either a password and a salt, or a pre-generated secret key. With these parameters you can instantiate an instance of the Cipher component. After instantiation use the `func encrypt(data:) throws` and `func decrypt(data:) throws` methods to encrypt / decrypt data.

### Initialize with password and salt

```swift
do {
    let cipher = try Cipher(password: <#String#>, salt: <#String#>)
    let originalData = <#Data#>
    let encryptedData = try cipher.encrypt(data: originalData)
    let decryptedData = try cipher.decrypt(data: encryptedData)
    
    assert(originalData == decryptedData)
} catch {
    // TODO: handle errors
}
```

### Initialize with key

```swift
do {
    let cipher = Cipher(key: <#Data#>)
    let originalData = <#Data#>
    let encryptedData = try cipher.encrypt(data: originalData)
    let decryptedData = try cipher.decrypt(data: encryptedData)
    
    assert(originalData == decryptedData)
} catch {
    // TODO: handle errors
}
```
