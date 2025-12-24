class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        for(auto e: edges){
            int u=e[0],v=e[1],w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<bool>vis(V,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int ans=0;
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop(); 
            if (vis[node]) continue;
            vis[node]=1;
            ans+=wt;
            for(auto[aNode,aWt]:adj[node]){
                if(!vis[aNode]){
                    pq.push({aWt,aNode});
                }
            }
        }
        return ans;
    }
};