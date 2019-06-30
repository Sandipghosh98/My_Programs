#include<bits/stdc++.h>
using namespace std;
/*
Job  End-time Profit
J1      3      16
J2      1       4
J3      3       3
J4      1       2
*/

struct Job
{
    int id,etime,profit;
};
bool cmp(Job a,Job b)
{
    return a.profit>b.profit;
}
void seqence(Job a[],int n)
{
    int slot[n],seq[n];
    for(int i=0;i<n;i++)
        slot[i]=false;
    for(int i=0;i<n;i++)
    {
        for(int j=a[i].etime-1;j>=0;j--)
        {
            if(slot[j]==false)
            {
                slot[j]=true;
                seq[j]=i;
                break;
            }
        }
    }
    cout<<"Job sequence to get maximum profit"<<endl;
    for(int i=0;i<n;i++)
    {
        if(slot[i])
            cout<<a[seq[i]].id<<" ";
    }

}
int main()
{
    Job arr[]={{1,3,16},{2,1,4},{3,3,3},{4,1,2}};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n,cmp);
    seqence(arr,n);
    return 0;
}
//Job selection problem using time shedueling
/*
struct Job
{
    int id,start,finish;
};
bool cmp(Job a,Job b)
{
    return a.finish<b.finish;
}
void max_jobs(Job arr[],int n)
{
    int res=1,j=0;
    cout<<arr[0].id<<" ";
    for(int i=1;i<n;i++)
    {
        if(arr[i].start>=arr[j].finish){
            cout<<arr[i].id<<" ";
            res++;
            j=i;
        }
    }
    cout<<endl<<res;
}
int main()
{
    Job arr[]={{1,0,10},{2,10,20},{3,15,30},{4,30,35}};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n,cmp);
  //  cout<<"sandip"<<arr<<"fg123"<<endl;
  cout<<"sandip";
    for(int x=0;x<4;x++)
    cout<<arr[x].id<<"   "<<arr[x].start<<"   "<<arr[x].finish<<endl;
    cout<<"sudip";
    max_jobs(arr,n);
    return 0;
}
*/
// fractional knapack problem
/*
struct Job
{
    int value,weight;
};
bool cmp(Job a,Job b){return a.value*b.weight>b.value*a.weight; }
double max_value(Job arr[],int n,int w){
    double total=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i].weight<=w){
            w=w-arr[i].weight;
            total+=arr[i].value;
        }
        else if(w>0)
        {
            total+=((double)arr[i].value/arr[i].weight)*w;
            w=0;
        }
    }
    return total;
}

int main()
{
    Job arr[]={{100,10},{50,20},{120,30}};
    int n=sizeof(arr)/sizeof(arr[0]);
    int w=50;
    cout<<max_value(arr,n,w);
}
*/
