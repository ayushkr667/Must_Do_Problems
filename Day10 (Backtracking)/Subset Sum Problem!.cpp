// Given an integer array A of size N.

// You are also given an integer B, you need to find whether their exist a subset in A whose sum equal B.

// If there exist a subset then return 1 else return 0.



// Problem Constraints
// 1 <= N <= 100

// 1 <= A[i] <= 100

// 1 <= B <= 105



// Input Format
// First argument is an integer array A.

// Second argument is an integer B.



// Output Format
// Return 1 if there exist a subset with sum B else return 0.



// Example Input
// Input 1:

//  A = [3, 34, 4, 12, 5, 2]
//  B = 9
// Input 2:

//  A = [3, 34, 4, 12, 5, 2]
//  B = 30


// Example Output
// Output 1:

//  1
// Output 2:

//  0


// Example Explanation
// Explanation 1:

//  There is a subset (4, 5) with sum 9.
// Explanation 2:

//  There is no subset that add up to 30.


unordered_map<string, bool> dp;
bool issubsetsum(vector<int>&arr, int n, int sum)
{
    if(sum==0)
        return true;
        
    string key = to_string(n) + " " + to_string(sum);
    if(dp.find(key) != dp.end())
        return dp[key];
        
    if(sum!=0 && n ==0)
        return dp[key] = false;
        
    else
    {
        //not included in subset for sure
        if(arr[n-1]>sum)
            return dp[key] = issubsetsum( arr, n-1, sum);

        else//either include or not
        {
            return dp[key] = (issubsetsum(arr, n-1, sum-arr[n-1])
                || issubsetsum(arr, n-1, sum));
        }
        
    } 
}

int Solution::solve(vector<int> &A, int B) {
    return issubsetsum(A, A.size(), B);
}
