// problem statement:- You are given with an integer k and an array of integers that contain numbers in random order
//. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.



/*

problem statement
Code : K smallest Elements
Send Feedback
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(n * logk) and space complexity should not be more than O(k).
Note: Order of elements in the output is not important.
Input Format :
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of k.
Output Format :
The first and only line of output print k smallest elements. The elements in the output are separated by a single space. 
Constraints:
Time Limit: 1 sec
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Sample Output 1 :
1 2 3 5 


*/




// #include<iostream>
// using namespace std;

// #include<queue>
// #include<vector>
// #include<algorithm>

// vector<int> ksmallestelement(int *arr,int n,int k){

//     vector<int> v;
//     priority_queue<int> p;
//     for(int i=0; i<k; i++){
//         p.push(arr[i]);
//     }

//     for(int i=k; i<n; i++){
//         if(p.top()>arr[i]){
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
//     int n;
//     cin>>n;
//     int *arr=new int[10000];
//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//     }
//     int k; cin>>k;
//     vector<int> ans=ksmallestelement(arr,n,k);
//     sort(ans.begin(),ans.end());  // for the sorting
//     for(int i=0; i<ans.size(); i++){
//          cout<<ans[i]<<" ";
//     }
//     delete []arr;
// }