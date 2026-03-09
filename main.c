#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bit_ops.h"

int main(int argc, char* argv[]) {
	
	if(argc < 2) {
        printf("Usage: ./bit-tool <command> [value] [position]\n");
        return 1;
    }

    char* command = argv[1];

    if(strcmp(command, "--print") == 0) {
        if(argc < 3) {
            printf("Error: --print requires a value\n");
            printf("Usage: ./bit-tool --print [value])\n");
            return 1;
        }
        unsigned int value = (unsigned int)atoi(argv[2]);
        printf("\nOrginal: %u\n", value);
        printf("Binary: ");
        print_binary(value);
        
    } //else if(strcmp(command, "--set") == 0) {
        // arguement check todo
        //unsigned int results = set_bit(value, position);
        //print_binary(results);
    //} else if(strcmp(command, "--clear") == 0 ) {
        // arguement check todo
        //unsigned int results = clear_bit(value, position);
        //print_binary(results);
    //} else {
        //printf("AHHH\n");
    //}
	return 0;
}
