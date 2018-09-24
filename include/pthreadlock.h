//
// Created by 徐钦钦 on 2018/9/24.
//

#include <pthread.h>

#ifndef CPROGRAM_PTHREADLOCK_H
#define CPROGRAM_PTHREADLOCK_H

typedef struct Pthread_param {
    int counter;
    pthread_mutex_t mutex;
} pthread_param;

void *pthread_function(void *params);

#endif //CPROGRAM_PTHREADLOCK_H
