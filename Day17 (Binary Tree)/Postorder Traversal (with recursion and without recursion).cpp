// Given the root of a binary tree, return the postorder traversal of its nodes' values.

// Example 1:

// Input: root = [1,null,2,3]
// Output: [3,2,1]
// Example 2:

// Input: root = []
// Output: []

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
    void solveRecursive(TreeNode* root, vector<int>& res){
        if(!root)
            return;
        solveRecursive(root->left, res);
        solveRecursive(root->right, res);
        res.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        // solveRecursive(root, res);
        stack<TreeNode*> st1, st2;
        TreeNode* curr = root;
        
        if(!root)
            return res;
        
        st1.push(curr);
        
        while(!st1.empty()){
            auto temp = st1.top();
            st1.pop();
            st2.push(temp);
            
            if(temp->left)
                st1.push(temp->left);
            if(temp->right)
                st1.push(temp->right);
        }
        
        while(!st2.empty()){
            curr = st2.top();
            res.push_back(curr->val);
            st2.pop();
        }
        return res;
    }
};
