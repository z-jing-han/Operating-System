#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>

#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

using namespace std;

void* dothing(void*);
inline int findLeft(int);
inline int findRight(int);
void Exit(int);

class philosopher{
	public:
		int* num;
		int state;
		pthread_cond_t cond;
		pthread_t pthread;
		
		philosopher(int i) {
			num = (int*)malloc(sizeof(int));
			*num = i;
			state = THINKING;
			
			pthread_cond_init(&cond, NULL);
			
			pthread = i;
			pthread_create(&pthread, NULL, dothing, (void*)num);
		};
		void think(){
			sleep(1);
		};
		void eat(){
			sleep(1);
		};
		void print(){
			printf("philosopher %d: ", *num);
			switch(state){
				case THINKING:
					printf("thinking\n");
					break;
				case HUNGRY:
					printf("hungry\n");
					break;
				case EATING:
					printf("eating\n");
					break;
				default:
					printf("undefine\n");
			}
		}
		~philosopher(){
			
		};
};

class Monitor{
	public:
		pthread_mutex_t mutex;
		philosopher person[N] = {philosopher(0),philosopher(1),philosopher(2),philosopher(3),philosopher(4)};
		Monitor(){
			pthread_mutex_init(&mutex, NULL);
		};
		void printState(){
			for(int i = 0; i < N; i++){
				person[i].print();
			}
			printf("***********************\n");
		};
		void test(int i){
			if(person[i].state == HUNGRY && person[findLeft(i)].state != EATING && person[findRight(i)].state != EATING){
				person[i].state = EATING;
				pthread_cond_signal(&person[i].cond);
			}
		};
		void takeForks(int i){
			pthread_mutex_lock(&mutex);
			person[i].state = HUNGRY;
			test(*person[i].num);
			if(person[i].state != EATING){
				pthread_cond_wait(&person[i].cond,&mutex);
			}
			pthread_mutex_unlock(&mutex);
		};
		void putForks(int i){
			pthread_mutex_lock(&mutex);
			person[i].state = THINKING;
			test(findLeft(*person[i].num));
			test(findRight(*person[i].num));
			pthread_mutex_unlock(&mutex);
		};
		~Monitor(){
			for(int i = 0; i < N; ++i){
				free(person[i].num);
				pthread_join(person[i].pthread, NULL);
				pthread_cond_destroy(&person[i].cond);
			}
			pthread_mutex_destroy(&mutex);
		};
};

#endif
