
#include <stdio.h>
#include <string.h>

#include "cbaseCmn.h"

int main(int argc, char ** argv)
{
	printf("test started ...\n");
    printf("argc: %d\n", argc);
    int ret = 0;

    if (argc != 4) {
        printHelp();

        return -1;
    }

    printf("\n");

     return 0;
}


