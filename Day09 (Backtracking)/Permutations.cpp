// Given an array nums of distinct integers, return all the possible permutations. 
// You can return the answer in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

class Solution {
public:
    void solve(int i, int n, vector<int>nums, vector<vector<int>>&res){
        if(i == n-1){
            res.push_back(nums);
            return;
        }
        
        for(int j = i; j<n; j++){
            swap(nums[i], nums[j]);
            solve(i+1, n, nums, res);
            swap(nums[i], nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        solve(0, n, nums, res);
        return res;
    }
};
