// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along 
// the longest path from the root node down to the farthest leaf node.
 
// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: 3
// Example 2:

// Input: root = [1,null,2]
// Output: 2

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
    // void calc(TreeNode* node, int level, int& res){
    //     if(node == NULL){
    //         res = max(res, level);
    //         return;
    //     }
    //     calc(node->left, level+1, res);
    //     calc(node->right, level+1, res);
    // }
    
    int maxDepth(TreeNode* root) {
        // int res = 0;
        // calc(root, 0, res);
        if(root == NULL)
            return 0;
        int lh = 1 + maxDepth(root->left);
        int lr = 1 + maxDepth(root->right);
        return max(lh, lr);
    }
};
