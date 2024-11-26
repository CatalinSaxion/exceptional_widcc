#include <stdio.h>

int main() {
    printf("Hello, World!\n");
	int ex_nr=0;
	try {
		int a,b,c;
		try {
			printf("Hello from try 2 block\n");
			throw("test");
			printf("Hello after throw 2 block\n");
		}
		catch(ex_nr) {
			printf("caught exception 2: %d\n", ex_nr);
		}
		finally {
			printf("Hello from finally 2 block\n");
		}
		
		throw("test");
		printf("Hello after throw block\n");
	}
	catch(ex_nr) {
		printf("caught exception: %d\n", ex_nr);

	}
	finally {
		printf("Hello from finally block\n");

	}
	
    return 0;
}
