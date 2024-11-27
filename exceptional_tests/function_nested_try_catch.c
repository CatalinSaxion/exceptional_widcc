#include <stdio.h>

int calc(int a, int b) {
	int sum = a + b;
	try{
		printf("Hello from try 3 block\n");
	throw sum;
	}
	catch(int sum) {
		printf("caught exception 3: %d\n", sum);
	}
	finally {
		printf("Hello from finally 3 block\n");
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
			throw sum;
			printf("Hello after throw 2 block\n");
		}
		catch(int ex) {
			printf("caught exception 2: %d\n", ex);
		}
		finally {
			printf("Hello from finally 2 block\n");
		}
		
		throw 2;
		printf("Hello after throw block\n");
	}
	catch(int ex2) {
		printf("caught exception: %d\n", ex2);

	}
	finally {
		printf("Hello from finally block\n");

	}
	
    return 0;
}
