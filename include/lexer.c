#include "./lexer.h"

lexer_t new_lexer(char * start) {
    lexer_t lexer;
    
    lexer.start = start;
    lexer.current = 0;

    return lexer;
}

/* get the next token */
token_t lexer_next(lexer_t * lexer) {
    token_t token;
    uint64_t beginning = lexer->current;
    uint8_t delta = -1;
    char current_char;

    /* if the char at [lexer->current] is an int*/
    do {
        current_char = lexer->start[lexer->current + ++delta];
    } while (!is_whitespace(current_char));

    strncpy(token.text, &(lexer->start[lexer->current+delta]), delta);
    lexer->current += delta;
    return token;

}

void print_token(token_t token) {
    printf("%s", token.text);
}