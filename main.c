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
        
    } else if(strcmp(command, "--set") == 0) {
        if(argc < 4) {
            printf("Error: --set requires a value and a position\n");
            printf("Usage: ./bit-tool --set [value] [position])\n");
            return 1;
        }
        unsigned int value = (unsigned int)atoi(argv[2]);
        unsigned int position = (unsigned int)atoi(argv[3]);
        unsigned int results = set_bit(value, position);
        print_binary(results);
    } else if(strcmp(command, "--clear") == 0 ) {
        if(argc < 4) {
            printf("Error: --clear requires a value and a position\n");
            printf("Usage: ./bit-tool --clear [value] [position])\n");
            return 1;
        }
        unsigned int value = (unsigned int)atoi(argv[2]);
        unsigned int position = (unsigned int)atoi(argv[3]);
        unsigned int results = clear_bit(value, position);
        print_binary(results);
    } else if(strcmp(command, "--toggle") == 0) {
        if (argc < 4) {
            printf("Error: --toggle requires a value and a position\n");
            printf("Usage: ./bit-tool --toggle [value] [position])\n");
            return 1;
        }
        unsigned int value = (unsigned int)atoi(argv[2]);
        unsigned int position = (unsigned int)atoi(argv[3]);
        unsigned int results = toggle_bit(value, position);
        print_binary(results);
    } else if(strcmp(command, "--count") == 0) {
        if (argc < 3) {
            printf("Error: --count requires a value\n");
            printf("Usage: ./bit-tool --count [value])\n");
            return 1;
        }
        unsigned int value = (unsigned int)atoi(argv[2]);
        unsigned int results = count_bits(value);
        printf("%u\n", results);
    } else if(strcmp(command, "--memory") == 0) {
        if (argc < 3) {
            printf("Error: --memory requires a value\n");
            printf("Usage: ./bit-tool --toggle [value])\n");
            return 1;
        }
        unsigned int value = (unsigned int)atoi(argv[2]);
        print_memory(&value, sizeof(value));
    } else if(strcmp(command, "--endian") == 0) {
        check_endianness();
    } else {
        printf("Error: Unknown or invalid command\n");
    }
	return 0;
}
