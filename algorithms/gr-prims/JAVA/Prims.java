public class Prim {
    public static void main(String[] args){
        // Initialized and added the graph earlier
        
        int startNode = 0;
        // Distance from the start node to itself is 0
        graph.setEdges(0, startNode); 

        for(int i = 0; i < graph.getNumOfNodes()-1; i++){
            int node = minEdgeNotIncluded(graph);

            graph.setIncludedInMST(node);

            double[][] matrix = graph.getMatrix();
            for(int v = 0; v < graph.getNumOfNodes(); v++){
                if(matrix[node][v] != 0 && 
                   !graph.getIncludedInMST(v) && 
                   matrix[node][v] < graph.getEdges(v)){
                    graph.setEdges(matrix[node][v], v);
                    graph.setParents(node, v);
                }
            }
        }
        
        double cost = 0;
        for(int i = 0; i < graph.getNumOfNodes(); i++){
            if(i != startNode){
                cost += graph.getEdges(i);
            }
        }
        System.out.println(cost);
    }
}