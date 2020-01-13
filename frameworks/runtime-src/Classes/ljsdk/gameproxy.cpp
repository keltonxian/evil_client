#include "GameProxy.h"

#include <jni.h>
#include <android/log.h>
#define LOG_TAG "JniSDK"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

extern "C" {

JNIEXPORT void JNICALL Java_com_xinmei365_game_proxy_JniHelper_prepared
(JNIEnv *, jobject, jobject);

JNIEXPORT void JNICALL Java_com_xinmei365_game_proxy_JniHelper_onLoginSuccess
(JNIEnv *, jclass, jobject, jobject);

JNIEXPORT void JNICALL Java_com_xinmei365_game_proxy_JniHelper_onLoginFailed
(JNIEnv *, jclass, jstring, jobject);

JNIEXPORT void JNICALL Java_com_xinmei365_game_proxy_JniHelper_onLogout
(JNIEnv *, jclass, jobject);

JNIEXPORT void JNICALL Java_com_xinmei365_game_proxy_JniHelper_payCallBackSuccess
(JNIEnv *, jclass,jobject);

JNIEXPORT void JNICALL Java_com_xinmei365_game_proxy_JniHelper_payCallBackFail
(JNIEnv *, jclass,jobject);

JNIEXPORT void JNICALL Java_com_xinmei365_game_proxy_JniHelper_xmExitCallBackOnExit
(JNIEnv *, jclass);

JNIEXPORT void JNICALL Java_com_xinmei365_game_proxy_JniHelper_xmExitCallBackNo3rd
(JNIEnv *, jclass);


JNIEnv* jniEnv;
//jobject jniContext;

// jclass GameProxyClass;
// jobject GameProxyObject;
jobject GlobalGameProxyObject;

jmethodID login;
jmethodID logout;
jmethodID charge;
jmethodID pay;
jmethodID onexit;
jmethodID setUserListener;
jmethodID setXMRoleData;
jmethodID setExtRoleData;

PayCallBack *payCallBack;
XMUserListener *userListener;
ExitCallBack *exitCallBack;




static char* jstringTostr(JNIEnv* jniEnv, jstring jstr) {
    char* pStr = NULL;
    jclass jstrObj = jniEnv->FindClass("java/lang/String");
    jstring encode = jniEnv->NewStringUTF("utf-8");
    jmethodID methodId = jniEnv->GetMethodID(jstrObj, "getBytes",
                                             "(Ljava/lang/String;)[B");
    jbyteArray byteArray = (jbyteArray) jniEnv->CallObjectMethod(jstr,
                                                                 methodId, encode);
    jsize strLen = jniEnv->GetArrayLength(byteArray);
    jbyte *jBuf = jniEnv->GetByteArrayElements(byteArray, JNI_FALSE);
    if (jBuf > 0) {
        pStr = (char*) malloc(strLen + 1);
        if (!pStr) {
            return NULL;
        }
        memcpy(pStr, jBuf, strLen);
        pStr[strLen] = 0;
    }
    jniEnv->ReleaseByteArrayElements(byteArray, jBuf, 0);
    return pStr;
}

static jstring stoJstring( JNIEnv* env, const char* pat )
{
    //定义java String类 strClass
    jclass strClass = (env)->FindClass("java/lang/String");
    //获取java String类方法String(byte[],String)的构造器,用于将本地byte[]数组转换为一个新String
    jmethodID ctorID = (env)->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
    jbyteArray bytes = (env)->NewByteArray(strlen(pat));//建立byte数组
    (env)->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte*)pat);//将char* 转换为byte数组
    jstring encoding = (env)->NewStringUTF("utf-8"); // 设置String, 保存语言类型,用于byte数组转换至String时的参数
    return (jstring)(env)->NewObject(strClass, ctorID, bytes, encoding);//将byte数组转换为java String,并输出
}

static string jstringTostring(JNIEnv* env, jstring jstr) {
    char* rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("utf-8");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes",
                                     "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid,
                                                         strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char*) malloc(alen + 1); //new   char[alen+1];
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    string stemp(rtn);
    free(rtn);
    return stemp;
}


void Java_com_xinmei365_game_proxy_JniHelper_prepared(JNIEnv * env,
		jobject thiz, jobject context) {
	if (jniEnv == NULL) {
		jniEnv = env;
	}
}

