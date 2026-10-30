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
int lookup_table_85_1[4] = {10 + 340, 25 + 85, 42, 99};
int lookup_table_85_2[4] = {10 + 340, 25 + 85, 42, 99};
int lookup_table_85[4] = {10 + 340, 25 + 85, 42, 99};
int glob_arr_85_1;
int glob_arr_85_2;
int glob_arr_85;
void table_kernel_85_2(int idx_1, int base_1, int idx_2, int base_2)
{
  int safe_idx_1 = idx_1 % 4;
  int safe_idx_2 = idx_2 % 4;
  if (safe_idx_1 < 0)
    safe_idx_1 = -safe_idx_1;
  if (safe_idx_2 < 0)
    safe_idx_2 = -safe_idx_2;
  assert(safe_idx_1 == safe_idx_2);
}

int table_kernel_85(int idx, int base)
{
  int safe_idx = idx % 4;
  if (safe_idx < 0)
    safe_idx = -safe_idx;
  return lookup_table_85[safe_idx] + base;
}

void main()
{
  int sec_idx_1;
  int sec_idx_2;
  int pub_base_1;
  int pub_base_2;
  int arr_out_1;
  int arr_out_2;
  arr_out_1 = table_kernel_85(sec_idx_1, pub_base_1);
  arr_out_2 = table_kernel_85(sec_idx_2, pub_base_2);
  table_kernel_85_2(sec_idx_1, pub_base_1, sec_idx_2, pub_base_2);
  glob_arr_85_1 = arr_out_1;
  glob_arr_85_2 = arr_out_2;
  __CPROVER_assume(sec_idx_1 != sec_idx_2);
  __CPROVER_assume(pub_base_1 == pub_base_2);
  assert(glob_arr_85_1 == glob_arr_85_2);
  assert(arr_out_1 == arr_out_2);
}


