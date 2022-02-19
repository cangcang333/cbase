#include <stdio.h>

int main(void) {
	signed char x = -10;
	unsigned char y = (unsigned char) x;
	printf("y = %d\n", y);  // should output 246

	return 0;
}
