#include<iostream>
using namespace std;

class binarySearchTree{
    binarySearchTree *left;
    int data;
    binarySearchTree *right;
    binarySearchTree *root;
    binarySearchTree *parent;
    int temp;

    public:

    binarySearchTree(){
        left=NULL;
        data=0;
        right=NULL;
        root=NULL;
        parent=NULL;
        temp=0;
    }

    binarySearchTree(int dummyData){
        left=NULL;
        data=dummyData;
        right=NULL;
        root=NULL;
        parent=NULL;
        temp=0;
    }

    binarySearchTree preOrder(binarySearchTree *root);
    binarySearchTree inOrder(binarySearchTree *root);
    binarySearchTree postOrder(binarySearchTree *root);
    binarySearchTree* insert(binarySearchTree *newNode, int data);
};

binarySearchTree binarySearchTree::preOrder(binarySearchTree *root){

    //pre-order Trversal: V - L - R

    if(!root){
        return NULL;
    }
    cout << root->data << endl;
    preOrder(root->left);
    preOrder(root->right);
}

binarySearchTree binarySearchTree::inOrder(binarySearchTree *root){

    //in-order Trversal: L - V - R

    if(!root){
        return NULL;
    }
    inOrder(root->left);
    cout << root->data << endl;
    inOrder(root->right);
}

binarySearchTree binarySearchTree::postOrder(binarySearchTree *root){

    //in-order Trversal: L - R - V

    if(!root){
        return NULL;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << endl;
}

binarySearchTree* binarySearchTree::insert(binarySearchTree *root, int newData){
    
    binarySearchTree *temp = NULL;
    
    if(!root){
        // root -> parent = 0;
        return new binarySearchTree(newData);
    }
    else if(newData > root -> data){
        root -> temp = newData;
        root -> right = insert(root->right, newData);
        
        // root -> parent = root -> right;
        cout<<root -> temp<<" right parent node \n";
        // root -> right = insert(root->right, newData);
    }
    else if(newData < root -> data){
        // root -> parent = root -> left;
        // cout<<root -> parent<<" left parent node \n";
        root-> left = insert(root->left, newData);
    }
    return root;
    
}

int main(){

    binarySearchTree b1;
    binarySearchTree *root = new binarySearchTree(10);

    b1.insert(root, 20);
    b1.insert(root, 40);

    b1.inOrder(root);

    return 0;
}