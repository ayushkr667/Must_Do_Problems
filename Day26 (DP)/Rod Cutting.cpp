// Given a rod of length N inches and an array of prices that contains 
// prices of all pieces of size smaller than N. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

// Example 1:

// Input:
// N = 8
// Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
// Output:
// 22
// Explanation:
// The maximum obtainable value is 22 by
// cutting in two pieces of lengths 2 and 
// 6, i.e., 5+17=22.
// Example 2:

// Input:
// N=8
// Price[] = {3, 5, 8, 9, 10, 17, 17, 20}
// Output: 24
// Explanation: 
// The maximum obtainable value is 
// 24 by cutting the rod into 8 pieces 
// of length 1, i.e, 8*3=24. 


class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> val(n+1, INT_MIN); 
        val[0] = 0; 
        int i, j; 
   
       for (i = 1; i<=n; i++) 
       { 
           for (j = 0; j < i; j++) 
                val[i] = max(val[i], price[j] + val[i-j-1]);
       } 
       return val[n];
    }
};
