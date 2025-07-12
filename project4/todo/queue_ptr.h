#ifndef QUEUE_PTR_H
#define QUEUE_PTR_H
#include "list_ptr.h"
#include "queue.h"
#define queue_ptr_h(T)	\
void EnQueue_ptr_##T(struct Node** Queue,T* data,int type);	\
T* DeQueue_ptr_##T(struct Node** Queue);

queue_ptr_h(char);
queue_ptr_h(short);
queue_ptr_h(int);
queue_ptr_h(long);
queue_ptr_h(float);
queue_ptr_h(double);
#endif
