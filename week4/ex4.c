#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100

int main() {
    char in[MAX_SIZE]; // variable for input
    while (in !="^Z") { // to exit press CTRL + Z
        scanf("%s", in);

        char *arguments[MAX_SIZE]; // array of arguments, last element is NULL
        for (int i = 0; i < MAX_SIZE; i++) {
            arguments[i] = NULL;
        }

        int arg_elem_i = 0; // index of an argument in array of them
        int arg_char_i = 0; // index of char of an argument word
        int in_char_i = 0; // index of char of input
        arguments[0] = (char*)malloc(MAX_SIZE);

        while (in[in_char_i] != '\0' && in[in_char_i] != '\n'){
            if (in[in_char_i] == ' ') { // new word
                arguments[++arg_elem_i] = (char*)malloc(MAX_SIZE);
                arg_char_i = 0;
            } else { // continue reading current word
                arguments[arg_elem_i][arg_char_i++] = in[in_char_i];
            }
            in_char_i++;
        }
        int pid = fork();
        if (pid == 0){ // if process is a child
            execvp(arguments[0], arguments);
        }
    }
    return 0;
}
