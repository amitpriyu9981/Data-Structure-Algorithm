
// problem statement
/*

Code : Maximum Frequency Number
You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains most frequent element in the given array.
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2
Sample Input 2 :
3
1 4 5
Sample Output 2 :
1

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define f(i,s,e) for(int i=s; i<e; i++)


int getmaxfreqelement(vector<int> a,int n){
    unordered_map<int,int> freq;
    int maxfreq=0;
    for(int i=0; i<a.size(); i++){
        freq[a[i]]++;
        maxfreq=max(maxfreq,freq[a[i]]);
    }
    int maxfreqelement;
    for(int i=0; i<a.size(); i++){
        if(freq[a[i]]==maxfreq){
            maxfreqelement=a[i];
            break;
        }
    }
    return maxfreqelement;
}



int main(){
    int n; cin>>n; vector<int> a(n);
    f(i,0,n) cin>>a[i];

    int ans=getmaxfreqelement(a,n);
    cout<<ans<<"\n";


    return 0;
}