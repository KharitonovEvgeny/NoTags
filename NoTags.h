#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <cstdlib>
#include <cstdio>

bool correct_file_name(char file_name[]);            //checks the correctness of the input file's name
int strScan(char* str,FILE* file);                   //scans string from file
char *out_file_name(char in_name[]);                 //returns the name of the output file
char *stringOp(char string[]);                       //removes <...> combination
int file_convert(char path_from[], char path_to[]);  //from file to file
int console_convert();                               //from console to console
