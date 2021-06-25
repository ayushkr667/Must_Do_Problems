// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

 

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i:nums){
            mp[i] = 1;
        }
        int res = 0;
        for(auto num: mp){
            int temp = num.first;
            if(mp.find(temp-1) == mp.end()){
                int count = 0;
                while(mp.find(temp) != mp.end()){
                    count++;
                    temp++;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};

