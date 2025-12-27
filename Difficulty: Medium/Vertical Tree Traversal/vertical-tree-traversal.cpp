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
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        map<int,map<int,vector<int>>>nodes;
        vector<vector<int>>ans;
        if(root==NULL)  return ans;
        queue<pair<Node*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            Node* frontNode=q.front().first;
            int hd=q.front().second.first;
            int lvl=q.front().second.second;
            q.pop();
            nodes[hd][lvl].push_back(frontNode->data);
            if(frontNode->left) q.push({frontNode->left,{hd-1,lvl+1}});
            if(frontNode->right) q.push({frontNode->right,{hd+1,lvl+1}});
        }
        
        for(auto i:nodes){
            vector<int>col;
            for(auto& j:i.second){
                // sort(j.second.begin(),j.second.end());
                for(int x: j.second)   col.push_back(x);
            }
            ans.push_back(col);
        }
        return ans;
    }
};