//Implementing dfs on graphs in c++


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;

static int n;
static int vis[n+1];

//Dfs function
void dfs(int cur ,vector<int> *adj)
{

vis[cur]= 1;
cout<<cur<<" ";

for(int i : adj[cur]) //for each loop used for iterating over a range of values 
{
	if(vis[cur])
		continue ;

	dfs(i,cur);
}
}


int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif


int u,v;
cin>>n; //no of nodes 

vector<int> adj[n+1];

for (int i = 0 ; i<n-1 ; i++) //no of edges n-1
{cin>>u>>v;
	adj[u].push_back(v);
	adj[v].push_back(u);
}

dfs(1,adj);

return 0;

}
