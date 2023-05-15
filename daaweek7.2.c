#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<limits.h>
struct edge{
	int source,dest,weight;
};
struct graph{
	int v,e;
	struct edge* edge;
};
struct graph* creategraph(int v,int e){
	struct graph* graph=(struct graph*)malloc(sizeof(struct graph));
	graph->v=v;
	graph->e=e;
	graph->edge=(struct edge*)malloc(graph->e * sizeof(struct edge));
	return graph;
}
void finalsol(int dis[],int n){
	printf("\n vertex \t distance from source vertex\n ");
	int i;
	for(i=0;i<n;i++){
		printf("%d \t\t %d\n",i,dis[i]);
	}
}
void bellmanford(struct graph* graph,int source){
	int v=graph->v;
	int e=graph->e;
	int storedistance[v];
	int i,j;
	for(i=0;i<v;i++){
		storedistance[i]=INT_MAX;
		storedistance[source]=0;
	}
	for(i=1;i<v-1;i++){
		for(j=0;j<e;j++){
			int u=graph->edge[j].source;
			int v=graph->edge[j].dest;
			int weight=graph->edge[j].weight;
			if(storedistance[u]+weight<storedistance[v])
			storedistance[v]=storedistance[u]+weight;
		}
	}
	for(i=0;i<e;i++){
		int u=graph->edge[i].source;
		int v=graph->edge[i].dest;
		int weight=graph->edge[i].weight;
		
		if(storedistance[u]+weight<storedistance[v])
		printf("this graph contains negative egde cycle");
	}
	finalsol(storedistance,v);{
		return;
	}
}
	int main()
	{
		int v,e,s;
		printf("enter number of vertices in graph: ");
		scanf("%d",&v);
		printf("enter number of edges in graph: ");
		scanf("%d",&e);
		printf("enter your source vertex number: ");
		scanf("%d",&s);
		struct graph* graph=creategraph(v,e);
		
		int i;
		for(i=0;i<e;i++){
			printf("enter edge %d properties source,des,weight respectively\n",i+1);
			scanf("%d",&graph->edge[i].source);
			scanf("%d",&graph->edge[i].dest);
			scanf("%d",&graph->edge[i].weight);
		}
		bellmanford(graph,s);
		return 0;
	}
	//complexity O(V.E)//
	


