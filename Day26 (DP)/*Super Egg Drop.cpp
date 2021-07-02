// You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

// You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher 
// than f will break, and any egg dropped at or below floor f will not break.

// Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). 
// If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

// Return the minimum number of moves that you need to determine with certainty what the value of f is.

// Example 1:

// Input: k = 1, n = 2
// Output: 2
// Explanation: 
// Drop the egg from floor 1. If it breaks, we know that f = 0.
// Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
// If it does not break, then we know f = 2.
// Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
// Example 2:

// Input: k = 2, n = 6
// Output: 3

class Solution {
public:
    int find(int k,int n,vector<vector<int>> &memo)
    {   if(n==0||n==1) return n;  //if no. of floor 0 , 1 return n:
        if(k==1) return n;        // if 1 egg return number of floor   
        if(memo[k][n]!=-1) return memo[k][n];
        int ans=1000000,l=1,h=n,temp=0;
     
        while(l<=h)
        {
            int mid=(l+h)/2;
            int left=find(k-1,mid-1,memo);   //egg broken check for down floors of mid
            int right=find(k,n-mid,memo) ;   // not broken check for up floors of mid
            temp=1+max(left,right);          //store max of both 
            if(left<right){                  //since right is more than left and we need more in worst case 
              l=mid+1;                       // so l=mid+1 to gain more temp for worst case : upward
            }
            else                             //left > right so we will go downward 
            {    
                h=mid-1;
            }
            ans=min(ans,temp);               //store minimum attempts
        }
        
        return memo[k][n]=ans;
     
    }
    int superEggDrop(int K, int N) {
        //K -> egg , N -> floor
        vector<vector<int>> memo(K+1,vector<int> (N+1,-1));
        return find(K,N,memo);
         
    }
};

