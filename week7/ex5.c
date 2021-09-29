#include <stdio.h>

int main() {
    char **s; // s in pointer to pointer to char
    s = malloc(sizeof(char*)); //FIXED. Because we don't allocate any memory and it causes segmentation fault.
    char foo[] = "Hello World";
    *s = foo; // FIXED. added *. now s points to foo (foo is pointer to char)
    printf("s is %p\n",s); //prints pointer (location in memory)
    s[0] = foo;
    printf("s[0] is %s\n",s[0]); //prints "Hello World"
    return (0);

    /*
     Output:
        s is 0x564522bb42a0
        s[0] is Hello World
    */
}
