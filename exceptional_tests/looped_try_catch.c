#include <stdio.h>

int main() {
    printf("Hello, World!\n");
	int ex_nr=0;
	while(ex_nr != 1000) {
	try {

		throw ex_nr;
		printf("Hello after throw block\n");
	}
	catch(ex_nr) {
		printf("caught exception: %d\n", ex_nr);

	}
	finally {
		printf("Hello from finally block\n");

	}
	ex_nr++;
	}
	
    return 0;
}
