// Given the root of a binary tree, return the level order 
// traversal of its nodes' values. (i.e., from left to right, level by level).

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        
        queue<TreeNode*> Q;
        vector<vector<int>> res;
        Q.push(root);
        while(!Q.empty()){
            
            int n = Q.size();
            vector<int> temp(n);
            
            for(int i=0; i<n; i++){
                auto t = Q.front(); Q.pop();
                temp[i] = t->val;
                
                if(t->left)
                    Q.push(t->left);
                if(t->right)
                    Q.push(t->right);
            }
            
            res.push_back(temp);
        }
        return res;
    }
};
