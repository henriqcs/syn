#ifndef TOKEN_H_
#define TOKEN_H_

typedef enum TokenType {
	tk_err,
	tk_num,
	tk_var,
	tk_sym
} TokenType;

typedef struct Token Token;

struct Token {
	TokenType type;
	char value;
	const char *next_token;
};

/*
 * Returns a token from the given input.
 */
Token
tk_read(const char* input);

/*
 * Returns next token position.
 */
const char *
tk_next(Token tk);

/*
 * Returns token type.
 */
TokenType
tk_type(Token tk);

/*
 * Returns token value.
 */
char
tk_val(Token tk);

/*
 * Returns token type for the given char.
 */
static TokenType
tk_type_from_char(char c);

#endif
