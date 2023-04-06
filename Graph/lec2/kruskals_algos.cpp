// problem
/*

Code : Kruskal's Algorithm

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Print the MST, as described in the task.
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
1 2 1
0 1 3
0 3 5



*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class edge{
    public:
      int source;
      int destination;
      int weight;

};
bool compare(edge e1,edge e2){
    return e1.weight<e2.weight;    //   ---this is for sort in the ascending order 
}


int findparent(int v,int *parent){
    if(parent[v]==v){
        return v;  // we get the parents
    }
    return findparent(parent[v],parent);
}

void krushkal(edge *input,int n, int e){
    // step-1 to  sort the input array according to the weight in ascending order
    sort(input,input+e,compare);

    // s-2 create a output array of edge type and of size n-1
    edge *output=new edge[n-1];

    // create a parent array of size n and initilise it with its index value
    int *parent=new int[n];
    for(int i=0; i<n; i++) parent[i]=i;

    int count=0;
    int i=0; // for knowing the at which edges right now
    while(count != n-1){
       edge currentedge=input[i];
       // check wether we can add this current edge in mst or not
       int sourceparent=findparent(currentedge.source,parent);
       int destinationparent=findparent(currentedge.destination,parent);

       if(sourceparent != destinationparent){
        // in this case we can add the edge else we have to skip this edge
        output[count]=currentedge;
        count++;
        // make the parent same
        parent[sourceparent]=destinationparent;
       }
       i++;
    }

    // print the output array
    for(int i=0; i<n-1; i++){
        if(output[i].source <output[i].destination){
            cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<"\n";
        }
        else{
            cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<"\n";
        }
    }
 
}

int main(){
    int n,e; cin>>n>>e;  // n-- no of vertex and e represent the no of edges
    // creating an input array
    edge *input=new edge[e];
    for(int i=0; i<e; i++){
        int s,d,w; cin>>s>>d>>w;
        input[i].source=s;
        input[i].destination=d;
        input[i].weight=w;
    }
    // kruskal's algorithm
    krushkal(input,n,e);
}