// Given two integer arrays A and B of size N each which represent values and weights associated with N items respectively.

// Also given an integer C which represents knapsack capacity.

// Find out the maximum value subset of A such that sum of the weights of this subset is smaller than or equal to C.

// NOTE:

// You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

// Input Format
// First argument is an integer array A of size N denoting the values on N items.

// Second argument is an integer array B of size N denoting the weights on N items.

// Third argument is an integer C denoting the knapsack capacity.

// Output Format
// Return a single integer denoting the maximum value subset of A such that sum of the weights of this subset is smaller than or equal to C.

// Example Input
// Input 1:

//  A = [60, 100, 120]
//  B = [10, 20, 30]
//  C = 50
// Input 2:

//  A = [10, 20, 30, 40]
//  B = [12, 13, 15, 19]
//  C = 10

// Example Output
// Output 1:

//  220
// Output 2:
//  0

// Example Explanation
// Explanation 1:

// Taking items with weight 20 and 30 will give us the maximum value i.e 100 + 120 = 220
// Explanation 2:

// Knapsack capacity is 10 but each item has weight greater than 10 so no items can be considered in the knapsack therefore answer is 0.


int solve1(int w, vector<int>& wt, vector<int>& val, int n, vector<vector<int>>& dp){
    if((n < 0)||(w==0))
        return 0;

    if(dp[n][w] != -1)
        return dp[n][w];
    
    if(wt[n] >w)
        return dp[n][w] = solve1(w, wt, val, n-1, dp);

    else
        return dp[n][w] = max(
            val[n]+ solve1(w-wt[n], wt, val, n-1, dp),
            solve1(w, wt, val, n-1, dp));
}

int solveTabulation(int w, vector<int>& wt, vector<int>& val, int n)
{
    int t[n+1][w+1];//to store dp
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=w; j++)
        {
            //base condition changes to initialization
            if(i==0 || j==0)
                t[i][j] =0;
            
            else if(wt[i-1] <= j)
                t[i][j] = max( val[i-1]+ t[i-1][j-wt[i-1]],
                    t[i-1][j]);

            else
                t[i][j] =  t[i-1][j];
        }
    }
  return t[n][w];  
}


int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    // vector<vector<int>> dp(n+1, vector<int>(C+1, -1));
    // return solve1(C, B, A, n-1, dp);
    return solveTabulation(C, B, A, n);
}
