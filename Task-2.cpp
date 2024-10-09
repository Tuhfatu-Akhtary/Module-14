void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int countComponents(int A, vector<vector<int>>& B) {
    // Step 1: Build the adjacency list
    vector<vector<int>> graph(A);
    for (auto& edge : B) {
        int u = edge[0] - 1, v = edge[1] - 1;  // 1-based to 0-based indexing
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // Step 2: Find connected components using DFS
    vector<bool> visited(A, false);
    int components = 0;
    
    for (int i = 0; i < A; i++) {
        if (!visited[i]) {
            components++;
            dfs(i, graph, visited);
        }
    }
    
    return components;
}

Time Complexity: O(V+E)
Space Complexity: O(V)