// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character
 

// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:

// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')


class Solution {
public:
    int solve(string w1, string w2){
        int n = w1.size();
        int m = w2.size();
        int dp[n+1][m+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i ==0 && j == 0)
                    dp[i][j] = 0;
                else if(i==0 && j!= 0)
                    dp[i][j] = j;
                else if(i != 0 && j == 0)
                    dp[i][j] = i;
                
                else if(w1[i-1] != w2[j-1])
                               //replace any one         //delete 1    //delete other
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                
                else
                    dp[i][j] = dp[i-1][j-1];
            }
        }
        return dp[n][m];
    }
    
    
    int minDistance(string word1, string word2) {
        
        return solve(word1, word2);
    }
};
