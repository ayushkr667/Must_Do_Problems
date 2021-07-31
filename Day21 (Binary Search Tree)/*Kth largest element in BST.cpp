// Given a Binary search tree. Your task is to complete the function 
// which will return the Kth largest element without doing any modification in Binary Search Tree.
  
// Example 1:

// Input:
//       4
//     /   \
//    2     9
// k = 2 
// Output: 4

// Example 2:

// Input:
//        9
//         \ 
//           10
// K = 1
// Output: 10

/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    private:
    void solve(Node* node, int& c, int k, int& ans){
        if(!node || c > k)
            return;
            
        solve(node->right, c, k, ans); //right
        
        c++;
        if(c == k) //root
            ans = node->data;
        
        solve(node->left, c, k, ans);//left
    }
    
    public:
    int kthLargest(Node *root, int k)
    {
        int c = 0, ans;
        solve(root, c, k, ans);
        return ans;
    }
};


