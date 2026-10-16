#include <stdio.h>

struct Packet {
  int id;
  int payload;
};

union Word {
  unsigned int as_int;
  unsigned char as_bytes[4];
};

void assume(int cond);
void assert(int cond);

int mix(int a, int b) {
  int r = a * 31 + b;
  r = r ^ (r >> 3);
  return r;
}

int checksum(int *data, int n) {
  int sum = 0;
  int i;
  for (i = 0; i < n; i++) {
    sum = sum + data[i];
  }
  return sum;
}

int classify(int v) {
  int bucket;
  switch (v % 3) {
  case 0:
    bucket = 10;
    break;
  case 1:
    bucket = 20;
    break;
  default:
    bucket = 30;
    break;
  }
  return bucket;
}

int main() {
  int secret_key;
  int public_token;
  int table[6];
  int i;
  int k;
  int out_public;
  int audit;
  int rounds;
  struct Packet pkt;
  union Word w;

  scanf("%d", &secret_key);
  scanf("%d", &public_token);
  assume(secret_key >= 0 && secret_key <= 255);
  assume(public_token >= 0 && public_token <= 255);
  assume(public_token != 13);

  out_public = 0;
  audit = 0;
  k = 0;
  rounds = 0;

  pkt.id = public_token;
  pkt.payload = secret_key + 7;

  for (i = 0; i < 6; i++) {
    table[i] = mix(public_token, i);
  }

  w.as_int = public_token;
  table[0] = table[0] + w.as_bytes[0];

  if (secret_key > 100) {
    out_public = public_token + 1;
  }

  while (k < secret_key % 4) {
    k = k + 1;
  }

  audit = mix(pkt.payload, 3);
  audit = audit + pkt.payload;

  if (pkt.payload % 2 == 0) {
    rounds = rounds + 1;
  }

  do {
    rounds = rounds + 1;
  } while (rounds < 3);

  out_public = out_public + checksum(table, 6);
  out_public = out_public + classify(public_token);

  assert(table[0] >= 0);
  assert(pkt.id == public_token);
  assert(out_public >= 0);

  printf("out_public=%d\n", out_public);
  printf("audit=%d\n", audit);
  printf("payload=%d\n", pkt.payload);
  puts("done");
  putchar('\n');
  return 0;
}