// NoTags.cpp
// Semestr1 Laba1

#define _CRT_SECURE_NO_WARNINGS
#include "NoTags.h"
#include <string.h>
#include <cstdlib>
#include <cstdio>

int correct_file_name(char file_name[])
{
    int l = strlen(file_name);
    if (file_name[l - 4] == '.' && file_name[l - 3] == 't' && file_name[l - 2] == 'x' && file_name[l - 1] == 't' 
        && fopen(file_name, "r") != NULL)
        return 0;
    else
        return 1;  
    return 0;
} 
int strScan(char* str,FILE* file){
    int i =0;
    int len = 0;
    if (str==NULL)
        str = (char*)malloc(sizeof(char)*301);
    char c = getc(file);
    while (c!='\n'){    
        if (i<300){
            str[i]= c;
            len++;
        } 
        c = getc(file);
        i++;
    }
    str[len]='\0';
    if (len == i) 
        return 0;
    else
        return 1;
}
char *out_file_name(char in_name[])
{
    char *out_name;
    out_name = (char *)malloc(sizeof(char)* 300);
    int i;
    int l = strlen(in_name);
    for (i = 0; i < l - 4; i++)
        out_name[i] = in_name[i];
    out_name[i] = '.';	out_name[i + 1] = 'o';	out_name[i + 2] = 'u';	out_name[i + 3] = 't';
    out_name[i + 4] = '.';	out_name[i + 5] = 't';	out_name[i + 6] = 'x';	out_name[i + 7] = 't';
    out_name[i + 8] = '\0';
    return out_name;
}
char *stringOp(char string[]) 
{
    int len = strlen(string);
    char temp[300];
    char *result;
    result = (char*)malloc(sizeof(char)* 300);
    int j = 0;
    int k = 0;
    bool tag = false;
    for (int i = 0; i < len; i++)
    {
        if (string[i] == 60)
        {
            tag = true;
            temp[j] = string[i];
            j++;
        }
        else if (string[i] == 62 && tag == true)
        {
            tag = false;
            temp[0] = '\0';
            j = 0;
        }
        else if (tag == false)
        {
            result[k] = string[i];
            k++;
        }
        else     //tag == true
        {
            temp[j] = string[i];
            j++;
        }
    }
    for (int i = 0; i < j; i++)
        result[i+k] = temp[i];
    result[k+j] = '\0';
    return result;
}
int file_convert(char path_from[], char path_to[]) 
{
    FILE *from, *to;
    char string[301];
    from = fopen(path_from, "r");
    to = fopen(path_to, "w");
    strScan(string, from);
    fprintf(to, "%s", stringOp(string));
    fclose(from);
    fclose(to);
    return 0;
}
int console_convert()
{
    char string[301];
    printf("Enter string to process: \n");
    if (strScan(string, stdin)==1){
        printf("Incorrect input, try again, enter string to process: \n");
        return 1;
    }
    else{
        printf("%s\n", stringOp(string));
        return 0;
    }
}
int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        if (correct_file_name(argv[1]) == 0)
        {
            char* from = argv[1];
            char *to;
            to = out_file_name(from);
            if (fopen(to, "w") != NULL)
            {
                file_convert(from, to);
                return 0;
            }
            else
            {
                printf("Error writing to file.»\n");
                return 1;
            }
        }
        else
        {
            printf("Incorrect filename or file not found. \n");
            if (console_convert() != 0)
            if (console_convert() != 0)
            if (console_convert() != 0)
            {
                printf("Incorrect input, exited.\n");
                return 1;
            }
        }
    }
    else
    if (console_convert() != 0)
    if (console_convert() != 0)
    if (console_convert() != 0)
    {
        printf("Incorrect input, exited.\n");
        return 1;
    }
    return 0;
}