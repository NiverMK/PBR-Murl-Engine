
include $(MURL_MODULE_EXECUTABLE_BEGIN)
include $(MURL_MODULE_EXECUTABLE_DEFAULTS)

# ==== Compiler flags ====
MURL_MODULE_CPP_FLAGS += -std=c++11

# ==== Output path and file ====
MURL_MODULE_BIN_PATH := binaries/$(MURL_PLATFORM)/$(MURL_BUILD)/$(MURL_CPU)
MURL_MODULE_BIN_FILE := pbr_project
MURL_MODULE_BIN_NAME := PbrProject

# ==== Source files ====
MURL_MODULE_SRC_PATH := source

MURL_MODULE_SRC_FILES += pbr_project.cpp
MURL_MODULE_SRC_FILES += pbr_project_logic.cpp
MURL_MODULE_SRC_FILES += pbr_project_app.cpp

# ==== Resources to pack ====
MURL_MODULE_RES_PATH := data/packages

MURL_MODULE_RES_FILES += main.murlres

# ==== Packages to include ====
MURL_MODULE_PKG_PATH := data/packages

MURL_MODULE_PKG_FILES += startup.murlpkg
MURL_MODULE_PKG_FILES += main.murlpkg

# ==== Android-specific ====
MURL_ANDROID_PACKAGE_NAME := at.spraylight.murl.pbr_project

MURL_ANDROID_TARGET_API_LEVEL := 28
MURL_ANDROID_MINIMUM_API_LEVEL := 14

MURL_ANDROID_PERMISSIONS += android.permission.INTERNET
MURL_ANDROID_PERMISSIONS += android.permission.VIBRATE
MURL_ANDROID_PERMISSIONS += android.permission.ACCESS_FINE_LOCATION

MURL_ANDROID_SCREEN_ORIENTATION := landscape

MURL_ANDROID_RESOURCE_PATH := resources/android

MURL_ANDROID_RESOURCE_FILES += drawable/icon.png
MURL_ANDROID_RESOURCE_FILES += drawable-ldpi/icon.png
MURL_ANDROID_RESOURCE_FILES += drawable-mdpi/icon.png
MURL_ANDROID_RESOURCE_FILES += drawable-hdpi/icon.png
MURL_ANDROID_RESOURCE_FILES += drawable-xhdpi/icon.png

MURL_ANDROID_RESOURCE_FILES += drawable-land-nodpi/loader_background.png
MURL_ANDROID_RESOURCE_FILES += drawable-port-nodpi/loader_background.png

MURL_ANDROID_SPLASH_IMAGE := drawable/loader_background

# ==== emscripten-specific ====
#MURL_EMSCRIPTEN_TARGETS := js wasm

include $(MURL_MODULE_EXECUTABLE_END)