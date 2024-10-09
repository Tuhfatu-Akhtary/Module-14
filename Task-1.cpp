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



Time Complexity: O(V+E)
Space Complexity: O(V)