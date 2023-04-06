#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
// question-1
/*
int main(){
    string str; cin>>str;
    // convert into uppercase just -32
    for(int i=0; i<str.size(); i++){
        if(str[i] >='a' and str[i] <='z') str[i] -=32;
    }
    cout<<"UPPER-CASE "<<str<<endl;
    // lowercase just add 32
    for(int i=0; i<str.size(); i++){
        if(str[i] >='A' and str[i]<='Z') str[i] +=32;
    }
    cout<<"LOWER-CASE "<<str<<endl;
    // inbuilt function to convert into lower and uppercase
    cout<<endl;
    transform(str.begin(),str.end(),str.begin(),::toupper);
    cout<<"Upper "<<str<<endl;
    // lower case
    transform(str.begin(),str.end(),str.begin(),::tolower);
    cout<<"Lower "<<str<<endl;
    return 0;
}
*/

// ques-2
// greatest no from the given string
int main(){
    string str; cin>>str;
    sort(str.begin(),str.end(),greater<int>());
    cout<<str<<endl;
    sort(str.begin(),str.end(),greater<char>());
    cout<<str<<endl;
    return 0;
}