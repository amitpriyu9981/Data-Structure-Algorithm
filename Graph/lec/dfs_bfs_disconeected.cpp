// graph implementation // dfs algorithm to print the edges btw vertices --FOR DISCONNECTED COMPONENT ALSO


#include<iostream>
#include<queue>
using namespace std;

// print function for the bfs algorithm
void printbfs(int **edges,int n,int sv,bool *visited){
    // use queue pendingvertex for the bfs traversal 
    queue<int> pendingvertex;
    // bool *visited=new bool[n]; 
    // // initilly initilise it with false
    // for(int i=0; i<n; i++){
    //     visited[i]=false;
    // }
    pendingvertex.push(sv);
    visited[sv]=true;
    while(!pendingvertex.empty()){
        int front=pendingvertex.front();
        pendingvertex.pop();
        cout<<front<<" ";
        for(int i=0; i<n; i++){
            if(front==i){continue;}
            if(edges[front][i]==1 and !visited[i]){
                // push into the queue and mark true with respect to that
                pendingvertex.push(i);
                visited[i]=true;
            }
        }
    }
    // deallocate the dynamically created memory
    // delete []visited;
}

// print function for the dfs as well 
void printdfs(int **edges,int n,int sv,bool *visited){
    cout<<sv<<" ";
    visited[sv]=true;
    // check 
    for(int i=0; i<n; i++){
        if(i==sv){
            continue;
        }
        
        if(edges[sv][i]==1){
            if(visited[i]){
            continue;
        }
            printdfs(edges,n,i,visited);
        }
    }
}
void dfs(int **edges,int n){
    bool *visited=new bool[n];
    for(int i=0; i<n; i++){
        visited[i]=false;
    }
    for(int i=0; i<n; i++){
        if(!visited[i])
            printdfs(edges,n,i,visited);
    }
}
void bfs(int **edges,int n){
    bool *visited=new bool[n];
    for(int i=0; i<n; i++){
        visited[i]=false;
    }
    for(int i=0; i<n; i++){
        if(!visited[i])
            printdfs(edges,n,i,visited);
    }

}
int main(){
    int n,e; cin>>n>>e;
    // creating a 2-d matrix dynamiclly
    int **edges=new int*[n];
    for(int i=0; i<n; i++){
        edges[i]=new int[n];
        // initilise all with the zero
        for(int j=0; j<n; j++){
            edges[i][j]=0;
        }
    }
    // take all the edges between  the vertices
    for(int i=0; i<e; i++){
        int f,s; cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
  
    
   
    dfs(edges,n);
    cout<<endl;
    bfs(edges,n);
    

    for(int i=0; i<n; i++){
        delete []edges[i];
    }
    delete []edges;
    return 0;
}