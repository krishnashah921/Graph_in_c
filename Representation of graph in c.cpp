#include<stdio.h>
#include<stdlib.h>
//Representation of graph in c
struct adjlistnode
{
	int dest;
	struct adjlistnode* next;
};
struct adjlist
{
	struct adjlistnode *head;
};
struct graph
{
	struct adjlist *array;
	int v;
};
struct adjlistnode* newadjlistnode(int dest)
{
	struct adjlistnode* newnode=(struct adjlistnode*)malloc(sizeof(struct adjlistnode));
	newnode->dest=dest;
	newnode->next=NULL;
	return newnode;
}
struct graph* creategraph(int v)
{
	struct graph* grap=(struct graph*)malloc (sizeof(struct graph));
	grap->v=v;
	grap->array=(struct adjlist*)malloc(v*(sizeof(struct adjlist)));
	int i;
	for (i=0;i<v;++i)
	{
		grap->array[i].head=NULL;
	}
	return grap;
}
void addedge(struct graph* grap,int src,int dest)
{
	struct adjlistnode* check=NULL;
	struct adjlistnode* newnode=newadjlistnode(dest);
	if (grap->array[src].head==NULL)
	{
		newnode->next=grap->array[src].head;
		grap->array[src].head=newnode;
	}
	else
	{
		check=grap->array[src].head;
		while (check->next!=NULL)
		{
			check=check->next;
		}
		check->next=newnode;
		
	}
	newnode=newadjlistnode(src);
	if (grap->array[dest].head==NULL)
	{
		newnode->next=grap->array[dest].head;
		grap->array[dest].head=newnode;
	}
	else 
	{
		check=grap->array[dest].head;
		while (check->next!=NULL)
		{
			check=check->next;
		}
		check->next=newnode;
	}
}
void printgraph(struct graph* grap)
{
	int v;
	for (v=0;v<grap->v;++v)
	{
		struct adjlistnode* temp=grap->array[v].head;
		printf("\n%d\n",v);
		while (temp)
		{
			printf("->%d",temp->dest);
			temp=temp->next;
		}
	printf("\n");
	}
}
int main()
{
	int v=5;
	struct graph* grap=creategraph(v);
	addedge(grap, 0, 1);
    addedge(grap, 0, 4);
    addedge(grap, 1, 2);
    addedge(grap, 1, 3);
    addedge(grap, 1, 4);
    addedge(grap, 2, 3);
    addedge(grap, 3, 4);
    printgraph(grap);
    return 0;
}
