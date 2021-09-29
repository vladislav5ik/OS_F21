#include <stdio.h>
int main(){
    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    // allocating memory for n elements
    int *arr = (int*) malloc(n*sizeof(int));

    // filling the array
    for (int i = 0; i < n; i++){
        arr[i] = i;
    }

    // printing all elements of array
    for (int i = 0; i < n; i++){
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // deallocating memory
    if (arr != NULL){
        free(arr);
    }
}
