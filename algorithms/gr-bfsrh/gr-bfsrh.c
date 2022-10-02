#include <stdio.h>

int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;

void bfs(int v) {
	
	for (i=1;i<=n;i++)
	  if(a[v][i] && !visited[i])
	   q[++r]=i;
	
	if(f<=r) {
		visited[q[f]]=1;
		bfs(q[f++]);
	}
}

int main() {
	int v;
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	
	for (i=1;i<=n;i++) {
		q[i]=0;
		visited[i]=0;
	}
	
	printf("\n Enter the vertex values in  matrix form:\n");
	
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	   scanf("%d",&a[i][j]);
	
	printf("\n Enter the starting vertex:");
	scanf("%d",&v);
	
	bfs(v);
	printf("\n Output :\n");
	
	for (i=1;i<=n;i++)
	  if(visited[i])
	   printf("%d ",i); else
	   printf("\n BFS not valid!! ");
	
	printf("\n");
	
}
