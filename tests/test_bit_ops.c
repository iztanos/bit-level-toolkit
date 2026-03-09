#include <stdio.h>
#include <assert.h>
#include "../bit_ops.h"

void run_tests() {
    unsigned int n = 100; // 0110 0100
    printf("\n");
    printf("Original: "); 
    print_binary(n);
    printf("\n");
    
    // Test Set
    n = 100; // 0110 0100
    unsigned int set = set_bit(n, 3);
    printf("Set bit 3: "); 
    print_binary(set);
    assert(set == 108);

    // Test Clear
    n = 100; // 0110 0100
    unsigned int cleared = clear_bit(n, 2);
    printf("Clear bit 2: "); 
    print_binary(cleared);
    assert(cleared == 96);

    // Test Toggle
    n = 100; // 0110 0100
    unsigned int toggled = toggle_bit(n, 0);
    printf("Toggle bit 0: "); 
    print_binary(toggled);
    assert(toggled == 101);

    // Test Count
    n = 100; // 0110 0100
    unsigned int count = count_bits(n);
    printf("Number of 1 bits: %u\n", count);
    assert(count == 3);

    // Test print_memory
    n = 100; // 0110 0100
    printf("\n");
    print_memory(&n, sizeof(n));
    unsigned char *byte_pointer = (unsigned char*)&n;
    assert(*byte_pointer == 100);
}

int main(void) {
    run_tests();
    printf("\n");
    printf("All tests passed!\n");
    return 0;
}
