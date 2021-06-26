// Given the head of a linked list, remove the nth node from the end of the list and return its head.
  
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL)
            return NULL;
        
        ListNode* curr = head;
        ListNode* last = head;
        
        while(n--){
            last = last->next;
        }
        
        if(last == NULL)
            return curr->next;
        
        while(last->next != NULL){
            last = last->next;
            curr = curr->next;
        }
        
        ListNode* temp = curr->next->next;
        curr->next = temp;
        return head;
    }
};
