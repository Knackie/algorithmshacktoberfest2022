{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    queue<int> q;
	    vector<int> indegree(V,0);
	    
	    for(int i=0; i<V; i++){
	        for(auto it : adj[i])
	        indegree[it]++;
	    }
	    for(int i=0; i<V; i++){
	        if(indegree[i] == 0)
	        q.push(i);
	        
	    }
	    vector<int> topo;
	    while(!q.empty()){

        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }

    }
    return topo;
	    
	}
};
