//
// Created by 徐钦钦 on 2018/9/24.
//

#include <pthread.h>

#ifndef CPROGRAM_PTHREADSYNC_H
#define CPROGRAM_PTHREADSYNC_H

void *decrement(void *params);
void * increment(void *params);

typedef struct Pthread_param {
    pthread_cond_t count_nz_event;
    pthread_mutex_t count_lock;
    unsigned count;
} thread_param;

#endif //CPROGRAM_PTHREADSYNC_H
