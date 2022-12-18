#include<iostream>
using namespace std;

class maxsub{
public:
    maxsub(int,int,int);
    int pow(int,int);
    int * unrank(int,int);
    bool checksub(string,char *,int);
    string LCS();
private:
    char *a;
    char *b;
    char *c;
    int n1,n2,n3;
};

int main(){
    int n1,n2,n3;
    cout<<"Enter the length of strings:";
    cin>>n1>>n2>>n3;
    maxsub obj(n1,n2,n3);
    cout<<obj.LCS();
    return 0;
}
maxsub :: maxsub(int p,int q,int r){
    n1=p;
    n2=q;
    n3=r;
    a=new char [n1];
    b=new char [n2];
    c=new char [n3];
    cout<<"Enter first sentence:";
    for(int i=0;i<n1;i++) cin>>a[i];
    cout<<"Enter second sentence:";
    for(int i=0;i<n2;i++) cin>>b[i];
    cout<<"Enter third sentence:";
    for(int i=0;i<n3;i++) cin>>c[i];
}

string maxsub :: LCS(){
    int *sub;
    int maximum=0;
    string s,re;
    for(int i=1;i<pow(2,n1);i++){
        s="";
        sub=unrank(i,n1);
        for(int j=0;j<n1;j++)
            if(sub[j]!=-1){
                s+=a[sub[j]];
            }
        if(checksub(s,b,n2) && checksub(s,c,n3) && s.size()>maximum){
            maximum=s.size();
            re=s;
        }
        delete [] sub;
    }
    return re;
}

bool maxsub :: checksub(string target,char * s,int n){
    int c=0;
    for(int i=0;i<n;i++){
        if(s[i]==target[c]) c++;
        if(c==target.size()) break;
    }
    if(c==target.size()) return true;
    return false;
}

int * maxsub :: unrank(int m,int n){
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

int maxsub :: pow(int a,int b){
    int re=1;
    for(int i=0;i<b;i++){
        re*=a;
    }
    return re;
}
