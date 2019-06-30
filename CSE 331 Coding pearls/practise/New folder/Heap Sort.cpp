#include<bits/stdc++.h>
using namespace std;
int n,heap[11],capacity=10;
int parent(int k)
{
	return k/2;
}
void siftup(int k)
{
	while(k>1 && heap[parent(k)]<heap[k])
	{
		swap(heap[parent(k)],heap[k]);
		k=parent(k);
	}
}
void display()
{
	for(int i=1;i<=n;i++)
	cout<<heap[i]<<" ";
	cout<<endl;
}
int getMax()
{
	return heap[1];
}
void ins(int num)
{
	if(n==capacity)
	{
		cout<<"Max Capacity reached "<<endl;
		return ;
	}
	heap[++n]=num;
	siftup(n);
}
void siftdown(int k)
{
	while(2*k<=n)
	{
		int j=2*k;
		if(j<n&&heap[j]<heap[j+1]) j++;
		if(heap[k]>heap[j]) break;
		swap(heap[k],heap[j]);
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
	int max=heap[1];
	swap(heap[1],heap[n--]);
	siftdown(1);
	return max;
	
}
void heapSort(int arr[], int n) 
{  
    for (int i = n / 2 - 1; i >= 0; i--) 
    heapify(arr, n, i); 
  	for (int i=n-1; i>=0; i--) 
    {  
        swap(arr[0], arr[i]);
        heapify(arr, i, 0); 
    }
} 
int main()
{
	int ch,num;
	while(1)
	{
		cout<<"1. Insert in heap"<<endl;
		cout<<"2. Get Max "<<endl;
		cout<<"3. Display "<<endl;
		cout<<"4. Extract Max"<<endl;
		cout<<"5. Increase key "<<endl;
		cout<<"6. Exit "<<endl;
		cout<<"Enter choice "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter Number "<<endl;
			cin>>num;
			ins(num);
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
			case 5:
				int index,value;
				cin>>index>>value;
				increaseKey(index,value);
				break;
				case 6:
				exit(0);
				break;
		}		
	}
	return 0;
}
