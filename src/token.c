#include <ctype.h>
#include <string.h>

#include "token.h"

/*
 * Returns a token from the given input.
 */
Token
tk_read(const char* input)
{
	Token tk;
	tk.value = input[0];
	tk.type = tk_type_from_char(tk.value);

	if (tk.type == tk_sym)
		tk.next_token = input + 1;
	else
		tk.next_token = strchr(input, ')') + 1;

	return tk;
}

/*
 * Returns next token position.
 */
const char *
tk_next(Token tk)
{
	return tk.next_token;
}

/*
 * Returns token type.
 */
TokenType
tk_type(Token tk)
{
	return tk.type;
}

/*
 * Returns token value.
 */
char
tk_val(Token tk)
{
	return tk.value;
}

/*
 * Returns token type for the given char.
 */
static TokenType
tk_type_from_char(char c)
{
	if (c == 'N') return tk_num;
	if (c == 'V') return tk_var;
	if (ispunct(c)) return tk_sym;
	return tk_err;
}
