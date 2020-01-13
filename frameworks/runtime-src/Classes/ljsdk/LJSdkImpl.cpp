//
//  LJSdkImpl.cpp
//  EvilCard
//
//  Created by keltonxian on 4/17/15.
//
//

#include "LJSdkImpl.h"
#include "GameProxy.h"

class XMUserListenerImpl: public XMUserListener {
private:
    LayerSocket *parent;
public:
    XMUserListenerImpl(LayerSocket *layerSocket) {
        this->parent = parent;
    }
    /*登录成功回调onLoginSucess，XMUser对象包含登录用户的信息*/
    virtual void onLoginSuccess(XMUser user, const char *customParams) {
        
        CCLOG("login success");
        char cmd[1000];
        sprintf(cmd, "ljsdk log_succ %s %s %s %s %s", user.getUserId()
		, user.getProductCode(), user.getChannelId() //, user.getChannelLabel()
		, user.getToken());
        LayerSocket::recvCmd(cmd);
//        auto engine = LuaEngine::getInstance();
//        auto stack = engine->getLuaStack();
//        stack->pushString("Hi ther");
//        stack->executeFunctionByHandler(handlerFunc, 1);
        
//        stringstream is;
//        stringstream is1;
//        stringstream is2;
//        
//        is << "uid=" << user.getUserId(); //不为空或者null，登录用户的userId，请以该字段为用户唯一标识映射游戏人物
//        is1 <<"token=" << user.getToken();//登录用户的令牌，用于校验登录是否合法有效，针对部分渠道该字段可能为空
//        is2 <<"channel=" << user.getChannelId();//登录用户所在渠道，标识渠道
//        
//        
//        
//        
//        
//        /*用户数据扩展接口，请准确接入，否则会造成渠道退包*/
//        
//        /*setExtData enterServer*/
//        
//        /*
//         请将登录用户的信息组成JSON串传入，请确保每个字段都有，保证每个字段的Key准确
//         
//         当前情景，目前支持 enterServer （进入服务器），levelUp （玩家升级），createRole （玩家创建角色）
//         
//         roleId 当前登录的玩家角色ID，必须为数字，若无，传入userid
//         
//         roleName 当前登录的玩家角色名，不能为空，不能为null，若无，传入”游戏名称+userId”
//         
//         roleLevel 当前登录的玩家角色等级，必须为数字，若无，传入1
//         
//         zoneId 当前登录的游戏区服ID，必须为数字，若无，传入1
//         
//         zoneName 当前登录的游戏区服名称，不能为空，不能为null，若无，传入”无区服”
//         
//         balance 当前用户游戏币余额，必须为数字，若无，传入0
//         
//         vip 当前用户VIP等级，必须为数字，若无，传入1
//         
//         partyName 当前用户所属帮派，不能为空，不能为null，若无，传入”无帮派”
//         
//         
//         */
//        string json =  "{\"partyName\":\"无尽天涯\",\"balance\":\"88\",\"vip\":\"2\",\"_id\":\"enterServer\",\"roleLevel\":\"24\",\"roleName\":\"方木\",\"zoneName\":\"墨土1区\",\"roleId\":\"13524696\",\"zoneId\":\"1\"}";
//        
//        GameProxy::SetExtRoleData(json.c_str());
//        
//        /*setExtData createRole*/
//        
//        string json2 =  "{\"partyName\":\"无尽天涯\",\"balance\":\"88\",\"vip\":\"2\",\"_id\":\"createRole\",\"roleLevel\":\"24\",\"roleName\":\"方木\",\"zoneName\":\"墨土1区\",\"roleId\":\"13524696\",\"zoneId\":\"1\"}";
//        
//        GameProxy::SetExtRoleData(json2.c_str());
//        
//        /*setExtData levelUp*/
//        
//        string json3 =  "{\"partyName\":\"无尽天涯\",\"balance\":\"88\",\"vip\":\"2\",\"_id\":\"levelUp\",\"roleLevel\":\"24\",\"roleName\":\"方木\",\"zoneName\":\"墨土1区\",\"roleId\":\"13524696\",\"zoneId\":\"1\"}";
//        
//        GameProxy::SetExtRoleData(json3.c_str());
        
    }
    ;
    
    /*登录失败回调，部分渠道不会回调此接口，请保证游戏做好兼容处理*/
    virtual void onLoginFailed(const char *reason,
                               const char *customParams) {
        char cmd[1000];
        sprintf(cmd, "ljsdk log_fail %s %s", reason, customParams);
        LayerSocket::recvCmd(cmd);
    }
    ;
    
    /*用户游戏内登出回调，用户在游戏内触发登出，会回调该接口，请在该接口做游戏登出处理，基本逻辑为注销游戏内账户，退回到游戏初始登录界面*/
    virtual void onLogout(const char *customParams) {
        char cmd[1000];
        sprintf(cmd, "ljsdk log_out");
        LayerSocket::recvCmd(cmd);
    }
    ;
};

class XMPayCallbackImpl: public PayCallBack {
private:
    LayerSocket *parent;
public:
    XMPayCallbackImpl(LayerSocket *layerSocket) {
        this->parent = parent;
    }

	virtual void onPaySuccess(char *success_info) {
		// TODO: pay success
        char cmd[1000];
        sprintf(cmd, "ljsdk pay_succ");
        LayerSocket::recvCmd(cmd);
	};

	virtual void onPayFail(char *fail_info) {
		// TODO: pay fail
        char cmd[1000];
        sprintf(cmd, "ljsdk pay_fail");
        LayerSocket::recvCmd(cmd);
	};

};

class XMExitCallbackImpl: public ExitCallBack {
private:
    LayerSocket *parent;
public:
    XMExitCallbackImpl(LayerSocket *layerSocket) {
        this->parent = parent;
    }

	virtual void onGameExit() {
		// TODO: 退出游戏
        char cmd[1000];
        sprintf(cmd, "ljsdk force_exit");
        LayerSocket::recvCmd(cmd);

		GameProxy::releaseResource();
	};

	virtual void onNo3rd() {
		// TODO: 退出游戏
        char cmd[1000];
        sprintf(cmd, "ljsdk exit");
        LayerSocket::recvCmd(cmd);

		GameProxy::releaseResource();
	};
};


void LJSdkImpl::setUserListener(LayerSocket *layerSocket)
{
	static XMUserListenerImpl impl(layerSocket);
    GameProxy::SetUserListener(&impl);//new XMUserListenerImpl(layerSocket));
}

void LJSdkImpl::login(const char *customParams)
{
    GameProxy::Login(customParams);
}

void LJSdkImpl::logout(const char *customParams)
{
    GameProxy::Logout(customParams);
}

void LJSdkImpl::pay(int amount, const char *unitName, int count, const char *callbackInfo, const char *callbackUrl, LayerSocket *layerSocket)
{
	static XMPayCallbackImpl impl(layerSocket);
	GameProxy::Pay(amount, unitName, count, callbackInfo, callbackUrl, &impl);
}

void LJSdkImpl::exit(LayerSocket *layerSocket)
{
	static XMExitCallbackImpl impl(layerSocket);
	GameProxy::Exit(&impl);
}

void LJSdkImpl::setExtRoleData(const char *json)
{
	GameProxy::SetExtRoleData(json);
}



