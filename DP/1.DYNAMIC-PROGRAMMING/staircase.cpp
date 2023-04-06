/*

Code : Staircase using Dp
Send Feedback
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Since the answer can be pretty large print the answer % mod(10^9 +7)
Input Format:
First line will contain T (number of test case).
Each test case is consists of a single line containing an integer N.
Output Format:
For each test case print the answer in new line
Constraints :
1 <= T < = 10
1 <= N <= 10^5
Sample input 1
2
2
3
Sample output 1
2
4
Explanation of sample input 1:
Test case 1:
To reach at top of 2nd stair, we have only two options i.e (2), (1,1)

Test case 2:
 To reach at top of 3rd stair, we have four options i.e (1,1,1), (1,2) ,(2,1), (3)
Sample input 2:
2
5
10
Sample output 2:
13
274
*/




#include<bits/stdc++.h>
using namespace std;
const unsigned long M = 1000000007;

int getstaircase(int n){
    // solve using dp , use bottom -up approach
    long *ans=new long[n+1];
    ans[0]=1;
    ans[1]=1;
    ans[2]=2;

    //now iterate from 3 to end
    for(int i=3; i<=n; i++){
        ans[i]=(ans[i-1]+ans[i-2]+ans[i-3])%M;
    }
    return ans[n]%M;

}

int main(){
//    int t; cin>>t;
//    while(t--){
     int n;
     cin >> n;
    long  ans=getstaircase(n);
    cout<<ans<<endl;
//    }
    
    
    // write your code here
    return 0;
}



// #include<iostream>
// using namespace std;

// #define M 1e9+7
// long staircase(int n){
//    long *ans=new long[n+1];
//    ans[0]=1;
//    if(n>=1){ ans[1]=1;}
//    if(n>=2){ ans[2]=2;}
//    for(long i=3; i<=n; i++){
//     ans[i]=(ans[i-1]+ans[i-2]+ans[i-3]);
//    }
//    return ans[n];
// }



// int main(){

//     int t; cin>>t;
//     while(t--){
//         int n; cin>>n;
//         long ans=staircase(n);
//         cout<<ans<<endl;
//     }
// }