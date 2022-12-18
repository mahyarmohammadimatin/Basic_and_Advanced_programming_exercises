#include<iostream>
using namespace std;

class elevator{
public:
    elevator(int,int);
    void bestValue();
    void resultViewer();
private:
    int **mat;
    int n,w;
};

int main(){
    int n,w;
    cout<<"How many person do you have?:";
    cin>>n;
    cout<<"what is the elevator's maximum tolerable weight?:";
    cin>>w;
    elevator myTeam(n,w);
    myTeam.bestValue();
    return 0;
}

elevator :: elevator(int n1,int w1){
    n=n1;
    w=w1;
    mat = new int * [n+1];
    for(int i=0;i<n+1;i++){
        mat[i] = new int [w+3];
    }
    mat[0][0]=0;
    mat[0][1]=0;
    for(int i=2;i<w+3;i++) mat[0][i]=i-2;
    for(int i=1;i<n+1;i++){
        cout<<"Enter person"<<i<<"'s value and weight:";
        cin>>mat[i][0]>>mat[i][1];
        mat[i][2]=0;
    }
}

void elevator :: bestValue(){
    for(int i=3;i<w+3;i++){ //fill second row.
        if(mat[0][i]>=mat[1][1])mat[1][i]=mat[1][1];
        else mat[1][i]=0;
    }
    for(int i=2;i<n+1;i++){
        for(int j=3;j<w+3;j++){
            if(mat[i][1]>mat[0][j]) mat[i][j]=mat[i-1][j];
            else mat[i][j]=max(mat[i-1][j],mat[i][0]+mat[i-1][j-mat[i][1]]);
        }
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+3;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    resultViewer();
}

void elevator :: resultViewer(){
    int i=n,j=w+2;
    cout<<"The biggest possible value is:"<<mat[i][j];
    cout<<endl<<"persons ";
    while(j!=2){
        if(mat[i-1][j]==mat[i][j]) i--;
        else{
            cout<<i<<",";
            j=j-mat[i][1];
            i--;
        }
    }
    cout<<"can go on elevator!"<<endl;
}
