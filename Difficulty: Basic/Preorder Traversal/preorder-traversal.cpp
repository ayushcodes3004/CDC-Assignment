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
  public:
    vector<int> preOrder(Node* root) {
        // code here
        vector<int>ans;
        if(root==NULL)  return ans;
        stack<Node*>st;
        st.push(root);
        while(!st.empty()){
            Node* node=st.top();
            st.pop();
            ans.push_back(node->data);
            if(node->right) st.push(node->right);
            if(node->left)  st.push(node->left);
        }
        return ans;
    }
};