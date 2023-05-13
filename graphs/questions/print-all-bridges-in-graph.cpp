void dfs(int node,int parent,vector<int>adj[],vector<int>&vis,vector<int>&disc,vector<int>&low,int timer){
    vis[node] = 1;
    low[node] = disc[node] = timer++;
    for(auto it:adj[node]){
        if(it == parent){
            continue;
        }
        
        if(!vis[it]){
            dfs(it,node,adj,vis,disc,low,timer);
            low[node] = min(low[node],low[it]);
            if(low[it] > disc[node]){
                cout<<node<<" "<<it<<endl;
            }
        }else{
            low[node] = min(low[node],disc[it]);
        }
    }
}

// bridge is any edge on removal of which it creates two or more components of graph


int bridges(int V, vector<int> adj[]) 
{
    // Code here
    
    vector<int>vis(V,0);
    vector<int>low(V,0);
    vector<int>disc(V,0);
    int timer = 0;

    for(int i = 0;i<V;i++){
        if(!vis[i]){
            dfs(i,-1,adj,vis,disc,low,timer);
                
        }
    }
    return ans;
    
}