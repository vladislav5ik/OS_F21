#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define tick_print 1000000000
int is_active[2] = {1, 1}; //consumer and producer flags

#define max_size 1000
int buffer[max_size];
int item_count = 0;

void sleep_t(int n){
    is_active[n] = 0;
}

void wakeup_t(int n){
    is_active[n] = 1;
}

void put_item(int item){
    buffer[item_count++] = item;
}

int pop_item(){
    return buffer[--item_count];
}


void *producer(){
    int tick = 1;
    while(1) {
        tick += 1;
        if (is_active[1] == 1){
            if (item_count == max_size - 1){
                sleep_t(1);
                wakeup_t(0);
                if (tick % tick_print == 0) {printf("full buffer\n");}
            } else {
                int item = item_count;
                put_item(item);
                if (tick % tick_print == 0) {printf("produced item %d\n", item);}
            }
        }
    }
}

void *consumer(){
    int tick = 1;
    while(1) {
        tick += 1;
        if (is_active[0] == 1){
            if (item_count == 0){
                sleep_t(0);
                wakeup_t(1);
                if (tick % tick_print == 0) {printf("empty buffer\n");}

            } else {
                int item = pop_item();
                if (tick % tick_print == 0) {printf("consumed item %d\n" ,item);}
            }
        }
    }
}

int main(void){
    pthread_t consumer_t, producer_t;

    pthread_create(&consumer_t, NULL, consumer, NULL);
    pthread_create(&producer_t, NULL, producer, NULL);

    pthread_join(producer_t, NULL);

    pthread_join(consumer_t, NULL);

    pthread_exit(NULL);
    return 0;
}

