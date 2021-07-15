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


//EFFICIENT
class Solution {
public:
    int findFirstNumIndex(int& k, int n)
    {

        if (n == 1)
            return 0;
        n--;

        int first_num_index;
        // n_actual_fact = n!
        int n_partial_fact = n;

        while (k >= n_partial_fact
               && n > 1) {
            n_partial_fact
                = n_partial_fact
                  * (n - 1);
            n--;
        }

        // First position of the
        // kth sequence will be
        // occupied by the number present
        // at index = k / (n-1)!
        first_num_index = k / n_partial_fact;

        k = k % n_partial_fact;

        return first_num_index;
    }


    string getPermutation(int n, int k) {
        string ans = "";

        vector<int> s;

        // Insert all natural number
        // upto n in set
        for (int i = 1; i <= n; i++)
            s.push_back(i);


        //NOTE : subtract 1 to get 0 based indexing
        k = k - 1;

        for (int i = 0; i < n; i++) {

            int index
                = findFirstNumIndex(k, n - i);

            // itr now points to the
            // number at index in set s
            ans += (to_string(s[index]));

            // remove current number from the set
            s.erase(s.begin() + index);

        }
        return ans;
    }
};
