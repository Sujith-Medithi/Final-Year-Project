// C program for RSA asymmetric cryptographic
// algorithm. For demonstration values are
// relatively small compared to practical
// application

 int power(int x, int n)
{
    // Initialize result to 1
    int pow = 1;
 
    // Multiply x for n times
    for (int i = 0; i < n; i++) {
        pow = pow * x;
    }
 
    return pow;
}
// Returns gcd of a and b
int gcd(int a, int b)
{
    // Find Minimum of a and b
    int result = ((a < b) ? a : b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
 
    // Return gcd of a and b
    return result;
}

int rsa(int p,int q,int e,int k,int msg)
{
 // Two random prime numbers
 
 
    // First part of public key:
    int n = p * q;
 
    // Finding other part of public key.
    // e stands for encrypt
   
    int phi = (p - 1) * (q - 1);
    while (e < phi) {
        // e must be co-prime to phi and
        // smaller than phi.
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }
 
    // Private key (d stands for decrypt)
    // choosing d such that it satisfies
    // d*e = 1 + k * totient
   // A constant value
    int d = (1 + (k * phi)) / e;
 
    // Message to be encrypted
   
 
    
 	
    // Encryption c = (msg ^ e) % n
    int c = power(msg, e);
    c = c%n;
  
 
    // Decryption m = (c ^ d) % n
    int m = power(c, d);
    m =m%n;
    
  return m;
// Code to demonstrate RSA algorithm
}
int main()
{
   int p=3,q=7,e=2,k=2,msg=12,res;
   res=rsa(p,q,e,k,msg);
  	return res;
}
// This code is contributed by Akash Sharan.
