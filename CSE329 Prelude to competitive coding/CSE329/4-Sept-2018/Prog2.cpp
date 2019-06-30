#include<iostream>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,q;
    cin>>n>>q;
    int **a = new int*[n];
    int *x = new int[q];
    int *y = new int[q];
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        int *b = new int(k);
        for(int j=0;j<k;j++){
            cin>>b[j];
        }
        a[i]=b;
    }
    for(int i=0;i<q;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=0;i<q;i++){
        cout<<a[x[i]][y[i]]<<endl;
    }
    return 0;
}