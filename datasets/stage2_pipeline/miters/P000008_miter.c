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
int glob_direct_2_1;
int glob_direct_2_2;
int glob_direct_2;
void direct_kernel_2_2(int h_1, int p_1, int h_2, int p_2)
{
  int t1_1 = h_1 + 10;
  int t1_2 = h_2 + 10;
  assert(t1_1 == t1_2);
}

int direct_kernel_2(int h, int p)
{
  int t1 = h + 10;
  return (t1 - 10) + p;
}

void main()
{
  int key_in_1;
  int key_in_2;
  int pub_in_1;
  int pub_in_2;
  int res_1;
  int res_2;
  res_1 = direct_kernel_2(key_in_1, pub_in_1);
  res_2 = direct_kernel_2(key_in_2, pub_in_2);
  direct_kernel_2_2(key_in_1, pub_in_1, key_in_2, pub_in_2);
  glob_direct_2_1 = res_1;
  glob_direct_2_2 = res_2;
  __CPROVER_assume(pub_in_1 == pub_in_2);
  __CPROVER_assume(key_in_1 != key_in_2);
  assert(glob_direct_2_1 == glob_direct_2_2);
  assert(res_1 == res_2);
}


