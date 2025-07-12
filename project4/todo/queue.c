#include "queue.h"
#define queue_c(T)	\
void EnQueue_##T(struct Node** Queue,T data,int type){	\
	insertFront_##T(Queue,data,type);	\
}	\
T DeQueue_##T(struct Node** Queue){	\
	if((*Queue) == NULL){	\
		printf("Queue is empty. Could't dequeue anything more.\n");	\
		return -1;	\
	}else{	\
		return deleteBehind_##T(Queue);	\
	}	\
}	\

queue_c(char);
queue_c(short);
queue_c(int);
queue_c(long);
queue_c(float);
queue_c(double);

void deleteAllQueue(struct Node** Queue){
	while((*Queue)){
		switch((*Queue)->type){
			case 0:
				DeQueue_char(Queue); break;
			case 1:
				DeQueue_short(Queue); break;
			case 2:
				DeQueue_int(Queue); break;
			case 3:
				DeQueue_long(Queue); break;
			case 4:
				DeQueue_float(Queue); break;
			case 5:
				DeQueue_double(Queue); break;
		}
	}
}

void printQueue(struct Node** Queue){
	if((*Queue) == NULL){
		printf("Queue is empty.\n");
	}else{
		printf("head: ");
		printDoublyLinkedListBehind(Queue);
		printf(":tail\n");
	}
}

