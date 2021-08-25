#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int a = 0; a < n - i - 1; a++){
			printf(" ");
		}
		for(int b = 0; b < 2*i + 1; b++){
			printf("*");
		}
		printf("\n");
	}
}
