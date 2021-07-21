// Given a Binary Tree, print Left view of it. Left view of a Binary 
// Tree is set of nodes visible when tree is visited from Left side. 
// The task is to complete the function leftView(), which accepts root of the tree as argument.

// Left view of following tree is 1 2 4 8.

//           1
//        /     \
//      2        3
//    /     \    /    \
//   4     5   6    7
//    \
//      8   

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> res;
    if(!root)
        return res;
        
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty()){
        int n = Q.size();
        
        for(int i=0; i<n; i++){
            auto temp = Q.front();
            Q.pop();
            
            if(i==0)
                res.push_back(temp->data);
                
            if(temp->left)
                Q.push(temp->left);
            if(temp->right)
                Q.push(temp->right);
        }
    }
    return res;
}
