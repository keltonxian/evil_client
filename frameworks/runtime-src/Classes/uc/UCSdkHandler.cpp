//
//  UCSdkHandler.cpp
//  EvilCard
//
//  Created by keltonxian on 4/17/15.
//
//

#include "UCSdkHandler.h"
#include "CUCGameSdk.h"
#include "UCSdkCallback.h"
#include "UCSdk.h"

using namespace ucgamesdk;

void UCSdkHandler::initSDK(bool debugMode, int cpId, int gameId, int serverId, const char *serverName, bool enablePayHistory, bool enableLogout) {
    CUCGameSdk::setLogLevel(UCSdk::s_loglevel);
    CUCGameSdk::setOrientation(UCSdk::s_orientation);
    CUCGameSdk::setLogoutCallback(UCSdkCallback::logout_callback);
//    CUCGameSdk::initSDK(UCSdk::s_debugMode, UCSdk::s_loglevel, UCSdk::s_cpid, UCSdk::s_gameid, UCSdk::s_serverid, UCSdk::s_servername.c_str(), UCSdk::s_enablePayHistory, UCSdk::s_enableLogout,UCSdkCallback::init_callback);
    CUCGameSdk::initSDK(debugMode, UCSdk::s_loglevel, cpId, gameId, serverId, serverName, enablePayHistory, enableLogout, UCSdkCallback::init_callback);
}

void UCSdkHandler::login() {
    CUCGameSdk::login(UCSdkCallback::login_callback);
}

void UCSdkHandler::logout() {
    CUCGameSdk::logout();
}

void UCSdkHandler::pay(bool allowContinuousPay, float amount, int serverId, const char *pszRoleId, const char *pszRoleName, const char *pszGrade, const char* pszCustomInfo, const char *pszNotifyUrl, const char *pszTransactionNum) {
    CUCGameSdk::pay(allowContinuousPay, amount, serverId, pszRoleId, pszRoleName, pszGrade, pszCustomInfo, pszNotifyUrl, pszTransactionNum, UCSdkCallback::pay_callback);
}

void UCSdkHandler::showFloatButton(float x, float y, bool visible) {
    CUCGameSdk::showFloatButton(x, y, visible);
}

void UCSdkHandler::enterUserCenter() {
    CUCGameSdk::enterUserCenter(UCSdkCallback::userCenter_callback);
}

void UCSdkHandler::enterUI(const char *business) {
    CUCGameSdk::enterUI(business, UCSdkCallback::enterUI_callback);
}

void UCSdkHandler::submitExtendData(const char* dataType, const char* dataStr) {
    // example:
    // std::string dataStr = "{\"roleId\":\"29392\",\"roleName\":\"落日传说\",\"serverId\":2359,\"serverName\":\"98区-紫禁之巅\"}";
    CUCGameSdk::submitExtendData(dataType, dataStr);
}

void UCSdkHandler::uPointCharge() {
    CUCGameSdk::uPointCharge(UCSdkCallback::uPointCharge_callback);
}

void UCSdkHandler::exitSDK() {
    CUCGameSdk::destroyFloatButton();
}

void UCSdkHandler::destroyFloatButton() {
    CUCGameSdk::exitSDK(UCSdkCallback::exit_callback);
}



