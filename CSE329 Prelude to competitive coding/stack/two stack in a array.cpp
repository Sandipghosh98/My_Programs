#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
using namespace std;

//void pop
/*
int  main()
{
	
stack<int>s;
s.push(1);
s.push(2);
	s.push(3);
	
	while(!s.empty())
	{
		cout<<s.top();
		s.pop();
	}
	
	
	
	
	
	
	
}
*/
void answer(int a[], int n){
	stack<int>s;
	s.push(a[0]);
	for(int i=1;i<n;i++)
	{
		
		while(!s.empty()  && s.top() < a[i])
		{
			cout<<a[i]<<"  ";
			s.pop();
		}
		s.push(a[i]);
		
	}
	while(!s.empty())
	{
		cout<<-1<<" ";
		s.pop();
	}
	
}
int main()
{  int a[]={1,2,3,4},n=sizeof(a)/sizeof(a[0]);
	answer(a,n);
	
}










