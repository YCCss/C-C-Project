#include <iostream>
#include <cstdio>
#include <unistd.h>

#include "tool.h"
#include "timer.h"

int main()
{
    int num;
    std::cout << "UT test start!" << std::endl;
    while (1)
    {
        std::cout << "Pleas input test case number!" << std::endl;
        std::cin >> num;
        switch (num)
        {
            case 1:
            {
                tool_ut_test(1);
                break;
            }
            case 2:
            {
                timer_ut_test(2);
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
    std::cout << "UT test end!" << std::endl;
    return 0;
}