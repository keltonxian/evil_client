//
//  LJSdkImpl.h
//  EvilCard
//
//  Created by keltonxian on 4/17/15.
//
//

#ifndef __EvilCard__LJSdkImpl__
#define __EvilCard__LJSdkImpl__

#include "cocos2d.h"
#include "../LayerSocket.h"

USING_NS_CC;

class LJSdkImpl {
public:
    static void setUserListener(LayerSocket *layerSocket);
    static void login(const char *customParams);
    static void logout(const char *customParams);
	static void pay(int amount, const char *unitName, int count, const char *callbackInfo, const char *callbackUrl, LayerSocket *layerSocket);
	static void exit(LayerSocket *layerSocket);
	static void setExtRoleData(const char *json);
};

#endif /* defined(__EvilCard__LJSdkImpl__) */
