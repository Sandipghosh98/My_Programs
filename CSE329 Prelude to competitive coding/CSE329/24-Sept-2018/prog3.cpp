#include<bits/stdc++.h>
using namespace std;

void primeFactors(int n) 
{ 
    while (n%2 == 0) 
    { 
        cout<<2<<" "; 
        n = n/2; 
    } 
    
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        if(n%i == 0) 
        { 
            cout<<i<<" ";
            n = n/i; 
        } 
    } 

    if (n > 2) cout<<n<<" ";
}

int main(){
    primeFactors(1990874038);
    cout<<endl;
}