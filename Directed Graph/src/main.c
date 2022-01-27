#include <stdio.h>
#include <stdlib.h>

// A structure to represent an adjacency list node
struct AdjListNode
{
	char dest;
	struct AdjListNode* next;
};

// A structure to represent an adjacency list
struct AdjList
{
	struct AdjListNode *head;
};

// A structure to represent a graph.
struct Graph
{
	int V;
	struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(char dest)
{
	struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));

    graph->V = V;

	graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, char src, char dest)
{
	// Add an edge from src to dest. A new node is
	// added to the adjacency list of src. The node
	// is added at the beginning
	struct AdjListNode* newNode = newAdjListNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	// Since graph is undirected, add an edge from
	// dest to src also
	newNode = newAdjListNode(src);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(struct Graph* graph)
{
	for (int v = 0; v < graph->V; ++v)
	{
		struct AdjListNode* pCrawl = graph->array[v].head;
		printf("\n Adjacency list of vertex %d\n head ", v);
		while (pCrawl)
		{
			printf("-> %c", pCrawl->dest);
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}

// Driver program to test above functions
int main()
{
	// create the graph given in above fugure
	int V = 9;
	struct Graph* graph = createGraph(V);
	addEdge(graph, 'A', 'F');
    addEdge(graph, 'A', 'C');
    addEdge(graph, 'A', 'B');
	addEdge(graph, 'B', 'G');
    addEdge(graph, 'B', 'C');
	addEdge(graph, 'C', 'F');
	addEdge(graph, 'D', 'C');
	addEdge(graph, 'E', 'D');
    addEdge(graph, 'E', 'C');
    addEdge(graph, 'E', 'J');
	addEdge(graph, 'F', 'D');
    addEdge(graph, 'G', 'C');
    addEdge(graph, 'G', 'E');
    addEdge(graph, 'J', 'D');
    addEdge(graph, 'J', 'K');
	addEdge(graph, 'K', 'E');
	addEdge(graph, 'K', 'G');

	// print the adjacency list representation of the above graph
	printGraph(graph);

	return 0;
}
