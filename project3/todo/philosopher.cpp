#include "philosopher.h"

Monitor DP;
bool running = true;

int main(){
	signal(SIGINT, Exit);
	while(running){
		pthread_mutex_lock(&DP.mutex);
		DP.printState();
		pthread_mutex_unlock(&DP.mutex);
		sleep(1);
	}
	return 0;
}

void* dothing(void* pi){
	int i = *((int*)pi);
	while(running){
		DP.person[i].think();
		DP.takeForks(i);
		DP.person[i].eat();
		DP.putForks(i);
	}
	printf("philosopher %d stop\n", i);
	return NULL;
}
inline int findLeft(int i){
	return (N+i-1) % N;
}
inline int findRight(int i){
	return (i+1) % N;
}
void Exit(int i){
	printf("\n");
	running = false;
}	
