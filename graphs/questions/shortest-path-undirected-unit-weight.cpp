vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    // code here
    vector<int>adj[N];
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    
    vector<int>dist(N,1e9);
    queue<int>q;
    dist[src] = 0;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:adj[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it] = dist[node]+1;
                q.push(it);
            }
        }
    }
    for(int i = 0;i<dist.size();i++){
        if(dist[i] == 1e9){
            dist[i] = -1;
        }
    }
    return dist;
    
}