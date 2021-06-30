// Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.
 

// Example 1:

// Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
// Output: 106
// Explanation:The maximum sum of a
// increasing sequence is obtained from
// {1, 2, 3, 100}
// Example 2:

// Input: N = 3, arr[] = {1, 2, 3}
// Output: 6
// Explanation:The maximum sum of a
// increasing sequence is obtained from
// {1, 2, 3}

class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int dp[n+1];
	    for(int i=0; i<n; i++)
	        dp[i] = arr[i];
	        
	    for(int i=1; i<n; i++){
	        for(int j=0; j<i; j++){
	            if(arr[i] > arr[j])
	                dp[i] = max(dp[j]+arr[i], dp[i]);
	        }
	    }
	    
	    int res = dp[0];
	    for(int i=0; i<n; i++){
	        res = max(res, dp[i]);
	    }
	    return res;
	}  
};
