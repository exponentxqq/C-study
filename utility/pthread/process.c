//
// Created by 徐钦钦 on 2018/9/24.
//
#include <stdio.h>
#include <pthread.h>
#include "process.h"

void *printPthread(void *pthreadParam)
{
    // 传进来的是一个int型类型的指针，需要将参数转为int型的指针，然后再进行取值
    printf("pthread print and arg=%d\n", *((int*)pthreadParam));
    return 0;
}

int process()
{
    pthread_t pth_id;
    int *pth_red = NULL;
    int ret;
    int param = 11;

    ret = pthread_create(&pth_id, NULL, printPthread, &param);

    if (ret != 0) {
        printf("error\n");
        return -1;
    }

    printf("the main process.\n");

    pthread_join(pth_id, (void **) &pth_red); // 同步等待线程结束
    printf("thread_ret=%d\n", *pth_red);
    return 0;
}