/* Minimal C99 stdlib.h stub */
#ifndef _STDLIB_H
#define _STDLIB_H

typedef unsigned int size_t;

#define NULL ((void*)0)
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void *malloc(size_t size);
void *calloc(size_t num, size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);
void exit(int status);
void abort(void);
int abs(int j);
long int labs(long int j);
int rand(void);
void srand(unsigned int seed);

#endif
