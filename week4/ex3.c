#include <stdio.h>

int main() {
	char input[100];
	scanf("%s", input);
	while (input !="^Z"){ //to exit press CTRL + Z
		system(input);
    		scanf("%s", input);
	}
	return 0;
}
