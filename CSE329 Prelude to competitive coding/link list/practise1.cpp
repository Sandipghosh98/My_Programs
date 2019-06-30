#include <iostream>
#include<math.h>

using namespace std;

int main() {
	//code
	int n,j,c;
	int count=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	for(int p=0;p<n;p++){
	    count=0;
	    	//cout<<a[p]<<endl;
	    //cout<<"sdf"<<endl;
	    for(int j=1;j<=a[p]/2;j++){
	        if(a[p]%j==0){
	        //	cout<<a[p]<<endl;
	        //	cout<<"yhvh"<<"  "<<j<<endl;
	        //	cout<<"sxdc"<<endl;
	            count=count +1;
	           // cout<<count<<endl;
	            if(count==2){
	                c=j;
	               // cout<<"dvfd"<<" "<<c<<" " <<endl;
	            }
	        }//	cout<<"ssss"<<"  "<<j<<endl;
	    }
	    cout<<"1";
	   // cout<<"okm";
	    if(count>1){
	        cout<<c;
	    }
	    cout<<endl<<count+1<<endl;
	    count=0;
	}
	return 0;
}
