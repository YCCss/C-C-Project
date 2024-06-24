#ifndef _TOOL_H
#define _TOOL_H

#include <stdio.h>


#define LOG(fmt, ...) do { printf("[LOG] " fmt "\n", ##__VA_ARGS__); } while(0)


int msum(int a, int b);


#endif