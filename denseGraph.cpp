#include<iostream>
using namespace std;

class dense{
public:
    dense(int);
    void subgraph();
    int ** display(int *);
    int vrtxC(int *);
    int edgeC(int *);
    int * unrank(int);
    int pow(int,int);
    void printgraph(int **g,int n1);
private:
    int n;
    int **G;
};

int main(){
    int n;
    cin>>n;
    dense mygraph(n);
    mygraph.subgraph();
    return 0;
}

dense :: dense(int n1){
    n=n1;
    int p,q;
    G = new int * [n];
    for(int i=0;i<n;i++){
        G[i] = new int [n];
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            G[i][j]=0;
    while(true){
        cout<<"Enter 2 connected vertex or -1 to finish:";
        cin>>p>>q;
        if(p==-1 || q==-1) break;
        G[p][q]=1;
        G[q][p]=1;
    }
    printgraph(G,n);
}

void dense :: subgraph(){
    for(int i=1;i<pow(2,n);i++){
        int *sub;
        sub=unrank(i);

        if(vrtxC(sub)>1)
        if((edgeC(sub)*2)/(vrtxC(sub)*(vrtxC(sub)-1))>0.75){
            display(sub);
        }
        delete [] sub;
    }
}

int ** dense :: display(int *a){
    cout<<"the vertex of sub graph that makes dense graph:";
    for(int i=0;i<n;i++){
        if(a[i]!=-1) cout<<a[i]<<" ";
    }
    cout<<endl;
}

int dense :: vrtxC(int *a){
    int c=0;
    for(int i=0;i<n;i++){
        if(a[i]!=-1) c++;
    }
    return c;
}

int dense :: edgeC(int *a){
    int c=0,sum=0;
    for(int i=0;i<n;i++){
        if(a[i]!=-1){
            for(int j=0;j<n;j++){
                if(G[a[i]][j]==1 && a[j]!=-1) c++;
            }
            sum+=c;
            c=0;
        }
    }
    return sum/2;
}

int * dense :: unrank(int m){ //return an array that have subset.
    int c=0;
    int *re=new int [n];
    for(int i=0;i<n;i++){
        re[i]=-1;
    }
    while(m!=0){
        if(m%2==1) re[c]=c;
        m=m/2;
        c+=1;
    }
    return re;
}

int dense :: pow(int a,int b){
    int re=1;
    for(int i=0;i<b;i++){
        re*=a;
    }
    return re;
}

void dense :: printgraph(int **g,int n1){
    for(int i=0;i<n1;i++){
        for(int j=0;j<n1;j++)
            cout<<g[i][j]<<" ";
        cout<<endl;
    }
}
