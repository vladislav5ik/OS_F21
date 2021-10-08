#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/resource.h>
/* When values are displayed, the ru_maxrss indicator increases ,
 * and the other indicators remain unchanged and equal to zero.*/

#define MB10 10485760 // how much bytes in 10 megabytes

int main(){
    struct rusage usage;
    char* a[10];
    for(int i = 0; i < 10; i++){
        a[i] = (char*)malloc(MB10);
        memset(a[i], 0, MB10); // filling allocated memory with zeros
        getrusage(RUSAGE_SELF , &usage);
        //printf("10 MB more allocated\n");
        printf("ru_stime = %d, ru_maxrss = %d, ru_ixrss = %d, ru_idrss = %d, ru_isrss = %d\n",
               usage.ru_stime.tv_sec, usage.ru_maxrss , usage.ru_ixrss, usage.ru_idrss, usage.ru_isrss);
        sleep(1);
    }

    for(int i = 0; i < 10; i++){
        free(a[i]); // deallocating memory
    }
    printf("Memory deallocated\n");
    return 0;
}


