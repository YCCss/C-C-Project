#include "tool.h"

int msum(int a, int b)
{
    return a + b;
}

void tool_ut_test(int n)
{
    switch (n)
    {
        case 1:
        {
            LOGD("sum = %d", msum(5, 6));
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        default:
        {
            break;
        }
    }
}