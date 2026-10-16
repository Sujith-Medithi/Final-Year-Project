void assert(int expression);
void __CPROVER_assume(int expression);
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
struct Account
{
  int uid;
  int limit;
};
union Reg
{
  int word;
  unsigned char part[2];
};
int g_attempts_1 = 0;
int g_attempts_2 = 0;
int g_attempts = 0;
void scale_2(int x_1, int f_1, int x_2, int f_2)
{
}

int scale(int x, int f)
{
  return (x * f) + 3;
}

void total_2(int *vals_1, int n_1, int *vals_2, int n_2)
{
  int acc_1 = 0;
  int acc_2 = 0;
  int j_1 = 0;
  int j_2 = 0;
  while ((j_1 < n_1) && (j_2 < n_2))
  {
    acc_1 += vals_1[j_1];
    acc_2 += vals_2[j_2];
    j_1++;
    j_2++;
  }

  assert(acc_1 == acc_2);
  assert(j_1 == j_2);
}

int total(int *vals, int n)
{
  int acc = 0;
  int j = 0;
  while (j < n)
  {
    acc += vals[j];
    j++;
  }

  return acc;
}

void main()
{
  int pin_1;
  int pin_2;
  int seed_1;
  int seed_2;
  int user_id_1;
  int user_id_2;
  int slots_1[6];
  int slots_2[6];
  int history_1[6];
  int history_2[6];
  int status_1 = 0;
  int status_2 = 0;
  int bonus_1 = 0;
  int bonus_2 = 0;
  int report_1 = 0;
  int report_2 = 0;
  int visible_1 = 0;
  int visible_2 = 0;
  struct Account acct_1;
  struct Account acct_2;
  union Reg reg_1;
  union Reg reg_2;
  scanf("%d", &pin_1);
  scanf("%d", &pin_2);
  scanf("%d", &seed_1);
  scanf("%d", &seed_2);
  scanf("%d", &user_id_1);
  scanf("%d", &user_id_2);
  ((pin_1 >= 0) && (pin_1 < 10000)) ? ((void) 0) : (exit(0));
  ((pin_2 >= 0) && (pin_2 < 10000)) ? ((void) 0) : (exit(0));
  exit_2(0, 0);
  ((seed_1 >= 0) && (seed_1 < 100)) ? ((void) 0) : (exit(0));
  ((seed_2 >= 0) && (seed_2 < 100)) ? ((void) 0) : (exit(0));
  exit_2(0, 0);
  ((user_id_1 >= 1) && (user_id_1 <= 50)) ? ((void) 0) : (exit(0));
  ((user_id_2 >= 1) && (user_id_2 <= 50)) ? ((void) 0) : (exit(0));
  exit_2(0, 0);
  for (int i_1 = 0, i_2 = 0; (i_1 < 6) && (i_2 < 6); i_1++, i_2++)
  {
    slots_1[i_1] = scale(user_id_1, i_1 + 1);
    slots_2[i_2] = scale(user_id_2, i_2 + 1);
    scale_2(user_id_1, i_1 + 1, user_id_2, i_2 + 1);
    history_1[i_1] = 0;
    history_2[i_2] = 0;
  }

  acct_1.uid = user_id_1;
  acct_2.uid = user_id_2;
  acct_1.limit = (pin_1 / 10) + seed_1;
  acct_2.limit = (pin_2 / 10) + seed_2;
  reg_1.word = acct_1.limit;
  reg_2.word = acct_2.limit;
  history_1[reg_1.part[0] % 6] = acct_1.limit;
  history_2[reg_2.part[0] % 6] = acct_2.limit;
  if (pin_1 > 5000)
  {
    status_1 = 2;
    g_attempts_1++;
  }
  if (pin_2 > 5000)
  {
    status_2 = 2;
    g_attempts_2++;
  }
  if ((user_id_1 % 2) == 0)
  {
    report_1 = total(history_1, 6);
  }
  if ((user_id_2 % 2) == 0)
  {
    report_2 = total(history_2, 6);
  }
  total_2(history_1, 6, history_2, 6);
  for (int t_1 = 0, t_2 = 0; (t_1 < (seed_1 % 3)) && (t_2 < (seed_2 % 3)); t_1++, t_2++)
  {
    bonus_1 += 5;
    bonus_2 += 5;
  }

  visible_1 = scale(user_id_1, 2);
  visible_2 = scale(user_id_2, 2);
  scale_2(user_id_1, 2, user_id_2, 2);
  visible_1 = visible_1 + acct_1.limit;
  visible_2 = visible_2 + acct_2.limit;
  assert((status_1 == 0) || (status_1 == 2));
  assert((status_2 == 0) || (status_2 == 2));
  assert(slots_1[0] > 0);
  assert(slots_2[0] > 0);
  assert(g_attempts_1 <= 1);
  assert(g_attempts_2 <= 1);
  printf("%d\n", user_id_1);
  printf("%d\n", user_id_2);
  printf("%d\n", report_1);
  printf("%d\n", report_2);
  printf("%d\n", visible_1);
  printf("%d\n", visible_2);
  printf("%d\n", slots_1[2]);
  printf("%d\n", slots_2[2]);
  printf("%d\n", history_1[user_id_1 % 6]);
  printf("%d\n", history_2[user_id_2 % 6]);
  __CPROVER_assume(user_id_1 == user_id_2);
  __CPROVER_assume(pin_1 != pin_2);
  __CPROVER_assume(seed_1 != seed_2);
  assert(g_attempts_1 == g_attempts_2);
  for (int i_0 = 0; i_0 < 6; i_0++)
  {
    assert(slots_1[i_0] == slots_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 6; i_0++)
  {
    assert(history_1[i_0] == history_2[i_0]);
  }

  assert(status_1 == status_2);
  assert(bonus_1 == bonus_2);
  assert(report_1 == report_2);
  assert(visible_1 == visible_2);
  assert(acct_1.uid == acct_2.uid);
  assert(acct_1.limit == acct_2.limit);
  assert(reg_1.word == reg_2.word);
  for (int i_part = 0; i_part < 2; i_part++)
  {
    assert(reg_1.part[i_part] == reg_2.part[i_part]);
  }

}


