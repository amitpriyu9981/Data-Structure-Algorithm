#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void printsub(string input,string output){
    // Base case
    if(input.length()==0){
        cout<<output<<endl;
        return;
    }
    // case-1 , do not include the first char in the output
    printsub(input.substr(1),output);
    // case-2 include the first char in the output
    printsub(input.substr(1),output+input[0]);
}
int main(){
    string input; cin>>input;
    string output="";
    printsub(input,output);
    cout<<endl;
}