#include<iostream>
#include<conio.h>
#include<malloc.h>
using namespace std;
main()
{
	struct node{
		int info;
		struct node *f,*r;
	};
	cout<<"enter the number of nodes you want to have"<<endl;
	int n;
	cin>>n;
	typedef struct node ss;
	ss *start,*ptr,*p;
	start=(ss*)malloc(sizeof(ss));
	ptr=start;
	start->f=NULL;
	for(int i=1;i<=n;i++)
	{
		if(i<n)
		{
		
		cin>>ptr->info;
		p=ptr;
		ptr->r=(ss*)malloc(sizeof(ss));
		ptr=ptr->r;
		ptr->f=p;
	    }
	    else
	    {
	    	cin>>ptr->info;
	    	ptr->r=NULL;
		}
		
	}
	ptr=start;
	while(ptr!=NULL)
	{
		cout<<ptr->info<<" ";
		ptr=ptr->r;
	}
	ptr=start;
	while(ptr!=NULL)
	{
		p=ptr;
		ptr=ptr->r;
	}
	cout<<endl;
	
	while(p!=start)
	{
		cout<<p->info<<" ";
		p=p->f;
	}
	cout<<start->info;
}
