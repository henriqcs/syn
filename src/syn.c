#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "syn.h"
#include "token.h"

int
machine(const char const **input, int submachine)
{
	Token tk;
	goto A;

A:
	tk = tk_read(*input);
	if (tk_type(tk) == tk_num || tk_type(tk) == tk_var) {
		*input = tk_next(tk);
		goto D;
	} else if (tk_type(tk) == tk_sym && tk_val(tk) == '(') {
		*input = tk_next(tk);
		goto B;
	} else {
		return EXIT_FAILURE;
	}

B:
	if (machine(input, 1) == EXIT_FAILURE)
		return EXIT_FAILURE;
	goto C;

C:
	tk = tk_read(*input);
	if (tk_type(tk) == tk_sym && tk_val(tk) == ')') {
		*input = tk_next(tk);
		goto D;
	} else {
		return EXIT_FAILURE;
	}

D:
	tk = tk_read(*input);
	if (submachine && tk_val(tk) == ')') {
		return EXIT_SUCCESS;
	} else if (tk_type(tk) == tk_sym) {
		*input = tk_next(tk);
		goto A;
	} else if (tk_val(tk) == '\0' || tk_val(tk) == '\n') {
		return EXIT_SUCCESS;
	} else {
		return EXIT_FAILURE;
	}
}
