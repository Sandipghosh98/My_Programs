#include<bits/stdc++.h>
using namespace std;
int main()
{
	priority_queue<int> pq;
	pq.push(10);
	pq.push(100);
	pq.push(1);
	pq.push(1000);
	pq.push(10000);
	pq.push(11);
	cout<<"Front : "<<pq.top()<<endl;
	cout<<"Size : "<<pq.size()<<endl;
	pq.pop();
	cout<<"Front : "<<pq.top()<<endl;
	cout<<"Size : "<<pq.size()<<endl;
	priority_queue<int>nq=pq;
	cout<<"MAX HEAP : "<<endl;
	while(!nq.empty())
	{
		cout<<nq.top()<<endl;
		nq.pop();
	}
	while(!pq.empty())
	{
		cout<<pq.top()<<endl;
		pq.pop();
	}
	priority_queue<int, vector<int>, greater<int> > pq1;
	pq1.push(10);
	pq1.push(100);
	pq1.push(1);
	pq1.push(1000);
	pq1.push(10000);
	pq1.push(11);
	cout<<"MIN HEAP : "<<endl;
	while(!pq1.empty())
	{
		cout<<pq1.top()<<endl;
		pq1.pop();
	}
	return 0;
}
