// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a 
// binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

// Example 1:

// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: inorder = [-1], postorder = [-1]
// Output: [-1]

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

//NOTE : we can use unordered map to find index 
//but it will work only for distinct element
class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& root_id, int left, int right){
        if(left > right) return NULL;
        
        int curr = left; 
        
        //pos of root id element in inorder
        while(inorder[curr] != preorder[root_id]) curr++;
        
        TreeNode* newNode = new TreeNode(preorder[root_id]);
        root_id--;
        
        //right subtree first
        newNode->right = build(preorder, inorder, root_id, curr+1, right);
        
        
        //left sub tree
        newNode->left = build(preorder, inorder, root_id, left, curr-1);
        
        return newNode;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int root_index = inorder.size()-1;
        return build(postorder, inorder, root_index, 0, inorder.size()-1);
    }
};

