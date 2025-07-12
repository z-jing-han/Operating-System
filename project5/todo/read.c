#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<unistd.h>

int main(){
	int fd = open("file.txt", O_RDONLY);
	if(fd < 0){
		printf("file.txt not found!\n");
		exit(1);
	}
	struct stat buf = {0};
	fstat(fd, &buf);
	int len = (int)buf.st_size;
	char *map = (char *)mmap(0, getpagesize(), PROT_READ, MAP_SHARED, fd, 0);
	close(fd);
	if(map == MAP_FAILED){
		close(fd);
		printf("mapping error!\n");		
		exit(0);
	}
	char opt[10];
	do{
		printf("enter \"read\" or \"exit\": ");
		scanf("%s", opt);
		if(!strcmp(opt, "read") || !strcmp(opt, "Read"))
			if(!len){
				printf("this file is empty!\n");
				exit(1);
			}else
				for(int i = 0; i < getpagesize(); ++i)
					printf("%c", map[i]);
		printf("\n");
	}while(strcmp(opt, "exit") && strcmp(opt, "Exit"));
	return 0;
}
