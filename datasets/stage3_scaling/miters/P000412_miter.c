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
int glob_arith_11_1;
int glob_arith_11_2;
int glob_arith_11;
void affine_kernel_11_2(int s_1, int sc_1, int s_2, int sc_2)
{
}

int affine_kernel_11(int s, int sc)
{
  return (((s * 25) + 78) % 256) * sc;
}

void main()
{
  int sec_val_1;
  int sec_val_2;
  int pub_scale_1;
  int pub_scale_2;
  int arith_out_1;
  int arith_out_2;
  arith_out_1 = affine_kernel_11(sec_val_1, pub_scale_1);
  arith_out_2 = affine_kernel_11(sec_val_2, pub_scale_2);
  affine_kernel_11_2(sec_val_1, pub_scale_1, sec_val_2, pub_scale_2);
  glob_arith_11_1 = arith_out_1;
  glob_arith_11_2 = arith_out_2;
  __CPROVER_assume(pub_scale_1 == pub_scale_2);
  __CPROVER_assume(sec_val_1 != sec_val_2);
  assert(glob_arith_11_1 == glob_arith_11_2);
  assert(arith_out_1 == arith_out_2);
}


