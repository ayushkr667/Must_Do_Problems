// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right child pointer points 
// to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 
// Example 1:

// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]
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
    void help(TreeNode* node, vector<TreeNode*>& vec){
        if(node == NULL)
            return;
        
        vec.push_back(node);
        help(node->left, vec);
        help(node->right, vec);
    }
    
    void flatten(TreeNode* root) {
        // vector<TreeNode*> vec;
        // help(root, vec);
        // for(int i=1; i<vec.size(); i++){
        //     root->right = vec[i];
        //     root->left = NULL;
        //     root  = root->right;
        // }
        
        if(!root || (!root->left && !root->right))
           return;
          
        if(root->left != NULL){
            flatten(root->left);
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = NULL;
            
            //go to the right most node of flattened
            TreeNode* t= root->right;
            while(t->right){
                t = t->right;
            }
            
            t->right = temp;
        }
        
        flatten(root->right);
    }
};


