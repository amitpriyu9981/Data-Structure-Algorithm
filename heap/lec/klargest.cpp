//problem statement 
// You are given with an integer k and an array of integers that contain numbers in random order
// rite a program to find k largest numbers from given array. You need to save them in an array and return it.
// Time complexity should be O(nlogk) and space complexity should be not more than O(k).

/*

Code : K largest elements
Send Feedback
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k largest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(nlogk) and space complexity should be not more than O(k).
Order of elements in the output is not important.
Input Format :
Line 1 : Size of array (n)
Line 2 : Array elements (separated by space)
Line 3 : Integer k
Output Format :
k largest elements
Sample Input :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Sample Output :
12
16
20
25

*/


/*
#include<bits/stdc++.h>

vector<int> kLargest(int input[], int n, int k){
   
   vector<int> ans;
   priority_queue<int > p;
   for(int i=0; i<n; i++){
       p.push(input[i]);
   }

   // Now we have to find the k largest element 
   for(int i=0; i<k; i++){
       ans.push_back(p.top());
       p.pop();
   }
   return ans;
}

*/
















// #include<iostream>
// using  namespace std;

// #include<queue>
// #include<vector>
// #include<algorithm>

// vector<int> klargest(int *arr,int n,int k){
//     vector<int> v;
//     priority_queue<int,vector<int>,greater<int> > p;
//     for(int i=0; i<k; i++){
//         p.push(arr[i]);
//     }
//     for(int i=k; i<n; i++){
//         if(p.top()<arr[i]){
//             p.pop();
//             p.push(arr[i]);
//         }
//     }
//     while(!p.empty()){
//         v.push_back(p.top());
//         p.pop();
//     }
//     return v;
// }

// int main(){
//     int n; cin>>n; int *arr=new int[100000];
//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//     }
//     int k; cin>>k;
//     vector<int> ans=klargest(arr,n,k);
//     // sort(ans.end(),ans.begin());
//     for(int i=0; i<ans.size(); i++){
//         cout<<ans[i]<<endl;
//     }
//     delete []arr;
//     return 0;
// }