#include<bits/stdc++.h>
using namespace std;
// Job sequencing problem
/*struct Job{
    int id,li,ti;
};
bool cmp(Job a,Job b){
    return a.li * b.ti > b.li * a.ti;

}
void opt_seq(Job arr[],int n)
{

    for(int i=0;i<n;i++)
        cout<<arr[i].id<<" ";
}
int main()
{

    Job arr[]={{1,2,4},{2,3,1000},{3,4,2},{4,1,5}};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n,cmp);
    opt_seq(arr,n);
}*/
// Job selection problem
double max_vol(int a[],int n,int p)
{
    double ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=pow((1-p),n-1-i)*a[i];
        cout<<a[i]<<"  ";
        cout<<ans<<endl;
    }
    return ans;
}
int main()
{

    int s[]={70,80,10,20};
    int n=sizeof(s)/sizeof(s[0]);
    sort(s,s+n);
    double p=0.10;
    cout<<max_vol(s,n,p);
}


