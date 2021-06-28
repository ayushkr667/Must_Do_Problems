// Given n non-negative integers representing an elevation map where the 
// width of each bar is 1, compute how much water it can trap after raining.

// Example 1:

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by 
// array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         if(!height.size())
//             return 0;
        
//         vector<int>left(height.size(), 0);
//         vector<int>right(height.size(), 0);
        
//         left[0] = height[0];
//         for(int i=1; i<height.size(); i++){
//             left[i] = max(left[i-1], height[i]);
//         }
        
//         right[height.size()-1] = height[height.size()-1];
//         for(int i=height.size()-2; i>=0; i--){
//             right[i] = max(right[i+1], height[i]);
//         }
//         int res = 0;
//         for(int i=0; i<height.size(); i++){
//             res += (min(left[i], right[i]) - height[i] );
//         }
//         return res;
//     }
// };

//ANOTHER APPROACH using 2 POINTER

class Solution {
public:
    int trap(vector<int>& height) {
        if(!height.size())
            return 0;
        
        int l = 0, r = height.size() -1;
        int max_left = 0, max_right = 0;
        int res = 0;
        while(l < r){
            if(height[l] < height[r]){
                if(height[l] > max_left)    max_left = height[l];
                else{
                    res+= (max_left - height[l]);
                    l++;
                }
            }
            else{
                if(height[r] > max_right)   max_right = height[r];
                else{
                    res+= (max_right - height[r]);
                    r--;
                }
            }
        }
        return res;
    }
};
