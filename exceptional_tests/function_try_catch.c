#include <stdio.h>

int calc(int a, int b) {
	int sum = a + b;
	int test = 10;
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

int calc1(int a, int b) {
	int sum = a + b;
	int test = 10;
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
int calc2(int a, int b) {
	int sum = a + b;
	int test = 10;
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

int calc3(int a, int b) {
	int sum = a + b;
	int test = 10;
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

void* calc4(int a, int b) {
	int sum = a + b;
	int test = 10;
	try{
		printf("Hello from try 3 block\n");
	throw (void*)1;
	}
	catch(void* sum) {
		printf("caught exception 3: %d\n", sum);
	}
	finally {
		printf("Hello from finally 3  block\n");
	}
	return sum;
}

int main() {
    printf("Hello, World!\n");
    for (int i = 0; i < 10000; i++) {
    calc(3,5);
	calc1(3,5);
	calc2(4,5);
	calc3(5,5);
	calc4(10,4);
}
    return 0;
}
