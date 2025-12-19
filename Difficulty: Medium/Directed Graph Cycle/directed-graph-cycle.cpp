class Solution {
  private:
    bool dfs(int node,vector<vector<int>>&adj,vector<bool>&vis,vector<bool>&dfsVis){
        vis[node]=1;
        dfsVis[node]=1;
        for(int neigh: adj[node]){
            if(!vis[neigh]){
                if(dfs(neigh,adj,vis,dfsVis))   return true;
            }
            else if(dfsVis[neigh])  return true;
        }
        dfsVis[node]=0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
        }
        vector<bool>vis(V,0);
        vector<bool>dfsVis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,dfsVis))   return true;
            }
        }
        return false;
    }
};