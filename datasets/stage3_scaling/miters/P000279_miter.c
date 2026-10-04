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
int glob_part_78_1;
int glob_part_78_2;
int glob_part_78;
void partial_kernel_78_2(int s_1, int b_1, int s_2, int b_2)
{
}

int partial_kernel_78(int s, int b)
{
  return ((s >> 1) & 15) + b;
}

void main()
{
  int secret_k_1;
  int secret_k_2;
  int pub_bias_1;
  int pub_bias_2;
  int part_out_1;
  int part_out_2;
  part_out_1 = partial_kernel_78(secret_k_1, pub_bias_1);
  part_out_2 = partial_kernel_78(secret_k_2, pub_bias_2);
  partial_kernel_78_2(secret_k_1, pub_bias_1, secret_k_2, pub_bias_2);
  glob_part_78_1 = part_out_1;
  glob_part_78_2 = part_out_2;
  __CPROVER_assume(secret_k_1 != secret_k_2);
  __CPROVER_assume(pub_bias_1 == pub_bias_2);
  assert(glob_part_78_1 == glob_part_78_2);
  assert(part_out_1 == part_out_2);
}


