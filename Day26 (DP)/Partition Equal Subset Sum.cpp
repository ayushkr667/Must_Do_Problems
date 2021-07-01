// Given a non-empty array nums containing only positive integers, find 
// if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto n: nums){
            sum += n;
        }
        
        if(sum%2)
            return false;
        
        int r_sum = sum/2;
        bool dp[nums.size()+1][r_sum+1];
        
        for(int i=0; i<=nums.size(); i++){
            for(int j=0; j<=r_sum; j++){
                if(i == 0)
                    dp[i][j] = false;
                else if(j == 0)
                    dp[i][j] = true;
                else if(nums[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[nums.size()][r_sum];
    }
};

