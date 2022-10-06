// function to add edge to graph
function addedge(u, v, adj){
    adj[u].push(v);
    adj[v].push(u);
}

// function to print BFS traversal from a given source s
function bfs(s, adj){
    let visited = new Array(adj.length).fill(false);
    let q = [];
    q.push(s);
    visited[s] = true;
    for(let i=0;i<adj.length;i++){
        if(visited[i]==false){
            while(q.length > 0){
                let u = q.shift();
                console.log(u);
                for(let i = 0; i < adj[u].length; i++){
                    if(visited[adj[u][i]] == false){
                        q.push(adj[u][i]);
                        visited[adj[u][i]] = true;
                    }
                }
            }
        }
    }
}

// Driver code
let adj = new Array(14).fill(new Array());

addedge(0, 1, adj);
addedge(0, 2, adj);
addedge(0, 3, adj);
addedge(1, 4, adj);
addedge(1, 5, adj);
addedge(2, 6, adj);
addedge(2, 7, adj);
addedge(3, 8, adj);
addedge(8, 9, adj);
addedge(8, 10, adj);
addedge(9, 11, adj);
addedge(9, 12, adj);
addedge(9, 13, adj);

let start = 0;
bfs(start, adj);

