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
int glob_multi_11_1 = 0;
int glob_multi_11_2 = 0;
int glob_multi_11 = 0;
void multi_kernel_11_2(int k1_1, int k2_1, int nonce_1, int k1_2, int k2_2, int nonce_2)
{
  int comb_1 = (k1_1 & 15) ^ (k2_1 & 15);
  int comb_2 = (k1_2 & 15) ^ (k2_2 & 15);
  assert(comb_1 == comb_2);
}

int multi_kernel_11(int k1, int k2, int nonce)
{
  int comb = (k1 & 15) ^ (k2 & 15);
  return comb + nonce;
}

void main()
{
  int sec_key1_1;
  int sec_key1_2;
  int sec_key2_1;
  int sec_key2_2;
  int pub_nonce_1;
  int pub_nonce_2;
  int combo_out_1;
  int combo_out_2;
  combo_out_1 = multi_kernel_11(sec_key1_1, sec_key2_1, pub_nonce_1);
  combo_out_2 = multi_kernel_11(sec_key1_2, sec_key2_2, pub_nonce_2);
  multi_kernel_11_2(sec_key1_1, sec_key2_1, pub_nonce_1, sec_key1_2, sec_key2_2, pub_nonce_2);
  glob_multi_11_1 = combo_out_1;
  glob_multi_11_2 = combo_out_2;
  __CPROVER_assume(sec_key2_1 != sec_key2_2);
  __CPROVER_assume(pub_nonce_1 == pub_nonce_2);
  __CPROVER_assume(sec_key1_1 != sec_key1_2);
  assert(glob_multi_11_1 == glob_multi_11_2);
  assert(combo_out_1 == combo_out_2);
}


