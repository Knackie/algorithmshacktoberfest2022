public void dfs(int start) {
    boolean[] isVisited = new boolean[adjVertices.size()];
    dfsRecursive(start, isVisited);
}

private void dfsRecursive(int current, boolean[] isVisited) {
    isVisited[current] = true;
    visit(current);
    for (int dest : adjVertices.get(current)) {
        if (!isVisited[dest])
            dfsRecursive(dest, isVisited);
    }
}