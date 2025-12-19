class Solution {
private:
    void dfsHelper(int node,vector<bool>&vis,vector<vector<int>>&adj,vector<int>&ans){
        vis[node]=1;
        ans.push_back(node);
        for(int neigh:adj[node]){
            if(!vis[neigh]){
                dfsHelper(neigh,vis,adj,ans);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,0);
        vector<int>ans;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfsHelper(i,vis,adj,ans);
                cnt++;
            }
        }
        return cnt;
    }
};
