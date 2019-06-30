// join rope problem
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*int main()
{
    int n,i,j;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int result=0;
    for(i=0;i<n;i++)
    {
        a[i+1]=a[i]+a[i+1];
        a[i]=0;
        result+=a[i+1];
        sort(a+i+1,a+n);
    }
    cout<<result<<endl;
    return 0;
}
*/
/*
int join_ropes(int a[],int n)
{
    int total=0;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        v.push_back(a[i]);
    }
    while(v.size()>1)
    {
        sort(v.begin(),v.end());
        total+=v[0]+v[1];
        v.push_back(v[0]+v[1]);
        v.erase(v.begin(),v.begin()+2);
    }
    return total;

}
int main()
{


    int a[]={2,5,4,6};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<join_ropes(a,n);
}*/

/*
*/
int naive_search(string t,string p)
{
    int total=0;
    for(int i=0;i<=t.size()-p.size();i++)
    {
    	//cout<<"fcv1";
        int j=0;
        for(;j<p.size();j++)
        { cout<<t[i+j]<<endl;
            if(t[i+j]!=p[j])
                break;
            if(j==p.size())
            {//	cout<<"fcv";
                cout<<"INDEX : "<<i;
                total++;
            }
        }
    }
    return total;
}
int main()
{
    string t="AXABXBABA", p="AXAB";
    int r=t.size();
   // cout<<r;
    cout<<endl<<naive_search(t,p);
    //cout<<"cv";
    return 0;
}
