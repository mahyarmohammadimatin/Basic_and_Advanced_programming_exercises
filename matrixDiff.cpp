#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void maxmat(int **mat,int m,int n);

int main(){
	srand(time(0));
	int m,n;
	cout<<"Enter row and column splited with a space:";
	cin>>m>>n;

	//--------make empty matrix------------------------
	int * * mat;
	mat = new int * [m];
	for(int i=0;i<m;i++)
		mat[i] = new int [n];

	//--------fill matrix with random numbers--------------
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			if(rand()%2==1) mat[i][j] = rand()%100;
			else mat[i][j] = -1 * (rand()%100);
		}

	//--------print matrix--------------------------
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	
	//-------run our function-------------------------
	maxmat(mat,m,n);
	
	return 0;
}


void maxmat(int **mat,int m,int n){
	int sum=0,max=-1,flag=1;
	int column,row,re; //we save result in this variables.
	for(int c=1;c<=min(m,n);c++) //this is length of submatrix.
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++){
				for(int p=i;p<i+c;p++)
					for(int q=j;q<j+c;q++){
						if(p>=m || q>=n){
							flag=0;
							break;
						}
						sum+=mat[p][q];
					}
				if(sum>max && flag==1){
					max=sum;
					column=i;
					row=j;
					re=c;
				}
				sum=0;
				flag=1;
			}

	cout<<"the max number is:"<<max<<"\n\n";
	cout<<"this is your sub matrix:"<<endl;
	for(int i=column;i<column+re;i++){
		for(int j=row;j<row+re;j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
