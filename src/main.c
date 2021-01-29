#include "../include/utility.h"

int main(int argc, char **argv)
{
    /* declare compile related variables */
    lexer_t lexer;
    token_t token;

    /* initalize debugging file  */
    char line[80];
    sprintf(line, "logs/debug-%d.log", (int)time(NULL) % 10000);
    debug_file = fopen(line, "w");

    fputs("== debugging information ==\n", debug_file);
    
    if (argc < 2) {
        printf("no source file supplied!");
    }

    lexer = new_lexer(fopen(argv[1], "r"));


    do {
        token = lexer_next(&lexer);
        print_token(token);
    } while (token.type != eof_token);


    fputs("Compiled succesfully\n", debug_file);

    fclose(debug_file);
    return EXIT_SUCCESS;
}
