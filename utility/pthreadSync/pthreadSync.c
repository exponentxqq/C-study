//
// Created by 徐钦钦 on 2018/9/24.
//

#include <stdio.h>
#include <pthread.h>
#include "pthreadSync.h"

void *decrement(void *params)
{
    thread_param *param = (thread_param *)params;
    pthread_mutex_lock(&param->count_lock);
    printf("dec before count=%d\n", param->count);
    while (param->count == 0) {
        /**
         *  先释放锁，避免increment无法获取锁导致死锁
         *  等待信号返回
         *  重新获取锁
         */
        pthread_cond_wait(&param->count_nz_event, &param->count_lock);
    }

    param->count--;
    printf("dec after count=%d\n", param->count);
    pthread_mutex_unlock(&param->count_lock);
    return NULL;
}

void * increment(void * params)
{
    thread_param *param = (thread_param *)params;
    pthread_mutex_lock(&param->count_lock);
    printf("inc before count=%d\n", param->count);
    param->count++;
    if (param->count == 1) {
        // 发送信号，通知pthread_cond_wait
        pthread_cond_signal(&param->count_nz_event);
    }
    printf("inc after count=%d\n", param->count);
    pthread_mutex_unlock(&param->count_lock);
    return NULL;
}