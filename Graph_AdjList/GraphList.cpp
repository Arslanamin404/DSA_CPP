#include <iostream>
#include "GraphList.h"
#include <queue>
#include <stack>

using namespace std;

AdjList::AdjList()
{
    start = nullptr;
    vertex = 0;
}

AdjList::AdjList(int vertex)
{
    start = nullptr;
    this->vertex = vertex;
}

bool AdjList::isEmpty() { return start == nullptr; }
Node *AdjList::getStart() { return start; }
void AdjList::setVertex(int vertex) { this->vertex = vertex; }

void AdjList::addNode(int vertex)
{
    // PREVENT DUBLICATE ENTRIES
    for (Node *temp = start; temp; temp = temp->next)
        if (temp->vertex == vertex)
            return;

    Node *new_node = new Node(vertex);
    new_node->next = start;
    start = new_node;
}

void AdjList::removeFrontNode()
{
    if (isEmpty())
    {
        cout << "LIST IS EMPTY!" << endl;
        return;
    }
    Node *temp = start;
    start = start->next;
    delete temp;
}

Node *AdjList::search(int vertex)
{
    Node *temp = start;
    while (temp)
    {
        if (temp->vertex == vertex)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

void AdjList::removeNode(int vertex)
{
    Node *data_ptr = search(vertex);
    if (!data_ptr)
    {
        cout << "removeNode() Failed! " << vertex << " vertex not found in list" << endl;
        return;
    }
    if (start == data_ptr)
        removeFrontNode();
    else
    {
        Node *temp = start;
        while (temp->next != data_ptr)
            temp = temp->next;
        temp->next = data_ptr->next;
        delete data_ptr;
    }
}

void AdjList::printList()
{
    Node *temp = start;
    while (temp)
    {
        cout << temp->vertex << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
}

AdjList::~AdjList()
{
    while (!isEmpty())
        removeFrontNode();
}

Graph::Graph() : v_count(0), arr(nullptr) {}

int Graph::getVcount() { return v_count; }

void Graph::createGraph(int v_count)
{
    this->v_count = v_count;
    arr = new AdjList[v_count];

    for (int i = 0; i < v_count; i++)
    {
        arr[i].setVertex(i);
        cout << "Vertex " << i << endl;

        int n;
        cout << "Enter number of adjacent nodes of V" << i << ": ";
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            int val;
            cout << "Enter vertex/node number connecteing to it (0 to " << v_count - 1 << "): ";
            cin >> val;

            if (val >= v_count || val < 0)
            {
                cout << "Invalid node index. Please enter a value between 0 and " << v_count - 1 << ".\n";
                j--;
                continue;
            }

            if (val == i)
            {
                cout << " Node cannot connect to itself (self-loop). Skipping...\n";
                j--;
                continue;
            }

            arr[i].addNode(val);
        }
    }
}

void Graph::addEdge(int src, int dest)
{
    if (src < 0 || dest < 0 || src >= v_count || dest >= v_count)
    {
        std::cout << "Invalid vertex number!\n";
        return;
    }
    arr[src].addNode(dest);
    arr[dest].addNode(src); // undirected graph
}

void Graph::removeEdge(int src, int dest)
{
    if (src < 0 || dest < 0 || src >= v_count || dest >= v_count)
    {
        std::cout << "Invalid vertex number!\n";
        return;
    }

    arr[src].removeNode(dest);
    arr[dest].removeNode(src);
}

void Graph::printGraph()
{
    for (int i = 0; i < v_count; i++)
    {
        cout << "Adjacency list of V" << i << ": ";
        arr[i].printList();
        cout << endl;
    }
}
void Graph::get_neighbours(int vertex)
{
    if (vertex >= v_count || vertex < 0)
    {
        cout << "INVALID VERTEX!" << endl;
        return;
    }
    Node *temp = arr[vertex].getStart();
    if (!temp)
        cout << "None neighbour" << endl;
    else
    {
        while (temp)
        {
            cout << temp->vertex << " ";
            temp = temp->next;
        }
    }
    cout << endl;
}
bool Graph::edgeExists(int src, int dest)
{
    if (src < 0 || dest < 0 || src >= v_count || dest >= v_count)
    {
        std::cout << "Invalid vertex number!\n";
        return false;
    }

    return arr[src].search(dest) != nullptr;
}
void Graph::BFS(int src)
{
    if (src < 0 || src >= getVcount())
    {
        cout << "Invalid source vertex.\n";
        return;
    }
    bool *visited = new bool[getVcount()](); // Initialize all to false

    queue<int> Q;

    Q.push(src);
    visited[src] = true;

    cout << "BFS Traversal stating from V" << src << endl;

    while (!Q.empty())
    {
        int current = Q.front();
        cout << current << " ";
        Q.pop();

        Node *temp = arr[current].getStart();
        while (temp)
        {
            if (!visited[temp->vertex])
            {
                Q.push(temp->vertex);
                visited[temp->vertex] = true;
            }
            temp = temp->next;
        }
    }
    cout << endl;
    delete[] visited;
}
void Graph::DFS(int src)
{
    if (src < 0 || src >= getVcount())
    {
        cout << "Invalid source vertex.\n";
        return;
    }
    if (src < 0 || src >= getVcount())
    {
        cout << "Invalid source vertex.\n";
        return;
    }
    bool *visited = new bool[getVcount()]();

    stack<int> S;
    S.push(src);

    visited[src] = true;

    cout << "DFS Traversal stating from V" << src << endl;
    while (!S.empty())
    {
        int current = S.top();
        cout << current << " ";
        S.pop();

        Node *temp = arr[current].getStart();

        while (temp)
        {
            if (!visited[temp->vertex])
            {
                S.push(temp->vertex);
                visited[temp->vertex] = true;
            }
            temp = temp->next;
        }
    }

    delete[] visited;
}
Graph::~Graph() { delete[] arr; }