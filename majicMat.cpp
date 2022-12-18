#include<iostream>
using namespace std;

class MagicMat{
    public:
        MagicMat(int n1){
            n=n1;
            mat=new int * [n];
            for(int i=0;i<n;i++)
                mat[i]=new int [n];
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++){
                    mat[i][j]=0;
                }
        }
        void create(){
            int i=n/2 , j=n-1;
            for(int number=1;number<=n*n;number++){

                if(i<0 && j==n){
                    i=0;
                    j=n-2;
                }
                if (i<0) i=n-1;
                if (j==n) j=0;

                if(mat[i][j]!=0) {i+=1;j-=2;}
                mat[i][j]=number;
                i-=1;
                j+=1;
            }
        }
        void print(){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                    cout<<mat[i][j]<<" ";
                cout<<endl;
            }
        }
    private:
        int n;
        int **mat;
};

int main(){
    int n;
    cout<<"enter length of matrix:";
    cin>>n;
    MagicMat mymat(n);
    mymat.create();
    mymat.print();

    return 0;
}
