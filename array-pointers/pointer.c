#include <stdio.h>

int main(){

	int var, c, sum;
	
	c = 8;
	var = 7;
	sum = c + var;
	int *ptr = &sum;
	ptr = &sum;
	printf("ptr = %d(at %p)\n", *ptr, ptr);
	return 0;
}
