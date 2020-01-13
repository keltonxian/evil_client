#include "lua_ucsdkclass_auto.hpp"
#include "UCSdk.h"
#include "UCSdkCallback.h"
#include "UCSdkHandler.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



static int lua_ucsdkclass_UCSdk_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UCSdk)");
    return 0;
}

int lua_register_ucsdkclass_UCSdk(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UCSdk");
    tolua_cclass(tolua_S,"UCSdk","UCSdk","",nullptr);

    tolua_beginmodule(tolua_S,"UCSdk");
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(UCSdk).name();
    g_luaType[typeName] = "UCSdk";
    g_typeCast["UCSdk"] = "UCSdk";
    return 1;
}

int lua_ucsdkclass_UCSdkCallback_floatMenu_callback(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkCallback",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        int arg0;
        const char* arg1;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        UCSdkCallback::floatMenu_callback(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "floatMenu_callback",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkCallback_floatMenu_callback'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkCallback_uPointCharge_callback(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkCallback",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        int arg0;
        const char* arg1;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        UCSdkCallback::uPointCharge_callback(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "uPointCharge_callback",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkCallback_uPointCharge_callback'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkCallback_pay_callback(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkCallback",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 5)
    {
        int arg0;
        const char* arg1;
        double arg2;
        int arg3;
        const char* arg4;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        ok &= luaval_to_number(tolua_S, 4,&arg2);
        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);
        std::string arg4_tmp; ok &= luaval_to_std_string(tolua_S, 6, &arg4_tmp); arg4 = arg4_tmp.c_str();
        if(!ok)
            return 0;
        UCSdkCallback::pay_callback(arg0, arg1, arg2, arg3, arg4);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "pay_callback",argc, 5);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkCallback_pay_callback'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkCallback_getUCVipInfo_callback(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkCallback",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        int arg0;
        const char* arg1;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        UCSdkCallback::getUCVipInfo_callback(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getUCVipInfo_callback",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkCallback_getUCVipInfo_callback'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkCallback_init_callback(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkCallback",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        int arg0;
        const char* arg1;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        UCSdkCallback::init_callback(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "init_callback",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkCallback_init_callback'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkCallback_login_callback(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkCallback",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        int arg0;
        const char* arg1;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        UCSdkCallback::login_callback(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "login_callback",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkCallback_login_callback'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkCallback_logout_callback(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkCallback",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        int arg0;
        const char* arg1;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        UCSdkCallback::logout_callback(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "logout_callback",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkCallback_logout_callback'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkCallback_gameUserLogin_callback(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkCallback",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        const char* arg0;
        const char* arg1;
        char** arg2;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        #pragma warning NO CONVERSION TO NATIVE FOR char**;
        if(!ok)
            return 0;
        int ret = UCSdkCallback::gameUserLogin_callback(arg0, arg1, arg2);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "gameUserLogin_callback",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkCallback_gameUserLogin_callback'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkCallback_exit_callback(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkCallback",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        int arg0;
        const char* arg1;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        UCSdkCallback::exit_callback(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "exit_callback",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkCallback_exit_callback'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkCallback_isUCVip_callback(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkCallback",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        int arg0;
        bool arg1;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        UCSdkCallback::isUCVip_callback(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "isUCVip_callback",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkCallback_isUCVip_callback'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkCallback_enterUI_callback(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkCallback",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        int arg0;
        const char* arg1;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        UCSdkCallback::enterUI_callback(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "enterUI_callback",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkCallback_enterUI_callback'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkCallback_userCenter_callback(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkCallback",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        int arg0;
        const char* arg1;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        UCSdkCallback::userCenter_callback(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "userCenter_callback",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkCallback_userCenter_callback'.",&tolua_err);
#endif
    return 0;
}
static int lua_ucsdkclass_UCSdkCallback_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UCSdkCallback)");
    return 0;
}

int lua_register_ucsdkclass_UCSdkCallback(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UCSdkCallback");
    tolua_cclass(tolua_S,"UCSdkCallback","UCSdkCallback","",nullptr);

    tolua_beginmodule(tolua_S,"UCSdkCallback");
        tolua_function(tolua_S,"floatMenu_callback", lua_ucsdkclass_UCSdkCallback_floatMenu_callback);
        tolua_function(tolua_S,"uPointCharge_callback", lua_ucsdkclass_UCSdkCallback_uPointCharge_callback);
        tolua_function(tolua_S,"pay_callback", lua_ucsdkclass_UCSdkCallback_pay_callback);
        tolua_function(tolua_S,"getUCVipInfo_callback", lua_ucsdkclass_UCSdkCallback_getUCVipInfo_callback);
        tolua_function(tolua_S,"init_callback", lua_ucsdkclass_UCSdkCallback_init_callback);
        tolua_function(tolua_S,"login_callback", lua_ucsdkclass_UCSdkCallback_login_callback);
        tolua_function(tolua_S,"logout_callback", lua_ucsdkclass_UCSdkCallback_logout_callback);
        tolua_function(tolua_S,"gameUserLogin_callback", lua_ucsdkclass_UCSdkCallback_gameUserLogin_callback);
        tolua_function(tolua_S,"exit_callback", lua_ucsdkclass_UCSdkCallback_exit_callback);
        tolua_function(tolua_S,"isUCVip_callback", lua_ucsdkclass_UCSdkCallback_isUCVip_callback);
        tolua_function(tolua_S,"enterUI_callback", lua_ucsdkclass_UCSdkCallback_enterUI_callback);
        tolua_function(tolua_S,"userCenter_callback", lua_ucsdkclass_UCSdkCallback_userCenter_callback);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(UCSdkCallback).name();
    g_luaType[typeName] = "UCSdkCallback";
    g_typeCast["UCSdkCallback"] = "UCSdkCallback";
    return 1;
}

int lua_ucsdkclass_UCSdkHandler_pay(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkHandler",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 9)
    {
        bool arg0;
        double arg1;
        int arg2;
        const char* arg3;
        const char* arg4;
        const char* arg5;
        const char* arg6;
        const char* arg7;
        const char* arg8;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        ok &= luaval_to_number(tolua_S, 3,&arg1);
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp); arg3 = arg3_tmp.c_str();
        std::string arg4_tmp; ok &= luaval_to_std_string(tolua_S, 6, &arg4_tmp); arg4 = arg4_tmp.c_str();
        std::string arg5_tmp; ok &= luaval_to_std_string(tolua_S, 7, &arg5_tmp); arg5 = arg5_tmp.c_str();
        std::string arg6_tmp; ok &= luaval_to_std_string(tolua_S, 8, &arg6_tmp); arg6 = arg6_tmp.c_str();
        std::string arg7_tmp; ok &= luaval_to_std_string(tolua_S, 9, &arg7_tmp); arg7 = arg7_tmp.c_str();
        std::string arg8_tmp; ok &= luaval_to_std_string(tolua_S, 10, &arg8_tmp); arg8 = arg8_tmp.c_str();
        if(!ok)
            return 0;
        UCSdkHandler::pay(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "pay",argc, 9);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkHandler_pay'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkHandler_destroyFloatButton(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkHandler",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        UCSdkHandler::destroyFloatButton();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "destroyFloatButton",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkHandler_destroyFloatButton'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkHandler_enterUI(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkHandler",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        UCSdkHandler::enterUI(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "enterUI",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkHandler_enterUI'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkHandler_showFloatButton(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkHandler",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        double arg0;
        double arg1;
        bool arg2;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_number(tolua_S, 3,&arg1);
        ok &= luaval_to_boolean(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        UCSdkHandler::showFloatButton(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "showFloatButton",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkHandler_showFloatButton'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkHandler_initSDK(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkHandler",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 7)
    {
        bool arg0;
        int arg1;
        int arg2;
        int arg3;
        const char* arg4;
        bool arg5;
        bool arg6;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);
        std::string arg4_tmp; ok &= luaval_to_std_string(tolua_S, 6, &arg4_tmp); arg4 = arg4_tmp.c_str();
        ok &= luaval_to_boolean(tolua_S, 7,&arg5);
        ok &= luaval_to_boolean(tolua_S, 8,&arg6);
        if(!ok)
            return 0;
        UCSdkHandler::initSDK(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "initSDK",argc, 7);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkHandler_initSDK'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkHandler_exitSDK(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkHandler",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        UCSdkHandler::exitSDK();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "exitSDK",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkHandler_exitSDK'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkHandler_submitExtendData(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkHandler",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        UCSdkHandler::submitExtendData(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "submitExtendData",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkHandler_submitExtendData'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkHandler_uPointCharge(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkHandler",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        UCSdkHandler::uPointCharge();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "uPointCharge",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkHandler_uPointCharge'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkHandler_logout(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkHandler",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        UCSdkHandler::logout();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "logout",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkHandler_logout'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkHandler_enterUserCenter(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkHandler",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        UCSdkHandler::enterUserCenter();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "enterUserCenter",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkHandler_enterUserCenter'.",&tolua_err);
#endif
    return 0;
}
int lua_ucsdkclass_UCSdkHandler_login(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UCSdkHandler",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        UCSdkHandler::login();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "login",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ucsdkclass_UCSdkHandler_login'.",&tolua_err);
#endif
    return 0;
}
static int lua_ucsdkclass_UCSdkHandler_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UCSdkHandler)");
    return 0;
}

int lua_register_ucsdkclass_UCSdkHandler(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UCSdkHandler");
    tolua_cclass(tolua_S,"UCSdkHandler","UCSdkHandler","",nullptr);

    tolua_beginmodule(tolua_S,"UCSdkHandler");
        tolua_function(tolua_S,"pay", lua_ucsdkclass_UCSdkHandler_pay);
        tolua_function(tolua_S,"destroyFloatButton", lua_ucsdkclass_UCSdkHandler_destroyFloatButton);
        tolua_function(tolua_S,"enterUI", lua_ucsdkclass_UCSdkHandler_enterUI);
        tolua_function(tolua_S,"showFloatButton", lua_ucsdkclass_UCSdkHandler_showFloatButton);
        tolua_function(tolua_S,"initSDK", lua_ucsdkclass_UCSdkHandler_initSDK);
        tolua_function(tolua_S,"exitSDK", lua_ucsdkclass_UCSdkHandler_exitSDK);
        tolua_function(tolua_S,"submitExtendData", lua_ucsdkclass_UCSdkHandler_submitExtendData);
        tolua_function(tolua_S,"uPointCharge", lua_ucsdkclass_UCSdkHandler_uPointCharge);
        tolua_function(tolua_S,"logout", lua_ucsdkclass_UCSdkHandler_logout);
        tolua_function(tolua_S,"enterUserCenter", lua_ucsdkclass_UCSdkHandler_enterUserCenter);
        tolua_function(tolua_S,"login", lua_ucsdkclass_UCSdkHandler_login);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(UCSdkHandler).name();
    g_luaType[typeName] = "UCSdkHandler";
    g_typeCast["UCSdkHandler"] = "UCSdkHandler";
    return 1;
}
TOLUA_API int register_all_ucsdkclass(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_ucsdkclass_UCSdkHandler(tolua_S);
	lua_register_ucsdkclass_UCSdkCallback(tolua_S);
	lua_register_ucsdkclass_UCSdk(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

