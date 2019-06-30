#include<bits/stdc++.h>
using namespace std;
//prism algo


int main(){
	
	int n;
	cin>>n;
	int e;
	cin>>e;
	int g[n][n];
	
	int d[n][n];
		for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)
				d[i][j]=0;
			else
				d[i][j]=1000;		
		}
		
	}
	cout<<"enter the source, destination and weight"<<endl;
	int x,y,z;
		for(int j=0;j<e;j++){
			cin>>x;
			cin>>y;
			cin>>z;
			g[x][y]=z;
			d[x][y]=z;
		}
		cout<<"before"<<endl;
	for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<d[i][j]<<" ";
			}
			cout<<endl;
			}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				
				if(d[i][j] > d[i][k]+d[k][j])
					d[i][j]= d[i][k]+d[k][j];
			}
		}
	}
		cout<<"after"<<endl;
	for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<d[i][j]<<" ";
			}
			cout<<endl;
			}
	for(int i=0;i<n;i++){
		cout<<"0-> "<<i<<"  "<<d[0][i]<<endl;
	}
/*	0 1 2
	0 2 3
	2 1 -2
	2 3 3
	*/
}
