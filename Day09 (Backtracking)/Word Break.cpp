// Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words. 


// Example 1:

// Input:
// n = 12
// B = { "i", "like", "sam", "sung", "samsung", "mobile",
// "ice","cream", "icecream", "man", "go", "mango" }
// A = "ilike"
// Output: 1
// Explanation:The string can be segmented as "i like".

// â€‹Example 2:

// Input:
// n = 12
// B = { "i", "like", "sam", "sung", "samsung", "mobile",
// "ice","cream", "icecream", "man", "go", "mango" }
// A = "ilikesamsung"
// Output: 1
// Explanation: The string can be segmented as 
// "i like samsung" or "i like sam sung".

int solve(int i, string s, unordered_map<string, int>& dict){
        if(i == s.size())
            return 1;
        
        string curr = "";
        for(int j=i; j<s.size(); j++){
            curr += s[j]; 
            if(dict[curr] && solve(j+1, s, dict))
                return 1;
        }
        
        return 0;
    }
    
    int wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> dict;
        for(auto word: wordDict){
            dict[word] = 1;
        }
        return solve(0, s, dict);
    }
