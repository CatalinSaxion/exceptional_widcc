#include <stdio.h>

int main() {
    printf("Hello, World!\n");
	
	try {
		int a,b,c;
		try {
			printf("Hello from try 2 block\n");
			throw 2;
			printf("Hello after throw 2 block\n");
		}
		catch(int ex_nr) {
			printf("caught exception 2: %d\n", ex_nr);
		}
		finally {
			printf("Hello from finally 2 block\n");
		}
		char* some_character = "test";
		throw some_character;
		printf("Hello after throw block\n");
	}
	catch(char* my_char) {
		printf("caught exception: %d\n", my_char);

	}
	finally {
		printf("Hello from finally block\n");

	}
	
    return 0;
}
