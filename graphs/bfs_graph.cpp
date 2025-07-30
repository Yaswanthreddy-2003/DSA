//bfs traversal of a graph
//what is bfs?
//bfs is a graph traversal algorithm that explores the neighbor nodes at the present depth prior to moving on to nodes at the next depth level.
//it uses a queue data structure to keep track of the nodes to be explored next.

//given a graph, we will perform bfs traversal on it and print the nodes in the order they are visited.
//we will use an adjacency list to represent the graph
//adj[][] = [[1,2], [0,2,3], [0,1,4], [1,4], [2,3]]

//Given a undirected graph represented by an adjacency list adj, where each adj[i] represents the list of vertices connected to vertex i.


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int>bfs(vector<vector<int>>&adj,int start){
    vector<int>visited(adj.size(),0);
    vector<int>result;
    queue<int>q;
    visited[start]=1;
    q.push(start);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        result.push_back(node);
        for(int i=0;i<adj[node].size();i++){
            int neighbour=adj[node][i];
            if(visited[neighbour]!=1){ //if neighbour is not visited
                visited[neighbour]=1; //marking neighbour as visited
                q.push(neighbour); //adding neighbour to queue for further exploration
            }
        }
    }
    return result;  


}
int main(){
    vector<vector<int>> adj = {
        {1, 2},    // Node 0 is connected to Node 1 and Node 2
        {0, 2, 3}, // Node 1 is connected to Node 0, Node 2, and Node 3
        {0, 1, 4}, // Node 2 is connected to Node 0, Node 1, and Node 4
        {1, 4},    // Node 3 is connected to Node 1 and Node 4
        {2, 3}     // Node 4 is connected to Node 2 and Node 3
    };
    vector<int>final=bfs(adj,0);//starting bfs traversal from node 0
    for(int i=0;i<final.size();i++){
        cout<<final[i]<<" ";
    }
    return 0;
}
//space comp: O(v) for visited arr, O(v) for result arr, O(v) for queue
//O(3v) = O(v) total space complexity

//tc
//in the bfs function, for loop iterates every neighbour of the current node
//the total number of edges of a node is called degree
//degree of the total graph is the sum of degrees of all nodes= 2E ,E is the number of edges
//queue q runs in O(E) time as it processes each edge once
//the while loop runs O(V) times as queue takes only unvisited nodes
//so the total time complexity is O(V + E) for bfs traversal


