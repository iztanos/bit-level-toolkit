#include <stdio.h>
#include "bit_ops.h"

// Print binary
void print_binary(unsigned int n) {
	int binary_break = 0 ;
	for(int i=31;i>=0;i--) {
		printf("%d", (n>>i) & 1);
		
		binary_break += 1;
		if (binary_break == 8) {
			printf(" ");
			binary_break = 0;
		}
	}
	printf("\n");
}

// Force a bit to 1
unsigned int set_bit(unsigned int n, int pos) {
	return (1u << pos) | n;
}

// Force a bit to 0
unsigned int clear_bit(unsigned int n, int pos) {
	return ~(1u << pos) & n;
}

// Flip a bit
unsigned int toggle_bit(unsigned int n, int pos) {
	return (1u << pos) ^ n;
}