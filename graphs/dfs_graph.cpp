//depth firsst traversal of a graph
//what is dfs?
//dfs is a graph traversal algorithm that starts at the root (or an arbitrary node in the case of a graph) and explores as far as possible along each branch before backtracking.
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&adj,int node,vector<int>&visited,vector<int>&result){
    visited[node]=1;
    result.push_back(node);
    for(int i=0;i<adj[node].size();i++){
        int neighbour=adj[node][i];
        if(visited[neighbour]!=1){
            dfs(adj,neighbour,visited,result);
        }
    }
}
int main(){
    vector<vector<int>>adj={
        {1,2},{4,5},{0,3,6},{2,7},{1},{1},{2,7},{3,6}
    };
    vector<int>visited(adj.size(),0);
    vector<int>result;
    int start=0;
    dfs(adj,start,visited,result);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}

//sc: o(v) for visited arr,result arr, annd for recursion stack worst case o(v)(skewed path)
//tc: for every unvisited node, we call dfs function once - o(v)
//for loop traverses through all neighbours of evry node(edges)-- degree of the node
//for total nodes- degree of graph fo undirected graph is 2E, where E is the number of edges
// tc: o(v+2E) for undirected graph ~ o(v+E)
//for directed graph, it is o(v+E) as degree of directed graph is E
