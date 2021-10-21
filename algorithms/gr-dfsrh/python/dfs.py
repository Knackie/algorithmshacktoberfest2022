from typing import Dict, List


# Graph used for the example:
#      0
#     / \
#    1   2
#   / \   \
#  3   4 - 5
#
# Expected DFS:
# 0 -> 1 -> 3 -> 4 -> 5 -> 2
graph = {
  '0' : ['1','2'],
  '1' : ['3', '4'],
  '2' : ['5'],
  '3' : [],
  '4' : ['5'],
  '5' : []
}


def dfs(graph: Dict[str, List[str]], root: str, visited = []) -> List[str]:
    if root in visited:
        return visited

    visited.append(root)
    [dfs(graph, k, visited) for k in graph[root]]
    return visited


if __name__ == '__main__':
    dfs_result = dfs(graph, '0')
    print(f'Depth-First Search result: {" -> ".join(dfs_result)}')
