#include <iostream>
#include <signal.h>
#include <time.h>
#include <thread>
#include <cstring>

class Timer
{
public:
    Timer(void (*callback)(), unsigned int interval) : callback(callback), interval(interval)
    {
        struct sigevent sev;
        std::memset(&sev, 0, sizeof(sev));  // 确保清空结构体
        sev.sigev_notify = SIGEV_THREAD;
        sev.sigev_notify_function = timerCallback;
        sev.sigev_value.sival_ptr = this;
        if (timer_create(CLOCK_REALTIME, &sev, &timerid) == -1)
        {
            std::cerr << "Error creating timer." << std::endl;
        }
    }

    ~Timer()
    {
        stop();                // 在析构函数中停止定时器
        timer_delete(timerid); // 删除定时器对象
    }

    void start()
    {
        struct itimerspec its;
        its.it_interval.tv_sec = interval / 1000;
        its.it_interval.tv_nsec = (interval % 1000) * 1000000;
        its.it_value.tv_sec = its.it_interval.tv_sec;
        its.it_value.tv_nsec = its.it_interval.tv_nsec;

        if (timer_settime(timerid, 0, &its, NULL) == -1)
        {
            std::cerr << "Error starting timer." << std::endl;
        }
    }

    void stop()
    {
        struct itimerspec its;
        its.it_interval.tv_sec = 0;
        its.it_interval.tv_nsec = 0;
        its.it_value.tv_sec = 0;
        its.it_value.tv_nsec = 0;

        if (timer_settime(timerid, 0, &its, NULL) == -1)
        {
            std::cerr << "Error stopping timer." << std::endl;
        }
    }

    static void timerCallback(sigval_t sv)
    {
        Timer *timer = (Timer *)sv.sival_ptr;
        timer->callback();
    }

private:
    timer_t timerid;
    void (*callback)();
    unsigned int interval;
};

int g_count;
void my_task()
{
    printf("Task executed : %d.\n", g_count++);
    if (g_count > 1000)
    {
        printf("--------------------------Task executed : set g_count=0---------------------------------\n");
        g_count = 0;
    }
}

// g++ -o mp timer.cpp -lpthread
// 很奇怪，不能将这个放到ut_test中，只能单独build 这个文件，否者timer起不来
int timer_cpp_main()
{
    Timer timer(my_task, 1000); // 创建一个间隔为1秒的定时器，执行任务函数task
    timer.start();              // 启动定时器

    // 运行一段时间后停止定时器
    int count = 0;
    while(1) {
        printf("running---------- %d\n", count++);
        sleep(3);
        if (count == 20) break;
    }
    timer.stop();
    
    return 0;
}
void timer_ut_test(int n)
{
    switch (n)
    {
        case 1:
        {
            timer_cpp_main(); 
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