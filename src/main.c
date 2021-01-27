#include "../include/utility.h"

int main(int argc, char **argv)
{
    /* initalize debugging file  */
    char log_name[80];
    char line[80];
    FILE* test_file;
    int i;

    sprintf(log_name, "logs/debug-%d.log", time(NULL) % 10000);
    debug_file = fopen(log_name, "w");

    fputs("Hello world!\n", debug_file);
    
    test_file = fopen("tests/basic.txt", "r");
    for (i = 0; i < 10; i++)
    {
        fscanf(test_file, "%s", line);
        printf("%s\n", line);
    }
    
    fclose(test_file);
    fclose(debug_file);

    return EXIT_SUCCESS;
}