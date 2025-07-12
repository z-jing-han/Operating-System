#include "queue_ptr.h"
#define queue_ptr_c(T)	\
void EnQueue_ptr_##T(struct Node** Queue,T* data,int type){	\
	insertFront_ptr_##T(Queue,data,type);	\
}	\
T* DeQueue_ptr_##T(struct Node** Queue){	\
	if((*Queue) == NULL){	\
		printf("Queue is empty. Could't dequeue anything more.\n");	\
		return NULL;	\
	}else{	\
		return deleteBehind_ptr_##T(Queue);	\
	}	\
}	\

queue_ptr_c(char);
queue_ptr_c(short);
queue_ptr_c(int);
queue_ptr_c(long);
queue_ptr_c(float);
queue_ptr_c(double);


