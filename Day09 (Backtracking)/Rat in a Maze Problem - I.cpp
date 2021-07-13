// Consider a rat placed at (0, 0) in a square matrix of order N * N. 
// It has to reach the destination at (N - 1, N - 1). 
// Find all possible paths that the rat can take to reach from source to destination. 
// The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).
// Value 0 at a cell in the matrix represents that it is blocked and rat 
// cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time.

// Example 1:

// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR
// Explanation:
// The rat can reach the destination at 
// (3, 3) from (0, 0) by two paths - DRDDRR 
// and DDRDRR, when printed in sorted order 
// we get DDRDRR DRDDRR.
// Example 2:
// Input:
// N = 2
// m[][] = {{1, 0},
//          {1, 0}}
// Output:
// -1
// Explanation:
// No path exists and destination cell is 
// blocked.

class Solution{
    private:
    bool isSafe(int row, int col, vector<vector<int>> &m, int n, bool visited[][5])
    {
        if (row == -1 || row == n || col == -1 || 
            col == n || visited[row][col] || m[row][col] == 0)
            return false;
    
        return true;
    }
    
    void solve(int row, int col, vector<vector<int>> &m, 
              int n, string& path, vector<string>& 
               possiblePaths, bool visited[][5])
    {
        // This will check the initial point
        // (i.e. (0, 0)) to start the paths.
        if (row == -1 || row == n || col == -1 
                   || col == n || visited[row][col] || m[row][col] == 0)
            return;
    
        // If reach the last cell (n-1, n-1)
        // then store the path and return
        if (row == n - 1 && col == n - 1) {
            possiblePaths.push_back(path);
            return;
        }
    
        // Mark the cell as visited
        visited[row][col] = true;
    
        // Check if downward move is valid
        if (isSafe(row + 1, col, m, n, visited))
        {
            path.push_back('D');
            solve(row + 1, col, m, n,path, possiblePaths, visited);
            path.pop_back();
        }
    
        // Check if the left move is valid
        if (isSafe(row, col - 1, m, n, visited))
        {
            path.push_back('L');
            solve(row, col - 1, m, n,path, possiblePaths, visited);
            path.pop_back();
        }
    
        // Check if the right move is valid
        if (isSafe(row, col + 1, m, n, visited)) 
        {
            path.push_back('R');
            solve(row, col + 1, m, n,path, possiblePaths, visited);
            path.pop_back();
        }
    
         // Check if the upper move is valid
        if (isSafe(row - 1, col, m, n, visited))
        {
            path.push_back('U');
            solve(row - 1, col, m, n,path, possiblePaths, visited);
            path.pop_back();
        }
    
        // Mark the cell as unvisited for 
        // other possible paths
        visited[row][col] = false;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        string path;
        bool visited[n][5];
        memset(visited, false, sizeof(visited));
         
        solve(0, 0, m, n, path, res, visited);
        
        return res;
    }
};

