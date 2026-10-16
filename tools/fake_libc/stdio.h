/* Minimal C99 stdio.h stub for pycparser and CBMC */
#ifndef _STDIO_H
#define _STDIO_H

typedef void FILE;
typedef unsigned int size_t;

#define NULL ((void*)0)
#define EOF (-1)

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

int printf(const char *format, ...);
int fprintf(FILE *stream, const char *format, ...);
int sprintf(char *str, const char *format, ...);
int snprintf(char *str, size_t size, const char *format, ...);
int puts(const char *str);
int putchar(int c);
int getchar(void);

#endif
