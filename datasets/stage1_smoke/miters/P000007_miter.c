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
int glob_nested_7_1 = 0;
int glob_nested_7_2 = 0;
int glob_nested_7 = 0;
void classify_kernel_7_2(int score_1, int flag_1, int score_2, int flag_2)
{
  int cat_1 = 0;
  int cat_2 = 0;
  if (score_1 > 50)
  {
    if (score_1 > 80)
    {
      cat_1 = 3;
    }
    else
    {
      cat_1 = 2;
    }
  }
  else
  {
    if (score_1 > 20)
    {
      cat_1 = 1;
    }
    else
    {
      cat_1 = 0;
    }
  }
  if (score_2 > 50)
  {
    if (score_2 > 80)
    {
      cat_2 = 3;
    }
    else
    {
      cat_2 = 2;
    }
  }
  else
  {
    if (score_2 > 20)
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

int classify_kernel_7(int score, int flag)
{
  int cat = 0;
  if (score > 50)
  {
    if (score > 80)
    {
      cat = 3;
    }
    else
    {
      cat = 2;
    }
  }
  else
  {
    if (score > 20)
    {
      cat = 1;
    }
    else
    {
      cat = 0;
    }
  }
  return cat + flag;
}

void main()
{
  int sec_score_1;
  int sec_score_2;
  int pub_flag_1;
  int pub_flag_2;
  int level_1;
  int level_2;
  level_1 = classify_kernel_7(sec_score_1, pub_flag_1);
  level_2 = classify_kernel_7(sec_score_2, pub_flag_2);
  classify_kernel_7_2(sec_score_1, pub_flag_1, sec_score_2, pub_flag_2);
  glob_nested_7_1 = level_1;
  glob_nested_7_2 = level_2;
  __CPROVER_assume(sec_score_1 != sec_score_2);
  __CPROVER_assume(pub_flag_1 == pub_flag_2);
  assert(glob_nested_7_1 == glob_nested_7_2);
  assert(level_1 == level_2);
}


