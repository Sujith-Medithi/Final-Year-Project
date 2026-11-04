#include <assert.h>
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
int g_sink_1 = 0;
int g_sink_2 = 0;
int g_sink = 0;
void security_kernel_2(int sec_1, int pub_1, int sec_2, int pub_2)
{
  int mask_1 = (sec_1 ^ 0x3F) & 15;
  int mask_2 = (sec_2 ^ 0x3F) & 15;
  int acc_1 = pub_1 * 3;
  int acc_2 = pub_2 * 3;
  if (mask_1 > 8)
  {
    acc_1 += mask_1 * 2;
  }
  else
  {
    acc_1 -= mask_1 + 1;
  }
  if (mask_2 > 8)
  {
    acc_2 += mask_2 * 2;
  }
  else
  {
    acc_2 -= mask_2 + 1;
  }
  assert(mask_1 == mask_2);
  assert(acc_1 == acc_2);
}

int security_kernel(int sec, int pub)
{
  int mask = (sec ^ 0x3F) & 15;
  int acc = pub * 3;
  if (mask > 8)
  {
    acc += mask * 2;
  }
  else
  {
    acc -= mask + 1;
  }
  return acc;
}

void main()
{
  int secret_val_1;
  int secret_val_2;
  int public_val_1;
  int public_val_2;
  __CPROVER_assume((public_val_1 >= (-1000)) && (public_val_1 <= 1000));
  __CPROVER_assume((public_val_2 >= (-1000)) && (public_val_2 <= 1000));
  __CPROVER_assume((secret_val_1 >= 0) && (secret_val_1 <= 255));
  __CPROVER_assume((secret_val_2 >= 0) && (secret_val_2 <= 255));
  int intermediate_1;
  int intermediate_2;
  intermediate_1 = security_kernel(secret_val_1, public_val_1);
  intermediate_2 = security_kernel(secret_val_2, public_val_2);
  security_kernel_2(secret_val_1, public_val_1, secret_val_2, public_val_2);
  int status_1 = 0;
  int status_2 = 0;
  status_1 = status_1 + 1;
  status_2 = status_2 + 1;
  g_sink_1 = intermediate_1 + status_1;
  g_sink_2 = intermediate_2 + status_2;
  __CPROVER_assume(public_val_1 == public_val_2);
  __CPROVER_assume(secret_val_1 != secret_val_2);
  assert(g_sink_1 == g_sink_2);
  assert(intermediate_1 == intermediate_2);
  assert(status_1 == status_2);
}


