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
struct Packet
{
  int id;
  int payload;
};
union Word
{
  unsigned int as_int;
  unsigned char as_bytes[4];
};
void assume(int cond);
void assert(int cond);
void mix_2(int a_1, int b_1, int a_2, int b_2)
{
  int r_1 = (a_1 * 31) + b_1;
  int r_2 = (a_2 * 31) + b_2;
  r_1 = r_1 ^ (r_1 >> 3);
  r_2 = r_2 ^ (r_2 >> 3);
  assert(r_1 == r_2);
}

int mix(int a, int b)
{
  int r = (a * 31) + b;
  r = r ^ (r >> 3);
  return r;
}

void checksum_2(int *data_1, int n_1, int *data_2, int n_2)
{
  int sum_1 = 0;
  int sum_2 = 0;
  int i_1;
  int i_2;
  for (i_1 = 0, i_2 = 0; (i_1 < n_1) && (i_2 < n_2); i_1++, i_2++)
  {
    sum_1 = sum_1 + data_1[i_1];
    sum_2 = sum_2 + data_2[i_2];
  }

  assert(sum_1 == sum_2);
  assert(i_1 == i_2);
}

int checksum(int *data, int n)
{
  int sum = 0;
  int i;
  for (i = 0; i < n; i++)
  {
    sum = sum + data[i];
  }

  return sum;
}

void classify_2(int v_1, int v_2)
{
  int bucket_1;
  int bucket_2;
  switch (v_1 % 3)
  {
    case 0:
      bucket_1 = 10;
      break;

    case 1:
      bucket_1 = 20;
      break;

    default:
      bucket_1 = 30;
      break;

  }

  switch (v_2 % 3)
  {
    case 0:
      bucket_2 = 10;
      break;

    case 1:
      bucket_2 = 20;
      break;

    default:
      bucket_2 = 30;
      break;

  }

  assert(bucket_1 == bucket_2);
}

int classify(int v)
{
  int bucket;
  switch (v % 3)
  {
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

void main()
{
  int secret_key_1;
  int secret_key_2;
  int public_token_1;
  int public_token_2;
  int table_1[6];
  int table_2[6];
  int i_1;
  int i_2;
  int k_1;
  int k_2;
  int out_public_1;
  int out_public_2;
  int audit_1;
  int audit_2;
  int rounds_1;
  int rounds_2;
  struct Packet pkt_1;
  struct Packet pkt_2;
  union Word w_1;
  union Word w_2;
  scanf("%d", &secret_key_1);
  scanf("%d", &secret_key_2);
  scanf("%d", &public_token_1);
  scanf("%d", &public_token_2);
  assume((secret_key_1 >= 0) && (secret_key_1 <= 255));
  assume((secret_key_2 >= 0) && (secret_key_2 <= 255));
  assume((public_token_1 >= 0) && (public_token_1 <= 255));
  assume((public_token_2 >= 0) && (public_token_2 <= 255));
  assume(public_token_1 != 13);
  assume(public_token_2 != 13);
  out_public_1 = 0;
  out_public_2 = 0;
  audit_1 = 0;
  audit_2 = 0;
  k_1 = 0;
  k_2 = 0;
  rounds_1 = 0;
  rounds_2 = 0;
  pkt_1.id = public_token_1;
  pkt_2.id = public_token_2;
  pkt_1.payload = secret_key_1 + 7;
  pkt_2.payload = secret_key_2 + 7;
  for (i_1 = 0, i_2 = 0; (i_1 < 6) && (i_2 < 6); i_1++, i_2++)
  {
    table_1[i_1] = mix(public_token_1, i_1);
    table_2[i_2] = mix(public_token_2, i_2);
    mix_2(public_token_1, i_1, public_token_2, i_2);
  }

  w_1.as_int = public_token_1;
  w_2.as_int = public_token_2;
  table_1[0] = table_1[0] + w_1.as_bytes[0];
  table_2[0] = table_2[0] + w_2.as_bytes[0];
  if (secret_key_1 > 100)
  {
    out_public_1 = public_token_1 + 1;
  }
  if (secret_key_2 > 100)
  {
    out_public_2 = public_token_2 + 1;
  }
  while ((k_1 < (secret_key_1 % 4)) && (k_2 < (secret_key_2 % 4)))
  {
    k_1 = k_1 + 1;
    k_2 = k_2 + 1;
  }

  audit_1 = mix(pkt_1.payload, 3);
  audit_2 = mix(pkt_2.payload, 3);
  mix_2(pkt_1.payload, 3, pkt_2.payload, 3);
  audit_1 = audit_1 + pkt_1.payload;
  audit_2 = audit_2 + pkt_2.payload;
  if ((pkt_1.payload % 2) == 0)
  {
    rounds_1 = rounds_1 + 1;
  }
  if ((pkt_2.payload % 2) == 0)
  {
    rounds_2 = rounds_2 + 1;
  }
  do
  {
    rounds_1 = rounds_1 + 1;
    rounds_2 = rounds_2 + 1;
  }
  while ((rounds_1 < 3) && (rounds_2 < 3));
  out_public_1 = out_public_1 + checksum(table_1, 6);
  out_public_2 = out_public_2 + checksum(table_2, 6);
  checksum_2(table_1, 6, table_2, 6);
  out_public_1 = out_public_1 + classify(public_token_1);
  out_public_2 = out_public_2 + classify(public_token_2);
  classify_2(public_token_1, public_token_2);
  assert(table_1[0] >= 0);
  assert(table_2[0] >= 0);
  assert(pkt_1.id == public_token_1);
  assert(pkt_2.id == public_token_2);
  assert(out_public_1 >= 0);
  assert(out_public_2 >= 0);
  printf("out_public=%d\n", out_public_1);
  printf("out_public=%d\n", out_public_2);
  printf("audit=%d\n", audit_1);
  printf("audit=%d\n", audit_2);
  printf("payload=%d\n", pkt_1.payload);
  printf("payload=%d\n", pkt_2.payload);
  puts("done");
  puts("done");
  putchar('\n');
  putchar('\n');
  __CPROVER_assume(secret_key_1 != secret_key_2);
  __CPROVER_assume(public_token_1 == public_token_2);
  for (int i_0 = 0; i_0 < 6; i_0++)
  {
    assert(table_1[i_0] == table_2[i_0]);
  }

  assert(i_1 == i_2);
  assert(k_1 == k_2);
  assert(out_public_1 == out_public_2);
  assert(audit_1 == audit_2);
  assert(rounds_1 == rounds_2);
  assert(pkt_1.id == pkt_2.id);
  assert(pkt_1.payload == pkt_2.payload);
  assert(w_1.as_int == w_2.as_int);
  for (int i_as_bytes = 0; i_as_bytes < 4; i_as_bytes++)
  {
    assert(w_1.as_bytes[i_as_bytes] == w_2.as_bytes[i_as_bytes]);
  }

}


