
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int N,heap[11],capacity=10;
int parent(int k)
{
    return k/2;
}

void shiftup(int k) {
    while (k > 1 && heap[parent(k)] < heap[k])
    {
        swap(heap[parent(k)], heap[k]);

    k=parent(k);}
}

void ins(int num)
{
    if(N== capacity)
    {
        cout<<"Max CAPACITY REACHED"<<endl;
        return;

    }
    heap[++N]=num;
    shiftup(N);
}

int getmax()
{
    return heap[1];
}
void shiftdown(int k){
    while(2*k<=N)
    {
        int j=2*k;
        if(j<N && heap[j]<heap[j+1])j++;
        if (heap[k]>heap[j])
        break;
        swap(heap[k],heap[j]);
        k=j;

    }
}


int extractMax()
{
    if(N<1)
    {
        cout<<"trying to extract from empty heap"<<endl;
        return -1;
    }
    int MAX=heap[1];
    swap(heap[1],heap[N--]);
    shiftdown(1);
    return MAX;
}

void display()
{
    for(int i=1;i<=N;i++)
       cout<<heap[i]<<" ";
    cout<<endl;
}

int main()

{

    //array limit 10
    int a[30];
while(1) {
    cout << "\t\t\t\t************ Enter Choice ************" << endl;
    cout << "1. For getting maximum  big(1)\n2. FOr extract max  log(n)\n3. insert log(n)\n4. Display big(n)" << endl;
    cout << "Enter NO" << endl;
    int ch, num;
    cin >> ch;

    switch (ch) {

        case 1:
            cout << "Max ELemt" << getmax()<<endl;
            break;
        case 2:
        
            extractMax();
            break;
        case 3:
            cout << "Enter number" << endl;
            cin >> num;
            ins(num);
            break;
        case 4:
            display();
            break;
            
        default:
            exit(0);
    }
}


}
