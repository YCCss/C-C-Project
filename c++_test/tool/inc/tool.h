#pragma once

#include <cstdio>

#define DEBUG_SWITCH

#ifdef DEBUG_SWITCH
#define LOGD(fmt, ...) do { printf("[Debug] " fmt "\n", ##__VA_ARGS__); } while(0)
#define LOGW(fmt, ...) do { printf("[Warning] " fmt "\n", ##__VA_ARGS__); } while(0)
#define LOGE(fmt, ...) do { printf("[Error] " fmt "\n", ##__VA_ARGS__); } while(0)
#define LOGI(fmt, ...) do { printf("[Info] " fmt "\n", ##__VA_ARGS__); } while(0)
#elif
#define LOGD(fmt, ...) 
#define LOGW(fmt, ...) 
#define LOGE(fmt, ...) 
#define LOGI(fmt, ...) 
#endif

void tool_ut_test(int n);


