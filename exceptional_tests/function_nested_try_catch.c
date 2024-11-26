#include <stdio.h>

int calc(int a, int b) {
	int sum = a + b;
	try{
		printf("Hello from try 3 block\n");
	throw 1;
	}
	catch(int exception) {
		printf("caught exception 3: %d\n", exception);
	}
	finally {
		printf("Hello from finally 3  block\n");
	}
	return sum;
}

int main() {
    printf("Hello, World!\n");
	try {

		int sum = calc(1,2);
		int a,b,c;
		try {
			printf("Hello from try 2 block\n");
			char* ex = "test";
			throw ex;
			printf("Hello after throw 2 block\n");
		}
		catch(char* ex_nr) {
			printf("caught exception 2: %s\n", ex_nr);
		}
		finally {
			printf("Hello from finally 2 block\n");
		}
		
		char* ex2 = "test";
		throw ex2;
		printf("Hello after throw block\n");
	}
	catch(char* ex_nr) {
		printf("caught exception: %s\n", ex_nr);

	}
	finally {
		printf("Hello from finally block\n");

	}
	
    return 0;
}
