// problem statement
//Given an array A of random integers and an integer k, find and return the kth largest element in the array

/*
Kth largest element
Send Feedback
Given an array A of random integers and an integer k, find and return the kth largest element in the array.
Note: Try to do this question in less than O(N * logN) time.
Input Format :
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
The following contains an integer, that denotes the value of k.
Output Format :
The first and only line of output contains the kth largest element
Constraints :
1 <= N, Ai, k <= 10^5
Time Limit: 1 sec
Sample Input 1 :
6
9 4 8 7 11 3
2
Sample Output 1 :
9
Sample Input 2 :
8
2 6 10 11 13 4 1 20
4
Sample Output 2 :
10

*/




#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<queue>

int kthlargestelement(int *arr,int n,int k){
    priority_queue<int> p;
    for(int i=0; i<n; i++){
        p.push(arr[i]);
    }
    int cnt=0;
    while(cnt<k-1){
        p.pop();
        cnt++;
    }
    int ans=p.top();
    return ans;
}

int main(){
    
    int  n; cin>>n; int *arr=new int[10000];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k; cin>>k;
    int ans=kthlargestelement(arr,n,k);
    cout<<"K-th largest element is  "<<ans<<endl;


    return 0;
}