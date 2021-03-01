//
// Created by Sun,Qi(Int'l RD) on 2021/2/25.
//
#include <jni.h>
#include <string>
#include "TimeUtils.h"

extern "C"
{
JNIEXPORT jstring JNICALL
Java_demo_sunqi13_myapplication_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject clazz /* this */) {
    std::string hello = "Hello from C++";

    // 1. 获取 thiz 的 class，也就是 java 中的 Class 信息
    jclass thisclazz = env->GetObjectClass(clazz);
    // 2. 根据 Class 获取 getClass 方法的 methodID，第三个参数是签名(params)return
    jmethodID mid_getClass = env->GetMethodID(thisclazz, "getClass", "()Ljava/lang/Class;");

    // 3. 执行 getClass 方法，获得 Class 对象
    jobject clazz_instance = env->CallObjectMethod(clazz, mid_getClass);
    // 4. 获取 Class 实例
    jclass thiz = env->GetObjectClass(clazz_instance);
    // 5. 根据 class  的 methodID
    jmethodID mid_getName = env->GetMethodID(thiz, "getName", "()Ljava/lang/String;");
    // 6. 调用 getName 方法
    jstring name = static_cast<jstring>(env->CallObjectMethod(clazz_instance, mid_getName));
//    LOGE("class name:%s", env->GetStringUTFChars(name, 0));
    return name;
}

JNIEXPORT jstring JNICALL
Java_demo_sunqi13_myapplication_MediaUtils_play(
        JNIEnv *env,
        jobject /* this */) {
    std::string status = "Media Play";
    return env->NewStringUTF(status.c_str());
}

JNIEXPORT jstring JNICALL
Java_demo_sunqi13_myapplication_MediaUtils_pause(
        JNIEnv *env,
        jobject /* this */) {
    std::string status = "Media Pause";
    return env->NewStringUTF(status.c_str());
}

JNIEXPORT jstring JNICALL
Java_demo_sunqi13_myapplication_MediaUtils_stop(
        JNIEnv *env,
        jobject /* this */) {
    std::string status = "Media Stop";
    return env->NewStringUTF(status.c_str());
}


JNIEXPORT jint JNICALL
Java_demo_sunqi13_myapplication_TimeUtils_getNum(
        JNIEnv *env, jobject clazz, jint input) {
    return 2 * input;
}

JNIEXPORT void JNICALL Java_demo_sunqi13_myapplication_TimeUtils_getNum2
        (JNIEnv *, jobject, jint) {

}

JNIEXPORT jint JNICALL Java_demo_sunqi13_myapplication_TimeUtils_getNum3
        (JNIEnv *env, jobject clazz, jintArray array) {
    // 1.获取数组长度
    jint len = env->GetArrayLength(array);
    jboolean isCopy;

    // 2.获取数组地址
    // 第二个参数代表 javaArray -> c/c++ Array 转换的方式：
    // 0: 把指向Java数组的指针直接传回到本地代码中
    // 1: 新申请了内存，拷贝了数组
    // 返回值： 数组的地址（首元素地址
    jint *firstElement = env->GetIntArrayElements(array, &isCopy);
    jint result = 0;
    // 3.遍历数组（移动地址）
    for (int i = 0; i < len; ++i) {
        result = result + *(firstElement + i);
    }
    // 4.使用后释放数组
    // 第一个参数是 jarray，第二个参数是 GetIntArrayElements 返回值
    // 第三个参数代表 mode
    env->ReleaseIntArrayElements(array, firstElement, 0);

    // 5. 创建一个 java 数组
    return result;
}

JNIEXPORT void JNICALL Java_demo_sunqi13_myapplication_TimeUtils_printEachChar
        (JNIEnv *env, jobject, jstring str) {
    // 1.jstring -> char*
    // java  中的字符创是 unicode 编码， c/C++ 是UTF编码，所以需要转换一下。第二个参数作用同上面
    const char *firstChar = env->GetStringUTFChars(str, NULL);

    // 2.异常处理
    if (firstChar == NULL) {
        return;
    }

    // 3.当做一个 char 数组打印
    jint length = env->GetStringLength(str);
    for (int i = 0; i < length; ++i) {
        LOGE("sunqi_log Char at %d : %c", i, *(firstChar + i))
    }

    // 4.释放
    env->ReleaseStringUTFChars(str, firstChar);
}


/*
 *
操作 jobject
c/c++ 操作 java 中的对象使用的是 java 中反射，步骤分为：
- 获取 class 类
- 根据成员变量名获取 methodID / fieldID
- 调用 get/set 方法操作 field，或者 CallObjectMethod 调用 method

操作 Field
- 非静态成员变量使用: GetXXXField,比如 GetIntField，对于引用类型，比如 String，使用 GetObjectField
- 对于静态成员变量使用: GetStaticXXXField,比如 GetStaticIntField

 * */

JNIEXPORT void JNICALL
Java_demo_sunqi13_myapplication_TimeUtils_testFiled(JNIEnv *env, jobject thiz) {
    LOGE("sunqi_log Java_demo_sunqi13_myapplication_TimeUtils_testFiled")
    jclass  clazz = env->GetObjectClass(thiz);

    jfieldID  strFieldId = env->GetFieldID(clazz, "testFiled", "Ljava/lang/String;");
    jstring javaStrFile = static_cast<jstring>(env->GetObjectField(thiz, strFieldId));
    const  char* cStr = env->GetStringUTFChars(javaStrFile, NULL);
    LOGE("sunqi_log 获取 String field ：%s",cStr)

    jstring newValue = env->NewStringUTF("新的字符创");
    env-> SetObjectField(thiz,strFieldId,newValue);
    jstring javaStrFile2 = static_cast<jstring>(env->GetObjectField(thiz, strFieldId));
    const  char* cStr2 = env->GetStringUTFChars(javaStrFile2, NULL);
    LOGE("sunqi_log 反射修改后，获取 String field ：%s",cStr2)

    env->ReleaseStringUTFChars(javaStrFile, cStr);
    env->ReleaseStringUTFChars(javaStrFile2, cStr2);
    env->DeleteLocalRef(newValue);

    jfieldID  staticFieldId = env->GetStaticFieldID(clazz, "staticTestFiled", "I");
    jint  staticIntFile = env->GetStaticIntField(clazz, staticFieldId);
    LOGE("sunqi_log 获取 static field ：%d", staticIntFile)

    jfieldID  staticLongFieldId = env->GetStaticFieldID(clazz, "staticTestLongFiled", "J");
    jlong staticLongFile = env->GetStaticLongField(clazz, staticLongFieldId);
    LOGE("sunqi_log 获取 staticLongFile  ：%ld", staticLongFile)

    env->DeleteLocalRef(clazz);
}
}