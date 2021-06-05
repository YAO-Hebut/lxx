#include <stdio.h>  
#include <pthread.h>  
#include<semaphore.h>
#include<unistd.h>
sem_t empty, full;                
pthread_mutex_t mutex;          
int buffer_count = 0;               
void *producer(void *arg) {
	while (1) {
		sleep(1);
		sem_wait(&empty); 
		pthread_mutex_lock(&mutex);     
		printf(" producer put a product to buffer.");
		buffer_count++;
		printf("the buffer_count is %d\n", buffer_count);
		pthread_mutex_unlock(&mutex); 
		sem_post(&full);         
	}
}
void *consumer(void *arg) {
	while (1)
	{
		sleep(2);
		sem_wait(&full); 
		pthread_mutex_lock(&mutex);    
		printf(" consumer get a product from buffer.");
		buffer_count--;
		printf("the buffer_count is %d\n", buffer_count);
		pthread_mutex_unlock(&mutex); 
		sem_post(&empty);       
	}
}
int main(int argc, char *argv[]) {
	pthread_t thrd_producer, thrd_consumer;
	pthread_mutex_init(&mutex, NULL);   
	sem_init(&empty, 0, 5);           
	sem_init(&full, 0, 0);            
	if (pthread_create(&thrd_producer, NULL, producer, NULL) != 0)
		printf("thread create failed.");
	if (pthread_create(&thrd_consumer, NULL, consumer, NULL) != 0)
		printf("thread create failed.");
	if (pthread_join(thrd_producer, NULL) != 0)
		printf(" wait thread failed.");
	if (pthread_join(thrd_consumer, NULL) != 0)
		printf(" wait thread failed.");
	sem_destroy(&full);               
	sem_destroy(&empty);           
	pthread_mutex_destroy(&mutex);      
	return 0;
}
