//2 ways to store graphs
//1.Adjacency matrix
//2.Adjacency list

//in undirected graph (u,v) is same as (v,u)

//weights on edges represents the cost,distance or any metric considered from      one vertex to another.
//real life example: distance between two cities, cost of travel between two locations, etc.

//eg:5 6 //5 vertices and 6 edges
// 1 2
// 1 3
// 2 4
// 3 4 
// 3 5 
// 4 5

//vertices follow 1 indexing
//taking a matrix of size [n+1][n+1] for 1 indexing

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;//n vertices, m edges
    cin>>n>>m;
    //int adj[n+1][n+1]; //n+1 rows and n+1 columns for 1 indexing
    vector<vector<int>>adj(n+1,vector<int>(n+1,0));// n+1 rows and n+1 columns initialized to 0
    for(int i=0;i<m;i++){
        int u,v;
        //int weight;
        cin>>u>>v;
        //cin>>weight;
        adj[u][v]=1; //marking edge u-v
        adj[v][u]=1; //marking edge v-u for undirected graph

        //for weighted graph
        //adj[u][v]=weight; //marking edge u-v with weight
        //adj[v][u]=weight; //marking edge v-u with weight for undirected graph

    }

    //printing adjacency matrix
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

//tc:0(n^2) for adjacency matrix
// sc:o(n^2) for adjacency matrix

//adjacency list
//each index of the list contains a vector of integers representing the vertices connected to it

int main(){
    vector<vector<int>>adjlist(n+1); //n+1 rows for 1 indexing
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v); //adding edge u-v
        adjlist[v].push_back(u); //adding edge v-u for undirected graph
    }

    //printing adjacency list
    for(int i=1;i<=n;i++){
        cout<<i<<"->";
        for(int j=0;j<adjlist[i].size();j++){
            cout<<adjlist[i][j]<<" ";
        }
    }
}
//E is the number of edges
//tc:O(E+V) for adjacency list
//sc: O(V+2E) for undirected graph (each edge is stored twice, once for each vertex)
//sc: O(V+E) for directed graph (each edge is stored once)

//for weighted graph, we can use a pair to store the vertex and weight
//meaning for each vertex, we store a vector of pairs where each pair contains the connected vertex and the weight of the edge.
//eg: 1-> {2,3} means vertex 1 is connected to vertex 2 with weight 3

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adjlist(n+1);
    for(int i=0;i<m;i++){
        int u,v,weight;
        cin>>u>>v>.weight;
        adjlist[u].push_back({v,weight});
        adjlist[v].push_back({u,weight});

    }
    for(int i=1;i<=n;i++){
        cout<<i<<"->";
        for(int j=0;j<adjlist[i].size;j++){
            cout<<"(" << adjlist[i][j].first << "," << adjlist[i][j].second << ") ";
        }
        cout<<endl;

    }

}