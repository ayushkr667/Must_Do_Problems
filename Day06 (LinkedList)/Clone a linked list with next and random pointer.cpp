// You are given a special linked list with N nodes where each node has a next 
// pointer pointing to its next node. You are also given M random pointers , 
// where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b.

// ArbitLinked List1

// Example 1:

// Input:
// N = 4, M = 2
// value = {1,2,3,4}
// pairs = {{1,2},{2,4}}
// Output: 1
// Explanation: In this test case, there
// re 4 nodes in linked list.  Among these
// 4 nodes,  2 nodes have arbit pointer
// set, rest two nodes have arbit pointer
// as NULL. Second line tells us the value
// of four nodes. The third line gives the
// information about arbitrary pointers.
// The first node arbit pointer is set to
// node 2.  The second node arbit pointer
// is set to node 4.
// Example 2:

// Input:
// N = 4, M = 2
// value[] = {1,3,5,9}
// pairs[] = {{1,1},{3,4}}
// Output: 1
// Explanation: In the given testcase ,
// applying the method as stated in the
// above example, the output will be 1.
// Your Task:
// The task is to complete the function copyList() which takes one argument the head of the 
// linked list to be cloned and should return the head of the cloned linked list.
// NOTE : If their is any node whose arbitrary pointer is not given then its by default null.

// Expected Time Complexity : O(n)
// Expected Auxilliary Space : O(1)

/*struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
*/

//Function to clone a linked list with next and random pointer.
//O(n) extra space; O(2n) complexity
// Node *copyList(Node *head) {
//     unordered_map<Node*, Node*> mp;
//     Node* curr = head;
//     while(curr){
//         Node* temp = new Node(curr->data);
//         mp[curr] = temp;
//         curr = curr->next;
//     }
//     curr = head;
//     while(curr){
//         Node* temp = mp[curr];
//         if(curr->next)
//             temp->next = mp[curr->next];
//         if(curr->arb)
//             temp->arb = mp[curr->arb];
//         curr = curr->next;
//     }
//     return mp[head];
// }




//ANOTHER APPROACH
//O(1) extra space  ; complexity O(3n)
Node *copyList(Node *head) {
    Node* curr = head;
    //copy node is kept adjacent to the original
    while(curr){
        Node* copy = new Node(curr->data);
        copy->next = curr->next;
        curr->next = copy;
        curr = curr->next->next;
    }
    
    curr = head;
    //put arb pointer to copy nodes
    while(curr){
        Node* temp = curr->next;
        if(curr->arb)
            temp->arb = curr->arb->next;
        curr = curr->next->next;
    }
    
    curr = head;
    Node* nxt = curr->next->next; 
    Node* nh = new Node(0);
    Node* curr1 = nh;
    
    //seperate both list
    while(curr != NULL){
        curr1->next = curr->next;
        curr1 = curr1->next;
        curr->next = nxt;
        curr = nxt;
        if(nxt != NULL)
            nxt = nxt->next->next;
    }
    curr1->next = NULL;
    
    return nh->next;
}
