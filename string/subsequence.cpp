#include<iostream>

using namespace std;
#define endl cout<<"\n"
#define int long long

int sub(string s,string output[]){
    if(s.empty()){
        output[0]="";
        return 1;
    }
    string smallstring=s.substr(1);
    int smalloutputsize=sub(smallstring,output);
    for(int i=0; i<smalloutputsize; i++){
        output[i+smalloutputsize]=s[0]+output[i];
    }
    return 2*smalloutputsize;
}
int32_t main(){

    string s; cin>>s;
    // string output[10000];
    string *output=new string[10000];
    int size=sub(s,output);
    for(int i=0; i<size; i++){
        cout<<output[i]<<" ";
    }
    endl;
    return 0;
}