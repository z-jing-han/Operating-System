#include "philosopher.h"

pthread_mutex_t mutex;
struct philosopher person[N];
bool running;

int main(){
	running = true;
	signal(SIGINT, Exit);
	pthread_mutex_init(&mutex, NULL);
	
	for(int i = 0; i < N; i++){
		person[i].num = malloc(sizeof(int));
		*person[i].num = i;
		person[i].state = THINKING;
		
		pthread_mutex_init(&person[i].semaphore, NULL);
		pthread_mutex_lock(&person[i].semaphore);
		
		person[i].pthread = i;
		pthread_create(&person[i].pthread, NULL, dothing, (void*)person[i].num);
		
	}
	
	while(running){
		pthread_mutex_lock(&mutex);
		printState();
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	
	for(int i = 0; i < N; i++){
		pthread_join(person[i].pthread, NULL);
		pthread_mutex_destroy(&person[i].semaphore);
		free(person[i].num);
	}
	
	pthread_mutex_destroy(&mutex);
	
	return 0;
}

void printState(){
	for(int i = 0; i < N; i++){
		printf("philosopher %d: ", i);
		switch(person[i].state){
			case 0:
				printf("thinking\n");
				break;
			case 1:
				printf("hungry\n");
				break;
			case 2:
				printf("eating\n");
				break;
			default:
				printf("undefine\n");
		}
	}
	printf("***********************\n");
}

void* dothing(void* pi){
	int i = *((int*)pi);
	while(running){
		think(i);
		takeForks(i);
		eat(i);
		putForks(i);
	}
	printf("philosopher %d stop\n", i);
	return NULL;
}

void takeForks(int i){
	pthread_mutex_lock(&mutex);
	person[i].state = HUNGRY;
	test(i);
	pthread_mutex_unlock(&mutex);
	pthread_mutex_lock(&person[i].semaphore);
}

void putForks(int i){
	pthread_mutex_lock(&mutex);
	person[i].state = THINKING;
	test(LEFT);
	test(RIGHT);
	pthread_mutex_unlock(&mutex);
}

void test(int i){
	if(person[i].state == HUNGRY && person[LEFT].state != EATING && person[RIGHT].state != EATING){
		person[i].state = EATING;
		pthread_mutex_unlock(&person[i].semaphore);
	}
}

void think(int i){
	sleep(1);
}

void eat(int i){
	sleep(1);
}

void Exit(){
	printf("\n");
	running = false;
}	
