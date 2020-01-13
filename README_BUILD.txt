AnySDK:

android版
在运行cocos run/compile -p android ...前
需要进行一些设置更改
1.
修改"~/Documents/platform/cocos2dx-3.2/cocos2d-x-3.2/tools/cocos2d-console/bin/cocos_project.py"
"354 class AndroidConfig(PlatformConfig):"
"self.proj_path = os.path.join(self._proj_root_path, "frameworks", "runti    me-src", "proj.android")"
-->
"self.proj_path = os.path.join(self._proj_root_path, "frameworks", "runti    me-src", "proj.android_anysdk")"
2.
修改"~/Documents/workspace/evil/evil_client/EvilCard/frameworks/cocos2d-x/cocos/platform/android/Android.mk"
在"LOCAL_C_INCLUDES"
增加"$(LOCAL_PATH)/../../../../runtime-src/proj.android_anysdk/protocols/android"
修改"~/Documents/workspace/evil/evil_client/EvilCard/frameworks/cocos2d-x/cocos/platform/android/javaactivity.cpp"
增加"#include "PluginJniHelper.h"","using namespace anysdk::framework;"
在"jint JNI_OnLoad(JavaVM *vm, void *reserved)"
增加"PluginJniHelper::setJavaVM(vm);"
3.
修改"AppDelegate.cpp"
解除注释"#define E_ANYSDK_CN"
4.
修改res/startup/game_config.plist
将"CHANNEL_VER"的value改成3


UCSdk:

android版
因为proj.android_uc/uc_sdk/android/java不在proj.android_uc/src中会导致cocos命令编译时找不到其包，所以手动将其复制到了src中
