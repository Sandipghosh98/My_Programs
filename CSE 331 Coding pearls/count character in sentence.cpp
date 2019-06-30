#include <bits/stdc++.h>
using namespace std;
 main(){
	string s;
	getline(cin,s);
	char a[26];
	char b[26];
	int c[26];
	int u=0;
	for(int i=97;i<124;i++){
		a[u]=(char)i;
		b[u]=(char)(i-32);
		c[u]=0;
		u++;
	}
	for(int i=0;i<s.length();i++){
		for(int j=0;j<26;j++){
		
		if(s[i]==a[j]||s[i]==b[j]){
			c[j]=c[j]+1;
			
		}
	}
	}
	int index=0,max=0;
	for(int i=0;i<26;i++){
		if(c[i]>max){
			max=c[i];
			index=i;
		}
	}	
	cout<<a[index];
	
}
