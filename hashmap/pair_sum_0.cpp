// problem statement
/*
Code : Pair Sum to 0
Send Feedback
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output format :
The first and only line of output contains the count of pair of elements in the array which sum up to 0. 
Constraints :
0 <= N <= 10^4
Time Limit: 1 sec
Sample Input 1:
5
2 1 -2 2 3
Sample Output 1:
2

*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define f(i,s,e) for(int i=s; i<e; i++)
#define int long long
#define vi vector<int>
#define umii unordered_map<int,int>
#define endl '\n'

int getpairsum(vi a,int n){
    umii sum;
    int count=0;
    f(i,0,n){
        int complement=-a[i];
        if(sum.find(complement) != sum.end()){
           count +=sum[complement];
        }
        sum[a[i]]++;
    }
    return count;
}

int32_t main(){

    int n; cin>>n; vi a(n);
    f(i,0,n) cin>> a[i];
    int ans=getpairsum(a,n);
    cout<<ans;
    endl;
    return 0;
}