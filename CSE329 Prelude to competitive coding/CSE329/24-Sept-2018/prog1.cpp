#include<iostream>
using namespace std;

long int N = 1000000007;

int expo(long base, long exp){
    if (exp == 0) return 1;
    if (exp == 1) return base % N;

    int t = expo(base, exp / 2); 
    t = (t * t) % N; 

    if (exp % 2 == 0) 
        return t; 

    else
        return ((base % N) * t) % N; 
}

int main(){
    long int r=expo(5,100000);
    cout<<r;
}
