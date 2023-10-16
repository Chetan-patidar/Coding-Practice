#include <bits/stdc++.h>
long long gcdExtended(long long a, long long b, long long* x, long long* y);
 
// Function to find modulo inverse of a
long long modInverse(long long A, long long M)
{
    long long x, y;
    long long g = gcdExtended(A, M, &x, &y);
    if (g != 1)
        return 1;
        // cout << "Inverse doesn't exist";
    else {
 
        // m is added to handle negative x
        long long res = (x % M + M) % M;
        return res;
        // cout << "Modular multiplicative inverse is " << res;
    }
}
 
// Function for extended Euclidean Algorithm
long long gcdExtended(long long a, long long b, long long* x, long long* y)
{
 
    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
 
    // To store results of recursive call
    long long x1, y1;
    long long gcd = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}
int countSquares(int nn, int mm)
{
    long long mod = 1000000007;
    long long m = mm;
    long long n = nn;
    // Write your code here.
    // int answer = 0;
    // for(int i=1;i<=min(n,m);i++){
    //     answer = (answer + ((n-i+1)*(m-i+1))%1000000007)%1000000007;
    // }
    // return answer;
    if(n>m){
        int temp = m;
        m = n;
        n = temp;
    }


    long long int term1 = (((n*m)%mod)*n)%mod;
    long long int term2 = (((m+n)%mod)*(((n*(n-1))/2)%mod))%mod;
    long long int term3 = (((((n*(n-1))%mod)*(2*n-1))%mod)*modInverse(6,mod))%mod;

    // cout<<((30*modInverse(6,mod))%mod)<<" "<<((((n*(n-1))%mod)*(2*n-1))%mod)<<" "<<term3<<endl;
    int answer = (term1-term2+term3+mod)%mod;
    return answer;
}
