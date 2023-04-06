

/*

Extract Unique characters
Send Feedback
Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.
Input format:
The first and only line of input contains a string, that denotes the value of S.
Output format :
The first and only line of output contains the updated string, as described in the task.
Constraints :
0 <= Length of S <= 10^8
Time Limit: 1 sec
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde
*/



#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define f(i,s,e) for(int i=s; i<e; i++)
#define int long long
#define vi vector<int>
#define umii unordered_map<int,int>
#define umci unordered_map<char,int>
#define endl '\n'

string uniquechar(string str){
    string result="";
    umci h;
    for(int i=0; i<str.length(); i++){
       if(h.count(str[i])==0){
        result+=str[i];
        h[str[i]]=1;
       }
       
    }
    return result;

}

int32_t main(){
    
    string str;
    cin>>str;
    cout<<uniquechar(str);
    endl;
    return 0;
}