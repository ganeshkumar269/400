#include <iostream>
using namespace std;

struct node{
    int key,height;
    node* left,*right;
    node():height(0){left=NULL;right=NULL;}
    node(int data,int h):key(data),height(h){}
};

node* rightRotate(node* root);
node* leftRotate(node* root);
int nodeheight(node* root);

node* insert(node* root,int key){
    if(!root){
        root = new node(key,1);
    }else{
        if(root->key < key)
            root->right = insert(root->right,key);
        else 
            root->left = insert(root->left,key);
        int lh = nodeheight(root->left);
        int rh = nodeheight(root->right);
        root->height = max(lh,rh)+1;
        int dif = lh-rh;
        //left-left
        if(dif > 1 && key < root->left->key){
            root = rightRotate(root);
        }
        //left-right
        if(dif > 1 && key > root->left->key){
            root->left = leftRotate(root->left);
            root =  rightRotate(root);
        }
        //right-left
        if(dif < -1 && key < root->right->key){
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }
        //right-right
        if(dif < -1 && key > root->right->key){
            root = leftRotate(root);
        }
    }
    return root;
}

node* rightRotate(node* root){
    node* rL = root->left;
    node* rLR = rL->right;
    root->left = rLR;
    rL->right = root;
    root->height = max(nodeheight(root->left),nodeheight(root->right))+1;
    rL->height = max(nodeheight(rL->left),nodeheight(rL->right))+1;
    return rL;
}

node* leftRotate(node* root){
    node* rR = root->right;
    node* rRL = rR->left;
    rR->left = root;
    root->right = rRL;
    root->height = max(nodeheight(root->left),nodeheight(root->right))+1;
    rR->height = max(nodeheight(rR->left),nodeheight(rR->right))+1;
    return rR;
}
int nodeheight(node* root){
    if(root) return root->height;
    return 0;
}

void inorder(node* root){
    if(root){
        inorder(root->left);
        cout << root->key << " " << root->height << endl;
        inorder(root->right);
    }
}

int main(){
    node* root = NULL;
    root = insert(root,10);
    inorder(root);cout << endl;
    root = insert(root,20);
    inorder(root);cout << endl;
    root = insert(root,30);
    inorder(root);cout << endl;
    root = insert(root,40);
    inorder(root);cout << endl;
    root = insert(root,5);
    inorder(root);cout << endl;
    return 0;
}