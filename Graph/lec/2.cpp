// bfs and dfs traversal for the graph in case of disconnected component

#include <bits/stdc++.h>
using namespace std;
void printdfs(int **edges, int n, int sv, bool *visited)
{
   cout<<sv<<" ";
   visited[sv]=true;
   for(int i=0; i<n; i++){
    if(i==sv) continue;
    if(edges[sv][i]==1){
        if(!visited[i]){
            // continue;
            printdfs(edges,n,i,visited);
        }
        // printdfs(edges,n,i,visited);
    }
   }
}

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        
            printdfs(edges, n, i, visited);
        
    }
    // delete the dynamically allocated memory
    delete[] visited;
}
void printbfs(int **edges,int n,int sv,bool *visited){
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        cout<<front<<" ";
        for(int i=0; i<n; i++){
            if(i==front) continue;
            if(edges[front][i]==1 and !visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}
void BFS(int **edges,int n){
    bool *visited=new bool[n];
    for(int i=0; i<n; i++){
        visited[i]=false;
    }
    for(int i=0; i<n; i++){
        if(!visited[i])
           printbfs(edges,n,i,visited);
    }
    delete []visited;
}

int main()
{
    int n, e;
    cin >> n >> e;

    // matrix
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        // mark every-thing with zero
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    // taking input all the edges between the vertices
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    cout << "Dfs Traversal is " << endl;
    DFS(edges, n);
    cout<<"\n";
    cout<<"Bfs Traversal is "<<endl;
    BFS(edges,n);
}