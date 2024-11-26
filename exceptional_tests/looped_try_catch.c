#include <stdio.h>


int main() {
    printf("Hello, World!\n");
	int ex_nr=0;
	while(ex_nr != 8) {
		try {
			printf("Ex_nr: %d\n", ex_nr);
			throw ex_nr;
			printf("Hello after throw block\n");
		}
		catch(int a) {
			printf("caught exception: %d\n", a);

		}
		finally {
			printf("Hello from finally block\n");

		}
		ex_nr++;
	}
	
    return 0;
}
