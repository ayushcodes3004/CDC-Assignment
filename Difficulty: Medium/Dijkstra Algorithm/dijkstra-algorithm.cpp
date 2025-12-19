class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<int>dist(V,1e9);
        vector<vector<pair<int,int>>>adj(V);
        for(auto e: edges){
            int u=e[0],v=e[1],w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            if(wt>dist[node])   continue;
            for(auto [neigh,weight]: adj[node]){
                if(dist[node]+weight<dist[neigh]){
                    dist[neigh]=weight+dist[node];
                    pq.push({dist[neigh],neigh});
                }
            }
        }
        return dist;
    }
};