// step 1: sort nodes on the basis of their finish time while dfs
// step 2: reverse the edges of the graph
// step 3: do dfs again for the reversed and count the number of components in the graph
void dfsReversed(int node,vector<int>&vis,vector<int>adjT[]){
    vis[node] = 1;
    for(auto v : adjT[node]){
        if(!vis[v]){
            dfsReversed(v,vis,adjT);
        }
    }
}

void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,stack<int>&st){
    vis[node] = 1;
    for(auto v : adj[node]){
        if(!vis[v]){
            dfs(v,vis,adj,st);
        }
    }
    st.push(node);
}
int kosaraju(int V, vector<vector<int>>& adj)
{
    //code here
    vector<int>vis(V,0);
    stack<int>st;

    for(int i = 0;i<V;i++){
        if(!vis[i]){
            dfs(i,vis,adj,st);
        }
    }
    
    //reversing the edges
    vector<int>adjT[V];
    for(int i = 0;i<V;i++){
        vis[i] = 0;
        for(auto it : adj[i]){
            adjT[it].push_back(i);
        }
    }
    
    //doing dfs again and counting number of components
    int scc = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            scc++;
            dfsReversed(node,vis,adjT);
        }
    }
    return scc;
}