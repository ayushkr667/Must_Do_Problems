// Given an array of integers A and an integer B.

// Find the total number of subarrays having bitwise XOR of all elements equals to B.
  
// Example Input
// Input 1:

//  A = [4, 2, 2, 6, 4]
//  B = 6
// Input 2:

//  A = [5, 6, 7, 8, 9]
//  B = 5


// Example Output
// Output 1:

//  4
// Output 2:

//  2


// Example Explanation
// Explanation 1:

//  The subarrays having XOR of their elements as 6 are:
//  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
// Explanation 2:

//  The subarrays having XOR of their elements as 2 are [5] and [5, 6, 7, 8, 9]

int Solution::solve(vector<int> &A, int B) {
    int count = 0;
    int dp[A.size()];
    dp[0] = A[0];
    
    //store prefix xor 
    for(int i=1; i<A.size(); i++){
        dp[i] = dp[i-1]^A[i];
    }
    
    unordered_map<int, int> mp;
    
    for(int i=0; i<A.size(); i++){
        //calculate  B xor prefix
        int temp = B ^ dp[i];
        
        // If above XOR exists in map, then there
        // is another previous prefix with same
        // XOR, i.e., there is a subarray ending
        // at i with XOR equal to B.
        //as, A ^ B = C then A ^ C = B.
        // A is from 0......i and C is 0.....j < i
        //then B = j+1....i
        count = count + mp[temp];
        
        // If this subarray has XOR equal to B itself.
        if (dp[i] == B)
            count++;
            
        // Add the XOR of this subarray to the map
        mp[ dp[i] ]++;
    }
    
    return count;
}

