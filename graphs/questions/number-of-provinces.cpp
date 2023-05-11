// number of provinces is simply number of components of graph
void dfs(vector<int>adj[],vector<int>&vis,int i){
    vis[i] = 1;
    for(auto v: adj[i]){
        if(!vis[v]){
            dfs(adj,vis,v);
            
        }
    }
}
int numProvinces(vector<vector<int>> adj, int V) {
    // code here
    vector<int>adjList[V];
    for(int i = 0;i<V;i++){ // convert adj matrix to adj list
        for(int j = 0;j<V;j++){
            if(adj[i][j] == 1){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    
    vector<int>vis(V,0); 
    int ans = 0;
    for(int i = 0;i<V;i++){ // simple dfs
        if(!vis[i]){ // we are visiting each component if a vertex is not visited
            ans++; // increment ans
            dfs(adjList,vis,i);
        }
    }
    return ans;
}