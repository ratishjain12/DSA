void dfs(int node,vector<int>&vis,vector<int>adj[],stack<int>&st){
    vis[node] = 1;
    for(auto v : adj[node]){
        if(!vis[v]){
            dfs(v,vis,adj,st);
        }
    }
    st.push(node);
}
vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
    vector<int>ans;
    vector<int>vis(V,0);
    stack<int>st;
    for(int i = 0;i<V;i++){
        if(!vis[i]){
            dfs(i,vis,adj,st);
        }
    }
    
    while(!st.empty()){
        int node = st.top();
        st.pop();
        ans.push_back(node);
    }
    return ans;
}

// Note: bfs algo for topological sort is kahn's algorithm in algorithms folder