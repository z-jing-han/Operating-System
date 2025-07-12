#ifndef LIST_H
#define LIST_H
#include "mm.h"
struct Node{
	struct Node* pre;
	union{
		char data_char;
		short data_short;
		int data_int;
		long data_long;
		float data_float;
		double data_double;
		char *data_ptr_char;
		short *data_ptr_short;
		int *data_ptr_int;
		long *data_ptr_long;
		float *data_ptr_float;
		double *data_ptr_double;
	}data;
	int type;
	struct Node* post;
};

#define list_h(T)	\
struct Node* createNode_##T(struct Node* thepre,T thedata,int thetype,struct Node* thepost);	\
void insertFront_##T(struct Node** List,T data,int type);	\
T deleteFront_##T(struct Node** List);	\
T deleteBehind_##T(struct Node** List);	\
void deleteAll(struct Node** List); 

list_h(char);
list_h(short);
list_h(int);
list_h(long);
list_h(float);
list_h(double);

void printDoublyLinkedList(struct Node** List);
void printDoublyLinkedListBehind(struct Node** List);
#endif
