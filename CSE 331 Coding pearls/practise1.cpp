#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

int pal(int e){
	int n=e;
	 int reversedNumber = 0, remainder;
	 while(n != 0)
    {
        remainder = n%10;
        reversedNumber = reversedNumber*10 + remainder;
        n /= 10;
    }
return reversedNumber;
    //cout << "Reversed Number = " << reversedNumber;
	/*string s=itoa(c);
	reverse(s.begin(), s.end());
	cout<<s<<"  ";*/
//	cout<<e<<endl;

//	return 0;}
//	else
//	return 1;

}


//906609
int main(){
	int e,f,max=1,s,l;

	for(int i=999;i>100;i--){
		for(int j=999;j>100;j--){
		e=j*i;
		f=pal(e);
	if(f==e){
	if(max<f){
		max=f;
		s=i;
		l=j;
	}
		
}
		}
	}
	cout<<max<<"="<<s<<"*"<<l;
	
/*	for(int i=999;i>100;i--){
		for(int j=999;j>100;j--){
		cout<<i*j<<" "<<i<<"  "<<j<<endl;}}
	*/
}
