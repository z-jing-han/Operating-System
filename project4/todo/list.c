#include "list.h"
#define list_c(T)	\
struct Node* createNode_##T(struct Node* thepre,T thedata,int thetype,struct Node* thepost){	\
	struct Node* temp = (struct Node*)Mymalloc(sizeof(struct Node));	\
	temp->pre=thepre;	\
	temp->data.data_##T=thedata;	\
	temp->type=thetype;	\
	temp->post=thepost;	\
	return temp;	\
}	\
	\
void insertFront_##T(struct Node** List,T data,int type){	\
	struct Node* temp = createNode_##T(NULL,data,type,*List);	\
	if((*List) != NULL)	\
		(*List) -> pre = temp;	\
	(*List) = temp;	\
}	\
	\
T deleteFront_##T(struct Node** List){	\
	if((*List) == NULL)	\
		exit(1);	\
	struct Node* returnNode = (struct Node*)Mymalloc(sizeof(struct Node));	\
	if((*List) -> post == NULL){	\
		returnNode->data.data_##T = (*List) -> data.data_##T;	\
		returnNode->type = (*List) -> type;	\
		Myfree(*List);	\
		(*List) = NULL;	\
	}else{	\
		struct Node* temp = (*List);	\
		returnNode->data.data_##T = temp -> data.data_##T;	\
		returnNode->type = temp -> type;	\
		(*List) = (*List) -> post;	\
		(*List) -> pre = NULL;	\
		Myfree(temp);	\
	}	\
	switch(returnNode->type){	\
		case 0:	\
			return returnNode->data.data_char;	\
		case 1:	\
			return returnNode->data.data_short;	\
		case 2:	\
			return returnNode->data.data_int;	\
		case 3:	\
			return returnNode->data.data_long;	\
		case 4:	\
			return returnNode->data.data_float;	\
		case 5:	\
			return returnNode->data.data_double;	\
		default:	\
			printf("error: in deleteFront_##T, return invaild value\n");	\
	}	\
}	\
	\
T deleteBehind_##T(struct Node** List){	\
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
	returnNode->data.data_##T = temp -> data.data_##T;	\
	returnNode->type = temp -> type;	\
	Myfree(temp);	\
	switch(returnNode->type){	\
		case 0:	\
			return returnNode->data.data_char;	\
		case 1:	\
			return returnNode->data.data_short;	\
		case 2:	\
			return returnNode->data.data_int;	\
		case 3:	\
			return returnNode->data.data_long;	\
		case 4:	\
			return returnNode->data.data_float;	\
		case 5:	\
			return returnNode->data.data_double;	\
		default:	\
			printf("error: in deletebehind_##T, return invaild value\n");	\
	}	\
}

list_c(char);
list_c(short);
list_c(int);
list_c(long);
list_c(float);
list_c(double);

void deleteAll(struct Node** List){
	struct Node* temp;
	while((*List) != NULL){
		temp = (*List);
		(*List) = (*List) -> post;
		(*List) -> pre = NULL;
		free(temp);
	}
}

void printDoublyLinkedList(struct Node** List){
	for(struct Node* current = (*List);current != NULL; current=current->post){
		switch(current->type){
			case 0:
				printf("%c ",current->data.data_char); break;
			case 1:
				printf("%hd ",current->data.data_short); break;
			case 2:
				printf("%d ",current->data.data_int); break;
			case 3:
				printf("%ld ",current->data.data_long); break;
			case 4:
				printf("%f ",current->data.data_float); break;
			case 5:
				printf("%lf ",current->data.data_double); break;
			case 6:
				printf("(%p)%c ",current->data.data_ptr_char,*(current->data.data_ptr_char)); break;
			case 7:
				printf("(%p)%hd ",current->data.data_ptr_short,*(current->data.data_ptr_short)); break;
			case 8:
				printf("(%p)%d ",current->data.data_ptr_int,*(current->data.data_ptr_int)); break;
			case 9:
				printf("(%p)%ld ",current->data.data_ptr_long,*(current->data.data_ptr_long)); break;
			case 10:
				printf("(%p)%f ",current->data.data_ptr_float,*(current->data.data_ptr_float)); break;
			case 11:
				printf("(%p)%lf ",current->data.data_ptr_double,*(current->data.data_ptr_double)); break;
			default:
				printf("error: in printDoublyLinkedList, return type value\n");
		}
		//printf("type:%d \n", current->type);
	}
}
void printDoublyLinkedListBehind(struct Node** List){
	struct Node* temp = (*List);
	while(temp ->post!=NULL)
		temp = temp->post;
	for(struct Node* current = temp;current != NULL; current=current->pre){
		switch(current->type){
			case 0:
				printf("%c ",current->data.data_char); break;
			case 1:
				printf("%hd ",current->data.data_short); break;
			case 2:
				printf("%d ",current->data.data_int); break;
			case 3:
				printf("%ld ",current->data.data_long); break;
			case 4:
				printf("%f ",current->data.data_float); break;
			case 5:
				printf("%lf ",current->data.data_double); break;
			case 6:
				printf("(%p)%c ",current->data.data_ptr_char,*(current->data.data_ptr_char)); break;
			case 7:
				printf("(%p)%hd ",current->data.data_ptr_short,*(current->data.data_ptr_short)); break;
			case 8:
				printf("(%p)%d ",current->data.data_ptr_int,*(current->data.data_ptr_int)); break;
			case 9: 
				printf("(%p)%ld ",current->data.data_ptr_long,*(current->data.data_ptr_long)); break;
			case 10:
				printf("(%p)%f ",current->data.data_ptr_float,*(current->data.data_ptr_float)); break;
			case 11:
				printf("(%p)%lf ",current->data.data_ptr_double,*(current->data.data_ptr_double)); break;
			default:
				printf("error: in printDoublyLinkedList, return type value\n");
		}
		//printf("type:%d\n",current->type);
	}
}
