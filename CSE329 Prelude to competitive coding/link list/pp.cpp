#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        
    }
    int r,e=0;
    cin>>r;
    int x;
    int y;
    
    for(int j=0;j<r;j++){
        cin>>x>>y;
        for(int k=x-1;k<y;k++){
            int n1, rev = 0, rem;

//cout<<a[k]<<endl;
n1=a[k];
    while(n1 != 0)
    {
        rem = n1%10;
        rev = rev*10 + rem;
        n1 /= 10;
    }
   // cout<<rev<<endl;
  if(a[k]==rev){
      e=e+1;
  }
            
        }      
            cout<<e<<endl;
            e=0;
            
        
    }
    
    
    
    
    
    
    return 0;
}

