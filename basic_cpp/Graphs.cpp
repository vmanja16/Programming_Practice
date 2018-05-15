#include <iostream>
#include <stack>
# include <stdlib.h>

using namespace std;





/* Returns Vector of Nodes in index order w/ edge lists
 * Where param edges are 1-indexed (vert1,vert2) undirected pairs
 */
vector<Node> buildGraph(vector<vector<int>> edges, int nodeCount){
    vector<Node> graph(nodeCount);
    
    for (vector<int> edgePair : edges){
        if (edgePair.size() == 2){
            // put it in the graph (compensate for 1-index entries)
            graph[edgePair[0]-1].edges.push_back(edgePair[1]-1);
            graph[edgePair[1]-1].edges.push_back(edgePair[0]-1);
        }
    }
    return graph;
}

// BFS to find shortest distances from source node s 
// here edges were 1-index (vert1,vert2) undirected pairs
vector<int> bfs(int n, vector<vector<int>> edges, int s) {
    vector<int> distances(n,-1);
    queue<int> nodeQueue;
    // build graph
    vector<Node> graph = buildGraph(edges,n);
    
    // 1 -> 0 index
    s -= 1;
    
    // start a queue with s
    graph[s].visited = true;
    distances[s] = 0;
    nodeQueue.push(s);
    
    // Enqueue children if unvisited and update their distance
    while(!nodeQueue.empty()){
        int index = nodeQueue.front(); 
        nodeQueue.pop();
        Node node = graph[index];
        for (int i : node.edges){
            if(!graph[i].visited){
                nodeQueue.push(i);
                graph[i].visited = true;
                distances[i] = distances[index] + 1;
            }
        }
    }
    return distances;
}



int main(void){









	return 0;
}