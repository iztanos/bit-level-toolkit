#include <stdio.h>

void print_binary(unsigned int n){
	for(int i=31;i>=0;i--) {
		printf("%d", (n>>i) & 1);}
        printf("\n");
	}