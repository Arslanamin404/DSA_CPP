#include <iostream>
#include "graph.h"

using namespace std;

int Graph::getVcount() { return v_count; }

void Graph::createGraph(int v_number, int e_number)
{
    v_count = v_number;
    e_count = e_number;
    adj = new int *[v_count];

    for (int i = 0; i < v_count; i++)
        adj[i] = new int[v_count];

    for (int i = 0; i < v_count; i++)
        for (int j = 0; j < v_count; j++)
            adj[i][j] = 0;

    int u, v;

    for (int k = 0; k < e_count; k++)
    {
        cout << "EDGE " << k + 1 << endl;
        cout << "ENTER NODE NUMBERS CONNECTING EDGE (u v): ";
        cin >> u >> v;
        if (u >= v_count || v >= v_count || v < 0 || u < 0)
        {
            cout << "INVALID NODE! Please enter node number form 0 to " << v_count - 1 << endl;
            k--;
            continue; // to skip the invalid edge iteration
        }

        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

void Graph::printMatrix()
{
    for (int i = 0; i < v_count; i++)
    {
        for (int j = 0; j < v_count; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}
void Graph::printAdjacentNodes(int v)
{
    if (v < 0 || v >= v_count)
    {
        cout << "INVALID NODE NUMBER" << endl;
        return;
    }
    cout << "Adjacent nodes of NODE " << v << ": ";
    for (int i = 0; i < v_count; i++)
    {
        if (adj[v][i] == 1)
            cout << i << " ";
    }
}
void Graph::printAllAdjacentNodes()
{
    for (int i = 0; i < v_count; i++)
    {
        cout << "Adjacent nodes of NODE " << i << ": ";
        for (int j = 0; j < v_count; j++)
        {
            if (adj[i][j] == 1)
                cout << j << " ";
        }
        cout << endl;
    }
}
bool Graph::isIsolatedNode(int v)
{
    bool flag = true;
    if (v < 0 || v >= v_count)
    {
        cout << "INVALID NODE NUMBER" << endl;
        return false;
    }
    for (int i = 0; i < v_count; i++)
    {
        if (adj[v][i] == 1)
        {
            flag = false;
            break;
        }
    }

    return flag;
}
Graph::~Graph()
{
    for (int i = 0; i < v_count; i++)
        delete[] adj[i]; // this will delete every 1D array of 2D array

    delete[] adj;
}
