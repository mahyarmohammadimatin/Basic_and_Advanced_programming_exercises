#include <iostream>

using namespace std;

class knight_placer{
    public:
        knight_placer(int n1){
            n=n1;
        }

        void MakeEmpty(int **board){
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    board[i][j]=0; //0 means empty, 1 means knight , 2 means attacked.
        }

        void PlaceKnight(int k, int start1,int start2,int **board){
            if(k==0){
                counter++;
                showboard(board);
                cout<<endl;
            }
            else{
                for(int i=start1;i<n;i++){
                    for(int j=start2;j<n;j++){
                        if(board[i][j]==0){
                            int **secoundboard=new int *[n];
                            for(int q=0;q<n;q++){secoundboard[q]=new int [n];}
                            copyboard(secoundboard,board);
                            secoundboard[i][j]=1;
                            FillAttackedHouse(i,j,secoundboard);
                            PlaceKnight(k-1,i,j,secoundboard);
                            delete[] secoundboard;
                        }
                    }
                    start2=0;
                }
            }
        }
        void showcounter(){
            cout<<"it is "<<counter<<" ways";
        }

    private:
        int n;
        int counter=0;
        void showboard(int **mat){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                    if(mat[i][j]==1) cout<<"K"<<" ";
                    else cout<<"-"<<" ";
                cout<<endl;
            }
        }

        void copyboard(int **a,int **b){
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    a[i][j]=b[i][j];
        }

        void FillAttackedHouse(int i,int j,int **mat){
            if ((i + 2) < n && (j - 1) >= 0) mat[i + 2][j - 1] = 2;
            if ((i - 2) >= 0 && (j - 1) >= 0) mat[i - 2][j - 1] = 2;
            if ((i + 2) < n && (j + 1) < n) mat[i + 2][j + 1] = 2;
            if ((i - 2) >= 0 && (j + 1) < n) mat[i - 2][j + 1] = 2;
            if ((i + 1) < n && (j + 2) < n) mat[i + 1][j + 2] = 2;
            if ((i - 1) >= 0 && (j + 2) < n) mat[i - 1][j + 2] = 2;
            if ((i + 1) < n && (j - 2) >= 0) mat[i + 1][j - 2] = 2;
            if ((i - 1) >= 0 && (j - 2) >= 0) mat[i - 1][j - 2] = 2;
            }

};

int main()
{
    int n,**board;
    cout<<"enter n:";
    cin>>n;
    board=new int *[n];
    for(int i=0;i<n;i++){board[i]=new int [n];}
    knight_placer myboard(n);
    myboard.MakeEmpty(board);
    myboard.PlaceKnight(n,0,0,board);
    myboard.showcounter();
    return 0;
}
