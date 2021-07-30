// Floor Value Node: Node with the greatest data lesser than or equal to the key value. 
// Ceil Value Node: Node with the smallest data larger than or equal to the key value.






/* A binary tree node has key, left child and right child */
struct Node {
	int data;
	Node *left, *right;

	Node(int value)
	{
		data = value;
		left = right = NULL;
	}
};

// Helper function to find floor and ceil of a given key in BST
void floorCeilBSTHelper(Node* root, int key, int& floor, int& ceil)
{

	while (root) {

		if (root->data == key) {
			ceil = root->data;
			floor = root->data;
			return;
		}

		if (key > root->data) {
			floor = root->data;
			root = root->right;
		}
		else {
			ceil = root->data;
			root = root->left;
		}
	}
	return;
}

