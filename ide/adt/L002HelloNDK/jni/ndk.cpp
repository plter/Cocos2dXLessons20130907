#include <jni.h>
#include "cn_eoe_hellondk_Bridge.h"
#include "cn_eoe_hellondk_NativeMath.h"


jint Java_cn_eoe_hellondk_Bridge_getNum
  (JNIEnv *env, jobject __this){

	jclass _class = env->FindClass("cn/eoe/hellondk/Bridge");
	jmethodID mid = env->GetMethodID(_class,"showMsg","()V");
	env->CallVoidMethod(__this,mid);
	return 8;
}

jint Java_cn_eoe_hellondk_NativeMath_max
  (JNIEnv *, jclass, jint a, jint b){
	return a>b?a:b;
}

void Java_cn_eoe_hellondk_Bridge_callC
  (JNIEnv *env, jclass _class){
	env->CallStaticVoidMethod(_class,
			env->GetStaticMethodID(_class,"staticShowMsg","(Ljava/lang/String;)V"),
			env->NewStringUTF("SunQiming"));
}
