// Given an array of integers heights representing the histogram's bar height where 
// the width of each bar is 1, return the area of the largest rectangle in the histogram.

// Example 1:

// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:

// Input: heights = [2,4]
// Output: 4

//check for each element(right nxt smaller - left nxt smaller) * height
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        int left_smaller[n];
        int right_smaller[n];
        
        stack<int>st, st1;
        for(int i=0; i<n; i++){
            while((!st.empty()) && h[i] <= h[st.top()]){
                st.pop();
            }
            if(st.empty())
                left_smaller[i] = 0;
            else
                left_smaller[i] = st.top() + 1;
            st.push(i);
        }
        
        //clear stack
        while(!st.empty())
            st.pop();
        
        for(int i=n-1; i>=0; i--){
            while((!st.empty()) && h[i] <= h[st.top()]){
                st.pop();
            }
            if(st.empty())
                right_smaller[i] = n-1;
            else
                right_smaller[i] = st.top()-1;
            st.push(i);
        }
        
        int res = 0;
        for(int i=0; i<n; i++){
            int l = left_smaller[i], r = right_smaller[i];
            res = max(res, (r-l+1)*h[i]);
        }
        
        return res;
    }
};

