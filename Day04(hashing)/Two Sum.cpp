// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Output: Because nums[0] + nums[1] == 9, we return [0, 1].
[arbitrary case-insensitive reference text]: https://www.mozilla.org

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            int val = target - nums[i];
            if(mp.find(val) == mp.end()){
                mp[nums[i]] = i;
            }else{
                res = vector<int>{mp[val], i};
                break;
            }
        }
        return res;
    }
};
