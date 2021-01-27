#include "./utility.h"

/* the struct for the lexer itself */
typedef struct lexer
{
    char *start;
    uint64_t current;

} lexer_t;

/* the different syntax tokens */
typedef enum
{
    num_token,
    plus_token,
    minus_token,
    mult_token,
    div_token,
    assign_token,
    define_token,
    bad_token,
    eof_token
} token_type_t;

typedef struct token
{
    token_type_t type;
    char text[32];
    int64_t value;
} token_t;

/* initalise a new lexer on a string */
lexer_t new_lexer(char *);

/* get the next token */
token_t lexer_next(lexer_t *);

/* print a token */
void print_token(token_t);
