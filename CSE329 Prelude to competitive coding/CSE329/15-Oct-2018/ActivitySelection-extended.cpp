#include <bits/stdc++.h>
using namespace std;

struct Activity {
    char id[5];
    int start,end;
};

bool ActivityComparator(Activity a, Activity b) {
    return a.end < b.end;
}

void printActivities(Activity arr[], int n) {

    sort(arr,arr+n,ActivityComparator);

    int i=0;
    cout<<arr[i].id<<"("<<arr[i].start<<","<<arr[i].end<<")\n";

    for(int j = 1; j<n; j++) {
        if(arr[j].start >= arr[i].end) {
            cout<<arr[j].id<<"("<<arr[j].start<<","<<arr[j].end<<")\n";
            i=j;
        }
    }
}

int main()
{
    Activity arr[] = { {"a1",0,2}, {"a2",10,25}, {"a3",15,30}, {"a4",30, 35} };
    int n = sizeof(arr) / sizeof(arr[0]);

    printActivities(arr,n);
    return 0;
}