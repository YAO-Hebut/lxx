#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

struct DataBuffer

{

	int buffer[2];

	int count; //当前产品数量

} BUFFER;

void push(int data)
{
	BUFFER.buffer[BUFFER.count++] = data;
}

int take()
{
	int data = BUFFER.buffer[0];
	BUFFER.count--;
	for (int i = 0; i < BUFFER.count; i++)
	{
		BUFFER.buffer[i] = BUFFER.buffer[i + 1];
	}

	return data;
}

sem_t mutex, full, empty;

void *producer(void *arg)
{

	int product;
	int a;
	a = *((int *)arg);
	srand(time(NULL));
	product = rand() % 100 + a;
	printf("producer %d apply for buffer\n", a);

	sleep(1);

	sem_wait(&empty);

	printf("producer %d apply for buffer successfully\n", a);

	sleep(1);
}

void *consumer(void *arg)

{

	int index;

	int a;

	a = *((int *)arg);
	printf("customer %d apply for buffer\n", a);

	sem_wait(&full);

	printf("customer %d apply for buffer successfully\n", a);

	sleep(1);

	sem_wait(&mutex);

	index = take();

	printf("customer %d take product %d from buffer\n", a, index);

	sleep(1);

	sem_post(&mutex);

	sem_post(&empty);

	printf("custmoer %d free buffer，the buffer have %d products\n", a, BUFFER.count);
}

int main()
{

	int is_error;

	pthread_t producer_t, consumer_t;

	is_error = pthread_create(&producer_t, NULL, producer, NULL);
	if (!is_error)
	{
		printf("Producer creat failed...");
	}
	else
	{
		printf("Producer creat successfully");
	}

	is_error = pthread_create(&consumer_t, NULL, consumer, NULL);
	if (!is_error)
	{
		printf("Consumer creat failed...");
	}
	else
	{
		printf("Consumer creat successfully");
	}

	pthread_join(producer_t, NULL);

	pthread_join(consumer_t, NULL);

	return 0;
}
