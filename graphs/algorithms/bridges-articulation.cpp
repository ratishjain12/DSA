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
            if(low[it] > disc[node]){ // condition for a bridge
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


// articulation point
void dfs(int node,int parent,vector<int>adj[],vector<int>&vis,vector<int>&disc,vector<int>&low,vector<int>&mark,int timer){
    vis[node] = 1;
    low[node] = disc[node] = timer++;
    int child = 0;
    for(auto it:adj[node]){
        if(it == parent){
            continue;
        }
        
        if(!vis[it]){
            dfs(it,node,adj,vis,disc,low,timer);
            low[node] = min(low[node],low[it]);
            if(low[it] >= disc[node] && parent != -1){ // condition for a bridge
                mark[node] = 1;
            }
            child++;
        }else{
            low[node] = min(low[node],disc[it]);
        }
    }
    if(child > 1 && parent == -1){
        mark[node] = 1;
    }
}
vector<int>articulationPoints(int V, vector<int> adj[]) {
    // Code here
    
    vector<int>vis(V,0);
    vector<int>low(V,0);
    vector<int>disc(V,0);
    vector<int>mark(V,0);
    vector<int>ans;
    int timer = 0;

    for(int i = 0;i<V;i++){
        if(!vis[i]){
            dfs(i,-1,adj,vis,disc,low,mark,timer);
                
        }
    }

    for(int i = 0;i<mark.size();i++){
        if(mark[i] == 1){
            ans.push_back(i);
        }
    }
    if(ans.size() == 0) return {-1};
    return ans;
}

