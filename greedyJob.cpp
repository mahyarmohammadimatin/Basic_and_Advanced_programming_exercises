#include<iostream>
using namespace std;


class jobHandeler{
public:
    jobHandeler(int);
    void maxWork();
    void sorter(int **a);
    bool checkTime(int *,int *);
private:
    int n;
    int ** schedule;
};


int main(){
    int n;
    cout<<"How many jobs do you have?:";
    cin>>n;
    jobHandeler myjobs(n);
    myjobs.maxWork();
    return 0;
}

jobHandeler :: jobHandeler(int n1){
    n=n1;
    schedule = new int * [n];
    for(int i=0;i<n;i++){
        schedule[i]=new int [3];
        cout<<"Enter job "<<i+1<<" start and finish time:";
        cin>>schedule[i][0]>>schedule[i][1];
        schedule[i][2]=i+1;
    }
}

void jobHandeler :: maxWork(){
    sorter(schedule);
    int sum=0,c;
    cout<<"the jobs that should be done:"<<schedule[0][2];
    sum+=schedule[0][1]-schedule[0][0];
    for(int i=1;i<n;i++){
        c=0;
        for(int j=0;j<i;j++){
            if(checkTime(schedule[i],schedule[j])) c++;
        }
        if(c==i){
            cout<<" & "<<schedule[i][2];
            sum+=schedule[i][1]-schedule[i][0];
        }
    }
    cout<<endl<<"this get "<<sum<<" hours."<<endl;
}

bool jobHandeler :: checkTime(int *a,int *b){
    if(a[0]<b[0] && a[1]<b[0]) return true;
    if(b[0]<a[0] && b[1]<a[0]) return true;
    return false;
}


void jobHandeler :: sorter(int **a){
	int *q;
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++){
			if(a[j][1]-a[j][0]<a[j+1][1]-a[j+1][0]){
				q=a[j];
				a[j]=a[j+1];
				a[j+1]=q;
			}
		}
}
