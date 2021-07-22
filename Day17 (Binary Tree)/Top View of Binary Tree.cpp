// Given below is a binary tree. The task is to print the top view of binary tree. 
// Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree
//        1
//     /     \
//    2       3
//   /  \    /   \
// 4    5  6   7

// Top view will be: 4 2 1 3 7
// Note: Return nodes from leftmost node to rightmost node.

// Example 1:

// Input:
//       1
//    /    \
//   2      3
// Output: 2 1 3
// Example 2:

// Input:
//        10
//     /      \
//   20        30
//  /   \    /    \
// 40   60  90    100
// Output: 40 20 10 30 100

// O(n)

class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        vector<int> res;
        if(!root)
            return res;
            
        queue<pair<Node*, int>> Q;
        Q.push({root, 0});
        
        int max_left  = 0, max_right = 0;
        vector<int> lft, rit;
        rit.push_back(root->data);
        
        while(!Q.empty()){
            int n = Q.size();
            while(n--){
                auto t = Q.front();  Q.pop();
                auto temp = t.first;
                auto key = t.second;
                if(key < max_left){
                    max_left = key;
                    lft.push_back(temp->data);
                }
                if(key > max_right){
                    max_right = key;
                    rit.push_back(temp->data);
                }
                    
                if(temp->left)
                    Q.push({temp->left, key-1});
                if(temp->right)
                    Q.push({temp->right, key+1});
            }
        }
        for(int i=lft.size()-1; i>=0; i--){
            res.push_back(lft[i]);
        }
        for(auto i: rit){
            res.push_back(i);
        }
        return res;
    }

};


// O(nlog n)
// class Solution
// {
//     public:
//     vector<int> topView(Node *root)
//     {
//         map<int, int> mp;
//         vector<int> res;
//         if(!root)
//             return res;
            
//         queue<pair<Node*, int>> Q;
//         Q.push({root, 0});
//         while(!Q.empty()){
//             int n = Q.size();
//             while(n--){
//                 auto t = Q.front();  Q.pop();
//                 auto temp = t.first;
//                 auto key = t.second;
//                 if(mp.find(key) == mp.end())
//                     mp[key] = temp->data;                   
//                 if(temp->left)
//                     Q.push({temp->left, key-1});
//                 if(temp->right)
//                     Q.push({temp->right, key+1});
//             }
//         }
//         for(auto it = mp.begin(); it!=mp.end(); it++){
//             res.push_back(it->second);       
//         }
//         return res;
//     }
// };
