#include <stdio.h>

int main() {
    printf("Hello, World!\n");
	long int ex_nr=0;
	while(ex_nr != 10000) {
	try {		
		throw ex_nr;
		printf("Hello after throw block\n");
	}
	catch(long int ex_nr) {
		printf("caught exception: %ld\n", ex_nr);

	}
	finally {
		printf("Hello from finally block\n");
	}
	ex_nr+=1;
	}
	
    return 0;
}
