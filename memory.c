#include <stdio.h>
#include "memory.h"


// Prints the memory bytes of a variable
void print_memory(void *ptr, size_t size) {
	unsigned char *byte_pointer = (unsigned char*)ptr;

	printf("Memory Layout\n");
	
	for(size_t i = 0; i < size; i++) {
		
		printf("Address: %p | ", (void*)(byte_pointer + i));
		printf("Value: 0x%.2x\n", byte_pointer[i]);
	}
}

// Check if machine is little-endian or big-endian
void check_endianness() {
	unsigned int x = 1;
	unsigned char *bytes = (unsigned char*)&x;

	if(bytes[0] == 1) {
		printf("The machine is little-endian\n");
	} else {
		printf("The machine is big-endian\n");
	}	
}