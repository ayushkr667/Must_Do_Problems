// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> dict;
        for(auto word: wordDict){
            dict[word] = 1;
        }
        
        vector<bool> dp(s.size(), false);
        
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<=i; j++){
                string temp = s.substr(j, (i-j+1));
                if(j == 0){
                    if(dict[temp]){
                        dp[i] = true;
                    }else{
                        dp[i] = false;
                    }
                }
                else{
                    dp[i] = dp[i] | (dp[j-1] & dict[temp]);
                }
            }
        }
        
        for(auto i:dp)
            cout << i << " ";
        
        return dp[s.size()-1];
    }
};
