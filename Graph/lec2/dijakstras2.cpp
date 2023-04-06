#include<iostream>
#include<climits>

using namespace std;
#define int long long
#define endl cout<<"\n"
int findminvertex(int *distance,bool* visited,int n){
    int minvertex=-1;
    for(int i=0; i<n; i++){
        if(!visited[i] and(minvertex==-1 or distance[i]<distance[minvertex])){
            minvertex=i;
        }
    }
    return minvertex;         
}
void solve(int **edges,int n){
    int *distance=new int[n];
    bool *visited=new bool[n];
    for(int i=0; i<n; i++){
        distance[i]=INT_MAX;
        visited[i]=false;
    }
    distance[0]=0;
    for(int i=0; i<n; i++){
        int minvertex=findminvertex(distance,visited,n);
        visited[minvertex]=true;
        for(int j=0; j<n; j++){
            if(edges[minvertex][j] !=0 and !visited[j]){
                // cal distance first
                int dist=distance[minvertex]+edges[minvertex][j];
                if(dist<distance[j]){
                    distance[j]=dist;
                }
            }
        }
    }
    // print
    for(int i=0; i<n; i++){
        cout<<i<<" "<<distance[i];
        endl;
    }
    endl;
    // deallocate
    delete []visited;
    delete []distance;
}
int main(){
    int n; int e; 
    cin>>n>>e;
    int **edges=new int*[n]; //asj 
    for(int i=0; i<n; i++){
        edges[i]=new int[n];
        for(int j=0; j<n; j++){
            edges[i][j]=0;
        }
    }
    endl;
    solve(edges,n);
    for(int i=0; i<n; i++){
        delete [] edges[i];
    }
    delete [] edges;
}