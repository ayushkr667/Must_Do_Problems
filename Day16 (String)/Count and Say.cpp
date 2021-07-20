// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

// countAndSay(1) = "1"
// countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), 
// which is then converted into a different digit string.
// To determine how you "say" a digit string, split it into the minimal number of 
// groups so that each group is a contiguous section all of the same character. 
// Then for each group, say the number of characters, then say the character. 
// To convert the saying into a digit string, replace the counts with a number and concatenate every saying.
// For example, the saying and conversion for digit string "3322251":

// Given a positive integer n, return the nth term of the count-and-say sequence.

// Example 1:

// Input: n = 1
// Output: "1"
// Explanation: This is the base case.
// Example 2:

// Input: n = 4
// Output: "1211"
// Explanation:
// countAndSay(1) = "1"
// countAndSay(2) = say "1" = one 1 = "11"
// countAndSay(3) = say "11" = two 1's = "21"
// countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"

class Solution {
public:
    string countAndSay(int n)
    {
        string curr_str;

        // The initial case, when n = 1
        curr_str += '1';

        // The iterative case, when n > 1
        for (int i = 0; i < n - 1; i++)
        {
            string buffer;

            // Handle the current string
            int index = 0;
            for (int index = 0; index < curr_str.size(); ++index)
            {
                // Count the occurance of each digit
                int cnt = 1; // At least one occurance

                while (index + 1 < curr_str.size() and curr_str[index + 1] == curr_str[index]) 
                {
                    index++;
                    cnt++;
                }

                buffer.push_back(cnt + '0');
                buffer.push_back(curr_str[index]);
            }

            // Update the current string
            curr_str = buffer;
        }

        return curr_str;
    }
};
