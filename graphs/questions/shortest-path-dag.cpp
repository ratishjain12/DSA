/*Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, 
then return -1 for that vertex. */

void dfs(int node,vector<int>&vis,vector<pair<int,int>>adj[],stack<int>&st){
    vis[node] = 1;
    for(auto it : adj[node]){
        int v = it.first;
        if(!vis[v]){
            dfs(v,vis,adj,st);
        }
    }
    st.push(node);
    
}
 
vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    // code here
    vector<pair<int,int>>adj[N];
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adj[u].push_back({v,wt});
    }
    
    stack<int>st;
    vector<int>vis(N,0);
    
    for(int i = 0;i<N;i++){
        if(!vis[i]){
            dfs(i,vis,adj,st);
        }
    }
    vector<int>dist(N,1e9);
    dist[0] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto it : adj[node]){
            int adjNode = it.first;
            int wt = it.second;
            if(dist[node] + wt < dist[adjNode]){
                dist[adjNode] = dist[node] + wt;
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