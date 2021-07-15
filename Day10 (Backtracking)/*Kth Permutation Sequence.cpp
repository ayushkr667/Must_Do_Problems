// The set [1,2,3,…,n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order,

// We get the following sequence (ie, for n = 3 ) :

// 1. "123"
// 2. "132"
// 3. "213"
// 4. "231"
// 5. "312"
// 6. "321"
// Given n and k, return the kth permutation sequence.

// For example, given n = 3, k = 4, ans = "231"
  
  


//BACKTRACKING (TLE):
class Solution {
public:
    void solve(int i, string s, vector<string>& res){
        if(i == s.size()-1){
            res.push_back(s);
            return;
        }
        
        for(int j = i; j<s.size(); j++){
            swap(s[i], s[j]);
            solve(i+1, s, res);
            swap(s[i], s[j]);
        }
            
    }
    string getPermutation(int n, int k) {
        string s = "";
        
        for(int i=1; i<=n; i++)
            s += to_string(i);
        
        vector<string> res;
        solve(0, s, res);
        
        sort(res.begin(), res.end());
        return res[k-1];
    }
};


//EFFICIENT ( O( n*n) )
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> num;
        
        for(int i=1; i<n; i++){
            fact *= i;
            num.push_back(i);
        }
        
        num.push_back(n);
        string res = "";
        k = k -1; // 0 based index
        while(true){
            //got the number at index position start from 1st
            res += to_string( num[k/fact] ); 
            num.erase(num.begin() + (k/fact) );
            if(num.size() == 0)
                break;
            k = k % fact;
            fact = fact / num.size();
        }
        return res;
    }
};
