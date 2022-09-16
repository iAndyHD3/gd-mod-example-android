# gd-mod-example-android
Basic Geometry Dash android mod example meant for beginners or as a template.
A port of [gd-mod-example](https://github.com/matcool/gd-mod-example) for Android featuring a new modloader.
<p align="center">
<img src="https://user-images.githubusercontent.com/54410739/190515541-d97087fc-6a75-467a-8809-c7af67bf98f0.png" alt="screenshot" width="48%">
<img src="https://user-images.githubusercontent.com/54410739/190515615-9eae44bf-359b-4c4f-a8df-65edde3f8184.png" alt="screenshot" width="48%">
</p>

## Usage
### Build

- Clone the repo

- To build this project you will need the version r16b of the Native Development Kit for Android.

[Windows 32-bit](https://dl.google.com/android/repository/android-ndk-r16b-windows-x86.zip)
[Windows 64-bit](https://dl.google.com/android/repository/android-ndk-r16b-windows-x86_64.zip)

- Edit the paths inside Build.bat and run it
- The compiled files should be in gd-mod-example-android/libs/armeabi-v7a

### Inject the shared libraries into the APK
To make the mod work we need to edit the java source code of the APK to load the compiled .so files

- Have a Geometry Dash APK ready
- Get an APK Editor that supports **smali**

There are many APK Edit tools available, personally I recommend [APK Editor Studio](https://qwertycube.com/apk-editor-studio/download/)

- Decompile the APK with **smali**

To enable smali on APK Editor Studio:
Settings -> Options (CTRL + P) -> Apktool -> Decompile source code (smali)

- Open the contents of the APK
- Go to this path`/smali/com/robtopx/geometryjump`
and open `GeometryJump.smali`


- Copy + Paste this code 3 times
- Change the string to match our .so file names.
Note: names are without `lib` and without `.so`

```smali
    .line 70
    const-string v0, "cocos2dcpp"

    invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V
```

 In the Geometry dash 2.11 APK the method should look like this

```smali
# direct methods
.method static constructor <clinit>()V
    .locals 1

    .prologue
    .line 69
    const-string v0, "fmod"

    invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V

    .line 70
    const-string v0, "cocos2dcpp"

    invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V

    .line 70
    const-string v0, "dobby"

    invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V

    .line 70
    const-string v0, "hooking"

    invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V

    .line 70
    const-string v0, "game"

    invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V

    .line 85
    return-void
.end method
```
- Last, move the .so files to the `/lib/armeabi-v7a` folder
- Compile the APK and if sign it manually if necessary
(APK Editor Sutdio signs it for you)
- Install APK


---
After this one-time setup you only need to update the `libgame.so` file inside the `lib/armeabi-v7a/` folder.

All the source files contain a lot of comments which you should definitely read if you're just starting out :) (i recommend starting from main.cpp

## Resources
- [Ghidra](https://ghidra-sre.org/) - A free reverse engineering tool, which is almost mandatory for GD modding
- [GD Programming](https://discord.gg/jEwtDBK) - A discord server where you can ask a lot of questions :D
- [Awesome ADB](https://github.com/mzlogin/awesome-adb/blob/master/README.en.md) - Everything there's to know about how to use ADB to speed up development
- [ADB Logcat](https://developer.android.com/studio/command-line/logcat) - Powerful ADB command to print debug messages to console or to obtain crash logs
- [cocos2dx](https://hjfod.github.io/cocos-headers) - Documentation for the version of cocos robtop uses as a base (with robtop modifications documented)

## Credits
- [Italian APK Downloader](https://github.com/ItalianApkDownloader/) General help, modloader, project setup, gd.h
-  [mat](https://github.com/matcool/) - Original mod idea, example code, explanations