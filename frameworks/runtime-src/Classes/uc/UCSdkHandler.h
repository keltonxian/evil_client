//
//  UCSdkHandler.h
//  EvilCard
//
//  Created by keltonxian on 4/17/15.
//
//

#ifndef __EvilCard__UCSdkHandler__
#define __EvilCard__UCSdkHandler__

#include "cocos2d.h"

USING_NS_CC;

class UCSdkHandler {
public:
    static void initSDK(bool debugMode, int cpId, int gameId, int serverId, const char *serverName, bool enablePayHistory, bool enableLogout);
    static void login();
    static void logout();
    static void pay(bool allowContinuousPay, float amount, int serverId, const char *pszRoleId, const char *pszRoleName, const char *pszGrade, const char* pszCustomInfo, const char *pszNotifyUrl, const char *pszTransactionNum);
    static void showFloatButton(float x, float y, bool visible);
    static void enterUserCenter();
    static void enterUI(const char *business);
    static void submitExtendData(const char* dataType, const char* dataStr);
    static void uPointCharge();
    static void exitSDK();
    static void destroyFloatButton();
};

#endif /* defined(__EvilCard__UCSdkHandler__) */
