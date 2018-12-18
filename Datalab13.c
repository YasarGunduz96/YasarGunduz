#include <stdio.h>
#include <stdlib.h>
#define N 6

struct Graph {
	struct node* head[N];
};

struct node {
	int dest,weight;
	struct node* next;
};

struct Edge {
	int src, dest,weight;
	//src : Source;
	//dest: Destination;
	//weight: Data Verisi; /*Joker*/
};

struct Graph* createGraph(struct Edge edges[], int n){
	struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    // initialize head pointer for all vertices;
	for (int i = 0; i < N; i++)
		graph->head[i] = NULL;

	for (int i = 0; i < n; i++){
		int src = edges[i].src;
		int dest = edges[i].dest;
		int weight = edges[i].weight;

        //One Linked List /*Directed Yapý Oluyor*/
		struct node* newNode=(struct node*)malloc(sizeof(struct node));
		newNode->dest = dest;
        newNode->weight = weight;
		newNode->next = graph->head[src];
		graph->head[src] = newNode;

		//Double Linked List  /*Undirected Yapý Oluyor.*/
        newNode=(struct node*)malloc(sizeof(struct node));
        newNode->dest = src;
        newNode->next = graph->head[dest];
        graph->head[dest] = newNode;
	}
	return graph;
}

void printGraph(struct Graph* graph){
	for (int i = 0; i < N; i++){
		struct node* temp = graph->head[i];
		while (temp != NULL){
			printf("(%d -> %d (%d)\t", i, temp->dest,temp->weight);
			temp = temp->next;
		}
    printf("\n");
	}
}

int main(void){
	struct Edge edges[] ={ { 0, 1, 25 }, { 1, 2 ,35}, { 2, 0,45 }, { 2, 1,55 },{ 3, 2,65 }, { 4, 5,75 }, { 5, 4,85 } };
	int n = sizeof(edges)/sizeof(edges[0]);
	struct Graph *graph = createGraph(edges, n);
	printGraph(graph);
	return 0;
}
