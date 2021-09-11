// Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
// Note: One can move from node u to node v only if there's an edge from u to v and find the BFS 
// traversal of the graph starting from the 0th vertex, from left to right according to the graph. 
// Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.



class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> res;
        vector<int> vis(V, 0);
        
        queue<int> Q;
        Q.push(0);
        vis[0] =1;
        while(!Q.empty()){
            int temp = Q.front();   Q.pop();
            res.push_back(temp);
            for(int i=0; i<adj[temp].size(); i++){
                if(!vis[ adj[temp][i] ]){
                    Q.push(adj[temp][i]);
                     vis[ adj[temp][i] ] = 1;
                }
            }
        }
        
        return res;
    }
};



