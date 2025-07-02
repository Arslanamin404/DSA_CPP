#include <iostream>
#include "GraphList.h"

using namespace std;

int main()
{
    Graph g;
    int src, dest;
    int choice;
    while (true)
    {
        cout << "\n=== Graph Menu ===\n";
        cout << "1. Create Graph\n";
        cout << "2. Add Edge\n";
        cout << "3. Remove Edge\n";
        cout << "4. Print Graph\n";
        cout << "5. BFS\n";
        cout << "6. DFS\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int v;
            cout << "Enter number of vertices: ";
            cin >> v;
            g.createGraph(v);
            break;
        }
        case 2:
        {
            cout << "Enter source and destination vertices (u v): ";
            cin >> src >> dest;
            g.addEdge(src, dest);
            break;
        }
        case 3:
        {
            cout << "Enter source and destination vertices to remove (u v): ";
            cin >> src >> dest;
            g.removeEdge(src, dest);
            break;
        }
        case 4:
            g.printGraph();
            break;
        case 5:
            cout << "Enter source vertex: ";
            cin >> src;
            cout << "\nBFS ORDER: ";
            g.BFS(src);
            break;
        case 6:
            cout << "Enter source vertex: ";
            cin >> src;
            cout << "\nDFS ORDER: ";
            g.DFS(src);
            break;
        case 7:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}