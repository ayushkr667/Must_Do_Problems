// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:


// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
  
  

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> Q;
        int orange = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] > 0)
                    orange++;
                
                if(grid[i][j] == 2)
                    Q.push({i, j, 0});
            }
        }
        
        int res = 0;
        int dx[] = {0, 0, 1, -1};   int dy[] = {1, -1, 0, 0};
        
        while(!Q.empty()){
            int size = Q.size();
            while(size--){
                auto curr = Q.front(); Q.pop();
                int x = curr[0], y = curr[1], time = curr[2];
                orange--;
                res = max(res, time);
                
                for(int i=0; i<4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] ==  1){
                        grid[nx][ny] = 2;
                        Q.push({nx, ny, time+1});
                    }
                }
            }
        }
        if(!orange)
            return res;
        return -1;
    }
};
