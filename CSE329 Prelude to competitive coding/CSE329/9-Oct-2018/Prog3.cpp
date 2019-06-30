
#include<bits/stdc++.h> 
using namespace std; 

bool isPrime(int n) 
{ 
    if (n < 2) 
        return false; 
          
    for (int i = 2; i <= sqrt(n); i++) { 
        if (n % i == 0) 
            return false; 
    } 
    return true; 
} 

void lemoine(int n) 
{ 

    map<int, int> pr; 
      
    map<int, int>::iterator it; 
    it = pr.begin(); 
      
    for (int q = 1; q <= n / 2; q++)  
    {  
        int p = n - 2 * q; 
          
        if (isPrime(p) && isPrime(q)) 
          
            pr.insert(it, pair<int, int>(p, q)); 
    } 
       
    for (it = pr.begin(); it != pr.end(); ++it) 
        cout << n << " = " << it->first 
             << " + (2 * " << it->second << ")\n"; 
} 
  

int main() 
{ 
    int n=1;
    while(n){
        cin>>n;
        cout << n << " can be expressed as " << endl; 
        lemoine(n); 
    }
    return 0; 
} 
  
