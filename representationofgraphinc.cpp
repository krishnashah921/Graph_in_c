#include<stdio.h>
#include<stdlib.h>
struct adjlistnode
{
	int dest;
	struct adjlistnode* next;
};
struct adjlist
{
	struct adjlistnode* head;
};
struct Graph
{
	int v;
	struct adjlist* array;
};
struct adjlistnode* newadjlistnode(int dest);
struct Graph* creategraph(int v );
void addedge(struct Graph* graph,int src,int dest);
void printgraph(struct Graph* graph);
int main()
{
	int v=5;
	struct Graph*  graph;
	graph=creategraph(v);
	
	
	addedge(graph, 0, 1);
    addedge(graph, 0, 4);
    addedge(graph, 1, 2);
    addedge(graph, 1, 3);
    addedge(graph, 1, 4);
    addedge(graph, 2, 3);
    addedge(graph, 3, 4);
    printgraph(graph);
}
struct adjlistnode* newadjlistnode(int dest)
{
	struct adjlistnode* newnode=(struct adjlistnode*)malloc(sizeof(struct adjlistnode));
	newnode->dest=dest;
	newnode->next=NULL;
	return newnode;
}
struct Graph* creategraph(int v )
{
	struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
	graph->v=v;
	graph->array=(struct adjlist*)malloc(v*(sizeof(struct adjlist)));
	int i;
	for (i=0;i<v;++i)
	{
		graph->array[i].head=NULL;
	}
	return graph;
}
void addedge(struct Graph* graph,int src,int dest)
{
	struct adjlistnode* check=NULL;
	struct adjlistnode* newnode=newadjlistnode(dest);
	if(graph->array[src].head==NULL)
	{
		newnode->next=graph->array[src].head;
		graph->array[src].head=newnode;
	}
	else
	{
		check=graph->array[src].head;
		while(check->next!=NULL)
		{
			check=check->next;
		}
		check->next=newnode;
	}
	newnode=newadjlistnode(src);
	if (graph->array[dest].head==NULL)
	{
		newnode->next=graph->array[dest].head;
		graph->array[dest].head=newnode;
	}
	else
	{
		check=graph->array[dest].head;
		while(check->next!=NULL)
		{
			check=check->next;
		}
		check->next=newnode;
	}
}
void printgraph(struct Graph* graph)
{
	int v;
	for (v=0;v<graph->v;++v)
	{
		struct adjlistnode* temp=graph->array[v].head;
		printf("\nAdjacency list of %d\nHead",v);
		while (temp)
		{
			printf("->%d",temp->dest);
			temp=temp->next;
		}
	printf("\n");
	}
}
