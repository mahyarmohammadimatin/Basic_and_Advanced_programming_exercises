#include<iostream>
using namespace std;

int find(int l[],int n,int target); //this function take an element and array and return index


int main(){
	int n,m; //matrix is n*m
	int p,c; //just to cin

	cout<<"enter row and column splited with 1 space:";
	cin>>n>>m;

	int G[n][m]={0};

	//let's get our matrix
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>p;
			G[i][j]=p;
		}

	//you can choose sort mode
	cout<<"Enter 0 to sort by column or 1 to sort all matrix:";
	cin>>p;

	//now we get column
	cout<<"Enter your column:";
	cin>>c;


	int M1[n]; // this save our column
	int M2[n]; //this is M1 when it's sorted
	for(int i=0;i<n;i++)
		M1[i]=G[i][c]; 


	//sort
	int t,flag;
	for(int i=0;i<n;i++) M2[i]=M1[i]; //this for copy M1 to M2
	while(true){
		for(int i=0;i<n;i++)
			if(M2[i]>M2[i+1]){
				flag=1;
				t=M2[i];
				M2[i]=M2[i+1];
				M2[i+1]=t;
			}
		if(flag==0) break;
		flag=0;
	}



	if(p==0){ //case 0
		for(int i=0;i<n;i++)
			G[i][c]=M2[i];	
	}


	else{  //case 1
		int G2[n][m]={0}; //this is our result
		int M3[n]; //this holds sorted index
		for(int i=0;i<n;i++)
			M3[i]=find(M1,n,M2[i]);

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			G2[i][j]=G[M3[i]][j];

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				G[i][j]=G2[i][j];
	}
	
	//let's print our matrix
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<G[i][j]<<" ";
		cout<<endl;
	}
}


int find(int l[],int n,int target){ //this function take an element and array and return index
	for(int i=0;i<n;i++)
		if(l[i]==target) return i;
	return -1;
}
