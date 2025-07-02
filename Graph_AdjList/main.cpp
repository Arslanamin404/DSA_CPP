#include <iostream>
#include "GraphList.h"

using namespace std;

int main()
{
    Graph g;

    int choice;
    while (true)
    {
        cout << "\n=== Graph Menu ===\n";
        cout << "1. Create Graph\n";
        cout << "2. Add Edge\n";
        cout << "3. Remove Edge\n";
        cout << "4. Print Graph\n";
        cout << "5. Exit\n";
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
            int src, dest;
            cout << "Enter source and destination vertices (u v): ";
            cin >> src >> dest;
            g.addEdge(src, dest);
            break;
        }
        case 3:
        {
            int src, dest;
            cout << "Enter source and destination vertices to remove (u v): ";
            cin >> src >> dest;
            g.removeEdge(src, dest);
            break;
        }
        case 4:
            g.printGraph();
            break;
        case 5:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}