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
int glob_implicit_4_1 = 0;
int glob_implicit_4_2 = 0;
int glob_implicit_4 = 0;
void branch_kernel_4_2(int secret_1, int pub_id_1, int secret_2, int pub_id_2)
{
  int flag_1 = 0;
  int flag_2 = 0;
  if (secret_1 > 100)
  {
    flag_1 = 1;
  }
  else
  {
    flag_1 = 2;
  }
  if (secret_2 > 100)
  {
    flag_2 = 1;
  }
  else
  {
    flag_2 = 2;
  }
  assert(flag_1 == flag_2);
}

int branch_kernel_4(int secret, int pub_id)
{
  int flag = 0;
  if (secret > 100)
  {
    flag = 1;
  }
  else
  {
    flag = 2;
  }
  return flag + pub_id;
}

void main()
{
  int sec_pw_1;
  int sec_pw_2;
  int pub_user_1;
  int pub_user_2;
  int outcome_1;
  int outcome_2;
  outcome_1 = branch_kernel_4(sec_pw_1, pub_user_1);
  outcome_2 = branch_kernel_4(sec_pw_2, pub_user_2);
  branch_kernel_4_2(sec_pw_1, pub_user_1, sec_pw_2, pub_user_2);
  glob_implicit_4_1 = outcome_1;
  glob_implicit_4_2 = outcome_2;
  __CPROVER_assume(pub_user_1 == pub_user_2);
  __CPROVER_assume(sec_pw_1 != sec_pw_2);
  assert(glob_implicit_4_1 == glob_implicit_4_2);
  assert(outcome_1 == outcome_2);
}


