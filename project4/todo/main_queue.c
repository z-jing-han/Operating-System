#include "queue.h"
#include "queue_ptr.h"
#include <stdio.h>
#include <stdlib.h>
int main(){
	struct Node* head = NULL;
	int opt = 0;
	printf("This is queue.\n");
	printf("/************/\n");
	printf("1.Enqueue\n");
	printf("2.Dequeue\n");
	printf("3.Print Queue\n");
	printf("EOF.Exit\n");
	printf("/************/\n");
	while(opt != 4){
		printf("Option:");
		scanf("%d", &opt);
		if(opt == 1){
			int input;
			printf("0: char 1: short 2: int 3: long 4:float 5:double\n");
			printf("6: char_ptr 7: short_ptr 8: int_ptr 9: long_ptr 10:float_ptr 11:double_ptr\n");
			scanf("%d", &input);
			switch (input) {
				case 0:
					printf("Please input a char\n");
					getchar();
					char data_char;
					scanf("%c", &data_char);
					EnQueue_char(&head,data_char, 0);
					break;
				case 1:
					printf("Please input a short integer\n");
					short data_short;
					scanf("%hd", &data_short);
					EnQueue_short(&head,data_short, 1);
					break;
				case 2:
					printf("Please input a integer\n");
					int data_int;
					scanf("%d", &data_int);
					EnQueue_int(&head,data_int, 2);
					break;
				case 3:
					printf("Please input a long integer\n");
					long data_long;
					scanf("%ld", &data_long);
					EnQueue_long(&head,data_long, 3);
					break;
				case 4:
					printf("Please input a float\n");
					float data_float;
					scanf("%f", &data_float);
					EnQueue_float(&head,data_float, 4);
					break;
				case 5:
					printf("Please input a double\n");
					double data_double;
					scanf("%lf", &data_double);
					EnQueue_double(&head,data_double, 5);
					break;
				case 6:
					printf("Please input a char, store in pointer to char\n");
					getchar();
					char *data_ptr_char = (char *)Mymalloc(sizeof(char));
					scanf("%c", data_ptr_char);
					EnQueue_ptr_char(&head,data_ptr_char, 6);
					break;
				case 7:
					printf("Please input a short integer, store in pointer to short\n");
					short *data_ptr_short = (short *)Mymalloc(sizeof(short));
					scanf("%hd", data_ptr_short);
					EnQueue_ptr_short(&head,data_ptr_short, 7);
					break;
				case 8:
					printf("Please input a integer, store in pointer to int\n");
					int *data_ptr_int = (int*)Mymalloc(sizeof(int));
					scanf("%d", data_ptr_int);
					EnQueue_ptr_int(&head,data_ptr_int, 8);
					break;
				case 9:
					printf("Please input a long integer, store in pointer to long\n");
					long *data_ptr_long = (long*)Mymalloc(sizeof(long));
					scanf("%ld", data_ptr_long);
					EnQueue_ptr_long(&head,data_ptr_long, 9);
					break;
				case 10:
					printf("Please input a float, store in pointer to float\n");
					float *data_ptr_float = (float*)Mymalloc(sizeof(float));
					scanf("%f", data_ptr_float);
					EnQueue_ptr_float(&head,data_ptr_float, 10);
					break;
				case 11:
					printf("Please input a double, store in pointer to double\n");
					double *data_ptr_double = (double*)Mymalloc(sizeof(double));
					scanf("%lf", data_ptr_double);
					EnQueue_ptr_double(&head,data_ptr_double, 11);
					break;
			}
		}else if(opt == 2)
			if(head == NULL)
				printf("Queue is empty. Could't dequeue anything more.\n");
			else{
				char *temp1;
				short *temp2;
				int *temp3;
				long *temp4;
				float *temp5;
				double *temp6;
				struct Node *buffer = head;
				for(;buffer->post!=NULL;buffer=buffer->post);
				switch (buffer->type) {
					case 0:
						printf("Dequeue data %c from queue\n", DeQueue_char(&head));	break;
					case 1:
						printf("Dequeue data %hd from queue\n", DeQueue_short(&head));	break;
					case 2:
						printf("Dequeue data %d from queue\n", DeQueue_int(&head));	break;
					case 3:
						printf("Dequeue data %ld from queuek\n", DeQueue_long(&head));	break;
					case 4:
						printf("Dequeue data %f from queue\n", DeQueue_float(&head));	break;
					case 5:
						printf("Dequeue data %lf from queue\n", DeQueue_double(&head));	break;
					case 6:
						temp1 = DeQueue_ptr_char(&head);
						printf("Dequeue pointer %p from queue, value is %c\n",temp1,*temp1);
						break;
					case 7:
						temp2 = DeQueue_ptr_short(&head);
						printf("Dequeue pointer %p from queue, value is %hd\n",temp2,*temp2);
						break;
					case 8:
						temp3 = DeQueue_ptr_int(&head);
						printf("Dequeue pointer %p from queue, value is %d\n",temp3,*temp3);
						break;
					case 9:
						temp4 = DeQueue_ptr_long(&head);
						printf("Dequeue pointer %p from queue, value is %ld\n",temp4,*temp4);
						break;
					case 10:
						temp5 = DeQueue_ptr_float(&head);
						printf("Dequeue pointer %p from queue, value is %f\n",temp5,*temp5);
						break;
					case 11:
						temp6 = DeQueue_ptr_double(&head);
						printf("Dequeue pointer %p from queue, value is %lf\n",temp6,*temp6);
						break;
				}
			}
		else if(opt == 3)
			printQueue(&head);
		else if(opt != 4)
			printf("Invaild input, please try again.\n");
	}
	deleteAllQueue(&head);
	return 0;
}
