/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL)  return ans;
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            Node* front=q.front().first;
            int hd=q.front().second;
            q.pop();
            
            mp[hd]=front->data;
            
            if(front->left) q.push({front->left,hd-1});
            if(front->right)    q.push({front->right,hd+1});
        }
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};