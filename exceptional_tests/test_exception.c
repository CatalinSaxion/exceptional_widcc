#include <stdio.h>

int main() {
    try {
        signed long long int long_integer = -1221212123123123;
        int integer1 = 23;
        int integer2 = 2;
        float floating;
        double double_floating = 3.21;
        char* character = "Hello, World!";
        
        printf("In try block\n");

        throw integer1;
        
        printf("This will not be printed\n");

    } catch(int a) {
        printf("Exception caught: %f\n", a);

    } finally {
       printf("In finally block\n");
    }
    return 0;
}