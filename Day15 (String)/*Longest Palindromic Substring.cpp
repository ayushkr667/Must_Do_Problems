// Given a string s, return the longest palindromic substring in s.

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"

class Solution {
public:
    string longestPalindrome(string s) {
        if(!s.size()) return  "";
        int n = s.size();
        
        bool dp[n][n];// row is start index and col is end index
        
        //only upper half of diagonal is needed
        for(int i=0; i<n; i++)
            dp[i][i] = true;
       
        //fill table from bottom
        for(int i = n-1; i>=0; i--){
            for(int j = i+1; j<n; j++){
                //only two character substring
                if((j-i == 1) && (s[i] == s[j]))
                    dp[i][j] = true;
                
                else if( (j-i>1) && s[i] == s[j] && dp[i+1][j-1] )
                    dp[i][j] = true;
                
                else
                    dp[i][j] = false;
            }
        }
        
        //get the maximum substring
        int max = 0;
        string res = "";
        for(int i=0; i<n; i++){
            string temp = "";
            for(int j=i; j<n; j++){
                temp += s[j];
                if(dp[i][j] == true && (j-i+1) > max){
                    max = j-i+1;
                    res = temp;
                }
            }
        }
        
        return res;
    }
};
