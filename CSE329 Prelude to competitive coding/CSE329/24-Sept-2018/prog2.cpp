#include<iostream>
using namespace std;

long N = 1000000007L;

long exponentiation(long base, long exp) 
{ 
    long t = 1L; 
    while (exp > 0) { 
        if (exp % 2 != 0) 
            t = (t * base) % N; 

        base = (base * base) % N; 
        exp /= 2; 
    } 
    return t % N; 
} 

int main(){
    cout<<exponentiation(5,10000)<<endl;
}
