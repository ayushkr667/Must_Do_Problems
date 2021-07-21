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
            return ;
        
        res.push_back(root->val);
        solveRecursive(root->left, res);
        solveRecursive(root->right, res);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        // solveRecursive(root, res);
        
        stack<TreeNode* > st;
        TreeNode* curr = root;
        
        // while(curr || !st.empty()){
        //     while(curr){
        //         //root
        //         res.push_back(curr->val);
        //         if(curr->right)
        //             st.push(curr->right);
        //         //left
        //         curr = curr->left;
        //     }
        //     //right
        //     if(!st.empty()){
        //         curr = st.top();
        //         st.pop();
        //     }
        // }
        
        if(!root)
            return res;
        
        st.push(curr);
        while(!st.empty()){
            auto temp = st.top();
            st.pop();
            res.push_back(temp->val);
            
            if(temp->right)
                st.push(temp->right);
            if(temp->left)
                st.push(temp->left);
        }
        return  res;
    }
};
