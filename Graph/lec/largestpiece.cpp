#include<bits/stdc++.h>
#include<iostream>
#include<vector>
// #include<cmaths>
using namespace std;

int dir[4][2]={{-1,0},{0,1},{1,0},{-1,-1}};  // all valid four direction

int getcakehelper(vector<vector<int> > &cake,int n,int i,int j,bool **visited){
    // Base case
    visited[i][j]=true; int ans;
    for(int q=0; q<4; q++){
        int k=i+dir[q][0];
        int l=j+dir[q][1];
        
        if(k<n and k>=0 and l<n and l>=0){
             ans=getcakehelper(cake,n,i,j,visited);
        }
    }
    return ans+1;
}

int getcake(vector<vector<int>> &cake,int n){
    bool** visited=new bool*[n];
    for(int i=0; i<n; i++){
        visited[i]=new bool[n];
        
        for(int j=0; j<n; j++){
            visited[i][j]=0;
        }
    }
    int maxans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cake[i][j]==1 and !visited[i][j]){
                maxans=max(maxans,getcakehelper(cake,n,i,j,visited));
            }
        }
    }
}

int main(){

    int n; cin>>n;
    vector<vector<int>> cake(n,vector<int>(n));
    // input
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>cake[i][j];
        }
    }
    cout<<"Largetst piece of cake with 1's "<<getcake(cake,n);
    return 0;
}


