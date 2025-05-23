Pod::Spec.new do |s|
    
    s.name             = 'AlanSDK-iOS'
    s.version          = '3.15.0'
    s.summary          = 'Conversational Voice AI Platform.'
    s.description      = <<-DESC
    The Alan Voice AI Platform provides a framework for fast and easy development and deployment of voice experiences for your applications.
    Alan adds voice to any application, on any platform.
    DESC
    
    s.homepage         = 'https://github.com/alan-ai/alan-sdk-ios'
    s.source           = { :git => 'https://github.com/alan-ai/alan-sdk-ios.git', :tag => s.version }
    s.author           = { 'Alan AI, Inc' => 'developer@alan.app' }
    s.license          = { :type => 'MIT', :file => 'LICENSE' }
    s.social_media_url = 'https://twitter.com/alanvoiceai'
    
    s.frameworks = 'UIKit', 'CoreVideo', 'CoreMedia', 'CoreImage', 'CoreImage', 'CoreAudio', 'AVFoundation', 'AudioToolbox', 'VideoToolbox', 'Accelerate', 'MediaPlayer'
    
    s.ios.deployment_target = '15.0'
    s.ios.vendored_frameworks = 'AlanSDK-iOS/Frameworks/AlanSDK.xcframework'
    
end