void Java_com_xinmei365_game_proxy_JniHelper_onLoginSuccess(JNIEnv* env,
		jclass clazz, jobject xmUser, jobject customParams) {


	jclass XMUserClass = jniEnv->FindClass("com/xinmei365/game/proxy/XMUser");
    jmethodID getUserID = jniEnv->GetMethodID(XMUserClass, "getUserID",
        "()Ljava/lang/String;");
    jmethodID getChannelUserID = jniEnv->GetMethodID(XMUserClass, "getChannelUserId",
        "()Ljava/lang/String;");
    jmethodID getChannelID = jniEnv->GetMethodID(XMUserClass, "getChannelID",
				"()Ljava/lang/String;");
    jmethodID getChannelLabel = jniEnv->GetMethodID(XMUserClass, "getChannelLabel",
				"()Ljava/lang/String;");
    jmethodID getUsername = jniEnv->GetMethodID(XMUserClass, "getUsername",
				"()Ljava/lang/String;");
    jmethodID getToken = jniEnv->GetMethodID(XMUserClass, "getToken",
				"()Ljava/lang/String;");
    jmethodID getProdcutCode = jniEnv->GetMethodID(XMUserClass, "getProdcutCode",
				"()Ljava/lang/String;");

    jstring userId = static_cast<jstring>(jniEnv->CallObjectMethod(xmUser,
      getUserID));
    jstring channelUserId = static_cast<jstring>(jniEnv->CallObjectMethod(xmUser,
      getChannelUserID));
	jstring channelId = static_cast<jstring>(jniEnv->CallObjectMethod(xmUser,
			getChannelID));
	jstring channelLabel = static_cast<jstring>(jniEnv->CallObjectMethod(xmUser,
			getChannelLabel));
	jstring userName = static_cast<jstring>(jniEnv->CallObjectMethod(xmUser,
			getUsername));
	jstring token = static_cast<jstring>(jniEnv->CallObjectMethod(xmUser,
			getToken));
	jstring productCode = static_cast<jstring>(jniEnv->CallObjectMethod(xmUser,
			getProdcutCode));
	LOGI("%1$s", jstringTostr(jniEnv,userId));
	LOGI("%1$s", jstringTostr(jniEnv,channelId));
	LOGI("%1$s", jstringTostr(jniEnv,channelLabel));
	LOGI("%1$s", jstringTostr(jniEnv,userName));
	LOGI("%1$s", jstringTostr(jniEnv,token));
	LOGI("%1$s", jstringTostr(jniEnv,productCode));
	LOGI("%1$s", GameProxy::GetChannelLabel());

	XMUser user;
    user.setUserId(jstringTostr(jniEnv, userId));
    user.setChannelUserId(jstringTostr(jniEnv, channelUserId));
	user.setUserName(jstringTostr(jniEnv, userName));
	user.setToken(jstringTostr(jniEnv, token));
	user.setChannelId(jstringTostr(jniEnv, channelId));
	user.setChannelLabel(jstringTostr(jniEnv, channelLabel));
	user.setProductId(jstringTostr(jniEnv, productCode));
	jstring params = (jstring) customParams;
	char *result = jstringTostr(jniEnv, params);
	userListener->onLoginSuccess(user, result);
}
;

void Java_com_xinmei365_game_proxy_JniHelper_onLoginFailed(JNIEnv* env,
		jclass clazz, jstring reason, jobject customParams) {
	jstring res = (jstring) reason;
	char *result1 = jstringTostr(jniEnv, res);
	jstring params = (jstring) customParams;
	char *result2 = jstringTostr(jniEnv, params);
	userListener->onLoginFailed(result1, result2);
}
;

void Java_com_xinmei365_game_proxy_JniHelper_onLogout(JNIEnv* env, jclass clazz,
		jobject customParams) {
	jstring params = (jstring) customParams;
	char *result = jstringTostr(jniEnv, params);
	userListener->onLogout(result);
}
;

void Java_com_xinmei365_game_proxy_JniHelper_payCallBackSuccess(JNIEnv* env,
		jclass clazz, jobject successinfo) {
	jstring params = (jstring)successinfo;
	char *info = jstringTostr(jniEnv, params);
	payCallBack->onPaySuccess(info);
}
void Java_com_xinmei365_game_proxy_JniHelper_payCallBackFail(JNIEnv* env,
		jclass clazz, jobject failinfo) {
	char *info = jstringTostr(jniEnv, (jstring)failinfo);
	payCallBack->onPayFail(info);

}

void Java_com_xinmei365_game_proxy_JniHelper_xmExitCallBackOnExit
  (JNIEnv* env, jclass clazz){
	exitCallBack->onGameExit();
}

void Java_com_xinmei365_game_proxy_JniHelper_xmExitCallBackNo3rd
  (JNIEnv* env, jclass clazz){
	exitCallBack->onNo3rd();
}





jclass GetGameProxyClass(JNIEnv* env) {
    return  jniEnv->FindClass("com/xinmei365/game/proxy/GameProxyNativeStub");
}

