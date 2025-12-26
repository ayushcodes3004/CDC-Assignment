/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* predecessor(Node* curr){
        Node* prev=curr->left;
        while(prev->right && prev->right!=curr){
            prev=prev->right;
        }
        return prev;
    }
    
    vector<int> inOrder(Node* root) {
        // code here
        vector<int>ans;
        Node* curr=root;
        while(curr){
            if(curr->left==NULL){
                ans.push_back(curr->data);
                curr=curr->right;
            }else{
                Node* prev=predecessor(curr);
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }else{
                    prev->right=NULL;
                    ans.push_back(curr->data);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
    
};