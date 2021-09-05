// Given a connected undirected graph. Perform a Depth First Traversal of the graph.
// Note: Use recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph..

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void solve(vector<int> &res, int u, vector<int> adj[], vector<int>& visited){
        visited[u] = 1;
        res.push_back(u);
        for(int i=0; i<adj[u].size(); i++){
            if(!visited[adj[u][i]])
                solve(res, adj[u][i], adj, visited);
        }
    }
    
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        vector<int> visited(V, 0);
        solve(res, 0, adj, visited);
        return res;
    }
};





