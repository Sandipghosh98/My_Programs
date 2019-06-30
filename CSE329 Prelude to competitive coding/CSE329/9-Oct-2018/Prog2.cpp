/* Lemoines Conjecture : any odd integer > 5 can be represented as 
sum of odd prime number and even semi prime number.
*/

// WAP to print all possible combinations of the Lemoine's Conjecture for a given number.


#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) 
{ 
    if (n < 2)  return false;
    if (n == 2)    return true;        
    for (int i = 3; i <= sqrt(n); i+=2) { 
        if (n % i == 0) return false; 
    } 
    return true; 
} 
  
void LemoineCombinations(int num)
{
    // 7 = 3 + (2 * 2).
    int i=2;
    while(2*i<num) {

    }

}

int main()
{
    int num;
    cin>>num;

}


// HomeWork.    Complete The Above Program.