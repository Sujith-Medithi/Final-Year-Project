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
int status_arr_51_1[3] = {1 + 51, 2, 4 + 51};
int status_arr_51_2[3] = {1 + 51, 2, 4 + 51};
int status_arr_51[3] = {1 + 51, 2, 4 + 51};
int glob_mix_51_1;
int glob_mix_51_2;
int glob_mix_51;
void hybrid_kernel_51_2(int param_1, int cfg_1, int param_2, int cfg_2)
{
  int state_1 = cfg_1;
  int state_2 = cfg_2;
  for (int i_1 = 0, i_2 = 0; (i_1 < 3) && (i_2 < 3); i_1++, i_2++)
  {
    if ((param_1 >> i_1) & 1)
    {
      state_1 += status_arr_51_1[i_1];
    }
    else
    {
      state_1 -= 1;
    }
    if ((param_2 >> i_2) & 1)
    {
      state_2 += status_arr_51_2[i_2];
    }
    else
    {
      state_2 -= 1;
    }
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(status_arr_51_1[i_0] == status_arr_51_2[i_0]);
  }

  assert(state_1 == state_2);
}

int hybrid_kernel_51(int param, int cfg)
{
  int state = cfg;
  for (int i = 0; i < 3; i++)
  {
    if ((param >> i) & 1)
    {
      state += status_arr_51[i];
    }
    else
    {
      state -= 1;
    }
  }

  return state + 51;
}

void main()
{
  int sec_param_1;
  int sec_param_2;
  int pub_config_1;
  int pub_config_2;
  int mix_out_1;
  int mix_out_2;
  mix_out_1 = hybrid_kernel_51(sec_param_1, pub_config_1);
  mix_out_2 = hybrid_kernel_51(sec_param_2, pub_config_2);
  hybrid_kernel_51_2(sec_param_1, pub_config_1, sec_param_2, pub_config_2);
  glob_mix_51_1 = mix_out_1;
  glob_mix_51_2 = mix_out_2;
  __CPROVER_assume(sec_param_1 != sec_param_2);
  __CPROVER_assume(pub_config_1 == pub_config_2);
  assert(glob_mix_51_1 == glob_mix_51_2);
  assert(mix_out_1 == mix_out_2);
}


