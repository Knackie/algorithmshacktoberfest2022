// function to add edge to graph
function addedge(u, v, adj){
    adj.get(u).push(v);
    adj.get(v).push(u);
}

// function to print BFS traversal from a given source s
function dfs(adj){
    let visited = new Array(adj.size).fill(false);
    let st = [];
    for(let i=0;i<adj.size;i++){
        if(visited[i]==false){
            st.push(i);
            visited[i] = true;
            while(st.length > 0){
                let u = st.pop();
                console.log(u);
                for(let j = 0; j < adj.get(u).length; j++){
                    if(visited[adj.get(u)[j]] == false){
                        st.push(adj.get(u)[j]);
                        // console.log(adj.get(u));
                        visited[adj.get(u)[j]] = true;
                    }
                }
            }
        }
    }
}

// Driver code
var adj = new Map();

for(let i=0;i<14;i++){
    adj.set(i, []);
}

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

// console.log(adj);

dfs(adj);

