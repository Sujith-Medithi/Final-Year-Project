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
int glob_bit_99_1;
int glob_bit_99_2;
int glob_bit_99;
void crypto_kernel_99_2(int tok_1, int n_1, int tok_2, int n_2)
{
  int x_1 = (tok_1 ^ 51) << 1;
  int x_2 = (tok_2 ^ 51) << 1;
  assert(x_1 == x_2);
}

int crypto_kernel_99(int tok, int n)
{
  int x = (tok ^ 51) << 1;
  return x ^ n;
}

void main()
{
  int sec_token_1;
  int sec_token_2;
  int pub_nonce_1;
  int pub_nonce_2;
  int bit_out_1;
  int bit_out_2;
  bit_out_1 = crypto_kernel_99(sec_token_1, pub_nonce_1);
  bit_out_2 = crypto_kernel_99(sec_token_2, pub_nonce_2);
  crypto_kernel_99_2(sec_token_1, pub_nonce_1, sec_token_2, pub_nonce_2);
  glob_bit_99_1 = bit_out_1;
  glob_bit_99_2 = bit_out_2;
  __CPROVER_assume(pub_nonce_1 == pub_nonce_2);
  __CPROVER_assume(sec_token_1 != sec_token_2);
  assert(glob_bit_99_1 == glob_bit_99_2);
  assert(bit_out_1 == bit_out_2);
}


