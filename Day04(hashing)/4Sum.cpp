// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        int n = nums.size();
        int a, b;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-3; i++){
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
                a = nums[i];
                for(int j = i+1; j<n-2; j++){
                    if(j == i+1 || (j > i+1 && nums[j] != nums[j-1])){
                        b = nums[j];
                        int l = j+1, r = n-1;
                        while(l < r){
                            int sum = a + b + nums[l] + nums[r];
                            if(sum == target){
                                res.push_back({a, b, nums[l], nums[r]});
                                while(l < r && nums[l] == nums[l+1]) l++;
                                while(l < r && nums[r] == nums[r-1]) r--;
                                l++, r--;
                             }
                            else if(sum < target) l++;
                            else r--;
                        }
                    }
                }
            }
        }
        return res;
    }
};

