APP_CFLAGS := -fPIC -shared -fexceptions
APP_PLATFORM := android-17
APP_STL:= gnustl_static
APP_CPPFLAGS += -std=c++14 -fexceptions
LOCAL_CPP_FEATURES := rtti
NDK_TOOLCHAIN_VERSION := clang
LOCAL_CPPFLAGS := -fexceptions

#armeabi-v7a / arm64-v8a
#arm64 will only work with the 2.2 binary, robtop did not compile 2.11 for arm64
APP_ABI := armeabi-v7a
