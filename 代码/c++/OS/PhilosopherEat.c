#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

sem_t chopstick[5] = {1, 1, 1, 1, 1};
sem_t mutex = 1;

void *EatThink(void *arg)
{
    char philosopher = *(char *)arg;

    int left, right;

    switch (philosopher)
    {
    case 'A':
    {
        right = 5;
        left = 1;
    }
    case 'B':
    {
        right = 1;
        left = 2;
    }
    case 'C':
    {
        right = 2;
        left = 3;
    }
    case 'D':
    {
        right = 3;
        left = 4;
    }
    case 'E':
    {
        right = 4;
        left = 5;
    }
    }

    while (1)
    {
        sleep(1);

        sem_wait(&mutex); //保护信号量，防止产生死锁

        sem_wait(&chopstick[left]);

        printf("Philosopher %c pick up chopstick %d\n", philosopher, left);

        sem_wait(&chopstick[right]);

        printf("Philosopher %c pick up chopstick %d\n", philosopher, right);

        sem_post(&mutex);

        printf("The Philosopher is eating\n");

        sem_post(&chopstick[right]);

        printf("Philosopher %c put down chopstick %d\n", philosopher, right);

        sem_post(&chopstick[left]);

        printf("Philosopher %c put down chopstick %d\n", philosopher, left);
    }
}

int main()
{
    pthread_t A, B, C, D, E;

    pthread_create(&A, NULL, EatThink, NULL);
    pthread_create(&B, NULL, EatThink, NULL);
    pthread_create(&C, NULL, EatThink, NULL);
    pthread_create(&D, NULL, EatThink, NULL);
    pthread_create(&E, NULL, EatThink, NULL);

    pthread_join(&A, NULL);
    pthread_join(&B, NULL);
    pthread_join(&C, NULL);
    pthread_join(&D, NULL);
    pthread_join(&E, NULL);

    return 0;
}