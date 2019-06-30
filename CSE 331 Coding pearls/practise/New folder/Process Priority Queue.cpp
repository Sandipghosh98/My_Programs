#include<bits/stdc++.h>
using namespace std;
struct process
{
	int pid;
	int priority;
}heap[11];
int n,capacity=10;
int parent(int k)
{
	return k/2;
}
void siftup(int k)
{
	while(k>1 && heap[parent(k)].priority<heap[k].priority)
	{
		swap(heap[parent(k)].priority,heap[k].priority);
		swap(heap[parent(k)].pid,heap[k].pid);
		k=parent(k);
	}
}
void display()
{
	for(int i=1;i<=n;i++)
	cout<<heap[i].priority<<" "<<heap[i].pid<<" ";
	cout<<endl;
}
int getMax()
{
	return heap[1].pid;
}
void ins(int priority, int pid)
{
	if(n==capacity)
	{
		cout<<"Max Capacity reached "<<endl;
		return ;
	}
	heap[++n].priority=priority;
	heap[n].pid=pid;
	siftup(n);
}
void siftdown(int k)
{
	while(2*k<=n)
	{
		int j=2*k;
		if(j<n&&heap[j].priority<heap[j+1].priority) j++;
		if(heap[k].priority>heap[j].priority) break;
		swap(heap[k].priority,heap[j].priority);
		swap(heap[k].pid,heap[j].pid);
		k=j;
	}
}
int extractMax()
{
	if(n<1)
	{
		cout<<"Empty"<<endl;
		return -1;
		
	}
	int max=heap[1].priority;
	swap(heap[1].priority,heap[n--].priority);
	swap(heap[1].pid,heap[n].pid);
	siftdown(1);
	return max;
	
}
int main()
{
	int ch,num,priority,pid;
	while(1)
	{
		cout<<"1. Insert in heap"<<endl;
		cout<<"2. Get Max "<<endl;
		cout<<"3. Display "<<endl;
		cout<<"4. Extract Max"<<endl;
		cout<<"Enter choice "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter Priority and PID: "<<endl;
			cin>> priority;
			cin>>pid;
			ins(priority,pid);
			break;
			case 2:
				cout<<getMax()<<endl;
				break;
				
			case 3:
				
				display();
				 break;
			case 4:
				cout<<extractMax()<<endl;
				break;
		}		
	}
	return 0;
}
