#include <stdlib.h>
#include <stdio.h>

int min(size_t a, size_t b){
    if (a < b){
        return a;
    }
    return b;
}


void *myrealloc( void *ptr, size_t new_size, size_t old_size){

    if (ptr == NULL){
        return (void *) malloc(new_size);
    }

    if (new_size == 0){
        free(ptr);
        return (void *) NULL;
    }

    //copying element to new array:
    // if new size larger, we will copy all elements
    // if new size less than old size, we will copy maximum possible number of elements.
    void* new_ptr = (void*) malloc(new_size);
    memcpy(new_ptr, ptr, min(old_size, new_size));

    // deallocating memory
    free(ptr);
    return new_ptr;
}


int main(){
	//Allows you to generate random number
	srand(time(NULL));

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	//Create a new array of n1 ints
	int* a1 = (int*) malloc(n1*sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		//Set each value in a1 to 100
		a1[i] = 100;

		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2
	a1 = (int*) myrealloc(a1, n2*sizeof(int), n1*sizeof(int));

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

	for(i=n1; i < n2; i++){
		//Set new values in a1 to 0
		a1[i] = 0;
    }


	for(i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}
	printf("\n");

	//Done with array now, done with program :D

	return 0;
}
