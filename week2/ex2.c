#include <stdio.h>
#include <string.h>

int main(){
	char user_input[100];
	char reversed_string[100] = "";
	fgets(user_input, 100, stdin);
	int n = strlen(user_input);
	for(int i = 0; i < n; i++){
		reversed_string[i] = user_input[n - i - 1];
	}
	printf("%s", reversed_string);
	return 0;
}
