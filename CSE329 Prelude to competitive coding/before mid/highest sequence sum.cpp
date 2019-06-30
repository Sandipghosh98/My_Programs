
#include<iostream>
using namespace std;



int answer(int a[],int n){

int tillnow=0,max=0;
for(int i=0;i<n;i++){
	
	tillnow+=a[i];
	if(tillnow<0)
	tillnow=0;
	else if(tillnow>max)
	max=tillnow;
	
}
return max;

}


int main(){
	
	int a[]={1,101,-100,200,3},n=5;
	cout<<answer(a,n);
}
