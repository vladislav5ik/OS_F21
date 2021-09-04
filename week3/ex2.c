#include <stdio.h>

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}


void  bubble_sort(int a[], int size){
	for(int i = size - 1; i >= 0; i--){
		for(int j = 0; j < i; j++){
			if (a[j] > a[j+1]){
				swap(&a[j], &a[j+1]);
			}
		}
	}
}

int main(){
	int a[] = {5,3,2,1,4};
	int size = sizeof(a)/sizeof(int);
	bubble_sort(a, size);
	for(int i = 0; i < size; i++){
		printf("%d ", a[i]);
	}
}
