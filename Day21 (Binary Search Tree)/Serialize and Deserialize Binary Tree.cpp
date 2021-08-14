// Serialization is the process of converting a data structure or object into a sequence of bits
//so that it can be stored in a file or memory buffer, or transmitted across a network connection 
//link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how 
//your serialization/deserialization algorithm should work. You just need to ensure that a binary 
//tree can be serialized to a string and this string can be deserialized to the original tree structure.

// Clarification: The input/output format is the same as how LeetCode serializes a binary tree. 
//You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

// Example 1:

// Input: root = [1,2,3,null,null,4,5]
// Output: [1,2,3,null,null,4,5]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "X";
        
        string l = serialize(root->left);
        string r = serialize(root->right);
        
        return (to_string(root->val) + "," + l + "," + r);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(!data.size())
            return NULL;
        
        queue<string> nodeVals;
        string temp;
        for(int i=0; i<data.size(); i++){
            if(data[i] == ','){
                nodeVals.push(temp);
                temp.clear();
            }
            else{
                temp+=data[i]; 
            }   
        }
        nodeVals.push(temp);
        
        return helper(nodeVals);
    }
    
    TreeNode* helper(queue<string>& Q){
        string val = Q.front();
        Q.pop();
        if(val == "X")
            return NULL;
        
        int temp = stoi(val);
        TreeNode* node = new TreeNode(temp);
        
        node->left = helper(Q);
        node->right = helper(Q);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));






