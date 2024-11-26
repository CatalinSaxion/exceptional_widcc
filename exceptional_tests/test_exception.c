#include <stdio.h>

int main() {
    try {
        int integer = 12;
        float floating;
        double double_floating = 3.21;
        char* character = "Hello, World!";
        
        printf("In try block\n");

        throw character;
        
        printf("This will not be printed\n");

    } catch(char* a) {
        printf("Exception caught: %s\n", a);

    } finally {
       printf("In finally block\n");

    }
    return 0;
}