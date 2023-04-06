#include <iostream>
using namespace std;
#include <climits>

int minCostPath_Mem(int **input, int m, int n, int i, int j, int **output) {
    if(i == m- 1 && j == n- 1) {
        return input[i][j];
    }
    
    if(i >= m || j >= n) {
        return INT_MAX;
    }
    
    // Check if ans already exists
    if(output[i][j] != -1) {
        return output[i][j];
    }
    
    // Recursive calls
    int x = minCostPath_Mem(input, m, n, i, j+1, output);
    int y = minCostPath_Mem(input, m, n, i+1, j+1, output);
    int z = minCostPath_Mem(input, m, n, i+1, j, output);
    
    // Small Calculation
    int a = min(x, min(y, z)) + input[i][j];
    
    // Save the answer for future use
    output[i][j] = a;
    
    return a;
}

int minCostPath_Mem(int **input, int m, int n, int i, int j) {
    int **output = new int*[m];
    for(int i = 0; i < m; i++) {
        output[i] = new int[n];
        for(int j = 0; j < n; j++) {
            output[i][j] = -1;
        }
    }
    
    return minCostPath_Mem(input, m, n, i, j, output);
}

int main() {
    int m, n;
    cin >> m >> n;
    int **input = new int*[m];
    for(int i = 0; i < m; i++) {
        input[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> input[i][j];
        }	
    }
    cout << minCostPath_Mem(input, m, n, 0, 0) << endl;
    
}


// #include<iostream>
// #include<climits>


// using namespace std;

// int  mincostpath_helper(int **arr,int n,int m,int i,int j,int **ans){
//     // base case
//     if(i==m-1 and j==n-1){
//         return arr[i][j];
//     }
//     // in case of row and coulumn are out
//     if(i>=m or j>=n){
//         return INT_MAX;
//     }
//     // check if ans is already exists or not
//     if(ans[i][j] != -1){
//         return ans[i][j];
//     }
//     int x=mincostpath_helper(arr,m,n,i,j+1,ans);
// 	int y=mincostpath_helper(arr,m,m,i+1,j+1,ans);
// 	int z=mincostpath_helper(arr,m,n,i+1,j,ans);

//     // small calculation to find the min among x y and z
//     int samlloutput=min(x,min(y,z));
//     // store the ans for the future use 
//     ans[i][j]=samlloutput+arr[i][j];
//     return samlloutput;
// }

// int minCostPath(int **arr,int n,int m,int i,int j){
//     int **ans=new int*[m];
//     for(int i=0; i<m; i++){
//         ans[i]=new int[n];
//         for(int j=0; j<n; i++){
//             ans[i][j]=-1;
//         }
//     }
//     return mincostpath_helper(arr,n,m,0,0,ans);
// }

// int main(){
    
//     int **arr; int n,m; cin>>n>>m; arr=new int*[n];
//     // Declaring an 2-d array dynamically
//     for(int i=0; i<n; i++){
//         arr[i]=new int[m];
//     }
//     // Taking input in 2-d array
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             cin>>arr[i][j];
//         }
//     }
//     cout<<"Min cost path is "<<minCostPath(arr,n,m,0,0)<<endl;
//     return 0;
// }