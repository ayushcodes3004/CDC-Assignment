/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  private:
    Node* pred(Node* curr){
        Node* prev=curr->left;
        while(prev->right && prev->right!=curr){
            prev=prev->right;
        }
        return prev;
    }
  public:
    vector<int> preOrder(Node* root) {
        // code here
        vector<int>ans;
        if(root==NULL)  return ans;
        Node* curr=root;
        while(curr){
            if(curr->left==NULL){
                ans.push_back(curr->data);
                curr=curr->right;
            }else{
                Node* prev=pred(curr);
                if(prev->right==NULL){
                    prev->right=curr;
                    ans.push_back(curr->data);
                    curr=curr->left;
                }else{
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};