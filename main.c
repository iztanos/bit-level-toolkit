#include <stdio.h>
#include "bit_ops.h"

int main(int argc, char* argv[]) {
	
	unsigned int n = 120;

	printf("Decimal = %d\n", n);
	printf("Binary = ");
	print_binary(n);

	return 0;
}
