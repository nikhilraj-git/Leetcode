class Solution {
public:
    bool dfs(int start, int color, vector<int> adj[], vector<int>& vis) {
        vis[start] = color;
        for (auto it : adj[start]) {
            if (vis[it] == -1) {
                if (dfs(it, !color, adj, vis) == false) return false;
            } else if (vis[it] == color) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        
        // Create adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
            }
        }

        vector<int> vis(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                if (dfs(i, 0, adj, vis) == false) return false;
            }
        }
        return true;
    }
};
