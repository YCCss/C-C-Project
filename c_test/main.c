#include <stdio.h>
#include <unistd.h>

#include "tool.h"
#include "tool1.h"

int main()
{
    int a = 10, b = 5;
    LOG("hello world!");
    
    LOG("%d + %d = %d", a, b, msum(a, b)); //test module1
    LOG("%d - %d = %d", a, b, msub(a, b)); //test module2
    return 0;
}