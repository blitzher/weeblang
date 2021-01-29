#include "./lexer.h"

/* private declarations */
token_t _str_to_tok(char*);
bool_t _str_in_strlist(char *string, char** strlist);

/* public
   return a new instance of a lexeer */
lexer_t new_lexer(FILE * file) {
    lexer_t lexer = *(lexer_t*)malloc(sizeof(lexer));
    
    lexer.file = file;
    lexer.current = 0;

    return lexer;
}

/* public
   get the next token */
token_t lexer_next(lexer_t * lexer) {
    char text[64];
    token_t token = *(token_t *)malloc(sizeof(token_t));
    
    /* if we haven't not reached EOF */
    if (fscanf(lexer->file, "%s", text) != EOF ) {
        token = _str_to_tok(text);
    }
    else {
        token.type = eof_token;
        token.text[0] = '\0';
        token.value = EOF;
    }
    return token;
}

/* private */
token_t _str_to_tok(char* string) {
    token_t token;
    
    strcpy(token.text, string);

    if (_str_in_strlist(string, add_syntax_strs))    token.type = plus_token;   else
    if (_str_in_strlist(string, assign_syntax_strs)) token.type = assign_token; else
    if (_str_in_strlist(string, print_syntax_strs)) token.type = stdout_token;

    else token.type = bad_token;

    return token;
}

/* return true_b if string is a member of strlist
   otherwise, return false */
bool_t _str_in_strlist(char *string, char** strlist) {
    uint8_t i;
    
    for (i = 0; i < MAX_SYNTAX_VARIANTS; i++)
    {
        
        if (!strlist[i]) return false_b;

        if (strcmp(string, strlist[i]) == 0) return true_b;
    }
    return false_b;
    
}

/* public */
void print_token(token_t token) {
    printf("<token_t %s>%s\n", token_name_by_num(token.type), token.text);
}

/* helper function */

char* token_name_by_num(token_type_t token_type) {
    switch (token_type)
    {
    case 0: return "num_token";
    case 1: return "plus_token";
    case 2: return "minus_token";
    case 3: return "mult_token";
    case 4: return "div_token";
    case 5: return "assign_token";
    case 6: return "define_token";
    case 7: return "stdout_token";
    case 8: return "bad_token";
    case 9: return "eof_token";
    
    default: return "no_token";
    }

}
