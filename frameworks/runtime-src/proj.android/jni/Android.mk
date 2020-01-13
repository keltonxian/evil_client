LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dlua_shared

LOCAL_MODULE_FILENAME := libcocos2dlua

LOCAL_SRC_FILES := hellolua/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/str_queue.cpp \
                   ../../Classes/LayerSocket.cpp \
                   ../../Classes/KUtils.cpp \
                   ../../Classes/EvilSprite.cpp \
                   ../../Classes/MD5Checksum.cpp \
                   ../../Classes/EvilPlatformAndroid.cpp \
				   ../../Classes/dragonbones/animation/Animation.cpp \
				   ../../Classes/dragonbones/animation/AnimationState.cpp \
				   ../../Classes/dragonbones/animation/TimelineState.cpp \
				   ../../Classes/dragonbones/animation/WorldClock.cpp \
				   ../../Classes/dragonbones/core/Armature.cpp \
				   ../../Classes/dragonbones/core/Bone.cpp \
				   ../../Classes/dragonbones/core/Object.cpp \
				   ../../Classes/dragonbones/core/Slot.cpp \
				   ../../Classes/dragonbones/events/EventData.cpp \
				   ../../Classes/dragonbones/factories/BaseFactory.cpp \
				   ../../Classes/dragonbones/parsers/BaseDataParser.cpp \
				   ../../Classes/dragonbones/parsers/ConstValues.cpp \
				   ../../Classes/dragonbones/parsers/dbtinyxml2.cpp \
				   ../../Classes/dragonbones/parsers/XMLDataParser.cpp \
				   ../../Classes/dragonbones/renderer/DBCCArmature.cpp \
				   ../../Classes/dragonbones/renderer/DBCCArmatureNode.cpp \
				   ../../Classes/dragonbones/renderer/DBCCFactory.cpp \
				   ../../Classes/dragonbones/renderer/DBCCSlot.cpp \
                   ../../Classes/auto/lua_dragonbones_auto.cpp \
                   ../../Classes/auto/lua_layersocket_auto.cpp \
                   ../../Classes/auto/lua_evilclass_auto.cpp


LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
					$(LOCAL_PATH)/../../Classes/dragonbones/ \
					$(LOCAL_PATH)/../../Classes/dragonbones/animation \
					$(LOCAL_PATH)/../../Classes/dragonbones/core \
					$(LOCAL_PATH)/../../Classes/dragonbones/events \
					$(LOCAL_PATH)/../../Classes/dragonbones/factories \
					$(LOCAL_PATH)/../../Classes/dragonbones/geoms \
					$(LOCAL_PATH)/../../Classes/dragonbones/objects \
					$(LOCAL_PATH)/../../Classes/dragonbones/parsers \
					$(LOCAL_PATH)/../../Classes/dragonbones/renderer \
					$(LOCAL_PATH)/../../Classes/dragonbones/textures \
					$(LOCAL_PATH)/../../Classes/auto
					
LOCAL_STATIC_LIBRARIES := curl_static_prebuilt

LOCAL_WHOLE_STATIC_LIBRARIES := cocos_lua_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,scripting/lua-bindings)
