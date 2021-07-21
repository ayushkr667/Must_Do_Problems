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
        if(root == NULL)
            return;
        
        solveRecursive(root->left, res);
        res.push_back(root->val);
        solveRecursive(root->right, res);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        // solveRecursive(root, res);
        
        //iterative
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr || (!st.empty())){
            while(curr){
                st.push(curr);
                curr = curr -> left;
            }
            curr = st.top();
            st.pop();
            res.push_back(curr->val);
            cout << curr->val << " ";
            curr = curr->right;
        }
        return res;
    }
};

