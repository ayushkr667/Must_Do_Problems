// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// Example 1:

// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]
 
// Constraints:

// 1 <= n <= 9

class Solution {
public:
    bool isValid(vector<string> queens, int row, int col, int n){
        //check if the column had a queen before.
        for (int i = 0; i != row; ++i)
            if (queens[i][col] == 'Q')
                return false;
        //check if the 45° diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (queens[i][j] == 'Q')
                return false;
        //check if the 135° diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (queens[i][j] == 'Q')
                return false;
        return true;
    }
    
    void solve(int row, int n, vector<string> &queens, vector<vector<string>> &res){
        if(row == n){
            res.push_back(queens);
        }
        for(int col =0; col<n; col++){
            if(isValid(queens, row, col, n)){
                queens[row][col] = 'Q';
                solve(row+1, n, queens, res);
                queens[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>queens(n, string(n, '.'));
        solve(0, n, queens, res);
        return res;
    }
};
