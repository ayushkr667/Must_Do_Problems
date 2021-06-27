// Given the head of a singly linked list, return true if it is a palindrome.

// Example 1:

// Input: head = [1,2,2,1]
// Output: true
// Example 2:

// Input: head = [1,2]
// Output: false

// Constraints:

// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9 

// Follow up: Could you do it in O(n) time and O(1) space?

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        //first find the middle of the link list
        //then reverse right half of link list
        //then compare 1 pointer from head and one from middle
        if(head == NULL)
            return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow-> next;
        }
        
        //slow is at middle reverse right half
        ListNode* reverse_head = reverse(slow);
        
        while(head && reverse_head){
            if(head->val != reverse_head->val)
                return false;
            head = head->next;
            reverse_head = reverse_head->next;
        }
        return true;
    }
};
