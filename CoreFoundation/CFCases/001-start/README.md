
暂时移除了Apple的Foundation.xcodeproj中swift foundation库的代码。主要目的在于研究CoreFoundation的代码，Swift Foundation暂时不需要关注。

In order to compile and debug CoreFoundation separately. A few changes were made to this project: 

```
0. All header includes enclosed within <> are replaced with ""
1. Any thing related to Swift was deleted, including the Swift foundation project, build environment variable DEPLOYMENT_RUNTIME_SWIFT ... 
2. dyld_priv.h file was added to /bootstrap/x86_64-apple-darwin/usr/local/include/mach-o/
3. Macro DECLARE_STATIC_CLASS_REF was commented out
4. Macro TARGET_RT64_BIT was replaced with TARGET_RT_64_BIT
5. _CFThreadRef should be exposed 
6. Add DEPLOYMENT_RUNTIME_SWIFT to code snipets when neccessary
7. Add several keys like "kCFDateFormatterCalendar"... for CFLocaleKeys.c
8. Expose _NSCFXMLBridge to CFXMLInterface.h
9. Delete _mh_dylib_header because it can't be found. 
10. Add "INCLUDE_OBJC" to GCC_PREPROCESSOR_DEFINITIONS to any test targets, like 001-start

```

