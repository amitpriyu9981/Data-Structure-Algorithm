




#include<iostream>
using namespace std;

int Cntcycle(bool **edges,int n){
    int count=0;
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                if(edges[i][j] and edges[j][k] and edges[k][i]){
                    count++;
                }
            }
        }
    }
    return count;
}

int main(){
    int n,e; cin>>n>>e;
    bool** edge=new bool*[n];
    for(int i=0; i<n; ++i){
        edge[i]=new bool[n];
    }
    // taking all the edges input
    for(int i=0,f,s; i<e; ++i){
         cin>>f>>s;
        edge[f][s]=true;
        edge[s][f]=true;
    }
    // int ans=cntcycle(edge,n);
    cout << Cntcycle(edge,n)<<endl;
    for(int i=0; i<n; ++i){
        delete[] edge[i];
    }
    delete[] edge;
    return 0;
}