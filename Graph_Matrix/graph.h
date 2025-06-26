#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

class Graph
{
private:
    int v_count;
    int e_count;
    int **adj;

public:
    int getVcount();
    void createGraph(int v_number, int e_number);
    void printMatrix();
    void printAdjacentNodes(int v);
    void printAllAdjacentNodes();
    bool isIsolatedNode(int v);
    ~Graph();
};

#endif