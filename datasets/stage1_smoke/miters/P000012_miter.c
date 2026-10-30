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
int glob_cancel_12_1 = 0;
int glob_cancel_12_2 = 0;
int glob_cancel_12 = 0;
void cancel_kernel_12_2(int pin_1, int mode_1, int pin_2, int mode_2)
{
  int zero_1 = pin_1 ^ pin_1;
  int zero_2 = pin_2 ^ pin_2;
  assert(zero_1 == zero_2);
}

int cancel_kernel_12(int pin, int mode)
{
  int zero = pin ^ pin;
  return zero + (mode * 5);
}

void main()
{
  int sec_pin_1;
  int sec_pin_2;
  int pub_mode_1;
  int pub_mode_2;
  int verified_zero_1;
  int verified_zero_2;
  verified_zero_1 = cancel_kernel_12(sec_pin_1, pub_mode_1);
  verified_zero_2 = cancel_kernel_12(sec_pin_2, pub_mode_2);
  cancel_kernel_12_2(sec_pin_1, pub_mode_1, sec_pin_2, pub_mode_2);
  glob_cancel_12_1 = verified_zero_1;
  glob_cancel_12_2 = verified_zero_2;
  __CPROVER_assume(pub_mode_1 == pub_mode_2);
  __CPROVER_assume(sec_pin_1 != sec_pin_2);
  assert(glob_cancel_12_1 == glob_cancel_12_2);
  assert(verified_zero_1 == verified_zero_2);
}


