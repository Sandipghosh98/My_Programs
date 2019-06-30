#include<iostream>
using namespace std;
int main(){
	//int a[7];
int c=0,d=0;
	int a[7]={0,2,5,3,4,6};
	
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(i==a[j]){
			//	a[i]=i;
				cout<<"dfg"<<endl;
				c=3;
				
			//goto r;
				//cout<<j;
			}
			else{
			d=2;
			
			}
			}
					cout<<"san";
		if(c==3 && d==2){
		
		a[i]=i;
		
		}
		if(d==2 && c!=3){
		
			a[i]=-1;
		}
		c=0;
		d=0;
			
		}
	//
		

	
	int j;
	for(j=0;j<6;j++){
	cout<<a[j]<<"  ";
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
