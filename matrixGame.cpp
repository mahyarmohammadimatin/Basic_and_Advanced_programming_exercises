#include<iostream>
#include<string>
using namespace std;

int zero;
int** readtable(int **,int);
string inversion(int **,int);

int main(){
    int n;
    cout<<"Enter size of table:";
    cin>>n;
    int **table;
    table=readtable(table,n);
    if(n%2==1){
        if(inversion(table,n)=="even"){
            cout<<"it's solvable";
            return 0;
        }
    }
    else{
        if(zero%2==1 && inversion(table,n)=="even"){
            cout<<"it's solvable";
            return 0;
        }
        else if(zero%2==0 && inversion(table,n)=="odd"){
            cout<<"it's solvable";
            return 0;
        }
    }
    cout<<"it's not solvable";
    return 0;
}

int** readtable(int **table,int n){
    table = new int * [n];
    for(int i=0;i<n;i++)
        table[i]=new int [n];

    cout<<"Enter table from 1 to "<<n*n-1<<" and zero for empty house:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>table[i][j];
            if(table[i][j]==0) zero=i;
        }
    return table;
}

string inversion(int **table,int n){
    int a[n*n];
    int c=0,result=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[c]=table[i][j];
            c++;
        }
    }

    for(int i=0;i<n*n-1;i++){
        if(a[i]>a[i+1] && a[i]!=0 && a[i+1]!=0) result++;
    }
    if(result%2==0) return "even";
    return "odd";
}
