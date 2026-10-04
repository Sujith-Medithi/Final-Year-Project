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
int glob_loop_30_1;
int glob_loop_30_2;
int glob_loop_30;
void loop_kernel_30_2(int d_1, int seed_1, int d_2, int seed_2)
{
  int acc_1 = seed_1;
  int acc_2 = seed_2;
  for (int i_1 = 0, i_2 = 0; (i_1 < 4) && (i_2 < 4); i_1++, i_2++)
  {
    acc_1 += ((d_1 >> i_1) & 1) + 30;
    acc_2 += ((d_2 >> i_2) & 1) + 30;
  }

  assert(acc_1 == acc_2);
}

int loop_kernel_30(int d, int seed)
{
  int acc = seed;
  for (int i = 0; i < 4; i++)
  {
    acc += ((d >> i) & 1) + 30;
  }

  return acc;
}

void main()
{
  int sec_data_1;
  int sec_data_2;
  int pub_seed_1;
  int pub_seed_2;
  int loop_out_1;
  int loop_out_2;
  loop_out_1 = loop_kernel_30(sec_data_1, pub_seed_1);
  loop_out_2 = loop_kernel_30(sec_data_2, pub_seed_2);
  loop_kernel_30_2(sec_data_1, pub_seed_1, sec_data_2, pub_seed_2);
  glob_loop_30_1 = loop_out_1;
  glob_loop_30_2 = loop_out_2;
  __CPROVER_assume(pub_seed_1 == pub_seed_2);
  __CPROVER_assume(sec_data_1 != sec_data_2);
  assert(glob_loop_30_1 == glob_loop_30_2);
  assert(loop_out_1 == loop_out_2);
}


