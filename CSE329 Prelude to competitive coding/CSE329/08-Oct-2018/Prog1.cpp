// WAP to find first 15 Stormer Numbers.  if GPF(i*i+1) >= 2*i , Then i is a Stormer Number.
#include<bits/stdc++.h>
using namespace std;

int maxPrimeFactors(int n) { 
    int maxPrime = -1; 
    while(n % 2 == 0) {
        maxPrime = 2; 
        n /= 2; 
    }

    for(int i=3;i*i<=n;i+=2) 
        while(n % i == 0) { 
            maxPrime = i; 
            n /= i; 
        } 

    if (n > 2)  maxPrime = n; 
  
    return (int)(maxPrime); 
} 
void stormerNums(int n) { 
    int i = 1; 

    int count = 0; 
    while(count < n) { 
        int t = i * i + 1; 
        if (maxPrimeFactors(t) >= 2 * i) { 
            cout<<i<<" ";
            count += 1; 
        } 
        i += 1; 
    } 
}
int main(){
    int num=15;
    stormerNums(num);
}