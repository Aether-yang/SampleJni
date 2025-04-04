
#include <android/log.h>


#define LOG_TAG "MyJni"

// 定义通用日志宏，支持动态 tag 参数
#define LOGX(level, tag, ...)  __android_log_print(level, tag, __VA_ARGS__)

#define LOGV(tag, ...)  LOGX(ANDROID_LOG_VERBOSE, tag, __VA_ARGS__)
#define LOGD(tag, ...)  LOGX(ANDROID_LOG_DEBUG, tag, __VA_ARGS__)
#define LOGI(tag, ...)  LOGX(ANDROID_LOG_INFO, tag, __VA_ARGS__)
#define LOGW(tag, ...)  LOGX(ANDROID_LOG_WARN, tag, __VA_ARGS__)
#define LOGE(tag, ...)  LOGX(ANDROID_LOG_ERROR, tag, __VA_ARGS__)
#define LOGF(tag, ...)  LOGX(ANDROID_LOG_FATAL, tag, __VA_ARGS__)

