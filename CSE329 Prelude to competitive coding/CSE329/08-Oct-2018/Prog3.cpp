#include <bits/stdc++.h> 
using namespace std; 

vector<int> getPrimes(int n) 
{ 
    int i, j; 
    bool isPrime[n + 1]; 
    memset(isPrime, true, sizeof(isPrime)); 
    for (i = 2; i * i <= n; i++) 
    { 
        if (isPrime[i] == true) 
        { 
            for (j = i * 2; j <= n; j += i) 
                isPrime[j] = false; 
        } 
    } 
    vector<int> primes; 
    for (i = 2; i <= n; i++) 
        if (isPrime[i]) 
            primes.push_back(i); 
    return primes; 
} 
  
bool isRough(int n, int k) 
{ 
    vector<int> primes = getPrimes(n); 
  
    int min_pf = n; 
    for (int i = 0; i < primes.size(); i++) 
        if (n % primes[i] == 0) 
            min_pf = primes[i]; 
    return (min_pf >= k); 
} 
  
int main() 
{ 
    int n = 1, k = 3,count = 0;
    while(count<10) {
        if(isRough(n,4)) {
            cout<<n<<" ";
            count++;
        }
        n++;
    }
    return 0; 
} 
