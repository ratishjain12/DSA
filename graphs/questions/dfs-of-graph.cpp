// type 1 source node is given

void dfs(vector<int> adj[],int u,vector<int>&visited,vector<int>&ans){
    visited[u] = 1;
    ans.push_back(u);
    
    for(auto v : adj[u]){
        if(!visited[v]){
            dfs(adj,v,visited,ans);
        }
    }
}

vector<int> dfsOfGraph(int V,vector<int> adj[],int s) {
    // Code here
    vector<int>ans;
    vector<int>visited(V,0);
    dfs(adj,s,visited,ans);
    return ans;
}


// type 2 source node is not given and graph is disconnected

void dfs(vector<int> adj[],int u,vector<int>&visited,vector<int>&ans){
    visited[u] = 1;
    ans.push_back(u);
    
    for(auto v : adj[u]){
        if(!visited[v]){
            dfs(adj,v,visited,ans);
        }
    }
}

vector<int> dfsOfGraph(int V,vector<int> adj[]) {
    // Code here
    vector<int>ans;
    vector<int>visited(V,0);
    
    for(int i = 0;i<V;i++){
        if(!visited[i]){
            dfs(adj,i,visited,ans);
        }
    }
    
    return ans;
}
