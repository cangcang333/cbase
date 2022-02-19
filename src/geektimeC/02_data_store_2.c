#include <stdio.h>

int main(void) {
	int x = -10;
	unsigned int y = 1;
	if (x < y) {
		printf("x is smaller than y.\n");
	} else {
		printf("x is bigger than y.\n");  // this branch is picked.
	}


	return 0;
}
