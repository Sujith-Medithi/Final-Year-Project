#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


#define assume(c) ((c) ? (void)0 : exit(0))
#define SIZE 6

struct Account {
  int uid;
  int limit;
};

union Reg {
  int word;
  unsigned char part[2];
};

int g_attempts = 0;

int scale(int x, int f) { return x * f + 3; }

int total(int *vals, int n) {
  int acc = 0;
  int j = 0;
  while (j < n) {
    acc += vals[j];
    j++;
  }
  return acc;
}

int main(void) {
  int pin;
  int seed;
  int user_id;
  int slots[SIZE];
  int history[SIZE];
  int status = 0;
  int bonus = 0;
  int report = 0;
  int visible = 0;
  struct Account acct;
  union Reg reg;

  scanf("%d", &pin);
  scanf("%d", &seed);
  scanf("%d", &user_id);

  assume(pin >= 0 && pin < 10000);
  assume(seed >= 0 && seed < 100);
  assume(user_id >= 1 && user_id <= 50);

  for (int i = 0; i < SIZE; i++) {
    slots[i] = scale(user_id, i + 1);
    history[i] = 0;
  }

  acct.uid = user_id;
  acct.limit = pin / 10 + seed;
  reg.word = acct.limit;
  history[reg.part[0] % SIZE] = acct.limit;

  if (pin > 5000) {
    status = 2;
    g_attempts++;
  }

  if (user_id % 2 == 0) {
    report = total(history, SIZE);
  }

  for (int t = 0; t < seed % 3; t++) {
    bonus += 5;
  }

  visible = scale(user_id, 2);
  visible = visible + acct.limit;

  assert(status == 0 || status == 2);
  assert(slots[0] > 0);
  assert(g_attempts <= 1);

  printf("%d\n", user_id);
  printf("%d\n", report);
  printf("%d\n", visible);
  printf("%d\n", slots[2]);
  printf("%d\n", history[user_id % SIZE]);
  return 0;
}