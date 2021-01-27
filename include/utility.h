#pragma once

/* include standard libraries */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/* include own libraries */
#include "./colours.h"

/* a few extra types */
#include <stdint.h>
typedef unsigned char bool_t;

/* global debugging file
   available in all files, which include utility.h */
FILE* debug_file;

/* convert a char to int
   returns -1 if char is not an int */
uint8_t char_to_int(char ch);
/* return wether or not a char is an int */
bool_t is_int(char ch);
/* return wether or not a char is a whitespace */
bool_t is_whitespace(char ch);