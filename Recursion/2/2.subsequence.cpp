#include<iostream>
#include<string>
using namespace std;

int subsequence(string input,string output[]){
    // Base case
    if(input.empty()){
        output[0]="";
        return 1;
    }
    string smallstring=input.substr(1);
    int smalloutputsize=subsequence(smallstring,output);
    for(int i=0; i<smalloutputsize; i++){
        output[i+smalloutputsize]=input[0]+output[i];
    }
    return 2*smalloutputsize;
}

int main(){
    string input; cin>>input;
    string *output=new string[10000];
    int count=subsequence(input,output);
    for(int i=0; i<count; i++){
        cout<<output[i]<<endl;
    }
    return 0;
}