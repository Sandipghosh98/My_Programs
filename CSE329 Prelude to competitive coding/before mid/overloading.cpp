#include<iostream>
using namespace std;
class a{
	public:
	void area(int a){
		cout<<"the area of a square"<<endl;
		cout<<a*a<<endl;
	}
	void area(int a,int b){
		cout<<"the area of a rectangle"<<endl;
		cout<<a*b<<endl;
	}
	void area(double r){
			cout<<"the area of a circle"<<endl;
			
			float v=3.142*r*r;
			cout<<v<<endl;
	}
	void area(int a,double b){
		cout<<"the area of a triangle"<<endl;
		float v=1/2*a*b;
		cout<<v<<endl;
	}	
	
	
};

int main()
{
	a ob;
	ob.area(5);
	ob.area(5,6);
	ob.area(3.6);
	ob.area(3,3.6);
//	cout<<b;
	
}
