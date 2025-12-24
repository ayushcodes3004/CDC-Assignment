class Solution {
  private:
    void bfsHelper(int i,vector<vector<int>> &adj,vector<bool>&vis,vector<int>& ans){
        queue<int>q;
        q.push(i);
        vis[i]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int neigh: adj[node]){
                if(!vis[neigh]){
                    vis[neigh]=1;
                    q.push(neigh);
                }
            }
        }
    }
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        vector<int>ans;
        vector<bool>vis(n,0);
        bfsHelper(0,adj,vis,ans);
        return ans;
    }
};