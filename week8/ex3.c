#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
/* Running 'top -d 1' command, we will see that used memory value will increase slowly.
 And when we deallocate memory back, value will instant decrease and return back */

#define MB10 10485760 // how much bytes in 10 megabytes

int main(){
    char* a[10];
    for(int i = 0; i < 10; i++){
        a[i] = (char*)malloc(MB10);
        memset(a[i], 0, MB10); // filling allocated memory with zeros
        printf("10 MB more allocated\n");
        sleep(1);
    }

    for(int i = 0; i < 10; i++){
        free(a[i]); // deallocating memory
    }
    printf("Memory deallocated\n");
    return 0;
}

