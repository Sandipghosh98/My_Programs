#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	int a;
	queue<int>qe;
	for(int i=0;i<n;i++){
		cin>>a;
		qe.push(a);
	}
//	int e=log(n)/log(2);
	int u=2;
int q=0;
			
//	for(int i=1;i<e;i++){
	while(!qe.empty()){
	
		if(u%2==0){
		//	cout<<"123"<<endl;
				for(int j=0;j<pow(2,q);j++){
					
					
					if(qe.empty()){
					//	cout<<"1236"<<" ";
						break;
					}
		//	cout<<arr[j]<<" ";
		cout<<qe.front()<<" ";
			qe.pop();
			
	}
			
			
		}else{
		//	cout<<"abc"<<endl;
			stack<int>st;
				for(int j=0;j<pow(2,q);j++){
			if(qe.empty()){
			//		cout<<"abc6"<<" ";
						break;
					}
			st.push(qe.front());
			qe.pop();
			
	//	cout<<arr[j]<<" ";
	}
			
			while(!st.empty()){
				cout<<st.top()<<" ";
				st.pop();
			}
				
		}
		u++;
		q++;
	}
	
}
