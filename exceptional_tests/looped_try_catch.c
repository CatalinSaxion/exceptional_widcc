#include <stdio.h>

int main() {
    printf("Hello, World!\n");
	int ex_nr=0;
	while(ex_nr != 10000) {
	try {
		int c = 1;
		
		throw ex_nr;
		printf("Hello after throw block\n");
	}
	catch(ex_nr) {
		printf("caught exception: %d\n", ex_nr);

	}
	finally {
		printf("Hello from finally block\n");
		c++;

	}
	ex_nr++;
	}
	
    return 0;
}
