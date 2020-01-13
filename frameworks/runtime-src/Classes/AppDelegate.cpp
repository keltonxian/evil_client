#include "AppDelegate.h"
#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"

#include "auto/lua_evilclass_auto.hpp"
#include "auto/lua_layersocket_auto.hpp"
#include "auto/lua_dragonbones_auto.hpp"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
//#define E_ANYSDK_CN
//#define E_LJSDK
//#define E_UCSDK
#endif
#ifdef E_ANYSDK_CN
#include "anysdk/anysdkbindings.h"
#include "anysdk/anysdk_manual_bindings.h"
#endif
#ifdef E_LJSDK
#include "ljsdk/lua_ljsdkimpl_auto.hpp"
#endif
#ifdef E_UCSDK
#include "uc/lua_ucsdkclass_auto.hpp"
#endif

#include "LayerSocket.h"

using namespace CocosDenshion;

USING_NS_CC;
using namespace std;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
    SimpleAudioEngine::end();
}

bool AppDelegate::applicationDidFinishLaunching()
{
    queue_init();
    signal(SIGPIPE, SIG_IGN);
    ZipUtils::setPvrEncryptionKey(0x4e33a7ca, 0x2765d359, 0xc6d889f5, 0x4894b3a7);
    auto engine = LuaEngine::getInstance();
//    ValueMap data = FileUtils::getInstance()->getValueMapFromFile("startup/game_config.plist");
//    int cver = data.at("CHANNEL_VER").asInt();
//    int vanysdk = data.at("VER_ANYSDK").asInt();
//    CCLOG("1[%d] 2[%d]", cver, vanysdk);
//    if (cver == vanysdk) {
//#define IS_ANYSDK  1
//#ifdef IS_ANYSDK
//#include "anysdk/anysdkbindings.h"
//#include "anysdk/anysdk_manual_bindings.h"
//        LuaStack* stack = engine->getLuaStack();
//        lua_getglobal(stack->getLuaState(), "_G");
//        tolua_anysdk_open(stack->getLuaState());
//        tolua_anysdk_manual_open(stack->getLuaState());
//        lua_pop(stack->getLuaState(), 1);
//#endif
//    }
#ifdef E_ANYSDK_CN
    LuaStack* stack = engine->getLuaStack();
    lua_getglobal(stack->getLuaState(), "_G");
    tolua_anysdk_open(stack->getLuaState());
    tolua_anysdk_manual_open(stack->getLuaState());
    lua_pop(stack->getLuaState(), 1);
#endif
#ifdef E_LJSDK
    register_all_ljsdkimpl(engine->getLuaStack()->getLuaState());
#endif
#ifdef E_UCSDK
    register_all_ucsdkclass(engine->getLuaStack()->getLuaState());
#endif
    register_all_evilclass(engine->getLuaStack()->getLuaState());
    register_all_layersocket(engine->getLuaStack()->getLuaState());
    register_all_dragonbones(engine->getLuaStack()->getLuaState());
    ScriptEngineManager::getInstance()->setScriptEngine(engine);
    if (engine->executeScriptFile("src/version.lua")) {
        return false;
    }

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
