
#include<iostream>
using namespace std;
#include<math.h>


void answer(int a[],int n){

int tillnow=a[0],Max=a[0];
for(int i=1;i<n;i++){
	
tillnow= max(a[i],tillnow+a[i]);
	Max= max(Max,tillnow);
}
cout<<Max;

}


int main(){
	
	int a[]={-1,-101,-100,-200,-3},n=sizeof(a)/sizeof(a[0]);
	cout<<n;
	answer(a,n);
}
