#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long
void notdividing(){
	int n; cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
		if(arr[i]==1 and arr[i]<2) arr[i]++;
	}
	// iterate over all the element and a+1 % a
	for(int i=0; i<n-1; i++){
		if(arr[i+1]%arr[i]) continue;
		else arr[i+1]++;
	}
	// print 
	for(int i=0; i<arr.size(); i++){
		cout<<arr[i]<<" ";
	}cout<<"\n";
}
int32_t main(){

    int t; cin>>t;
	for(int i=1; i<=t; i++){
		notdividing();
	}
	return 0;
}
// // our palindrome function
// bool palindrome(string str){
// 	// finding the length of the string
// 	int len=str.length();
// 	for(int i=0; i<len/2; i++){
// 		if(str[i] != str[len-1-i]) return false;
// 	}
// 	return true;
// }
// void prefixandsuffixarray(){
// 	int n; cin>>n;
// 	vector<string> output; string str;
// 	for(int i=0; i<2*n-2; i++){
// 		// take string input
// 		cin>>str;
// 		// check if length is n-1 push into the string vector output
// 		if(str.length()==n-1) output.push_back(str);
// 	}
// 	if(n==2){
// 		if(output[0]==output[1]) cout<<"YES"<<endl;
// 		else cout<<"NO"<<endl;
// 		return;
// 	}
// 	// case -3 if n is 3
// 	if(n==3){
// 		string output1="";
// 		if(output[0][1]==output[1][0]){
// 			output1=output[0]+output[1].back(); // update
// 		}else{
// 			// rev update the output1
// 			output1=output[1]+output[0].back();
// 		}
// 		if(palindrome(output1)) cout<<"YES"<<endl;
// 		else cout<<"NO"<<endl;
// 		return;
// 	}
// 	// use substr concept
// 	string s1=output[0].substr(1);
// 	string s2=output[1].substr(0,n-2);
// 	string ans="";
// 	if(s1==s2) ans=output[0]+output[1].back();
// 	else ans=output[1]+output[0].back();
// 	if(palindrome(ans)){
// 		cout<<"YES"<<endl;
// 		return;
// 	}
// 	else cout<<"NO"<<endl;

// }
// int32_t main(){

//     int t; cin>>t;
// 	for(int i=1; i<=t; i++){
// 		prefixandsuffixarray();
// 	}
// 	return 0;
// }