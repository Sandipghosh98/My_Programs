
#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;




int main(){

stack<int>s;
queue<int>q;
for(int i=1;i<=10;i++)

	q.push(i);
	while(!q.empty())
	{
			s.push(q.front());
		cout<<q.front()<<endl;
	//	cout<<"dfg"<<endl;
		q.pop();
	}
	
//	cout<<q.size()<<endl;



	//q.push(j);
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
 while(!q.empty()){
 

cout<<q.front()<<endl;
//cout<<"iuytg"<<endl;
	q.pop();
}

}

