
/*
Code : Get Path - DFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :

*/


#include<iostream>
#include<vector>
using namespace std;

vector<int>* getpathhelper(int **edges,int n,int sv,int ev,bool *visited){
    if(sv==ev){
        vector<int>*ans=new vector<int>();
        ans->push_back(ev);
        return ans;
    }
    visited[sv]=true;
    for(int i=0; i<n; i++){
        if(edges[sv][i]==1 and !visited[i]){
            vector<int>* smalloutput=getpathhelper(edges,n,i,ev,visited);
            if(smalloutput != NULL){
                smalloutput->push_back(sv);
                return smalloutput;
            }
        }
    }
    return NULL;
}

vector<int>* getpath(int **edges,int n,int sv,int ev){
    bool *visited=new bool[n];
    for(int i=0; i<n; i++){
        visited[i]=false;
    }
    vector<int>* output=getpathhelper(edges,n,sv,ev,visited);
    delete []visited;
    return output;
}

int main(){
    int n,e; cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0; i<n; i++){
        edges[i]=new int[n];
        for(int j=0; j<n; j++){
            edges[i][j]=0;
        }
    }
    // Taking all the edges input
    for(int i=0; i<e; i++){
        int f,s; cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    // path between s1 and s2
    int v1,v2; cin>>v1>>v2;
    vector<int>* ans=getpath(edges,n,v1,v2);
    if(ans != NULL){
       for(int i=0; i<ans->size(); i++){
        cout<<ans->at(i)<<" ";
       }
    }
    else{
        cout<<"There is no path between "<<v1<<" "<<v2<<endl;
    }
    cout<<endl;
    return 0;
}


/*

/ #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> getPathDFSHelper(int **edges, int n, bool *visited, int sv, int v2)
// {
//     if (sv == v2)
//     {
//         vector<int> answer;
//         answer.push_back(sv);
//         return answer;
//     }
//     visited[sv] = true;
//     for (int i = 0; i < n; i++)
//     {
//         if (edges[sv][i] == 1 && !visited[i])
//         {
//             vector<int> answer = getPathDFSHelper(edges, n, visited, i, v2);
//             if (!answer.empty())
//             {
//                 answer.push_back(sv);
//                 return answer;
//             }
//         }
//     }
//     return vector<int>(0);
// }

// vector<int> getPathDFS(int **edges, int n, int v1, int v2)
// {
//     bool *visited = new bool[n];
//     for (int i = 0; i < n; i++)
//     {
//         visited[i] = false;
//     }
//     return getPathDFSHelper(edges, n, visited, v1, v2);
// }

// int main()
// {
//     int n;
//     int e;
//     cin >> n >> e;
//     int **edges = new int *[n];
//     for (int i = 0; i < n; i++)
//     {
//         edges[i] = new int[n];
//         // Initially no edges
//         for (int j = 0; j < n; j++)
//         {
//             edges[i][j] = 0;
//         }
//     }
//     for (int i = 0; i < e; i++)
//     {
//         int f, s;
//         cin >> f >> s;
//         edges[f][s] = 1;
//         edges[s][f] = 1;
//     }
//     int v1, v2;
//     cin >> v1 >> v2;

//     vector<int> answer = getPathDFS(edges, n, v1, v2);

//     for (int i = 0; i < answer.size(); i++)
//     {
//         cout << answer.at(i) << " ";
//     }
//     return 0;
// }


*/