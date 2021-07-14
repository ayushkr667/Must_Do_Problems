// Given a collection of candidate numbers (candidates) and a target number (target), 
// find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]

class Solution {
public:
    void solve(int i, int sum, int t, int n, vector<int>&curr, vector<vector<int>> &res, vector<int> cd){
        if(sum == t){
            res.push_back(curr);
            return;
        }
        
        for(int j = i; j<n; j++){
            if(sum + cd[j] <= t){
                curr.push_back(cd[j]);
                solve(j+1, sum+cd[j], t, n, curr, res, cd);
                curr.pop_back();
                //to remove duplicate
                while(j < n-1 && cd[j] == cd[j+1])
                    j++;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        int n = candidates.size();
        solve(0, 0, target, n, curr, res, candidates);
        return res;
    }
};
