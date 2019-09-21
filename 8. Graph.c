// # Program to implement adjacency list of a graph
// # @Author: D. Kasi Pavan Kumar
// # @Date: 19 September 2019

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node {
    int destination;
    struct Node *next;
};

struct List {
    struct Node *head;
};

struct Graph {
    int vertices;
    struct List *array;
};

struct Node *CreateNode(int destination) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> destination = destination;
    newNode -> next = NULL;
    return(newNode);
}

struct Graph *CreateGraph(int vertices) {
    struct Graph *newGraph = (struct Graph*) malloc(sizeof(struct Graph));
    newGraph -> vertices = vertices;
    newGraph -> array = (struct List*) malloc(vertices * sizeof(struct List));

    int i;
    for(i = 0; i < vertices; ++i) {
        newGraph -> array[i].head = NULL;
    }

    return(newGraph);
}

void AddEdge(struct Graph *graph, int source, int destination) {
    struct Node *node = CreateNode(destination);
    node -> next = graph -> array[source].head;
    graph -> array[source].head = node;

    node = CreateNode(source);
    node -> next = graph -> array[destination].head;
    graph -> array[destination].head = node;
}

void ShowGraph(struct Graph *graph) {
    int vertices;
    for(vertices = 0; vertices < graph -> vertices; ++vertices) {
        struct Node *crawl = graph -> array[vertices].head;
        printf("\nAdjacency list of vertex %d\n head", vertices);
        while(crawl) {
            printf(" -> %d", crawl -> destination);
            crawl = crawl -> next;
        }
        printf("\n");
    }
}

int main() {
    int vertices = 5;
    struct Graph *graph = CreateGraph(vertices);

    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 4);
    AddEdge(graph, 1, 2);
    AddEdge(graph, 1, 3);
    AddEdge(graph, 1, 4);
    AddEdge(graph, 2, 3);
    AddEdge(graph, 3, 4);

    ShowGraph(graph);

    getch();
    return 0;

}