LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := ndk
LOCAL_SRC_FILES := ndk.cpp

include $(BUILD_SHARED_LIBRARY)
