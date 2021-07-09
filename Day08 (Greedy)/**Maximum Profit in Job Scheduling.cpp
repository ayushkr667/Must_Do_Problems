// We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

// You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

// If you choose a job that ends at time X you will be able to start another job that starts at time X.

// Example 1:

// Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
// Output: 120
// Explanation: The subset chosen is the first and fourth job. 
// Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
// Example 2:

// Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
// Output: 150
// Explanation: The subset chosen is the first, fourth and fifth job. 
// Profit obtained 150 = 20 + 70 + 60.


//Complexity n log n

// class Solution {
// public:
//     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//         int n = profit.size();
//         vector<vector<int>> jobs;
//         for (int i = 0; i < n; ++i) {
//             jobs.push_back({endTime[i], startTime[i], profit[i]});
//         }
        
//         sort(jobs.begin(), jobs.end());
        
//         map<int, int> dp = {{0, 0}};
//         for (auto& job : jobs) {
//         //upper bound: first element which has endtime greater than start time of this
//             int cur = prev(dp.upper_bound(job[1]))->second + job[2];
            
//             //update last
//             if (cur > dp.rbegin()->second)
//                 dp[job[0]] = cur;
//         }
//         return dp.rbegin()->second;
//     }
// };







//ANOTHER APPROACH

class Solution {
public:
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
        int n = profit.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        vector<int> dp(n, 0);
        
        dp[0] = jobs[0][2];
        
        for(int i=1; i<n; i++){
            dp[i] = jobs[i][2];
            //find last non-overlapping job that ends before start of this current 
            //job and record max profit up to j, dp[j]
            int f = 0;
            for (int j = i - 1; j >= 0; j--) 
                if (jobs[j][0] <= jobs[i][1])
                    {f = dp[j]; break;}
		    
            //last max profit calculated from 0 .. i-1
            //current profit and max profit up to last non-overlapping job
            dp[i] = max(dp[i-1], f + jobs[i][2]);
        }
        
        return dp[n-1];
    }
};
