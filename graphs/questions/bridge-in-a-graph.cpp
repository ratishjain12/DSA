
void dfs(int node,int parent,int c, int d,int&ans,vector<int>adj[],vector<int>&vis,vector<int>&disc,vector<int>&low,int timer){
    vis[node] = 1;
    low[node] = disc[node] = timer++;
    for(auto it:adj[node]){
        if(it == parent){
            continue;
        }
        
        if(!vis[it]){
            dfs(it,node,c,d,ans,adj,vis,disc,low,timer);
            low[node] = min(low[node],low[it]);
            if(low[it] > disc[node] && ((c == node && d == it) || (c==it && d == node)) ){
                ans = 1;
            }
        }else{
            low[node] = min(low[node],disc[it]);
        }
    }
}
//Function to find if the given edge is a bridge in graph.
// give is node and a edge between c to d check whether it is a bridge
// bridge is any edge on removal of which it creates two or more components of graph


int isBridge(int V, vector<int> adj[], int c, int d) 
{
    // Code here
    
    vector<int>vis(V,0);
    vector<int>low(V,0);
    vector<int>disc(V,0);
    int timer = 0;
    int ans = 0;
    for(int i = 0;i<V;i++){
        if(!vis[i]){
            dfs(i,-1,c,d,ans,adj,vis,disc,low,timer);
                
        }
    }
    return ans;
    
}