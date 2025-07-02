#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

struct Node
{
    int vertex;
    Node *next;
    Node() {};
    Node(int vertex) : vertex(vertex), next(nullptr) {}
};

class AdjList
{
private:
    Node *start;
    int vertex; // adjList of which node/vertex

public:
    AdjList();
    AdjList(int vertex);
    bool isEmpty();
    Node *getStart();
    Node *search(int vertex);
    void setVertex(int vertex);
    void addNode(int vertex);
    void removeFrontNode();
    void removeNode(int vertex);
    void printList();
    ~AdjList();
};

class Graph
{
private:
    int v_count;
    AdjList *arr;

public:
    Graph();
    int getVcount();
    void createGraph(int v_count);
    void addEdge(int src, int dest);
    void removeEdge(int src, int dest);
    void printGraph();
    void get_neighbours(int vertex);
    bool edgeExists(int src, int dest);
    void BFS(int src);
    void DFS(int src);
    ~Graph();
};

#endif