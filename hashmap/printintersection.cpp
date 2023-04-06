// problem statement
/*

You have been given two integer arrays/lists (ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in the order they appear in the second array/list (ARR2).


Input format :
The first line of input contains an integer 'N' representing the size of the first array/list.

The second line contains 'N' single space separated integers representing the elements of the first the array/list.

The third line contains an integer 'M' representing the size of the second array/list.

The fourth line contains 'M' single space separated integers representing the elements of the second array/list.
Output format :
Print the intersection elements. Each element is printed in a separate line.
Constraints :
0 <= N <= 10^6
0 <= M <= 10^6

Time Limit: 1 sec 
Sample Input 1 :
6
2 6 8 5 4 3
4
2 3 4 7 
Sample Output 1 :
2
3 
4
Sample Input 2 :
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
1 
2 
2


*/



#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define f(i,s,e) for(int i=s; i<e; i++)
#define int long long
#define umii unordered_map<int,int>
#define endl '\n'

void printintersection(vector<int> a,vector<int> b,int n,int m){
    // function  to print the intersection of the array
    umii ans;
    f(i,0,n) ans[a[i]]++;
    f(i,0,m){
        if(ans[b[i]]>0){
            cout<<b[i]<<" ";
            ans[b[i]]--;
        }
    }
    endl;
    endl;
}
int32_t main(){

    int n,m; cin>>n>>m;
    vector<int> a(n),b(m);
    f(i,0,n) cin>>a[i];
    f(i,0,m) cin>>b[i];
    printintersection(a,b,n,m);
    endl;
    return 0;
}