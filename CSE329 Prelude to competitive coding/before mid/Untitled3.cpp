
#include<iostream>
using namespace std;
#include<math.h>


int answer(int a[],int n){
int x,y;
int tillnow=a[0],Max=a[0];
for(int i=1;i<n;i++){
	
tillnow= max(a[i],tillnow+a[i]);
	Max= max(Max,tillnow);
}
return Max;

}


int main(){
	
	int a[]={-1,101,100,-200,50},n=sizeof(a)/sizeof(a[0]);
	//cout<<n;
	cout<<answer(a,n);
}
