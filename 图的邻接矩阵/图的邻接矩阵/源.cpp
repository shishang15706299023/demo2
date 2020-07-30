#include<iostream>
typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535
int visited[MAXVEX];
using namespace std;

typedef struct
{
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G)
{
	int i, j, k;
	cout << "please enter numVertexes and numEdges:" << endl;
	cin >> G->numVertexes >> G->numEdges;
	for (i = 0; i != G->numVertexes; i++)
	{
		cin >> G->vexs[i];
	}
	for (i = 0; i != G->numVertexes; i++)
		for (j = 0; j < G->numVertexes; j++)
			G->arc[i][j] = INFINITY;
	for (k = 0; k < G->numEdges; k++)
	{
		cout << "please enter i¡¢j¡¢k:" << endl;
		cin >> i >> j >> k;
		G->arc[i][j] = k;
		G->arc[i][j] = G->arc[j][i];
	}
}

void DFS(MGraph G, int i)
{
	int j;
	visited[i] = 1;
	printf("%c",G.vexs[i]);
	for (j = 0; j != G.numVertexes; j++)
	{
		if (G.arc[i][j] = 1 && visited[j])
			DFS(G, j);
	}
}

void DFSTraverse(MGraph G)
{
	int i;
	for (i = 0; i < G.numVertexes; i++)
		visited[i] = 0;
	for (i = 0; i < G.numVertexes; i++)
	{
		if (!visited[i])
			DFS(G, i);
	}
}