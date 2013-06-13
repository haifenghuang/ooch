LOCAL_PATH := $(call my-dir)  
include $(CLEAR_VARS)  
LOCAL_LDLIBS := -llog  
LOCAL_MODULE    := ndk_ooch  
LOCAL_SRC_FILES := android_ooch.c ooch/src/Executable_oo.c 
include $(BUILD_SHARED_LIBRARY)  