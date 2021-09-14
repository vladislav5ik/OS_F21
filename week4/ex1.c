#include <stdio.h>

int main(){
	int n = fork();
	int pid = getpid();
	if(n == 0){
		printf("Hello from child [%d]\n", pid);
	} else {
		printf("Hello from parent [%d]\n", pid);
	}
}
