/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include<android/log.h>
/* Header for class demo_sunqi13_myapplication_TimeUtils */

#ifndef _Included_demo_sunqi13_myapplication_TimeUtils
#define _Included_demo_sunqi13_myapplication_TimeUtils
#ifdef __cplusplus

#ifndef LOG_TAG
#define LOG_TAG "sunqi_log"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,LOG_TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,LOG_TAG ,__VA_ARGS__) // 定义LOGF类型
#endif

#define  LOGE(...) __android_log_print(ANDROID_LOG_ERROR,"JNI",__VA_ARGS__);
extern "C" {
#endif
/*
 * Class:     demo_sunqi13_myapplication_TimeUtils
 * Method:    getNum
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_demo_sunqi13_myapplication_TimeUtils_getNum
        (JNIEnv *, jobject clazz, jint art);


/*
 * Class:     demo_sunqi13_myapplication_TimeUtils
 * Method:    getNum2
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_demo_sunqi13_myapplication_TimeUtils_getNum2
        (JNIEnv *, jobject, jint);

/*
 * Class:     demo_sunqi13_myapplication_TimeUtils
 * Method:    getNum3
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_demo_sunqi13_myapplication_TimeUtils_getNum3
        (JNIEnv *, jobject, jintArray);

/*
 * Class:     demo_sunqi13_myapplication_TimeUtils
 * Method:    printEachChar
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_demo_sunqi13_myapplication_TimeUtils_printEachChar
        (JNIEnv *, jobject, jstring);

/*
 * Class:     demo_sunqi13_myapplication_TimeUtils
 * Method:    testFiled
 */
JNIEXPORT void JNICALL Java_demo_sunqi13_myapplication_TimeUtils_testFiled
        (JNIEnv *env, jobject);


/*
 * Class:     demo_sunqi13_myapplication_TimeUtils
 * Method:    testNewObject
 */
JNIEXPORT void JNICALL
Java_demo_sunqi13_myapplication_TimeUtils_testNewObject(JNIEnv *env, jobject thiz);

#ifdef __cplusplus
}
#endif
#endif
