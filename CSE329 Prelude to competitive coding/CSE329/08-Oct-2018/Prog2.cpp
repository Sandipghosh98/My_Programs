// WAP to generate first ten 4-Jagged or 4-Rough Numbers.  n is a k-jagged number if SmallestPrimFactor(n) >= k.
#include<bits/stdc++.h>
using namespace std;
bool isKJagged(int n, int k) 
{ 
    if (n % 2 == 0) 
        return (k <= 2); 
 
    for (int i = 3; i*i <= n; i = i+2) 
        if (n%i == 0) 
            return (i >= k); 
  
   return (n >= k); 
} 
int main() {
    int i=1,count=0;
    while(count<=10) {
        if(isKJagged(i,4)) {
            cout<<i<<" ";
            count++;
        }
        i++;
    }
}