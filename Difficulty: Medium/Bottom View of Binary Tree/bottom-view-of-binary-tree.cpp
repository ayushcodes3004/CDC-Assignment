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
        if(root == NULL) return ans;
        map<int,int>mp;
        queue<pair<Node*,int>>q;//{node,hd}
        q.push({root,0});
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            Node* node=front.first;
            int hd=front.second;
            mp[hd]=node->data;
            if(node->left)      q.push({node->left,hd-1});
            if(node->right)      q.push({node->right,hd+1});
        }
        for(auto [hd,nodeVal]:mp){
            ans.push_back(nodeVal);
        }
        return ans;
    }
};