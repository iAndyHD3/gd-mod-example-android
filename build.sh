LUSR=$(whoami)
NDK=/home/${LUSR}/path/to/your/android-ndk-r16b/path
SRC=$PWD

$NDK/ndk-build NDK_PROJECT_PATH=$SRC NDK_APPLICATION_MK=$SRC/jni/Application.mk MAIN_LOCAL_PATH=$SRC/jni
