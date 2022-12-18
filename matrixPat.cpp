#include<iostream>
using namespace std;

int main(){
	//--------cin first matrix---------
	int m1,n1;
	cout<<"Enter your first matrix column and row:";
	cin>>m1>>n1;

	char * * mat1,c;
	mat1 = new char * [m1];

	for(int i=0;i<m1;i++)
		mat1[i] = new char [n1];

	for(int i=0;i<m1;i++)
		for(int j=0;j<n1;j++){
			cin>>c;
			mat1[i][j]=c;
		}
			
	//-------cin secound matrix--------
	int m2,n2;
	cout<<"Enter your secound matrix column and row:";
	cin>>m2>>n2;

	char * * mat2;
	mat2 = new char * [m2];

	for(int i=0;i<m2;i++)
		mat2[i] = new char [n2];

	for(int i=0;i<m2;i++)
		for(int j=0;j<n2;j++){
			cin>>c;
			mat2[i][j]=c;
		}

	
	int flag=1;
	for(int i=0;i<=m2-m1;i++)
		for(int j=0;j<=n2-n1;j++){
			for(int p=0;p<m1;p++)
				for(int q=0;q<n1;q++)
					if(mat1[p][q]!=mat2[p+i][q+j]) flag=0;
			if(flag==1){cout<<"yes"<<endl; return 0;}
			flag=1;
		}
	cout<<"no"<<endl;
	return 0;
}
