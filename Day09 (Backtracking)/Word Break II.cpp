// Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence 
// where each word is a valid dictionary word. Return all such possible sentences in any order.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Example 1:

// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]
// Example 2:

// Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
// Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
// Explanation: Note that you are allowed to reuse a dictionary word.

class Solution {
public:
    void solve(int i, string curr, string s, unordered_map<string, int>& dict, vector<string>& res){
        if(i == s.size()){
            res.push_back(curr);
            return;
        }
        
        string temp = "";
        for(int j=i; j<s.size(); j++){
            temp.push_back(s[j]);
            if(dict[temp] ){
                if(j < s.size()-1){
                    temp.push_back(' ');
                    solve(j+1, curr+temp, s, dict, res);
                    temp.pop_back();
                }else{
                    solve(j+1, curr+temp, s, dict, res);
                }   
            }
        }
    }
    
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> dict;
        vector<string> res;
        for(auto word: wordDict){
            dict[word] = 1;
        }
        string curr;
        solve(0 ,curr, s, dict, res);
        return res; 
    }
};
