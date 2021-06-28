// Given an integer array nums, return all the triplets [nums[i], nums[j], 
// nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Example 2:

// Input: nums = []
// Output: []

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3)
            return ans;
        
        sort(nums.begin(), nums.end());
        int num1;
        for(int i=0; i<nums.size()-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            num1 = nums[i];
            int l = i+1, r = nums.size()-1;
            while(l < r){
                int sum = num1 + nums[l] + nums[r];
                if(sum > 0)
                    r--;
                else if(sum < 0)
                    l++;
                else{
                    ans.push_back({num1, nums[l], nums[r]});
                    while(l+1 < r && nums[l] == nums[l+1]) l++;
                    while(l< r-1 && nums[r] == nums[r-1]) r--;
                    l++, r--;
                }
            }
        }
        
        return ans;
    }
};

