// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// A palindrome string is a string that reads the same backward as forward.

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]


class Solution {
public:
    bool isPalindrome(string s){
        int n = s.size();
        for(int i=0; i<n/2; i++){
            if(s[i] != s[n-i-1])
                return false;
        }
        return true;
    }
    
    void solve(int i, string s, vector<string>&curr, vector<vector<string>> &res){
        if(i == s.size()){
            res.push_back(curr);
            return;
        }
        
        string temp;
        for(int j=i; j<s.size(); j++){
            temp.push_back(s[j]);
            if( isPalindrome(temp) ){
                curr.push_back(temp);
                solve(j+1, s, curr, res);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        solve(0, s, curr, res);
        return res;
    }
};
