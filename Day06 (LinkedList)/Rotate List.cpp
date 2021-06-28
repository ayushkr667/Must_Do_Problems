// Given the head of a linked list, rotate the list to the right by k places.

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Example 2:

// Input: head = [0,1,2], k = 4
// Output: [2,0,1]

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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            prev = curr;
            n++;    curr = curr->next;
        }
        if(n==0 || k%n == 0)
            return head;
        k = k%n;
        int remain = n-k-1;
        curr = head;
        while(remain--)
            curr = curr->next;
        
        ListNode* nh = NULL;
        if(curr)
            nh = curr->next;
        
        curr->next = NULL;
        if(prev)
            prev->next = head;
        
        if(nh)
            return nh;
        return head;
    }
};
