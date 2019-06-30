
#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
void revers(queue<int>& q){
	if(q.empty())
	return ;
	int data=q.front();
	q.pop();
	revers(q);
	q.push(data);
	
	
	
	
}



int main(){

stack<int>s;
queue<int>q;
for(int i=1;i<=10;i++)
	q.push(i);

revers(q);
 while(!q.empty()){
 

cout<<q.front()<<endl;
//cout<<"iuytg"<<endl;
	q.pop();
}
}
