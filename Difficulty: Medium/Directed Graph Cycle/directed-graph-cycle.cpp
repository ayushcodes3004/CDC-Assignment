class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
        }
        vector<int>indegree(V,0);
        for(int u=0;u<V;u++){
            for(int v:adj[u]){
                indegree[v]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)  q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto neigh: adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0) q.push(neigh);
            }
        }
        return (ans.size()!=V);
    }
};