void power_2(int x_1, unsigned n_1, int x_2, unsigned n_2)
{
  long long pow_1 = 1;
  long long pow_2 = 1;
  for (int i_1 = 0, i_2 = 0; (i_1 < n_1) && (i_2 < n_2); i_1++, i_2++)
  {
    pow_1 = pow_1 * x_1;
    pow_2 = pow_2 * x_2;
  }

  assert(pow_1 == pow_2);
}

long power(int x, unsigned n)
{
  long long pow = 1;
  for (int i = 0; i < n; i++)
  {
    pow = pow * x;
  }

  return pow;
}

void gcd_2(int a_1, int h_1, int a_2, int h_2)
{
  int temp_1;
  int temp_2;
  while (1 && 1)
  {
    temp_1 = a_1 % h_1;
    temp_2 = a_2 % h_2;
    if (temp_1 == 0)
      return h_1;
    if (temp_2 == 0)
      return h_2;
    a_1 = h_1;
    a_2 = h_2;
    h_1 = temp_1;
    h_2 = temp_2;
  }

  assert(temp_1 == temp_2);
}

int gcd(int a, int h)
{
  int temp;
  while (1)
  {
    temp = a % h;
    if (temp == 0)
      return h;
    a = h;
    h = temp;
  }

}

void rsa_2(int p_1, int q_1, int e_1, int k_1, int msg_1, int p_2, int q_2, int e_2, int k_2, int msg_2)
{
  int n_1 = p_1 * q_1;
  int n_2 = p_2 * q_2;
  int e_1;
  int e_2;
  int phi_1 = (p_1 - 1) * (q_1 - 1);
  int phi_2 = (p_2 - 1) * (q_2 - 1);
  while ((e_1 < phi_1) && (e_2 < phi_2))
  {
    if (gcd(e_1, phi_1) == 1)
      break;
    else
      e_1++;
    if (gcd(e_2, phi_2) == 1)
      break;
    else
      e_2++;
    gcd_2(e_1, phi_1, e_2, phi_2);
  }

  int k_1;
  int k_2;
  int d_1 = (1 + (k_1 * phi_1)) / e_1;
  int d_2 = (1 + (k_2 * phi_2)) / e_2;
  int msg_1;
  int msg_2;
  int c_1 = power(msg_1, e_1);
  int c_2 = power(msg_2, e_2);
  power_2(msg_1, e_1, msg_2, e_2);
  c_1 = c_1 % n_1;
  c_2 = c_2 % n_2;
  int m_1 = power(c_1, d_1);
  int m_2 = power(c_2, d_2);
  power_2(c_1, d_1, c_2, d_2);
  m_1 = m_1 % n_1;
  m_2 = m_2 % n_2;
  
  assert(n_1 == n_2);
  assert(phi_1 == phi_2);
  assert(d_1 == d_2);
  assert(c_1 == c_2);
  assert(m_1 == m_2);
}

int rsa(int p, int q, int e, int k, int msg)
{
  int n = p * q;
  int e;
  int phi = (p - 1) * (q - 1);
  while (e < phi)
  {
    if (gcd(e, phi) == 1)
      break;
    else
      e++;
  }

  int k;
  int d = (1 + (k * phi)) / e;
  int msg;
  int c = power(msg, e);
  c = c % n;
  int m = power(c, d);
  m = m % n;
  return 0;
}

void main()
{
  int p_1;
  int p_2;
  int q_1;
  int q_2;
  int e_1;
  int e_2;
  int k_1;
  int k_2;
  int msg_1;
  int msg_2;
  int res_1 = rsa(p_1, q_1, e_1, k_1, msg_1);
  int res_2 = rsa(p_2, q_2, e_2, k_2, msg_2);
  rsa_2(p_1, q_1, e_1, k_1, msg_1, p_2, q_2, e_2, k_2, msg_2);
  __CPROVER_assume(e_1 == e_2);
  __CPROVER_assume(q_1 == q_2);
  __CPROVER_assume(msg_1 == msg_2);
  __CPROVER_assume(p_1 == p_2);
 __CPROVER_assume(k_1 != k_2);
 
  assert(res_1 == res_2);
}


