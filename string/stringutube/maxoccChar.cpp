#include<iostream>
#include<string>
using namespace std;

int main(){
    string str; cin>>str;
    int freq[26];
    for(int i=0; i<26; i++) freq[i]=0;
    for(int i=0; i<str.size(); i++){
        freq[str[i]-'a']++;
    }
    int maxfreq=0;
    char output='a';
    for(int i=0; i<26; i++){
        if(freq[i]>maxfreq){
            maxfreq=freq[i];
            output=i+'a';
        }
    }
    cout<<output<<endl;
}