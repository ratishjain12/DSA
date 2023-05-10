// Given a Directed Acyclic Graph (DAG) with V vertices and E edges,
// Kahn's algorithm
vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
    vector<int>ans;
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
    
    while(!q.empty()){ // pop out first of queue and add to ans also go its adjacent and decrement indegree
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(auto v:adj[u]){
            inDegree[v]--; // after incrementing if indegree becomes zero add to queue making it independent
            if(inDegree[v] == 0){
                q.push(v);
            }
        }
    }
    return ans;
}