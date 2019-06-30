#include<bits/stdc++.h>
//in this tree the parent value is always greater than the child value
using namespace std;



bool check(int a[],int n){

for(int i=n/2;i>=1;i--){
if(a[i]<a[2*i])
return false;
if(2*i+1 <= n && a[i]<a[2*i+1])     // we have to check only for the right child not for left child
return false;
}
return true;
}

int main(){
	
	
	int a[6]={8,0,6,5,4,3};
	int e=0;
	int n=5;
/*	for(int i=5/2;i>=1;i--){
		if(a[i]>a[2*i] && a[i]> a[(2*i)+1]){
		e++;	
		}
		else{
			cout<<"not possible"<<endl;
	break;
		//	system.exit(0);
		}
	}
	*/
	if(check(a,--n))
		cout<<"it is possible"<<endl;
		else 
		cout<<"it is not  possible a max heap tree"<<endl;
		
		// stl function
		priority_queue<int> pq;
		pq.push(10);
		pq.push(100);
		pq.push(1);
		pq.push(10000);
		pq.push(1000);
		pq.push(120);
		cout<<"front: "<<pq.top()<<endl;
		cout<<"Size : "<<pq.size()<<endl;
		pq.pop();
		cout<<"front: "<<pq.top()<<endl;
			
		priority_queue<int> nq=pq;
		while(!nq.empty()){
			cout<<nq.top()<<endl;
			nq.pop();
		}
		priority_queue<int,vector<int>, greater<int> > eq;  // it will display like max heap opposite of the above
				pq.push(10);
		eq.push(1);
		eq.push(10);
		eq.push(100);
		eq.push(1000);
		eq.push(10000);
		
		//given with k arrays with n element in a increasing order than make a single array with the same element in a single array 
		//with increasing order
}
