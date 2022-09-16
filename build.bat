@echo off

REM edit paths here, important: \ at the end

set NDK=C:\Users\user\example\path\android-ndk-r16b\

set MAIN=C:\Users\user\example\path\gd-mod-example-android\

call %NDK%ndk-build.cmd NDK_PROJECT_PATH=%MAIN% NDK_APPLICATION_MK=%MAIN%jni\Application.mk MAIN_LOCAL_PATH=%MAIN%jni
pause