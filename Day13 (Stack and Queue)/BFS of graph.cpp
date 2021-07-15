// Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
// Note: One can move from node u to node v only if there's an edge from u to v and find the BFS 
// traversal of the graph starting from the 0th vertex, from left to right according to the graph. 
// Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

// Your task:
// You don’t need to read input or print anything. Your task is to complete the function bfsOfGraph() 
// which takes the integer V denoting the number of vertices and adjacency list as input parameters 
// and returns  a list containing the BFS traversal of the graph starting from the 0th vertex from left to right.


class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int> res;
	    queue<int> st;
	    int arr[V] = {0};
	    st.push(0);
	    arr[0] = 1;
	    while(!st.empty()){
	        int u = st.front();    st.pop();
	        res.push_back(u);
	        for(auto v : adj[u]){
	            if(arr[v] == 0){
	                st.push(v);
	                arr[v] = 1;
	            }
	        } 
	    }
	    return res;
	}
};
