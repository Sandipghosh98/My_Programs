#include<bits/stdc++.h>
using namespace std;
int search(int x,int in[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(in[i]==x)
		{
			return i;
		}
	}
	return -1;
}
void postorder(int pre[],int in[],int n)
{
	int root=search(pre[0],in,n);
	if(root!=0)
	{
		postorder(pre+1,in,root);
	}
	if(root!=n-1)
	{
		postorder(pre+root+1,in+root+1,n-root-1);
	}
	cout<<pre[0]<<" ";
}
int main()
{
	int pre[]={1,2,4,3,5,6};
	int in[]={4,2,1,5,3,6};
	//post-> 4 2 5 6 3 1
	postorder(pre,in,6);
}
