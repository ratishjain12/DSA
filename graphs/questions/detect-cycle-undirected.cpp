//dfs
bool dfs(vector<int> adj[],vector<int>&vis,int s,int parent){
    vis[s] = 1;
    for(int u : adj[s]){
        if(!vis[u]){
            if(dfs(adj,vis,u,s) == true){
                return true;
            }
        }else if(u!=parent){
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    // Code here
    vector<int>vis(V,0);
    for(int i = 0;i<V;i++){
        if(!vis[i]){
            if(dfs(adj,vis,i,-1)){
                return true;
            } 
        }
        
    }
    return false; 
}