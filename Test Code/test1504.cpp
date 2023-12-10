#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100

typedef char VertexType[3];		/*定义VertexType为char数组类型*/

typedef struct vertex
{	
	int adjvex;     				/*顶点编号*/
	struct vertex *next;			/*指向下一个邻接点的指针*/
} VertexNode;

typedef struct
{
	VertexType vexs[MAXVEX];		/*顶点表*/
	VertexNode *adjlist[MAXVEX];	/*邻接表*/
	int numVertexes, numEdges;		/*图中当前的顶点数和边数*/
} GraphAdjList;

int visited[MAXVEX];				/*访问标志的数组*/

int FirstAdjVex(GraphAdjList *G, int v)
{
	if (G->adjlist[v] != NULL)
		return G->adjlist[v]->adjvex;
	return -1;
}

int NextAdjVex(GraphAdjList *G, int v, int w)
{
	VertexNode *p = G->adjlist[v];
	while (p != NULL && p->adjvex != w)
		p = p->next;
	if (p != NULL && p->next != NULL)
		return p->next->adjvex;
	return -1;
}

int DFS(GraphAdjList *G, int v)
{
	visited[v] = 1;
	int w = FirstAdjVex(G, v);
	while (w != -1)
	{
		if (!visited[w])
		{
			if (DFS(G, w))
				return 1;
		}
		else if (visited[w] == 1)
			return 1;
		w = NextAdjVex(G, v, w);
	}
	visited[v] = 2;
	return 0;
}

int isCyclic(int numVertices, int numEdges, int (*edges)[2])
{
	GraphAdjList G;
	G.numVertexes = numVertices;
	G.numEdges = numEdges;

	for (int i = 0; i < numVertices; i++)
	{
		G.adjlist[i] = NULL;
		visited[i] = 0;
	}

	for (int i = 0; i < numEdges; i++)
	{
		int start = edges[i][0];
		int end = edges[i][1];

		VertexNode *node = (VertexNode *)malloc(sizeof(VertexNode));
		node->adjvex = end;
		node->next = G.adjlist[start];
		G.adjlist[start] = node;
	}

	for (int i = 0; i < numVertices; i++)
	{
		if (!visited[i] && DFS(&G, i))
			return 1;
	}

	return 0;
}
