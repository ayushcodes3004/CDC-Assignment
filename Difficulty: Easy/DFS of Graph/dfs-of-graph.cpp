class Solution {
  private:
    void dfsHelper(int node,vector<bool>& vis,vector<vector<int>>& adj,vector<int>& ans){
        vis[node]=1;
        ans.push_back(node);
        for(int neigh: adj[node]){
            if(!vis[neigh]){
                dfsHelper(neigh,vis,adj,ans);
            } 
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V=adj.size();
        vector<int>ans;
        vector<bool>vis(V,0);
        dfsHelper(0,vis,adj,ans);
        return ans;
    }
};