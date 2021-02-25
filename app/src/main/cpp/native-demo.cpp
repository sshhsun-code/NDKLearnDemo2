//
// Created by Sun,Qi(Int'l RD) on 2021/2/25.
//
#include <jni.h>
#include <string>

extern "C"
{
JNIEXPORT jstring JNICALL
Java_demo_sunqi13_myapplication_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
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
}