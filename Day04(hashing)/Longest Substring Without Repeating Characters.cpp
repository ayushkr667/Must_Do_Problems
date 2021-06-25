// Given a string s, find the length of the longest substring without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.


int Solution::lengthOfLongestSubstring(string A) {
    map<char, int> mp;
    int longest  = 1, temp =-1;
    for(int i=0; i<A.size(); i++)
    {
        //if it is previously found at k th location.
        if(mp.find( A[i] ) != mp.end() )
        {
            //temp will tell that we are not going backward
            //means repeating element previously occur at let 8
            //and now at 4 so. we do not need to go back at 4 simply, 
            //update from 8 only.
            temp = max( temp, mp[ A[i] ] );
        }
        
        longest = max(longest, (i - temp) );
        mp[ A[i] ] = i;
    }
    return longest;
}

