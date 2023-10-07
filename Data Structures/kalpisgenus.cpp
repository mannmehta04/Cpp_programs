#include<iostream>
using namespace std;

class binarySearchTree{
    binarySearchTree *left;
    int data;
    binarySearchTree *right;
    binarySearchTree *root;
    binarySearchTree *parent;

    public:

    binarySearchTree(){
        left=NULL;
        data=0;
        right=NULL;
        root=NULL;
        parent=NULL;
    }

    binarySearchTree(int dummyData,binarySearchTree *prt){
        left=NULL;
        data=dummyData;
        right=NULL;
        root=NULL;
        parent=prt;
    }
    void inOrder(binarySearchTree *root);
    binarySearchTree* insert(binarySearchTree *newNode, int data,binarySearchTree *prt);
};



void binarySearchTree::inOrder(binarySearchTree *root){

   

    if(!root){
        return;
    }
    inOrder(root->left);
    cout << root->data <<" "<<root->parent<< endl;
    inOrder(root->right);
}

binarySearchTree* binarySearchTree::insert(binarySearchTree *root, int newData,binarySearchTree *prt){

    if(!root)
        return new binarySearchTree(newData,prt);
    else if(newData > root -> data)
        root -> right = insert(root->right, newData,root);
    else if(newData < root -> data)
        root-> left = insert(root->left, newData,root);
    return root;
    
}

int main(){

    binarySearchTree b1;
    binarySearchTree *root = new binarySearchTree(10,NULL);

    b1.insert(root, 20, root);
    b1.insert(root, 40, root);
    b1.insert(root, 15, root);
    b1.insert(root, 30, root);
    b1.insert(root, 45, root);
    b1.inOrder(root);

    return 0;
}