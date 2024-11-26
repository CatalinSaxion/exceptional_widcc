#include <stdio.h>

int calc(int a, int b) {
	int sum = a + b;
	try{
		printf("Hello from try 3 block\n");
	throw 1;
	}
	catch(sum) {
		printf("caught exception 3: %d\n", sum);
	}
	finally {
		printf("Hello from finally 3  block\n");
	}
	return sum;
}

int main() {
    printf("Hello, World!\n");
	int ex_nr=0;
	try {

		int sum = calc(1,2);
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
