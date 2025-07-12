#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>

#define N 5
#define LEFT (N+i-1)%N
#define RIGHT (i+1)%N
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define bool int
#define true 1
#define false 0

struct philosopher{
	int* num;
	int state;
	pthread_mutex_t semaphore;
	pthread_t pthread;
};

void printState();
void* dothing(void*);
void takeForks(int);
void putForks(int);
void test(int);
void think(int);
void eat(int);
void Exit();

#endif
