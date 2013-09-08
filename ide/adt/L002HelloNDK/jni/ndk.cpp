#include <jni.h>
#include "cn_eoe_hellondk_Bridge.h"
#include "cn_eoe_hellondk_NativeMath.h"


jint Java_cn_eoe_hellondk_Bridge_getNum
  (JNIEnv *, jobject){
	return 8;
}

jint Java_cn_eoe_hellondk_NativeMath_max
  (JNIEnv *, jclass, jint a, jint b){
	return a>b?a:b;
}
