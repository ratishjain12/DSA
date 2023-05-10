// type 1 if source node is given
vector<int> bfsOfGraph(int V, vector<int> adj[],int s) {
    // Code here
    vector<int>ans; // stores the bfs traversal of the graph
    vector<int>visited(V,0);
    queue<int>q;
    q.push(s);
    visited[s] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(auto v : adj[u]){
            if(!visited[v]){
                q.push(v);
                visited[v] = 1;
            }
        }
    }
    return ans;
    
}

// type 2 if source node is not given and graph is disconnected

void bfs(vector<int> adj[],int u,vector<int>&ans,vector<int>&visited){
    queue<int>q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(auto v : adj[u]){
            if(!visited[v]){
                q.push(v);
                visited[v] = 1;
            }
        }
    }
    
}
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    vector<int>ans; // stores the bfs traversal of the graph
    vector<int>visited(V,0);
    for(int i = 0;i<V;i++){
        if(!visited[i]){
            bfs(adj,i,ans,visited);
        }
    }
    
    return ans;
    
}