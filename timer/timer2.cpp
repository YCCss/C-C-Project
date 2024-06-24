#include <iostream>
#include <signal.h>
#include <time.h>

class Timer {
public:
    Timer(void (*callback)(), unsigned int interval) : callback(callback), interval(interval) {
        struct sigevent sev;
        sev.sigev_notify = SIGEV_THREAD;
        sev.sigev_notify_function = timerCallback;
        sev.sigev_value.sival_ptr = this;
        if (timer_create(CLOCK_REALTIME, &sev, &timerid) == -1) {
            std::cerr << "Error creating timer." << std::endl;
        }
    }

    ~Timer() {
        stop(); // 在析构函数中停止定时器
        timer_delete(timerid); // 删除定时器对象
    }

    void start() {
        struct itimerspec its;
        its.it_interval.tv_sec = interval / 1000;
        its.it_interval.tv_nsec = (interval % 1000) * 1000000;
        its.it_value.tv_sec = its.it_interval.tv_sec;
        its.it_value.tv_nsec = its.it_interval.tv_nsec;

        if (timer_settime(timerid, 0, &its, NULL) == -1) {
            std::cerr << "Error starting timer." << std::endl;
        }
    }

    void stop() {
        struct itimerspec its;
        its.it_interval.tv_sec = 0;
        its.it_interval.tv_nsec = 0;
        its.it_value.tv_sec = 0;
        its.it_value.tv_nsec = 0;

        if (timer_settime(timerid, 0, &its, NULL) == -1) {
            std::cerr << "Error stopping timer." << std::endl;
        }
    }

    static void timerCallback(sigval_t sv) {
        Timer* timer = (Timer*)sv.sival_ptr;
        timer->callback();
    }

private:
    timer_t timerid;
    void (*callback)();
    unsigned int interval;
};

int count;
void my_task() {
    printf("Task executed : %d.\n", count++);
    if(count > 1000) {
        printf("--------------------------Task executed : set count=0---------------------------------\n");
        count = 0;
    }
}

// g++ -o mp timer2.cpp -lpthread
int main() {
    Timer timer(my_task, 1000); // 创建一个间隔为1秒的定时器，执行任务函数task
    timer.start(); // 启动定时器

    // 运行一段时间后停止定时器
    while (1) {
        pause();
    }

    return 0;
}