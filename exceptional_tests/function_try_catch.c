#include <stdio.h>

int calc(int a, int b) {
	int sum = a + b;
	try{
		printf("Hello from try 3 block\n");
	throw 1;
	}
	catch(int sum) {
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
		printf("Hello after throw block\n");
	}
	catch(int ex_nr) {
		printf("caught exception: %d\n", ex_nr);
	}
	finally {
		printf("Hello from finally block\n");
	}
	
    return 0;
}
