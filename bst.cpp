#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};
Node* insertNode(Node* root,int val){
    if(root==NULL)  return new Node(val);
    
    if(val<root->val){
        root->left=insertNode(root->left,val);
    }else if (val>root->val){
        root->right=insertNode(root->right,val);
    }
    return root;
}
bool searchNode(Node* root, int key){
    if(root==NULL)  return 0;
    
    if(root->val==key)  return 1;
    
    if(key<root->val){
        return searchNode(root->left,key);
    }else if (key>root->val){
       return searchNode(root->right,key);
    }
    return 0;
}
void inorder(Node* root){
    if(root==NULL)  return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
Node* findMin(Node* root){
    while(root->left)   root=root->left;
    return root;
}
Node* deleteNode(Node* root, int key){
    if(root==NULL)  return root;
    if(key<root->val){
        root->left=deleteNode(root->left,key);
    }else if(key>root->val){
        root->right=deleteNode(root->right,key);
    }else{
        //0 child
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        //1 child
        if(!root->left && root->right){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        if(root->left && !root->right){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        //2 child->inorder succesor
        if(root->left && root->right){
            Node* temp=findMin(root->right);
            root->val=temp->val;
            root->right=deleteNode(root->right,temp->val);
        }
    }
    return root;
}
int main() {
    Node* root=NULL;
    root=insertNode(root,50);
    root=insertNode(root,10);
    root=insertNode(root,20);
    root=insertNode(root,20);
    root=deleteNode(root,50);
    inorder(root);
    cout<<endl;
    cout<<searchNode(root,30);
    return 0;
}
