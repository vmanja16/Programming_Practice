#include <iostream>
#include <stack>
# include <stdlib.h>
#include <vector>
#include <map>
#include <queue>

#define Deleted -1

using namespace std;


struct Node{
	int id;
	int deps = 0;
	bool visited;
	vector<int> neighbors;
};

vector<Node> buildDirectedGraph(vector<vector<int>> & edges, vector<int> &verts){
	vector<Node> graph(verts.size());
	map<int,int> idIndexDict;
	// add vert IDs
	for(int i = 0; i < verts.size(); i ++){
		graph[i].id = verts[i];
		idIndexDict[graph[i].id] = i;
	}
	for (vector<int> edgePair : edges){
		int from = idIndexDict[edgePair[0]];
		int to = idIndexDict[edgePair[1]]; 
		graph[from].neighbors.push_back(to);
		graph[to].deps ++;
	}

	return graph;
}


vector<int> buildOrder(vector<int> & projects, vector<vector<int>> & dependencies){
	vector<Node> graph = buildDirectedGraph(dependencies, projects);
	
	vector<int> order;

	queue<int> checkQueue;


	// check for 0's to start the queue
	for (int i = 0; i < graph.size(); i++){
		if (graph[i].deps == 0) checkQueue.push(i);
	}
	while(!checkQueue.empty()){
		int index = checkQueue.front(); 
		checkQueue.pop();
		Node node = graph[index];
		if (node.id == Deleted) continue;
		// Check we can build his id and delete him!
		if (node.deps == 0){
			order.push_back(node.id);
			for (int n : node.neighbors){
				if (graph[n].id != Deleted){
					graph[n].deps--;
					checkQueue.push(n);
				}
			}
			graph[index].id = Deleted;
		}
	}

	// check and return
	if (order.size() != projects.size()){
		vector<int> v(1,-1); return v;
	}
	else return order;
}


void buildOrderTest(){
	vector<int> projects; 
	for(int i = 1; i < 7; i++){
		projects.push_back(i);
	}
	vector<vector<int>> dependencies;
	vector<int> a(2), b(2), c(2), d(2), e(2), f(2), g(2);
	a[0] = 1; a[1] = 4; dependencies.push_back(a);
	b[0] = 6; b[1] = 2; dependencies.push_back(b);
	c[0] = 2; c[1] = 4; dependencies.push_back(c);
	d[0] = 6; d[1] = 1; dependencies.push_back(d);
	e[0] = 4; e[1] = 3; dependencies.push_back(e);
	f[0] = 1; f[1] = 2; dependencies.push_back(f);
	// Add cycle
	//g[0] = 2; g[1] = 1; dependencies.push_back(g);

	vector<int> result = buildOrder(projects,dependencies);
	for (int i : result) cout << i << " ";

}

/* Returns Vector of Nodes in index order w/ edge lists
 * Where param edges are 1-indexed (vert1,vert2) undirected pairs
 */
/*
vector<Node> buildUndirectedGraph(vector<vector<int>> edges, int nodeCount){
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
*/
// BFS to find shortest distances from source node s 
// here edges were 1-index (vert1,vert2) undirected pairs
/*
vector<int> bfs(int n, vector<vector<int>> edges, int s) {
    vector<int> distances(n,-1);
    queue<int> nodeQueue;
    // build graph
    vector<Node> graph = buildUndirectedGraph(edges,n);
    
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

*/

int main(void){
	buildOrderTest();

	return 0;
}