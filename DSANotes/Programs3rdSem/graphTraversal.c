#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 100

// Linked List to store the connected/neighbouring nodes 
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int capacity;  // Maximum capacity of the graph
    Node** adjList;  // ADJ LIST for variable number of nodes
} Graph;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int capacity) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->capacity = capacity;
    graph->adjList = (Node**)malloc(capacity * sizeof(Node*));
    for (int i = 0; i < capacity; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int u, int v, int direction) {
    // Add edge from u to v
    Node* newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    // For undirected graph, add edge from v to u as well
    if (direction == 0) {
        newNode = createNode(u);
        newNode->next = graph->adjList[v];
        graph->adjList[v] = newNode;
    }
}

void printAdjList(Graph* graph, int n) {
    for (int i = 0; i < n; i++) {
        Node* temp = graph->adjList[i];
        printf("%d -> ", i);
        while (temp) {
            printf("%d, ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void bfs(Graph* graph, int node, int n) {
    int visited[n];
    int queue[MAX_QUEUE_SIZE];
    int front = -1, rear = -1;

    for (int i = 0; i < n; ++i) {
        visited[i] = 0;
    }

    visited[node] = 1;
    //push front is ++rear
    queue[++rear] = node;

    //while q is not empty condition
    while (front != rear) {
        //pop is ++front
        int current = queue[++front];
        printf("%d ", current);

        //take the node presnt in the CURRENT NODE
        Node* temp = graph->adjList[current];
        //traverse the neighbors
        while (temp) {
            int neighbour = temp->vertex;
            if (!visited[neighbour]) {
                visited[neighbour] = 1;
                //psuh fornt is ++rear
                queue[++rear] = neighbour;
            }
            //move to next neigbour
            temp = temp->next;
        }
    }
}

void dfsUtil(Graph* graph, int node, int visited[]) {
    visited[node] = 1;
    printf("%d ", node);

    //take the node present in the adj list
    Node* temp = graph->adjList[node];
    //traverse the neighbors
    while (temp) {
        int neighbour = temp->vertex;
        if (!visited[neighbour]) {
            dfsUtil(graph, neighbour, visited);
        }
        temp = temp->next;
    }
}

void dfs(Graph* graph, int node, int n) {
    int *visited = (int *)calloc(n, sizeof(int));
    dfsUtil(graph, node, visited);
    free(visited);
}

// //FOR DISCONNECTED GRAPHS
// void bfs(Graph* graph, int node, int n) {
//     int visited[n];
//     int queue[MAX_QUEUE_SIZE];
//     int front = -1, rear = -1;

//     for (int i = 0; i < n; ++i) {
//         visited[i] = 0;
//     }

//     for (int i = 0; i < n; ++i) {
//         if (!visited[i]) {
//             visited[i] = 1;
//             queue[++rear] = i;

//             while (front != rear) {
//                 int current = queue[++front];
//                 printf("%d ", current);

//                 Node* temp = graph->adjList[current];
//                 while (temp) {
//                     int neighbour = temp->vertex;
//                     if (!visited[neighbour]) {
//                         visited[neighbour] = 1;
//                         queue[++rear] = neighbour;
//                     }
//                     temp = temp->next;
//                 }
//             }
//         }
//     }
// }

// //for diconnected graphs
// void dfs(Graph* graph, int node, int n) {
//     int visited[n];
//     for (int i = 0; i < n; ++i) {
//         visited[i] = 0;
//     }

//     for (int i = 0; i < n; ++i) {
//         if (!visited[i]) {
//             dfsUtil(graph, i, visited);
//         }
//     }
// }


void inputGraph(Graph* graph, int m) {
    printf("\nENTER THE GRAPH AS AN EDGE OF NODE -> NODE: \n");
    for (int i = 0; i < m; i++) {
        int u, v, dirn;
        printf("EDGE %d: \n", i + 1);
        scanf("%d", &u);
        printf("  -> ");
        scanf("%d", &v);
        printf("\nDIRECTED?? (1/0) : ");
        scanf("%d", &dirn);
        addEdge(graph, u, v, dirn);
    }
}

int main() {
    int n, m;
    printf("ENTER THE CAPACITY OF THE GRAPH (Maximum number of nodes): ");
    scanf("%d", &n);
    printf("ENTER THE NUMBER OF EDGES: ");
    scanf("%d", &m);

    Graph* graph = createGraph(n);

    inputGraph(graph, m);

    printf("Adjacency List:\n");
    printAdjList(graph, n);
    
    printf("BFS traversal starting from vertex 0: ");
    bfs(graph, 0, n);
    printf("\n");
    
    printf("DFS traversal starting from vertex 0: ");
    dfs(graph, 0, n);
    printf("\n");

    return 0;
}
/*
ENTER THE CAPACITY OF THE GRAPH (Maximum number of nodes): 5
ENTER THE NUMBER OF EDGES: 6

ENTER THE GRAPH AS A PAIR OF NODE -> NODE: 
Pair 1: 
0
  -> 1

DIRECTED?? (1/0) : 0
Pair 2: 
1
  -> 2

DIRECTED?? (1/0) : 0
Pair 3: 
2
  -> 3

DIRECTED?? (1/0) : 0
Pair 4: 
3
  -> 1

DIRECTED?? (1/0) : 0
Pair 5: 
3
  -> 4

DIRECTED?? (1/0) : 0
Pair 6: 
0
  -> 4

DIRECTED?? (1/0) : 0
Adjacency List:
0 -> 4, 1,
1 -> 3, 2, 0,
2 -> 3, 1,
3 -> 4, 1, 2,
4 -> 0, 3,
BFS traversal starting from vertex 0: 0 4 1 3 2      
DFS traversal starting from vertex 0: 0 4 3 1 2 
*/
