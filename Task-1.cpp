#include <bits/stdc++.h>
using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    // Step 1: Create the adjacency list
    vector<vector<int>> graph(n);
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // Step 2: Perform BFS
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        if (node == destination) {
            return true;
        }
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
    return false;
}

int main() {
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    int source = 0, destination = 5;
    cout << (validPath(n, edges, source, destination) ? "true" : "false") << endl;
    return 0;
}


//Time Complexity:
//Space Complexity: