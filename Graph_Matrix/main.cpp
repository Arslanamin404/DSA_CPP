#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
    int v_count, e_count;

    cout << "Enter number of vertices: ";
    cin >> v_count;

    cout << "Enter number of edges: ";
    cin >> e_count;

    cout << "\n=======================================================" << endl;

    Graph g;
    g.createGraph(v_count, e_count);

    cout << "Graph created successfully ✅";

    cout << "\n=======================================================" << endl;

    cout << "\nAdjacency Matrix:" << endl;
    g.printMatrix();

    cout << "\n=======================================================" << endl;
    g.printAllAdjacentNodes();
    cout << "\n=======================================================" << endl;

    return 0;
}
