// Given the root of a Binary Search Tree and a target number k, 
// return true if there exist two elements in the BST such that 
//their sum is equal to the given target.

// Example 1:

// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true
  
// Example 2:

// Input: root = [5,3,6,2,4,null,7], k = 28
// Output: false

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* node, vector<int>& incr){
        if(node){
            inorder(node->left, incr);
            incr.emplace_back(node->val);
            inorder(node->right, incr);
        }
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(!root || (!root->left && !root->right))
            return false;
        
        vector<int> incr;
        inorder(root, incr);
        
        int n = incr.size();
        int l = 0, r = n-1;
        
        while(l<r){
            if(incr[l] + incr[r] == k)
                return true;
            else if(incr[l] + incr[r] > k)
                r--;
            else 
                l++;
        }
        return false;
    }
};



