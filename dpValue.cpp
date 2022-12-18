#include<iostream>
using namespace std;

int Nmin(int a,int b);

class coin{
public:
    coin(int);
    void makeMat(int);
    void display();
    void showCoins();
private:
    int **mat;
    int *coins;
    int n,v;
};


int main(){
    int n;
    cout<<"How many coins do you have?:";cin>>n;
    coin mycoins(n);
    while(true){
        int v;
        cout<<"How much do you want?(or 0 to finish):";cin>>v;
        if(v==0) break;
        mycoins.makeMat(v);
        mycoins.display();
        mycoins.showCoins();
    }
    cout<<endl<<"byeeee!";
}

coin :: coin(int n1){
    n=n1;
    coins = new int [n];
    cout<<"Enter coins value:";
    for(int i=0;i<n;i++) cin>>coins[i];
}

void coin :: makeMat(int v1){
    v=v1;
    mat = new int * [n+1];
    for(int i=0;i<n+1;i++) mat[i]=new int [v+2];

    //delete
    for(int i=0;i<n+1;i++){
        for(int j=0;j<v+2;j++)
            mat[i][j]=9;
    }
    mat[0][0]=0;


    for(int i=1;i<v+2;i++) mat[0][i]=i-1; //fill first row
    for(int i=1;i<n+1;i++) mat[i][0]=coins[i-1]; //fill first column
    for(int i=1;i<v+2;i++){ //fill second row
        if(mat[0][i]%mat[1][0]==0){
            mat[1][i]=mat[0][i]/mat[1][0];
        }
        else mat[1][i]=0;
    }


    for(int i=2;i<n+1;i++){
        for(int j=1;j<v+2;j++){
            if(mat[0][j]<mat[i][0]){mat[i][j]=mat[i-1][j];}
            else if(mat[0][j]==mat[i][0]) {mat[i][j]=1;}
            else if(mat[0][j]>mat[i][0]){
                if(mat[i][j-mat[i][0]]!=0)
                    mat[i][j]=Nmin(mat[i][j-mat[i][0]]+1,mat[i-1][j]);
                else mat[i][j]=mat[i-1][j];

            }
        }
    }
}

void coin :: display(){
    mat[0][0]=0;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<v+2;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    cout<<"with minimum of "<<mat[n][v+1]<<" coins.";
    cout<<endl;
}

int Nmin(int a,int b){
    if(a==0 && b==0) return 0;
    if(a==0) return b;
    if(b==0) return a;
    if(a<b) return a;
    return b;
}

void coin :: showCoins(){
    int i=n,j=v+1,sum=0,counter=0;
    int *re = new int [mat[n][v+1]];
    while(sum!=v){
        if(mat[i][j]==mat[i-1][j]) i--;
        else{
            j-=mat[i][0];
            re[counter]=mat[i][0];
            counter++;
            sum+=mat[i][0];
        }
    }
    i=0;
    while(i!=mat[n][v+1]){
        j=0;
        while(re[i]==re[i+j]) j++;
        cout<<j<<" coins with value "<<re[i]<<endl;
        i+=j;
    }
}
