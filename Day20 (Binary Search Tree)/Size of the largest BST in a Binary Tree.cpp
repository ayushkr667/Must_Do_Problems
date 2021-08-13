// Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
// Note: Here Size is equal to the number of nodes in the subtree.

// Example 1:

// Input:
//         1
//       /   \
//      4     4
//    /   \
//   6     8
// Output: 1
// Explanation: There's no sub-tree with size
// greater than 1 which forms a BST. All the
// leaf Nodes are the BSTs with size equal
// to 1.
// Example 2:

// Input: 6 6 3 N 2 9 3 N 8 8 2
//             6
//         /       \
//        6         3
//         \      /   \
//          2    9     3
//           \  /  \
//           8 8    2 
// Output: 2
// Explanation: The following sub-tree is a
// BST of size 2: 
//        2
//     /    \ 
//    N      8






/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
struct details{
    int size, max, min, ans;
    bool is_bst;
};

details solve(Node* root){
    //empty
    if(!root)
        return {0, INT_MIN, INT_MAX, 0, true};
    //one node   
    if (root->left == NULL && root->right == NULL)
        return {1, root->data, root->data, 1, true};
        
    details l = solve(root->left);
    details r = solve(root->right);
    
    details ret;
    ret.size = (1 + l.size + r.size);
    
    if (l.is_bst && r.is_bst && l.max < root->data && r.min > root->data)
    {
        ret.min = min(l.min, min(r.min, root->data));
        ret.max = max(r.max, max(l.max, root->data));
 
        // Update answer for tree rooted under
        // current 'root'
        ret.ans = ret.size;
        ret.is_bst = true;
 
        return ret;
    }
 
    // If whole tree is not BST, return maximum
    // of left and right subtrees
    ret.ans = max(l.ans, r.ans);
    ret.is_bst = false;
 
    return ret;
}

int largestBst(Node *root)
{
	details sol = solve(root);
	return sol.ans;
}
