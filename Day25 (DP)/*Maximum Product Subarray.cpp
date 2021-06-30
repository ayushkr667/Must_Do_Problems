// Given an integer array nums, find a contiguous non-empty subarray 
//within the array that has the largest product, and return the product.

// It is guaranteed that the answer will fit in a 32-bit integer.

// A subarray is a contiguous subsequence of the array.

 

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int max_till_i = res;
        int min_till_i = res;
        
        for(int i=1; i<n; i++){
            //because now max will give min as num is negative ansd vice versa
            if (nums[i] < 0)
                swap(max_till_i, min_till_i);
            
            //leave or take that number
            max_till_i = max(nums[i], max_till_i*nums[i]);
            min_till_i = min(nums[i], min_till_i*nums[i]);
            
            res = max(max_till_i, res);
        }
        return res;
    }
};
