//
// Created by 徐钦钦 on 2018/9/24.
//

#include <pthread.h>
#include <stdio.h>

pthread_mutex_t count_lock;
pthread_cond_t count_nz_event;

unsigned count = 0;

void *decrement(void *params)
{
    pthread_mutex_lock(&count_lock);

    while (count == 0) {
        /**
         *  先释放锁，避免increment无法获取锁导致死锁
         *  等待信号返回
         *  重新获取锁
         */
        pthread_cond_wait(&count_nz_event, &count_lock);
    }

    count--;
    pthread_mutex_unlock(&count_lock);
    return NULL;
}

void * increment(void * params) {
    pthread_mutex_lock(&count_lock);
    count++;
    if (count == 1) {
        // 发送信号，通知pthread_cond_wait
        pthread_cond_signal(&count_nz_event);
    }
    pthread_mutex_unlock(&count_lock);
    return NULL;
}

int main()
{
    pthread_mutex_init(&count_lock, NULL);
    pthread_cond_init(&count_nz_event, NULL);

    pthread_t pth_id1, pth_id2;
    pthread_create(&pth_id1, NULL, decrement, NULL);
    pthread_create(&pth_id2, NULL, increment, NULL);

    increment(NULL);

    pthread_join(pth_id1, NULL);
    pthread_join(pth_id2, NULL);

    printf("count=%d\n", count);
}