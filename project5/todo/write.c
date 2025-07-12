#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<unistd.h>
#define SIZE 100

int main(){
	int fd;
	fd = open("file.txt", O_RDWR|O_CREAT, S_IRUSR | S_IWUSR);
	if(fd < 0){
		printf("failed to open file.txt!\n");
		exit(1);
	}
	struct stat buf = {0};
	fstat(fd, &buf);
	if(fstat(fd, &buf) == -1){
		printf("failed to get file state!\n");
		exit(1);
	}
	int len = (int)buf.st_size;
	char *map = (char *)mmap(NULL, getpagesize(), PROT_WRITE, MAP_SHARED, fd, 0);
	if(map == MAP_FAILED){		
		close(fd);
		printf("mapping error!\n");
		exit(0);
	}
	while(1){
		char string[SIZE] = {0};	
		printf("enter a string, while enter \"exit\" will end input:\n");
		fgets(string, SIZE, stdin);
		int sLen = strlen(string);
		if(!strcmp(string,"exit\n")){
			break;
		}
		lseek(fd, len + sLen, SEEK_SET);
		write(fd, "", 1);
		lseek(fd, 0, SEEK_SET);
		for(int i = 0; i < sLen; i++)
			map[len+i] = string[i];
		len += sLen;
		printf("\n");
	}
	close(fd);
	return 0;
}
