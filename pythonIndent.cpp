#include<iostream>
#include<string>
using namespace std;

int main(){
	string s,re;
	int p=1,i=0;
	getline(cin,s);
	while(i<s.size()){
		if(s[i]=='"') p*=-1; //check if we are in string or not
		if(s[i]==" "[0] && p==1) re+="\n";
		else if(s[i]=="$"[0]) re+="\t";
		else if(s.substr(i,6)=="while "){
			while(s[i]!=":"[0]){
				re+=s[i];
				i-=-1;
			}
			re+=":";
		}
		else if(s.substr(i,5)=="print"){
			re+="print";
			i+=5;
			while(s[i]==" "[0]){
				re+=s[i];
				i-=-1;
			}
		}
		else if(s.substr(i,4)=="for "){
			while(s[i]!=":"[0]){
				re+=s[i];
				i-=-1;
			}
			re+=":";
		}
		else if(s.substr(i,4)=="def "){
			while(s[i]!=":"[0]){
				re+=s[i];
				i-=-1;
			}
			re+=":";
		}
		else if(s.substr(i,3)=="if "){
			while(s[i]!=":"[0]){
				re+=s[i];
				i-=-1;
			}
			re+=":";
		}
		else if(s.substr(i,7)=="return " || s.substr(i,7)=="return("){
			re+="return ";
			i+=7;
			while(s[i]!=" "[0] && i<s.size()){
				re+=s[i];
				i-=-1;
			}
			re+="\n";
		}
		else re+=s[i];
		i-=-1;
	}
	cout<<re<<endl;
	return 0;
}
