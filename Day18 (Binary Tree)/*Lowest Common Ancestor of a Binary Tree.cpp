// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined 
// between two nodes p and q as the lowest node in T that has both p and q as descendants 
// (where we allow a node to be a descendant of itself).”

// Example 1:

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.
// Example 2:

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5
// Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself 
// according to the LCA definition.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode* res)
    {
        //lcs already found no neeed to call remaining
        if(res != nullptr)
            return res;
        
        if(node == nullptr)
            return nullptr;
        
        //if any node is found return that to its parent
        if(node == p || node == q)
            return node;
        
        auto left = solve(node->left, p, q, res);
        auto right = solve(node->right, p, q, res);
        
        if(left == nullptr)
            return right;
        
        if(right == nullptr)
            return left;
        
        //if both node are found in left and right branch return root of that
        //here LCS is found
        return res = node;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = nullptr;
        return solve(root, p, q, res);
    }
};
