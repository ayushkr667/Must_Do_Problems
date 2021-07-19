// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string 
// should only have a single space separating the words. Do not include any extra spaces.
 
// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.

// class Solution {
// public:
//     string reverseWords(string s) {
//         vector<string> vec;
//         string temp ="";
//         for(int i=0; i<s.size(); i++){
//             if(s[i] != ' ')
//                 temp += s[i];
//             else {
//                 if(temp.size()){
//                     vec.push_back(temp);
//                 }
//                 temp = "";
//             }
//         }
//         if(temp.size())
//             vec.push_back(temp);
        
//         string res = "";
//         for(int i=vec.size()-1; i>=0; i--){
//             if(i == vec.size()-1){
//                 res += vec[i]; continue;
//             }
//             res = res + " " + vec[i];
//         }
//         return res;
//     }
// };


//O(1) space
class Solution {
public:
    string reverseWords(string &s) {
        int i, len, start, end;
        // remove leading spaces
        for (i = 0; i < s.size() && ' ' == s[i]; i++)
            ;
        start = i;
        // remove trailing spaces
        for (i = s.size() - 1; i >= 0 && ' ' == s[i]; i--)
            ;
        end = i;
        // remove multiple spaces btw. words
        for (i = start, len = 0; i <= end; i++) {
            if (' ' == s[i] && ' ' == s[i - 1])
                continue;
            s[len++] = s[i];
        }
        s.resize(len);

        reverse(s.begin(), s.end());
        for (i = 0, start = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        // last word
        reverse(s.begin() + start, s.end());
        return s;
    }
};