jobject InitGameProxyObject(JNIEnv* env, jclass gpc) {
    jmethodID construction_id = env->GetStaticMethodID(gpc,
      "getInstance", "()Lcom/xinmei365/game/proxy/GameProxyNativeStub;");
    jobject gpo = jniEnv->CallStaticObjectMethod(gpc, construction_id);
    if(gpo == NULL)
        return NULL;
    else
      return env->NewGlobalRef(gpo);
}


jobject GetGameProxyObject(JNIEnv * env, jclass gpc) {
  if (GlobalGameProxyObject == NULL)
    GlobalGameProxyObject = InitGameProxyObject(env, gpc);
  return GlobalGameProxyObject;
}




void GameProxy::SetUserListener(XMUserListener *listener) {
	userListener = listener;
  jclass GameProxyClass = GetGameProxyClass(jniEnv);
  jobject GameProxyObject = GetGameProxyObject(jniEnv, GameProxyClass);
	if (setUserListener == NULL) {
		setUserListener =
				jniEnv->GetMethodID(GameProxyClass, "setUserListener",
						"(Lcom/xinmei365/game/proxy/XMUserListener;)V");
	}

	jclass listenercls = jniEnv->FindClass(
			"com/xinmei365/game/proxy/XMUserListenerNativeImpl");
	jmethodID listenerid = jniEnv->GetMethodID(listenercls, "<init>", "()V");
	jobject xmUserListener = jniEnv->NewObject(listenercls, listenerid);

	jniEnv->CallVoidMethod(GameProxyObject, setUserListener, xmUserListener);

	__android_log_print(ANDROID_LOG_INFO, "JNIMsg", "setUserListener完毕");
}
;

void GameProxy::Login(const char *customParams) {

  jclass GameProxyClass = GetGameProxyClass(jniEnv);
  jobject GameProxyObject = GetGameProxyObject(jniEnv, GameProxyClass);
	if (login == NULL) {
		login = jniEnv->GetMethodID(GameProxyClass, "login",
				"(Ljava/lang/String;)V");
	}
	jniEnv->CallVoidMethod(GameProxyObject, login,
			jniEnv->NewStringUTF(customParams));
	__android_log_print(ANDROID_LOG_INFO, "JNIMsg", "调用Login方法完毕");
}

void GameProxy::Logout(const char *customParams) {


  jclass GameProxyClass = GetGameProxyClass(jniEnv);
  jobject GameProxyObject = GetGameProxyObject(jniEnv, GameProxyClass);

	if (logout == NULL) {
		logout = jniEnv->GetMethodID(GameProxyClass, "logout",
				"(Ljava/lang/String;)V");
	}

	jniEnv->CallVoidMethod(GameProxyObject, logout,
			jniEnv->NewStringUTF(customParams));
}

void GameProxy::Charge(const char *itemName, int unitPrice, int defaultNum,
		const char *callBackInfo, const char * callbackUrl, PayCallBack *payCallBackParam) {

	payCallBack = payCallBackParam;

	__android_log_print(ANDROID_LOG_INFO, "JNIMsg", "do charge,调用不定额支付");
	__android_log_print(ANDROID_LOG_INFO, "JNIMsg", "do charge 0");


  jclass GameProxyClass = GetGameProxyClass(jniEnv);
  jobject GameProxyObject = GetGameProxyObject(jniEnv, GameProxyClass);

	__android_log_print(ANDROID_LOG_INFO, "JNIMsg", "do charge 1");
	if (charge == NULL) {
		charge =
				jniEnv->GetMethodID(GameProxyClass, "charge",
						"(Ljava/lang/String;IILjava/lang/String;Ljava/lang/String;Lcom/xinmei365/game/proxy/PayCallBack;)V");
	}
	__android_log_print(ANDROID_LOG_INFO, "JNIMsg", "do charge 2");

	jclass pcbcls = jniEnv->FindClass(
			"com/xinmei365/game/proxy/PayCallBackNativeImpl");
	jmethodID pcbid = jniEnv->GetMethodID(pcbcls, "<init>", "()V");
	jobject callBack = jniEnv->NewObject(pcbcls, pcbid);

	jniEnv->CallVoidMethod(GameProxyObject, charge,
			jniEnv->NewStringUTF(itemName), unitPrice, defaultNum,
			jniEnv->NewStringUTF(callBackInfo), jniEnv->NewStringUTF(callbackUrl), callBack);

}

