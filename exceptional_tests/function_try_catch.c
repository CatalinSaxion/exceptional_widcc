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
		int c = 10;
		printf("In try c is %d\n", c);
		//int sum = calc(1,2);
		//printf("Hello after throw block\n");
		throw "caca";
	}
	catch(ex_nr) {
		//printf("caught exception: %d\n", ex_nr);

	}
	finally {
		//printf("Hello from finally block\n");
		printf("In finally c is %d\n", c);
		c=0;
		printf("In finally we change c to %d\n", c);
	}
	
    return 0;
}
