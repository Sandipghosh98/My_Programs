#include<bits/stdc++.h>
using namespace std;

double PHI = 1.6180339; 
int f[6] = { 0, 1, 1, 2, 3, 5 }; 

int fib (int n) 
{ 
    if (n < 6)  return f[n]; 
    
    int t = 5, fn = 5; 
    while (t < n) { 
         fn = round(fn * PHI); 
         t++; 
    } 
    return fn;    
} 

int gcd(int a, int b) 
{ 
    if (a == 0) return b; 
    return gcd(b % a, a); 
}

int main()
{
    int a,b,n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a>>b;
        a = fib(a);
        b = fib(b);
        cout<<gcd(a,b)<<endl;
    }
}