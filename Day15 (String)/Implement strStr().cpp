// O(m*n)
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int m = haystack.size(), n = needle.size();
//         for (int i = 0; i <= m - n; i++) {
//             int j = 0;
//             for (; j < n; j++) {
//                 if (haystack[i + j] != needle[j]) {
//                     break;
//                 }
//             }
//             if (j == n) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };


// //we can solve this(find a string inside other string) by using Rabin karp algorithm also
//     //-> basic idea of rabin carp is to use hash code to avoid checking again
//     //-> and again. O(n-m+1) is best case still worset case is O(m*n)
// 99991 is prime number , modding to get rid of overflow
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(!needle.size())
            return 0;
        long long hashFn = 0;
        long long sub = 1;
        
        //calculating hash function 
        for(int i=0; i<needle.size(); i++){
            long long temp = (needle[i] - 'a' + 1);
            hashFn = ((hashFn*10)%(99991) + temp)%(99991);
            if(i > 0)
                sub = (sub * 10)%(99991);
        }
        
        long long value = 0;
        int st = 0;
        for(int i=0; i<haystack.size(); i++){
            long long temp = (haystack[i] - 'a' + 1);
            value = ((value*10)%(INT_MAX - 1) + temp)%(99991);
            if(value < 0)
                value += 99991;
            
            if(i >= needle.size() -1){
                //then compare each character of string
                if(value == hashFn){
                    bool flag = true;
                    int l, l1;
                    for(l = st, l1=0; l < haystack.size() && l1 < needle.size(); l++, l1++){
                        if(haystack[l] != needle[l1]){
                            flag = false;
                            break;
                        }
                    }
                    
                    if(flag && l1 == needle.size())
                        return st;
                }
                value -= ((haystack[st] - 'a' + 1) * sub);
                st++;
            }
        }
        return -1;
    }
};



//ANOTHER solution is KMP search which has O(m+n)
