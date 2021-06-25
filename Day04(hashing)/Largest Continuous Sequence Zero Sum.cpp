// Find the largest continuous sequence in a array which sums to zero.

// Example:


// Input:  {1 ,2 ,-2 ,4 ,-4}
// Output: {2 ,-2 ,4 ,-4}

vector<int> Solution::lszero(vector<int> &A) {
    unordered_map<int, int> mp;
    int sum = 0;
    int larg_length = 0;
    int begining = -1;
    for(int i=0; i<A.size(); i++)
    {
        sum += A[i];
        if( sum == 0){
            larg_length = i+1;
            begining = -1;
        }
        
        if( mp.find(sum) != mp.end() ){
            int len = i - mp[sum];
            if( len  > larg_length ){
                begining = mp[sum];
                larg_length = len;
            }
        }
        else
            mp[sum] = i;
    }
    vector<int> res;
    for(int i = 1; i<=larg_length; i++){
        res.push_back( A[begining+i] );
    }
    return res;
}
