typedef void FILE;
typedef unsigned int size_t;
extern FILE *stdin_1;
extern FILE *stdin_2;
extern FILE *stdin;
extern FILE *stdout_1;
extern FILE *stdout_2;
extern FILE *stdout;
extern FILE *stderr_1;
extern FILE *stderr_2;
extern FILE *stderr;
int printf(const char *format, ...);
int fprintf(FILE *stream, const char *format, ...);
int sprintf(char *str, const char *format, ...);
int snprintf(char *str, size_t size, const char *format, ...);
int puts(const char *str);
int putchar(int c);
int getchar(void);
typedef unsigned int size_t;
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
typedef unsigned int size_t;
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
size_t strlen(const char *s);
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
char *strcat(char *dest, const char *src);
int glob_zero_52_1;
int glob_zero_52_2;
int glob_zero_52;
void zero_kernel_52_2(int s_1, int p_1, int s_2, int p_2)
{
  int temp_1 = (s_1 + 156) * 0;
  int temp_2 = (s_2 + 156) * 0;
  assert(temp_1 == temp_2);
}

int zero_kernel_52(int s, int p)
{
  int temp = (s + 156) * 0;
  return (temp + (p * 54)) + 1;
}

void main()
{
  int high_sec_1;
  int high_sec_2;
  int pub_val_1;
  int pub_val_2;
  int out_1;
  int out_2;
  out_1 = zero_kernel_52(high_sec_1, pub_val_1);
  out_2 = zero_kernel_52(high_sec_2, pub_val_2);
  zero_kernel_52_2(high_sec_1, pub_val_1, high_sec_2, pub_val_2);
  glob_zero_52_1 = out_1;
  glob_zero_52_2 = out_2;
  int dead_1 = high_sec_1 ^ high_sec_1;
  int dead_2 = high_sec_2 ^ high_sec_2;
  dead_1 = 0;
  dead_2 = 0;
  __CPROVER_assume(high_sec_1 != high_sec_2);
  __CPROVER_assume(pub_val_1 == pub_val_2);
  assert(glob_zero_52_1 == glob_zero_52_2);
  assert(out_1 == out_2);
  assert(dead_1 == dead_2);
}


