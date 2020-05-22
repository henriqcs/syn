#include <stdio.h>
#include <stdlib.h>

#include "syn.h"

int
main(void)
{
	char _input[SYN_INPUT_SIZE];
	const char *input = _input;
	int status = EXIT_SUCCESS;

	while (status == EXIT_SUCCESS && fgets(_input, SYN_INPUT_SIZE, stdin)) {
		status = machine(&input, 0);
	}

	/*
	if (status == EXIT_SUCCESS) {
		printf("\nSyntax OK\n");
	} else {
		printf("\nSyntax error!\n");
	}
	*/

	return status;
}
