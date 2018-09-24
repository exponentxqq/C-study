//
// Created by 徐钦钦 on 2018/9/24.
//

#include "pthreadlock.h"
#include <stdio.h>
#include <pthread.h>

void *pthread_function(void *params)
{
    pthread_param *param = (pthread_param *)params;
    int *counter = &param->counter;
    pthread_mutex_lock(&param->mutex);
    (*counter)++;   // C语言++操作是非原子性操作
    printf("pthread(%ld) counter=%d\n", pthread_self(),  *counter);
    pthread_mutex_unlock(&param->mutex);
    return NULL;
}