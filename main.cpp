#include <iostream>
#include <string>
#include <cctype>
using namespace std;
 
const int N = 20;       // number of nodes (A to T)
const int INF = 9999;
int graph[N][N];        // 0 means no edge 
void addEdge(char a, char b, int weight)
{
    graph[a - 'A'][b - 'A'] = weight;   // A = 0, B = 1, C = 2, ...
    graph[b - 'A'][a - 'A'] = weight;
}
void setupGraph()
{
    // row 1
    addEdge('A', 'B', 7);  addEdge('B', 'C', 12); addEdge('C', 'D', 21);
 
    // row 2
    addEdge('E', 'F', 5);  addEdge('F', 'G', 16); addEdge('G', 'H', 8);  addEdge('H', 'I', 19);
 
    // row 3
    addEdge('J', 'K', 4);  addEdge('K', 'L', 26); addEdge('L', 'M', 7);
    addEdge('M', 'N', 20); addEdge('N', 'O', 12);
 
    // row 4
    addEdge('P', 'Q', 18); addEdge('Q', 'R', 33); addEdge('R', 'S', 10); addEdge('S', 'T', 25);
 
    // between row 1 and row 2
    addEdge('A', 'E', 13); addEdge('A', 'F', 15); addEdge('B', 'F', 9);  addEdge('B', 'G', 6);
    addEdge('C', 'G', 24); addEdge('C', 'H', 30); addEdge('D', 'H', 10); addEdge('D', 'I', 35);
 
    // between row 2 and row 3
    addEdge('E', 'J', 15); addEdge('E', 'K', 35); addEdge('F', 'K', 18); addEdge('F', 'L', 28);
    addEdge('G', 'L', 9);  addEdge('G', 'M', 11); addEdge('H', 'M', 14); addEdge('H', 'N', 22);
    addEdge('I', 'N', 27); addEdge('I', 'O', 31);
 
    // between row 3 and row 4
    addEdge('J', 'P', 11); addEdge('K', 'P', 7);  addEdge('K', 'Q', 23); addEdge('L', 'Q', 10);
    addEdge('L', 'R', 6);  addEdge('M', 'R', 13); addEdge('M', 'S', 32); addEdge('N', 'S', 22);
    addEdge('N', 'T', 17); addEdge('O', 'T', 18);
}
void dijkstra(int start, int dist[], int previous[])
{
    bool visited[N];
    for (int i = 0; i < N; i++)
    {
        dist[i] = INF;
        previous[i] = -1;
        visited[i] = false;
    }
    dist[start] = 0;
    for (int count = 0; count < N; count++)
    {
        // finding the unvisited node with the smallest distance
        int u = -1;
        int smallest = INF;
        for (int i = 0; i < N; i++)
        {
            if (!visited[i] && dist[i] < smallest)
            {
                smallest = dist[i];
                u = i;
            }
        }
        if (u == -1)
            break;
        visited[u] = true;
        cout << "Visiting " << char('A' + u) << " (distance " << dist[u] << ")" << endl;
 
        // update the distances of neighbours
        for (int v = 0; v < N; v++)
        {
            if (graph[u][v] > 0 && !visited[v] && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                previous[v] = u;
            }
        }
    }
}
 void printPath(int previous[], int node)
{
    if (previous[node] != -1)
    {
        printPath(previous, previous[node]);
        cout << " -> ";
    }
    cout << char('A' + node);
}
 int readNode(string message)
{
    char letter;
    cout << message;
    cin >> letter;
    letter = toupper(letter);
    if (letter < 'A' || letter > 'T')
    {
        cout << "Invalid node. Please use a letter from A to T." << endl;
        return -1;
    }
    return letter - 'A';
}
int main()
{
    int dist[N];
    int previous[N];
     setupGraph();
    int start = readNode("Enter the starting node : ");
    if (start == -1)
        return 0;
 
    int end = readNode("Enter the destination node : ");
    if (end == -1)
        return 0;
 
    cout << endl;
    dijkstra(start, dist, previous);
    cout << "\nRESULT FROM " << char('A' + start) << " TO " << char('A' + end) << ":" << endl;
    if (dist[end] == INF)
    {
        cout << "No path exists." << endl;
    }
    else
    {
        cout << "Shortest Distance: " << dist[end] << endl;
        cout << "Path: ";
        printPath(previous, end);
        cout << endl;
    }
    return 0;
}
