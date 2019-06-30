
#include<bits/stdc++.h>
using namespace std;


int bin(int a[],int low,int high,int n,int val){
	if(low<=high){
	int mid=low+(high-low)/2;
	if(a[mid]==val)
	return mid;
	else if(val>a[mid])
	 return bin(a,mid+1,high,n,val);
	 else
	return bin(a,low,mid-1,n,val);
	
}
return -1;

}


int main(){
		int a[]={2,4,10,20,50};
		int e=-1;
		int c;
		/*  another method
		for(int i=0;i<5;i++){
			if(a[i]<40)
			c=40-a[i];
			else{
		//	cout<<"vf";
			c=a[i]-40;}
			cout<<c<<"  ";
		
				e=bin(a,1,5,5,c);
				//e=bin(a,1,5,5,-c);
			cout<<e;
					
			if(e>0){
				cout<<i<<"  "<<e;
			}		
			cout<<endl;
		}
		
		*/
		int index=-1;
		for(int i=0;i<5;i++){
		index=bin(a,1,5,5,a[i]-40);
	//	cout<<index;
		if((i!=index) && (index !=-1)){
			
			cout<<a[i]<<"  "<<a[index];
			break;
		}
		}
}
