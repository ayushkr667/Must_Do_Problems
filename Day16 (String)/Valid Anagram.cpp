// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26);
        for(int i=0; i<s.size(); i++){
            count[s[i] - 'a']++;
        }
        for(int i=0; i<t.size(); i++){
            count[t[i] - 'a']--;
        }
        for(int i=0; i<26; i++){
            if(count[i])
               return false; 
        }
        return true;
    }
};
