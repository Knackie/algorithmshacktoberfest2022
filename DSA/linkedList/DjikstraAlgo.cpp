
#include<iostream>
using namespace std;
#define V 5  //Defines total number of vertices in the graph
#define INFINITY 999
int min_Dist(int dist[], bool visited[])   
//This method used to find the vertex with minimum distance and is not yet visited
{
	int min=INFINITY,index;                 //Initialize min with infinity
	for(int v=1;v<=V;v++)
	{
		if(visited[v]==false &&dist[v]<=min)      
		{
			min=dist[v];
			index=v;
		}
	}
	return index;
}
void Dijkstra(int cost[V][V],int src) //Method to implement shortest path algorithm
{
	int dist[V];                             
	bool visited[V];
	for(int i=1;i<=V;i++)                    //Initialize dist[] and visited[] 
	{
		dist[i]=INFINITY;
		visited[i]=false;	
	}
	//Initialize distance of the source vertec to zero
	dist[src]=0;                                   
	for(int c=2;c<=V;c++)                           
	{
		//u is the vertex that is not yet included in visited and is having minimum 
		int u=min_Dist(dist,visited);            //distance
		visited[u]=true;                          //vertex u is now visited 
		for(int v=1;v<=V;v++)                    
//Update dist[v] for vertex v which is not yet included in visited[] and
//there is a path from src to v through u that has smaller distance than
// current value of dist[v]
		{
			if(!visited[v] && cost[u][v] &&dist[u]+cost[u][v]<dist[v])
			dist[v]=dist[u]+cost[u][v];
		}
	}
	 //will print the vertex with their distance from the source
	cout<<"The shortest path  "<<src<<" to all the other vertices is: \n";
	for(int i=1;i<=V;i++)                      
	{
	   if(i!=src)
	   cout<<"source:"<<src<<"\t destination:"<<i<<"\t MinCost is:"<<dist[i]<<"\n";
	}
}
int main()
{
	int cost[V][V], i,j, s;
	cout<<"\n Enter the cost matrix weights";
	for(i=1;i<=V;i++)      //Indexing ranges from 1 to n
          for(j=1;j<=V;j++)
          {
cin>>cost[i][j];
			//Absence of edge between vertices i and j is represented by INFINITY
             if(cost[i][j]==0)     
               cost[i][j]=INFINITY;    
           }
cout<<"\n Enter the Source Vertex"; 
cin>>s;

	Dijkstra(cost,s);
	return 0;	
}
