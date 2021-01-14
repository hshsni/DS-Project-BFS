#include<stdio.h>
int a[20][20],q[20],visited[20],reach[10];
int n,i=0,j;
void bfs(int v,int a[20][20],int n){
	int u,i,f=-1,r=-1,q[100];
	q[++r]=v;
	while(f<r){
		u=q[++f];//u indicates the current node.Dequeue the front of the queue and check all the nodes that can be visited from it
		for(i=0;i<n;i++){//n is the no. of nodes
			if(a[u][i]==1 && visited[i]==0){//a[u][i] indicates whether a node can be visited from the current node
                visited[i]=1;//Mark the node as visited
                q[++r]=i;//Add the visited node to the queue
			}
		}
	}
}
void main()
{
    int v, choice;
    printf("\n Enter the number of cities: ");
    scanf("%d",&n);
    printf("\n Enter graph data in matrix form:\n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d",&a[i][j]);

            printf("Enter the source vertex: ");
            scanf("%d",&v);
            if((v<1)||(v>n))
                printf("\nBFS not possible.Enter a valid source vertex. ");
            else
            {
                for(i=1;i<=n;i++)
                {
                     reach[i]=0;
                }
                    bfs(v,a,n); 
                    printf("The reachable nodes from node %d:\n",v);
                for(i=1;i<=n; i++)
                   {
                        if(visited[i] && i!=v)
                        printf("node %d   ",i);
                   }
            }
}
