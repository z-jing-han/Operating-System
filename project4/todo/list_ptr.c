#include "list_ptr.h"
#define list_ptr_c(T)	\
struct Node* createNode_ptr_##T(struct Node* thepre,T* thedata,int thetype,struct Node* thepost){	\
	struct Node* temp = (struct Node*)Mymalloc(sizeof(struct Node));	\
	temp->pre=thepre;	\
	temp->data.data_ptr_##T=thedata;	\
	temp->type=thetype;	\
	temp->post=thepost;	\
	return temp;	\
}	\
	\
void insertFront_ptr_##T(struct Node** List,T* data,int type){	\
	struct Node* temp = createNode_ptr_##T(NULL,data,type,*List);	\
	if((*List) != NULL)	\
		(*List) -> pre = temp;	\
	(*List) = temp;	\
}	\
	\
T* deleteFront_ptr_##T(struct Node** List){	\
	if((*List) == NULL)	\
		exit(1);	\
	struct Node* returnNode = (struct Node*)Mymalloc(sizeof(struct Node));	\
	if((*List) -> post == NULL){	\
		returnNode->data.data_ptr_##T = (*List) -> data.data_ptr_##T;	\
		returnNode->type = (*List) -> type;	\
		Myfree(*List);	\
		(*List) = NULL;	\
	}else{	\
		struct Node* temp = (*List);	\
		returnNode->data.data_ptr_##T = temp -> data.data_ptr_##T;	\
		returnNode->type = temp -> type;	\
		(*List) = (*List) -> post;	\
		(*List) -> pre = NULL;	\
		Myfree(temp);	\
	}	\
	switch(returnNode->type){	\
		case 6:	\
			return (T*)returnNode->data.data_ptr_char;	\
		case 7:	\
			return (T*)returnNode->data.data_ptr_short;	\
		case 8:	\
			return (T*)returnNode->data.data_ptr_int;	\
		case 9:	\
			return (T*)returnNode->data.data_ptr_long;	\
		case 10:	\
			return (T*)returnNode->data.data_ptr_float;	\
		case 11:	\
			return (T*)returnNode->data.data_ptr_double;	\
		default:	\
			printf("error: %d in deleteFront_ptr_##T, return invaild value\n",returnNode->type);	\
	}	\
}	\
	\
T* deleteBehind_ptr_##T(struct Node** List){	\
	if((*List) == NULL)	\
		exit(1);	\
	struct Node* temp = (*List);	\
	while(temp->post!=NULL)	\
		temp = temp->post;	\
	if(temp->pre!=NULL)	\
		temp->pre->post=NULL;	\
	else	\
		(*List) = NULL;	\
	struct Node* returnNode = (struct Node*)Mymalloc(sizeof(struct Node));	\
	returnNode->data.data_ptr_##T = temp -> data.data_ptr_##T;	\
	returnNode->type = temp -> type;	\
	Myfree(temp);	\
	switch(returnNode->type){	\
		case 6:	\
			return (T*)returnNode->data.data_ptr_char;	\
		case 7:	\
			return (T*)returnNode->data.data_ptr_short;	\
		case 8:	\
			return (T*)returnNode->data.data_ptr_int;	\
		case 9:	\
			return (T*)returnNode->data.data_ptr_long;	\
		case 10:	\
			return (T*)returnNode->data.data_ptr_float;	\
		case 11:	\
			return (T*)returnNode->data.data_ptr_double;	\
		default:	\
			printf("error: %d in deleteBehind_ptr_##T, return invaild value\n",returnNode->type);	\
	}	\
}

list_ptr_c(char);
list_ptr_c(short);
list_ptr_c(int);
list_ptr_c(long);
list_ptr_c(float);
list_ptr_c(double);