void GameProxy::Pay(int amount, const char *unitName, int count,
		const char *callBackInfo, const char *callbackUrl, PayCallBack *payCallBackParam) {

	payCallBack = payCallBackParam;


    jclass GameProxyClass = GetGameProxyClass(jniEnv);
    jobject GameProxyObject = GetGameProxyObject(jniEnv, GameProxyClass);

	if (pay == NULL) {
		pay =
				jniEnv->GetMethodID(GameProxyClass, "pay",
						"(ILjava/lang/String;ILjava/lang/String;Ljava/lang/String;Lcom/xinmei365/game/proxy/PayCallBack;)V");
	}

	jclass pcbcls = jniEnv->FindClass(
			"com/xinmei365/game/proxy/PayCallBackNativeImpl");
	jmethodID pcbid = jniEnv->GetMethodID(pcbcls, "<init>", "()V");
	jobject callBack = jniEnv->NewObject(pcbcls, pcbid);

	jniEnv->CallVoidMethod(GameProxyObject, pay,  amount,
			jniEnv->NewStringUTF(unitName), count,
			jniEnv->NewStringUTF(callBackInfo), jniEnv->NewStringUTF(callbackUrl), callBack);
}

void GameProxy::Exit(ExitCallBack *callback) {
	exitCallBack = callback;

    jclass GameProxyClass = GetGameProxyClass(jniEnv);
    jobject GameProxyObject = GetGameProxyObject(jniEnv, GameProxyClass);

	if (onexit == NULL) {
		onexit =
				jniEnv->GetMethodID(GameProxyClass, "exit",
						"(Lcom/xinmei365/game/proxy/XMExitCallback;)V");
	}

	jclass ecbcls = jniEnv->FindClass(
			"com/xinmei365/game/proxy/XMExitCallBackNativeImpl");
	jmethodID ecbid = jniEnv->GetMethodID(ecbcls, "<init>", "()V");
	jobject ecb = jniEnv->NewObject(ecbcls, ecbid);
	jniEnv->CallVoidMethod(GameProxyObject, onexit, ecb);
}

void GameProxy::SetXMRoleData(
                      const char* roleId, const char* roleName, const char*  roleLevel,
                      const char*  zoneId, const char* zoneName  ) {


  jclass GameProxyClass = GetGameProxyClass(jniEnv);
  jobject GameProxyObject = GetGameProxyObject(jniEnv, GameProxyClass);

	if (setXMRoleData == NULL ) {
		setXMRoleData = jniEnv->GetMethodID(GameProxyClass, "setXMRoleData",
					"(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
	}


	jniEnv->CallVoidMethod(GameProxyObject, setXMRoleData,
			jniEnv->NewStringUTF(roleId),
			jniEnv->NewStringUTF(roleName),
			jniEnv->NewStringUTF(roleLevel),
			jniEnv->NewStringUTF(zoneId),
			jniEnv->NewStringUTF(zoneName));
}

void GameProxy::SetExtRoleData(const char* json) {

  jclass GameProxyClass = GetGameProxyClass(jniEnv);
  jobject GameProxyObject = GetGameProxyObject(jniEnv, GameProxyClass);

  if (setExtRoleData == NULL ) {
    setXMRoleData = jniEnv->GetMethodID(GameProxyClass, "setExtData", "(Ljava/lang/String;)V");
  }


  jniEnv->CallVoidMethod(GameProxyObject, setXMRoleData,
      jniEnv->NewStringUTF(json));
}

const char* GameProxy::GetAndroidManifestMeta(const char* name  ) {


  jclass GameProxyClass = GetGameProxyClass(jniEnv);
  jobject GameProxyObject = GetGameProxyObject(jniEnv, GameProxyClass);

  jmethodID method = jniEnv->GetMethodID(GameProxyClass, "getAndroidManifestMeta",
					"(Ljava/lang/String;)Ljava/lang/String;");



  jobject value = jniEnv->CallObjectMethod(GameProxyObject, method, jniEnv->NewStringUTF(name));
  return jstringTostr(jniEnv, (jstring)value);


}


const char* GameProxy::GetChannelLabel() {

  jclass GameProxyClass = GetGameProxyClass(jniEnv);
  jobject GameProxyObject = GetGameProxyObject(jniEnv, GameProxyClass);

  jmethodID method = jniEnv->GetMethodID(GameProxyClass, "getAndroidManifestMeta",
					"(Ljava/lang/String;)Ljava/lang/String;");

  jobject value = jniEnv->CallObjectMethod(GameProxyObject, method, jniEnv->NewStringUTF("CHANNEL_LABEL"));

  if(value ==  NULL){
  	return "lj_test";
  }
  return jstringTostr(jniEnv, (jstring)value);
}



void GameProxy::releaseResource(){

	jclass apdcls = jniEnv->FindClass(
				"com/xinmei365/game/proxy/XMNativeApplicationDestroy");

	jmethodID apdmid = jniEnv->GetMethodID(apdcls, "<init>", "()V");

  jobject apdob = jniEnv->NewObject(apdcls, apdmid);

	jmethodID method = jniEnv->GetMethodID(apdcls, "releaseResource","()V");

	jniEnv->CallVoidMethod(apdob, method);
}
}
