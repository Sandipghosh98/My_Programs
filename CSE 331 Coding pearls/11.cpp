#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;



/*

struct Node 
{ 
    int data; 
    Node* left, * right; 
}; 
  

Node* newNode(int data) 
{ 
    Node* node = (Node*)malloc(sizeof(Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
  

Node* insertLevelOrder(int arr[], Node* root, 
                       int i, int n) 
{ 
     
    if (i < n) 
    { 
        Node* temp = newNode(arr[i]); 
        root = temp; 
  
       
        root->left = insertLevelOrder(arr, 
                   root->left, 2 * i + 1, n); 
  
       
        root->right = insertLevelOrder(arr, 
                  root->right, 2 * i + 2, n); 
    } 
    return root; 
} 
 void labelorder(Node *ro){
    queue <Node *> qe;
    if(ro==NULL)
        return;
        qe.push(ro);
        while(!qe.empty()){
            
            Node *temp= qe.front();
            qe.pop();
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
        qe.push(temp->left); 

        if(temp->right!=NULL)
        qe.push(temp->right);
        }}
        
        */
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long ar[1000];
    long n;
    cin>>n;
    long count=0;
    queue<int>qe;
    for(long i=0;i<n;i++){
        count++;
        cin>>ar[i];
        qe.push(ar[i]);
    }
    long q=1;
    long d=0,e=0,c=0;
    for(int c=0;c<count;){
      
        while(d<pow(2,e)){
            if(d>n-1){
            break;
        }
                if(q%2==0){
            cout<<ar[c]<<" ";
            c++;
            d++;
        }
            else{
                int p=pow(2,e)+c;
               // cout<<p;
                int a=c;
             
                for(int y=p;y>a;y--){
            cout<<ar[c]<<" ";
            c++;
            d++;
                }
                
                
            }
    
            }
        
            e++;
       q++;
    
    
    }
    int w1=log(7)/log(2);
    cout<<w1;
    return 0;
}
