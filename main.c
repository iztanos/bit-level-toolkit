#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bit_ops.h"

int main(int argc, char* argv[]) {
	
	if(argc < 2) {
        printf("Usage: ./bit-tool <command> [value] [position]\n");
        return 1;
    }

    unsigned char* command = argv[1];
    unsigned int value = atoi(argv[2]);
    //unsigned int position = atoi(argv[3]);

    if(strcmp(command, "--print") == 0) {
        print_binary(value);
    //} else if(strcmp(command, "--set") == 0) {
        // error check todo
        //unsigned int results = set_bit(value, position);
        //print_binary(results);
    }
	return 0;
}
