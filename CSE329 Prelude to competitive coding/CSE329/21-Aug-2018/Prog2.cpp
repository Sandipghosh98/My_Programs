// 2 Stacks in a single Array.

#include<iostream>
using namespace std;

int main()
{
    int a[10],top1=0,top2=9,opt;
    bool run=true;

while(run) {
    cout<<"\n1. Push in Stack1\n2.Push in Stack2\n3.Pop in Stack1\n4.Pop in Stack2\n5.Peek Stack1\n6.Peek Stack2\n7.Exit\n";
    cin>>opt;

    switch(opt) {
        case 1 :    if(top1+1<top2) {
                        cout<<"\nEnter Data : ";
                        top1++;
                        cin>>a[top1];
                    }
                    else {
                        cout<<"\nStack1 Overflow";
                    }
                    break;

        case 2 :    if(top2-1>top1) {
                        cout<<"\nEnter Data : ";
                        top2--;
                        cin>>a[top2];
                    }
                    else {
                        cout<<"\nStack2 Overflow";
                    }
                    break;

        case 3 :    if(top1>0) {
                        top1--;
                    }
                    else {
                        cout<<"\nStack1 Underflow.";
                    }
                    break;

        case 4 :    if(top2<9) {
                        top2++;
                    }
                    else {
                        cout<<"\nStack2 Underflow.";
                    }
                    break;

        case 5 :    if(top1>0) {
                        cout<<a[top1]<<"\n";
                    }
                    break;
        case 6 :    if(top2<9) {
                        cout<<a[top2]<<"\n";
                    }
                    break;
        case 7 :    run = false;
                    break;

        default :   cout<<"\nEnter Correct Option\n";
                    break;
    }
}   // While Loop Ends.
}