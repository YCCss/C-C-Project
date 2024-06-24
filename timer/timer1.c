#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

void error_exit(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void timer_handler(int signo, siginfo_t *info, void *context) {
    void (*callback)() = info->si_value.sival_ptr;
    callback();
}

void set_timer(int initial_seconds, int interval_seconds, void (*callback)()) {
    struct sigevent sev;
    struct itimerspec its;
    timer_t timerid;
    struct sigaction sa;

    // 设置信号处理程序
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = timer_handler;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGRTMIN, &sa, NULL) == -1) {
        error_exit("sigaction");
    }

    // 创建定时器
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = (void *)callback;
    if (timer_create(CLOCK_REALTIME, &sev, &timerid) == -1) {
        error_exit("timer_create");
    }

    // 设置定时器初始时间和间隔时间
    its.it_value.tv_sec = initial_seconds;
    its.it_value.tv_nsec = 0;
    its.it_interval.tv_sec = interval_seconds;
    its.it_interval.tv_nsec = 0;

    if (timer_settime(timerid, 0, &its, NULL) == -1) {
        error_exit("timer_settime");
    }
}

int count;
void my_task() {
    printf("Task executed : %d.\n", count++);
    if(count > 1000) {
        printf("--------------------------Task executed : set count=0---------------------------------\n");
        count = 0;
    }
}

// gcc -o mp main.c -lrt
int main() {
    int initial_seconds = 10;
    int interval_seconds = 5; // 定时器每5秒重复触发一次
    set_timer(initial_seconds, interval_seconds, my_task);

    // 主线程继续运行，等待信号处理
    while (1) {
        pause();
    }

    return 0;
}