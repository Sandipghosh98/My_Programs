
#include<iostream>
using namespace std;
#include<math.h>


int answer(int a[],int n){
int x,y;
int tillnow=0,Max=0,start=0,stop=0,s=0;
for(int i=1;i<n;i++){
	
tillnow+=a[i];
	if(tillnow<0){
	
	s=i+1;
	tillnow=0;
}
	else if(tillnow>Max){
	
	Max=tillnow;
	start=s;
	stop=i;
	}
}
cout<<"start with "<<start<<"  End with "<<stop<<endl;
return Max;

}


int main(){
	
	int a[]={-1,1,-100,200,5},n=sizeof(a)/sizeof(a[0]);
	//cout<<n;
	cout<<answer(a,n);
}
