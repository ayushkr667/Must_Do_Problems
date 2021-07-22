// Given a binary tree, print the bottom view from left to right.
// A node is included in bottom view if it can be seen when we look at the tree from bottom.

//                       20
//                     /    \
//                   8       22
//                 /   \        \
//               5      3       25
//                     /   \      
//                   10    14

// For the above tree, the bottom view is 5 10 3 14 25.
// If there are multiple bottom-most nodes for a horizontal distance from root, then print the 
// later one in level traversal. For example, in the below diagram, 3 and 4 are both the 
// nodes at horizontal distance 0, we need to print 4.

//                       20
//                     /    \
//                   8       22
//                 /   \     /   \
//               5      3 4     25
//                      /    \      
//                  10       14

//For the above tree the output should be 5 10 4 14 25


//O(n)...use array instead of map...with manipulation of negative key;


//O(nlogn)
class Solution {
  public:
    vector<int> bottomView(Node *root)
    {
        map<int, int> mp;
        vector<int> res;
        if(!root)
            return res;
            
        queue<pair<Node*, int>> Q;
        Q.push({root, 0});
        while(!Q.empty()){
            int n = Q.size();
            while(n--){
                auto t = Q.front();  Q.pop();
                auto temp = t.first;
                auto key = t.second;
                
                mp[key] = temp->data;
                    
                if(temp->left)
                    Q.push({temp->left, key-1});
                if(temp->right)
                    Q.push({temp->right, key+1});
            }
        }
        for(auto it = mp.begin(); it!=mp.end(); it++){
            res.push_back(it->second);       
        }
        return res;
    }

};

