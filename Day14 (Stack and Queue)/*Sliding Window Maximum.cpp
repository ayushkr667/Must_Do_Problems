// You are given an array of integers nums, there is a sliding window of size k which 
// is moving from the very left of the array to the very right. You can only see the 
// k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]

class Solution {
public:
    //arrange dequeue into descending from front to back
    //which contain only elements of window only
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window; //contains index
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            //remove out of window element
            while(!window.empty() && window.front() <= i-k){
                window.pop_front();
            }
            
            while(!window.empty() && nums[window.back()] <= nums[i])
                window.pop_back();
            
            window.push_back(i);
            if(i >= k-1) res.push_back(nums[window.front()]);
        }
        return res;
    }
};



