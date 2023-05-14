// based on kahn's algorithm(bfs)
bool isCyclic(int V, vector<int> adj[]) {
        
    vector<int>inDegree(V,0);
    for(int i = 0;i<V;i++){ // store indegree of every vertex
        for(auto x : adj[i]){
            inDegree[x]++;
        }
    }
    queue<int>q;
    for(int i = 0;i<V;i++){ // push to queue vertex of zero indegree
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    int count = 0; // we keep a count
    while(!q.empty()){ // pop out first of queue and add to ans also go its adjacent and decrement indegree
        int u = q.front();
        q.pop();
        count++;
        for(auto v:adj[u]){
            inDegree[v]--; // after incrementing if indegree becomes zero add to queue making it independent
            if(inDegree[v] == 0){
                q.push(v);
            }
        }
    }
    return count!=V; // if count comes out to be equal to number of vertex we return false else we return true
}


//using dfs
// we maintain two array pathVis and Vis
// and we check if visited and pathvisted for a node is true then there is a cycle
// while backtracking we make pathVis of node as 0
bool dfs(int node, vector<int> adj[],vector<int>&vis,vector<int>&pathVis){
    vis[node] = 1;
    pathVis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(dfs(it,adj,vis,pathVis)){
                return true;
            }
        }else if(pathVis[it]){
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}


// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[]) {
    
    vector<int>vis(V,0);
    vector<int>pathVis(V,0);
    for(int i = 0 ;i<V;i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,pathVis)){
                return true;
            }
        }
    }
    return false;
    
}