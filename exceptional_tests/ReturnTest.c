#include <stdio.h>
#include <stdlib.h>

int test() {
    try {
		printf("Hello before return in try\n");
        return 42;
		throw 1;
		printf("Hello after return in try\n");
    } catch (int x) {
		printf("Hello before return in catch\n");
        return 100;
		printf("Hello after return in catch\n");
    } finally {
        printf("Cleanup\n");
    }
}


int main() {
    test();
    return 0;
}