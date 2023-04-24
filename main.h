#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

void print_buffe(char buffer[], int *buff_ind); /* This function is created and
                                                   used in the _printf.c file*/
int _printf(const char *format, ...);
#endif
