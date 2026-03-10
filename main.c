#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bit_ops.h"
#include "memory.h"

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

void print_usage() {
    printf(COLOR_CYAN "\n--- Bit-Level Toolkit ---\n" COLOR_RESET);
    printf("\nUsage: ./bit-tool <command> [value] [position]\n\n");
    printf("Commands:\n");
    printf("  --print <val>          Show binary representation\n");
    printf("  --set <val> <pos>      Set bit at position to 1\n");
    printf("  --clear <val> <pos>    Set bit at position to 0\n");
    printf("  --toggle <val> <pos>   Flip bit at position\n");
    printf("  --count <val>          Count number of set bits (1s)\n");
    printf("  --memory <val>         Show raw memory bytes\n");
    printf("  --endian               Check system byte order\n\n");
}

int main(int argc, char* argv[]) {
	char* command = argv[1];
    if(argc < 2) {
        print_usage();
        return 1;
    }

    if(strcmp(command, "--print") == 0) {
        if(argc < 3) {
            printf(COLOR_RED "Error: --print requires a value\n" COLOR_RESET);
            return 1;
        }
        unsigned int value = (unsigned int)atoi(argv[2]);
        printf(COLOR_YELLOW"\nValue: %u\n"COLOR_RESET, value);
        printf(COLOR_GREEN"Binary: " COLOR_RESET);
        print_binary(value);
        
    } else if(strcmp(command, "--set") == 0) {
        if(argc < 4) {
            printf(COLOR_RED "Error: --set requires a value and a position\n" COLOR_RESET);
            return 1;
        }
        unsigned int value = (unsigned int)atoi(argv[2]);
        unsigned int position = (unsigned int)atoi(argv[3]);
        unsigned int results = set_bit(value, position);
        printf(COLOR_YELLOW"\nValue: %u\n"COLOR_RESET, value);
        printf(COLOR_GREEN"Updated Binary: " COLOR_RESET);
        print_binary(results);
    } 
    else if(strcmp(command, "--clear") == 0 ) {
        if(argc < 4) {
            printf(COLOR_RED"Error: --clear requires a value and a position\n" COLOR_RESET);
            return 1;
        }
        unsigned int value = (unsigned int)atoi(argv[2]);
        unsigned int position = (unsigned int)atoi(argv[3]);
        unsigned int results = clear_bit(value, position);
        printf(COLOR_YELLOW"\nValue: %u\n"COLOR_RESET, value);
        printf(COLOR_GREEN"Updated Binary: " COLOR_RESET);
        print_binary(results);
    } 
    else if(strcmp(command, "--toggle") == 0) {
        if (argc < 4) {
            printf(COLOR_RED "Error: --toggle requires a value and a position\n" COLOR_RESET);
            return 1;
        }
        unsigned int value = (unsigned int)atoi(argv[2]);
        unsigned int position = (unsigned int)atoi(argv[3]);
        unsigned int results = toggle_bit(value, position);
        printf(COLOR_YELLOW"\nValue: %u\n"COLOR_RESET, value);
        printf(COLOR_GREEN"Updated Binary: " COLOR_RESET);
        print_binary(results);
    } 
    else if(strcmp(command, "--count") == 0) {
        if (argc < 3) {
            printf(COLOR_RED "Error: --count requires a value\n"COLOR_RESET);
            return 1;
        }
        unsigned int value = (unsigned int)atoi(argv[2]);
        unsigned int results = count_bits(value);
        printf(COLOR_YELLOW"\nValue: %u\n"COLOR_RESET, value);
        printf(COLOR_GREEN"Number of 1 bits: " COLOR_RESET);
        printf("%u\n", results);
    }
     else if(strcmp(command, "--memory") == 0) {
        if (argc < 3) {
            printf(COLOR_RED "Error: --memory requires a value\n" COLOR_RESET);
            return 1;
        }
        unsigned int value = (unsigned int)atoi(argv[2]);
        print_memory(&value, sizeof(value));
    } 
    else if(strcmp(command, "--endian") == 0) {
        check_endianness();
    } 
    else {
        printf(COLOR_RED "Error: Unknown or invalid command\n" COLOR_RESET);
    }
	return 0;
}
