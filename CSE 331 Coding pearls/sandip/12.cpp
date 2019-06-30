#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    vector<int> v;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        v.push_back(a[i]);
    }
       sort(v.begin(), v.end(), greater<int>()); 
     for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    int t;
    cin>>t;
    int p;
    
    
    
    while(t--){
      cout<<"san"<<" ";
        cin>>p;
        cout<<p;
        if(p==1){
            cout<<"oi"<<" ";
            int e;
            cin>>e;
             v.push_back(e);
        }
        else if(p==2){
             cout<<"po"<<" ";
            int y=0;
            for(int i=0;i<v.size();i++){
                //cout<<v[i]<<" ";
                
                y++;
                if(y==10)
                    break;
            }
        }
        else if(p==3){
             cout<<"ed"<<" ";
             v.erase(v.begin());
        }
        
        
    }
    
    return 0;
}












