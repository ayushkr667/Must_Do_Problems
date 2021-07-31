// Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.

// Example 1:

// Input: root = [3,1,4,null,2], k = 1
// Output: 1
// Example 2:

// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3



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
    void solve(TreeNode* node, int& c, int k, int& ans){
        if(!node || c >= k)
            return;
        
        //left
        solve(node->left, c, k, ans);
        
        //root
        c++;
        if(c==k)
            ans = node->val;
        
        //right
        solve(node->right, c, k, ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int c = 0, ans;
        solve(root, c, k, ans);
        return ans;
    }
};

