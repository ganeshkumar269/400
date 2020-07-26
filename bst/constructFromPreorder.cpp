#include <iostream>
using namespace std;
struct node 
{ 
	int key; 
	struct node *left, *right; 
    	node(int val):key(val){}

}; 

void constructFromPreorder1(node** root,int l,int r,int* arr){
    if(l>r) return;
    int i=l+1;
    if(arr[r] < arr[l]) i = r+1;
    else while(i <=r && arr[i] < arr[l] ) i++;
    *root = new node(0);
    (*root)->key= arr[l];
    
    if(l+1 < i){
        (*root)->left = new node(0);
        constructFromPreorder1(&((*root)->left),l+1,i-1,arr);
    }
    if(i>l && i <= r){
        (*root)->right = new node(0);
        constructFromPreorder1(&((*root)->right),i,r,arr);        
    }
}

node* constructFromPreorder2(int* arr,int* pos,int key,int min_,int max_,int sz){
    node* root = NULL;
    if(key > min_ && key < max_ && *pos < sz){
        root= new node(key);
        *pos = *pos + 1;
        root->left = constructFromPreorder2(arr,pos,arr[*pos],min_,key-1,sz);
        root->right = constructFromPreorder2(arr,pos,arr[*pos],key+1,max_,sz);
    }
    return root;
}


void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		printf("%d \n", root->key); 
		inorder(root->right); 
	} 
} 
int main(){
    freopen("in.txt","r",stdin);
    int arr[10000];
    int n;cin>>n;
    for(int i =0 ;i < n;i++) cin>>arr[i];
    node* root;
    // constructFromPreorder1(&root,0,n-1,arr);
    // inorder(root);
    int pos = 0;
    root = constructFromPreorder2(arr,&pos,arr[0],-1,INT32_MAX,n);
    inorder(root);    
    return 0;
}