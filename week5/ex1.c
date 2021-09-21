#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

void* myThread(void* i){
    int n = (int)i;
    printf("Hello from thread #%d\n", n);
    pthread_exit(NULL);
}

int main(){
	pthread_t thread;
    for(int i = 0; i < 10; i++){
        if(pthread_create(&thread, NULL, myThread, (void *) (intptr_t) i)){
            printf("Error in creating thread #%d\n", i);
        } else {
            printf("Thread #%d created\n", i);
            pthread_join(thread, NULL);
        }
    }

}
