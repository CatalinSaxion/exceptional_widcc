#include <stdio.h>

int main() {
    printf("Hello, World!\n");
	int ex_nr=0;
	try {
		int a,b,c;
		try {
			printf("Hello from try 2 block\n");
			char* test_throw = "test";
			throw test_throw;
			printf("Hello after throw 2 block\n");
		}
		catch(char* super_test) {
			printf("caught exception 2: %s\n", super_test);
		}
		finally {
			printf("Hello from finally 2 block\n");
		}
		char* test_throw2 = "test2";
		throw test_throw2;
		printf("Hello after throw block\n");
	}
	catch(char* super_test2) {
		printf("caught exception: %s\n", super_test2);

	}
	finally {
		printf("Hello from finally block\n");

	}
	
    return 0;
}
