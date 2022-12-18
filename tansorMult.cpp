#include<iostream>
using namespace std;


int main(){
	int p;	
	
	int m1,n1;
	cout<<"Enter first matrix's row and column splited with 1 space:";
	cin>>n1>>m1;
	int M1[n1][m1];
	for(int i=0;i<n1;i++)
		for(int j=0;j<m1;j++){
			cin>>p;
			M1[i][j]=p;
		}
	
	int m2,n2;
	cout<<"Enter secound matrix's row and column splited with 1 space:";
	cin>>n2>>m2;
	int M2[n2][m2];
	for(int i=0;i<n2;i++)
		for(int j=0;j<m2;j++){
			cin>>p;
			M2[i][j]=p;
		}
	
	int result[n1*n2][m1*m2];
	
	for(int i=0;i<n1;i++)
		for(int j=0;j<m1;j++)
			for(int p=0;p<n2;p++)
				for(int q=0;q<m2;q++)
					result[2*i+p][2*j+q]=M1[i][j]*M2[p][q];
	for(int i=0;i<n2*n1;i++){
		for(int j=0;j<m2*m1;j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
}
