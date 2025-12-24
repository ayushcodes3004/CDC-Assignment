class Solution {
  private:
    void dfs(int node,vector<vector<int>>& adj,vector<bool>& vis,stack<int>& st){
        vis[node]=1;
        for(int neigh: adj[node]){
            if(!vis[neigh]){
                dfs(neigh,adj,vis,st);
            }
        }
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto e: edges){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
        }
        vector<bool>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};