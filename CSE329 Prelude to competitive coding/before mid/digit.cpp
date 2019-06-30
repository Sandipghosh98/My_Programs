#include<iostream>
using namespace std;
#include<math.h>
long long convert(int n){
long long decimalNumber = 0;
	 int  i = 1,e=0, remainder;
    while (n!=0)
    { e++;
        remainder = n%2;
        n /=2;
        decimalNumber += remainder*i;
        i=i*10;
    }	
	return decimalNumber;
	
}

int main()
{
	int a,b,n;
	cin>>a;
	cin>>b;
long long c,d;
c=convert(a);
d=convert(b);



    
    cout<<c;
    cout<<endl;
    cout<<d;
    cout<<endl;
   
}
