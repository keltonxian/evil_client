#include "lua_ljsdkimpl_auto.hpp"
#include "LJSdkImpl.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_ljsdkimpl_LJSdkImpl_setUserListener(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"LJSdkImpl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        LayerSocket* arg0;
        ok &= luaval_to_object<LayerSocket>(tolua_S, 2, "LayerSocket",&arg0);
        if(!ok)
            return 0;
        LJSdkImpl::setUserListener(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "setUserListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ljsdkimpl_LJSdkImpl_setUserListener'.",&tolua_err);
#endif
    return 0;
}
int lua_ljsdkimpl_LJSdkImpl_pay(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"LJSdkImpl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 6)
    {
        int arg0;
        const char* arg1;
        int arg2;
        const char* arg3;
        const char* arg4;
        LayerSocket* arg5;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp); arg3 = arg3_tmp.c_str();
        std::string arg4_tmp; ok &= luaval_to_std_string(tolua_S, 6, &arg4_tmp); arg4 = arg4_tmp.c_str();
        ok &= luaval_to_object<LayerSocket>(tolua_S, 7, "LayerSocket",&arg5);
        if(!ok)
            return 0;
        LJSdkImpl::pay(arg0, arg1, arg2, arg3, arg4, arg5);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "pay",argc, 6);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ljsdkimpl_LJSdkImpl_pay'.",&tolua_err);
#endif
    return 0;
}
int lua_ljsdkimpl_LJSdkImpl_exit(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"LJSdkImpl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        LayerSocket* arg0;
        ok &= luaval_to_object<LayerSocket>(tolua_S, 2, "LayerSocket",&arg0);
        if(!ok)
            return 0;
        LJSdkImpl::exit(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "exit",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ljsdkimpl_LJSdkImpl_exit'.",&tolua_err);
#endif
    return 0;
}
int lua_ljsdkimpl_LJSdkImpl_logout(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"LJSdkImpl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        LJSdkImpl::logout(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "logout",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ljsdkimpl_LJSdkImpl_logout'.",&tolua_err);
#endif
    return 0;
}
int lua_ljsdkimpl_LJSdkImpl_login(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"LJSdkImpl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        LJSdkImpl::login(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "login",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ljsdkimpl_LJSdkImpl_login'.",&tolua_err);
#endif
    return 0;
}
int lua_ljsdkimpl_LJSdkImpl_setExtRoleData(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"LJSdkImpl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        LJSdkImpl::setExtRoleData(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "setExtRoleData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ljsdkimpl_LJSdkImpl_setExtRoleData'.",&tolua_err);
#endif
    return 0;
}
static int lua_ljsdkimpl_LJSdkImpl_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (LJSdkImpl)");
    return 0;
}

int lua_register_ljsdkimpl_LJSdkImpl(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"LJSdkImpl");
    tolua_cclass(tolua_S,"LJSdkImpl","LJSdkImpl","",nullptr);

    tolua_beginmodule(tolua_S,"LJSdkImpl");
        tolua_function(tolua_S,"setUserListener", lua_ljsdkimpl_LJSdkImpl_setUserListener);
        tolua_function(tolua_S,"pay", lua_ljsdkimpl_LJSdkImpl_pay);
        tolua_function(tolua_S,"exit", lua_ljsdkimpl_LJSdkImpl_exit);
        tolua_function(tolua_S,"logout", lua_ljsdkimpl_LJSdkImpl_logout);
        tolua_function(tolua_S,"login", lua_ljsdkimpl_LJSdkImpl_login);
        tolua_function(tolua_S,"setExtRoleData", lua_ljsdkimpl_LJSdkImpl_setExtRoleData);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(LJSdkImpl).name();
    g_luaType[typeName] = "LJSdkImpl";
    g_typeCast["LJSdkImpl"] = "LJSdkImpl";
    return 1;
}
TOLUA_API int register_all_ljsdkimpl(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_ljsdkimpl_LJSdkImpl(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

