#include<bits/stdc++.h>
using namespace std;

// declaring the node for the AVL Tree
class Node
{
public:
	// value stored for each node
	int value;
	// pointer to the left node
    Node * left;
    // pointer to the right node
    Node * right;
    int height;
};
class AVLTree
{
   public:
   	// creating new node function
   	Node * newNode (int data);
    // function that returns the maximum among the two numbers
    int max (int x, int y);
    // function for finding the height of the node
    int height (Node * root);
    // function that verifies whether the tree is an AVL Tree or not
    bool verify (Node * root);
    // function that rotates the subtree rooted with node p
    Node * rightRotate (Node * p);
    // function that rotates the subtree rooted with node q
    Node * leftRotate (Node * q);
    // function for finding the balance factor
    int Balance (Node * N);
    // inserting each node in the form of an AVL tree
    Node * insert (Node * root, int data);
};

// function to find the height of the tree
int AVLTree::height(Node * root)
{
	if (root == NULL)
	{
		return 0; // function returns 0 if the tree does not exist
	}
	// returning the stored height.
	return root -> height;
}

// function to get the maximum among the two numbers
int AVLTree::max(int x, int y)
{
	return (x > y)?x:y;
}

// creating an new node for each of the roots
Node * AVLTree::newNode(int data)
{
	Node * root = new Node();
	root -> value = data;
	// the left and right of the root will naturally be null
	root -> left = NULL;
	root -> right = NULL;
	root -> height = 1; // the height will be one as it is a new node
	return root; // funtion then returns the root
}

// function for rotating the tree to right with vertex point
Node * AVLTree::rightRotate(Node * point)
{
	// geting the right pointer
	Node * point2 = point -> left;
	Node * location = point2 -> right;

	// doing the rotation
	point2 -> right = point;
	point -> left = location;

	// updating the heights by 1
	point -> height = max(height(point -> left), height(point -> right)) + 1;
	point2 -> height = max(height(point2 -> left), height(point2 -> right)) + 1;

	// returning the new root
	return point2;
}

// function for rotating the tree to left with vertex point
Node * AVLTree::leftRotate(Node * point)
{
	// getting the left pointer.
	Node * point2 = point -> right;
	Node * location = point2 -> left;

	// doing the rotation
	point2 -> left = point;
	point -> right = location;

	// updating the heights by 1
	point -> height = max(height(point -> left), height(point -> right)) + 1;
	point2 -> height = max(height(point2 -> left), height(point2 -> right)) + 1;

	// returning the new root
	return point2;
}
// function for finding the balance.
int AVLTree::Balance(Node * N)
{
   if(N == nullptr)
   {
   	 return 0;
   }
   // return the difference in heights
   return height(N -> left)-height(N -> right);
}

// recursive function for inserting the node
Node * AVLTree::insert(Node * root, int data)
{
	// case where it is the first node
	if(root == NULL)
	{
		return newNode(data);
	}
	// case where the data is less than that of the root
	if(data < root -> value)
	{
		root -> left = insert(root -> left, data);
	}
	// case where the data is greater than that of the root
	else if(data > root -> value)
	{
		root -> right = insert(root -> right, data);
	}

	else
	{
		return root;
	}

	// finding the height of present tree until the node
	root -> height = max(height(root -> left), height(root -> right)) + 1;

	// checking to see if the tree is balanced
	int balance = Balance(root);

	// perform the rotation
	if(balance > 1 && data < root -> left -> value)
	{
		return rightRotate(root);
	}

	if(balance < -1 && data > root -> right -> value)
	{
		return leftRotate(root);
	}

	if(balance > 1 && data > root -> left -> value)
	{
		root -> left = leftRotate(root -> left);
		return rightRotate(root);
	}

	if(balance < -1 && data < root -> right -> value)
	{
		root -> right = rightRotate(root -> right);
		return leftRotate(root);
	}

	// returning the root.
	return root;
}

// checking to see if it is an AVL tree or not
bool AVLTree::verify(Node * root)
{
   if(root == NULL)
   {
   	 return true;
   }

   // getting the left height of tree
   int lh = height(root -> left);

   // getting the right height of tree
   int rh = height(root -> right);
   if(abs(lh-rh) <= 1 && verify(root -> left) && verify(root -> right))
   {
   	 return true;
   }
   return false;
}

int main()
{
	AVLTree * set = new AVLTree();
	Node * root = NULL;
    root = set -> insert(root, 1);
    root = set -> insert(root, 2);
    root = set -> insert(root, 3);
    root = set -> insert(root, 4);
    root = set -> insert(root, 5);
    root = set -> insert(root, 6);
    if(set -> verify(root))
	{
    	cout << "The tree is AVL Tree" << endl;
    }
    else
	{
    	cout << "The tree is not AVL tree" << endl;
    }
}
;