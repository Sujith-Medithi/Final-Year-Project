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
int glob_nest_33_1;
int glob_nest_33_2;
int glob_nest_33;
void nested_kernel_33_2(int sc_1, int fl_1, int sc_2, int fl_2)
{
  int cat_1 = 0;
  int cat_2 = 0;
  if (sc_1 > 380)
  {
    cat_1 = 3;
  }
  else
  {
    if (sc_1 > 350)
    {
      cat_1 = 1;
    }
    else
    {
      cat_1 = 0;
    }
  }
  if (sc_2 > 380)
  {
    cat_2 = 3;
  }
  else
  {
    if (sc_2 > 350)
    {
      cat_2 = 1;
    }
    else
    {
      cat_2 = 0;
    }
  }
  assert(cat_1 == cat_2);
}

int nested_kernel_33(int sc, int fl)
{
  int cat = 0;
  if (sc > 380)
  {
    cat = 3;
  }
  else
  {
    if (sc > 350)
    {
      cat = 1;
    }
    else
    {
      cat = 0;
    }
  }
  return (cat + fl) + 33;
}

void main()
{
  int sec_score_1;
  int sec_score_2;
  int pub_flag_1;
  int pub_flag_2;
  int nest_out_1;
  int nest_out_2;
  nest_out_1 = nested_kernel_33(sec_score_1, pub_flag_1);
  nest_out_2 = nested_kernel_33(sec_score_2, pub_flag_2);
  nested_kernel_33_2(sec_score_1, pub_flag_1, sec_score_2, pub_flag_2);
  glob_nest_33_1 = nest_out_1;
  glob_nest_33_2 = nest_out_2;
  __CPROVER_assume(pub_flag_1 == pub_flag_2);
  __CPROVER_assume(sec_score_1 != sec_score_2);
  assert(glob_nest_33_1 == glob_nest_33_2);
  assert(nest_out_1 == nest_out_2);
}


