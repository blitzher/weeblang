#pragma once

#include "./utility.h"

#define test 1

/* the struct for the lexer itself */
typedef struct lexer
{
    FILE* file;
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
    stdout_token,
    bad_token,
    eof_token
} token_type_t;

char* token_name_by_num(token_type_t);

typedef struct token
{
    token_type_t type;
    char text[32];
    int64_t value;
} token_t;

/* initalise a new lexer on a string */
lexer_t new_lexer(FILE *);

/* get the next token */
token_t lexer_next(lexer_t *);

void print_token(token_t token);
