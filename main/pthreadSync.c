//
// Created by 徐钦钦 on 2018/9/24.
//

#include <pthread.h>
#include <stdio.h>
#include "pthreadSync.h"

int main()
{
    thread_param param;
    param.count = 0;
    pthread_mutex_init(&param.count_lock, NULL);
    pthread_cond_init(&param.count_nz_event, NULL);

    pthread_t pth_id1, pth_id2;
    pthread_create(&pth_id1, NULL, decrement, &param);
    pthread_create(&pth_id2, NULL, increment, &param);


    pthread_join(pth_id1, NULL);
    pthread_join(pth_id2, NULL);

//    increment(NULL);
    printf("count=%d\n", param.count);
}