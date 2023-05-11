// prim's algoritm for mst
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    vector<pair<int,int>>mst;
    vector<int>vis(V,0);
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{0,-1}});
    int sum = 0;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int node = p.second.first;
        int parent = p.second.second;
        int weight = p.first;
        if(vis[node]) continue;
        vis[node] = 1;
        if(parent != -1){
            mst.push_back({node,parent});
        }
        sum+=weight;
        for(auto v : adj[node]){
            int adjNode = v[0];
            int weight = v[1];
            if(!vis[adjNode]){
                pq.push({weight,{adjNode,node}});
            }
        }
        
    }
    
    // printing mst
    // for(auto it : mst){
    //     cout<<it.first <<" "<<it.second;
    // }
    return sum;
}