#include <iostream>
#include<math.h>
using namespace std;

bool isPrime(int n)
{
// Corner case
if (n <= 1)
return false;

// Check from 2 to n-1
for (int i = 2; i < n; i++)
if (n % i == 0)
return false;

return true;
}

int main()
{
int n;
cin>>n;

for (int i = 2; i < sqrt(n); i++) {
if ((n%i==0) and (isPrime(i)==true))
{
cout<<i<<" ";
}
}


return 0;

}
