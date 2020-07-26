// C program to demonstrate insert operation in binary search tree. 
#include<stdio.h> 
#include<stdlib.h> 
#include <stack>
#include <iostream>
using namespace std;

struct node 
{ 
	int key; 
	struct node *left, *right; 
	node(int val):key(val){}
}; 

// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		printf("%d \n", root->key); 
		inorder(root->right); 
	} 
} 

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key); 

	/* Otherwise, recur down the tree */
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 

	/* return the (unchanged) node pointer */
	return node; 
} 

node* concat(node* head1,node* head2){
	node* temp = head1;
	if(head1)head1 = head1->left;
	if(head1)head1->right = head2;
	if(head2)head2->left->right = temp;
	if(temp)temp->left = head2->left;
	if(head2)head2->left = head1;
	return temp;
}

node* bstToCLL(node* root){
	if(root){
		auto left = root->left;
		auto right = root->right;
		root->left = root;
		root->right = root;
		if(left)
			root = concat(bstToCLL(left),root);
		if(right)
			root = concat(root,bstToCLL(right)); 
		return root;
	}
	return root;
}


int main() 
{ 
	/* Let us create following BST 
			50 
		/	 \ 
		30	 70 
		/ \ / \ 
	20 40 60 80 */
	struct node *root = NULL; 
	root = insert(root, 50); 
	insert(root, 30); 
	insert(root, 20); 
	insert(root, 40); 
	insert(root, 70); 
	insert(root, 60); 
	insert(root, 80); 
	root = bstToCLL(root);
	auto temp = root;
	do{
	cout << root->key << " ", root = root->right;
	}while(root != temp);

	return 0; 
} 
