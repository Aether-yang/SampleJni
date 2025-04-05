//
// Created by Next on 2016/8/12.
//

#include "com_jeanboy_demo_jnitest_NdkTest.h"
#include "common.hpp"
#include <ctime>


/*#include <sys/time.h>
int64_t getCurrentTimeMs() {
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    return (int64_t)tv.tv_sec * 1000 + tv.tv_usec/1000;
}*/
int64_t getTimestampMsec() {
    struct timespec res{};
    clock_gettime(CLOCK_REALTIME, &res); // 获取实时时钟时间 [[6]]
    return (res.tv_sec * 1000.0) + (res.tv_nsec / 1e6); // 转换为毫秒
}


JNIEXPORT jstring JNICALL Java_com_jeanboy_demo_jnitest_NdkTest_getString
        (JNIEnv *env, jclass type) {
    __android_log_print(ANDROID_LOG_INFO, LOG_TAG, "%s", "getString");
    return env->NewStringUTF("hello world!!!");
}

JNIEXPORT jlong JNICALL Java_com_jeanboy_demo_jnitest_NdkTest_getTimestampMillis
        (JNIEnv *env, jclass type) {
    long tsMs = getTimestampMsec();
    //LOGI(LOG_TAG, "getTimestampMillis=%ld", tsMs);
    return tsMs;
}

/*
 * Class:     com_jeanboy_demo_jnitest_NdkTest
 * Method:    doAdd
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_jeanboy_demo_jnitest_NdkTest_doAdd
        (JNIEnv *env, jclass type, jint param1, jint param2) {
    return param1 + param2;
}

