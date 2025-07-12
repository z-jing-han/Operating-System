#ifndef LIST_PTR_H
#define LIST_PTR_H
#include "mm.h"
#include "list.h"

#define list_ptr_h(T)	\
struct Node* createNode_ptr_##T(struct Node* thepre,T* thedata,int thetype,struct Node* thepost);	\
void insertFront_ptr_##T(struct Node** List,T* data,int type);	\
T* deleteFront_ptr_##T(struct Node** List);	\
T* deleteBehind_ptr_##T(struct Node** List);	\

list_ptr_h(char);
list_ptr_h(short);
list_ptr_h(int);
list_ptr_h(long);
list_ptr_h(float);
list_ptr_h(double);
#endif
