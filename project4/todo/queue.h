#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"
#define queue_h(T)	\
void EnQueue_##T(struct Node** Queue,T data,int type);	\
T DeQueue_##T(struct Node** Queue);	\

queue_h(char);
queue_h(short);
queue_h(int);
queue_h(long);
queue_h(float);
queue_h(double);

void deleteAllQueue(struct Node** Queue);
void printQueue(struct Node** Queue);
#endif
