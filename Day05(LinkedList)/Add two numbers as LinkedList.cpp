// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. 
// Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

// Example 1:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
  
// Example 2:
// Input: l1 = [0], l2 = [0]
// Output: [0]

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = new ListNode(0);
        ListNode* head = curr;
        
        int carry = 0;
        while(l1 != NULL || l2 != NULL){
            int a, b;
            if(l1 == NULL)
                a = 0;
            else{
                a = l1->val;     l1 = l1->next;
            }
            
            if(l2 == NULL)
                b = 0;
            else{
                b = l2->val;      l2 = l2->next;
            }
                   
            ListNode* temp = new ListNode((a+b+carry)%10);
            carry = (a+b+carry)/10;
            curr->next = temp;
            curr = curr->next;
        }
        if(carry){
            ListNode* temp = new ListNode(carry);
            curr->next = temp;
        }
        return head->next;
    }
};
