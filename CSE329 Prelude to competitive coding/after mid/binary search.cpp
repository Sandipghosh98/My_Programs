
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
	
	int a[]={1,2,3,4,5};
	int c=bin(a,1,5,5,6);
	cout<<c;
	
}
