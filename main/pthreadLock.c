//
// Created by 徐钦钦 on 2018/9/24.
//

#include "pthreadlock.h"
#include <stdio.h>
#include <pthread.h>

int main()
{
    pthread_param param;
    param.counter = 0;

    pthread_t pthread_ids[10];
    int i, j;

    pthread_mutex_init(&param.mutex, NULL); //初始化线程锁
    for (i = 0; i < 10; ++i) {
        pthread_create(&pthread_ids[i], NULL, pthread_function, &param);
    }

    for (j = 0; j < 10; ++j) {
        pthread_join(pthread_ids[j], NULL);
    }

    return 0;
}