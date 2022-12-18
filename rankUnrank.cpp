#include <iostream>

using namespace std;

class Rank{
public:
        Rank(int *a,int n1){
            n=n1;
            subset=a;
        }
        int GiveMeRank(){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=power(2,subset[i]-1);
            }
            return sum;
        }
private:
    int power(int a,int b){
        int result=1;
        for(int i=0;i<b;i++){result*=a;}
        return result;
    }
    int *subset;
    int n;
};

class UnRank{
public:
        UnRank(int *a,int n1){
            n=n1;
            subset=a;
        }
        void UnRanker(){
            int i=0;
            while(n!=0){
                if(n%2==1) cout<<subset[i]<<" ";
                i+=1;
                n=n/2;
            }
        }
private:
    int *subset;
    int n;
};

int main()
{
    int n,status;
    cout<<"enter the length of set:";
    cin>>n;
    cout<<"enter 1 to rank or 0 to unrank:";
    cin>>status;
    if(status==1){
            int *a,sublen;
            cout<<"enter the length of subset:";
            cin>>sublen;
            a=new int [sublen];
            cout<<"enter your subset:";
            for(int i=0;i<sublen;i++){cin>>a[i];}
            Rank myrank(a,sublen);
            cout<<"your rank is:"<<myrank.GiveMeRank();
    }
    else{
        int *a,number;
        cout<<"enter your rank:";
        cin>>number;
        a=new int [n];
        for(int i=0;i<n;i++){a[i]=i+1;}
        UnRank mysubset(a,number);
        mysubset.UnRanker();
    }

    return 0;
}
