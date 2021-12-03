#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <fstream>
#include <stack>
#include <limits.h>
#include <iomanip>
#include <chrono>
using namespace std;
using namespace chrono;


class Graph
{
private:
    unordered_map<string, int> mapping;
    map<int, set<int>> adjList;
    int numVertices = 0;
    //pair that shows the most connected vertex, mostConnected.first shows vertex, mostConnected.second shows number of connections
    pair<int, int> mostConnected = { 0, 0 };

public:
    void insertEdge(string from, string to);
    set<int> getAdjacent(string vertex);
    void printGraph();
    int getNumvertices() { return numVertices; }
    //Overloaded the functions to either traverse the whole graph from initial vertex inserted, or from specified position 
    vector<pair<int, int>> Dijkstra(int start);
    vector<int> BFS();
    vector<int> BFS(int start, vector<int>& pred, vector<int>& dist);
    vector<int> DFS();
    vector<int> DFS(int start, vector<int>& pred, vector<int>& dist);
    //returns the degree of a vertex. Since undirected, in degree = out degree
    vector<int> degree();
    //returns the vertex with the highest degree
    pair<int, int> getMostConnected() { return mostConnected; };
    unordered_map<string, int> getMapping() { return mapping; };
    //prints the vertex and the string associated with that vertex
    void printMapping();
};

void Graph::insertEdge(string from, string to)
{
    if (mapping.find(from) == mapping.end())
    {
        mapping[from] = numVertices;
        numVertices++;
    }

    if (mapping.find(to) == mapping.end())
    {
        mapping[to] = numVertices;
        numVertices++;
    }
    bool from1 = true, to1 = true;

    adjList[mapping[from]].insert(mapping[to]);
    adjList[mapping[to]].insert(mapping[from]);


}

set<int> Graph::getAdjacent(string vertex)
{
    return adjList[mapping[vertex]];
}

void Graph::printGraph()
{
    for (auto i : adjList) {
        cout << i.first << ":";
        for (auto j : i.second) {
            cout << " " << j;
        }
        cout << endl;
    }
    cout << "Number of vertices: " << numVertices << endl;
}


//Dijkstra with any start vertex
vector<pair<int, int>> Graph::Dijkstra(int start)
{
    //initialize vector of solutions and vector of nodes visited
    vector<pair<int, int>> distances;
    distances.resize(numVertices);
    vector<bool> visited;
    visited.resize(numVertices);
    queue<int> q;
    for (int i = 0; i < numVertices; i++)
    {
        distances[i].first = INT_MAX;
        visited[i] = 0;
    }
    //set does not have random access, so set was transferred to vector to make operations easier
    vector<int> inSet;
    for (int i : adjList[start])
        inSet.push_back(i);
    //initialize distances from source to adjacent vertices
    for (unsigned int i = 0; i < inSet.size(); i++)
    {
        int index = inSet[i];
        distances[index].first = 1;
    }
    //start vertex distance initialized
    distances[start].first = 0;
    distances[start].second = -1;
    visited[start] = 1;

    //will iterate through adjacency list to make sure every path traversed
    for (unsigned int i = 0; i < adjList[start].size(); i++)
    {
        q.push(inSet[i]);
        int curr = 0;
        distances[inSet[i]].second = start;
        while (!q.empty())
        {
            curr = q.front();
            q.pop();
            for (auto iter : adjList[curr])
            {
                int index = iter;
                if (distances[curr].first + 1 < distances[index].first)
                {
                    distances[index].first = distances[curr].first + 1;
                    distances[index].second = curr;
                }
                if (!visited[index])
                {
                    q.push(index);
                    visited[index] = 1;
                }
            }
        }
    }
    return distances;
}

//Traverses from the first vertex inserted to the rest of the graph
vector<int> Graph::BFS()
{
    queue<int> q;
    vector<bool> visited;
    vector<int> sol;
    for (int i = 0; i < numVertices; i++)
        visited.push_back(0);
    visited[0] = 1;
    q.push(0);
    while (!q.empty())
    {
        int curr = q.front();
        sol.push_back(curr);
        q.pop();
        for (int i : adjList[curr])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    return sol;
}

//Overloaded to start from a start vertex until it reaches the target
vector<int> Graph::BFS(int start, vector<int>& pred, vector<int>& dist)
{
    queue<int> q;
    vector<bool> visited;
    vector<int> sol;


    for (int i = 0; i < numVertices; i++)
        visited.push_back(0);
    visited[start] = 1;
    q.push(start);
    while (!q.empty())
    {
        int curr = q.front();
        sol.push_back(curr);
        q.pop();
        for (int i : adjList[curr])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
                pred[i] = curr;
                dist[i] = dist[curr] + 1;
            }
        }
    }
    return sol;
}

//Traverses from the first vertex inserted to the rest of the graph
vector<int> Graph::DFS()
{
    stack<int> s;
    vector<bool> visited;
    vector<int> sol;
    for (int i = 0; i < numVertices; i++)
        visited.push_back(0);
    visited[0] = 1;
    s.push(0);
    while (!s.empty())
    {
        int curr = s.top();
        sol.push_back(curr);
        s.pop();
        for (int i : adjList[curr])
        {

            if (!visited[i])
            {
                s.push(i);
                visited[i] = 1;
            }
        }
    }
    return sol;
}

//Overloaded to start from a start vertex until it reaches the target
vector<int> Graph::DFS(int start, vector<int>& pred, vector<int>& dist)
{
    stack<int> s;
    vector<bool> visited;
    vector<int> sol;
    for (int i = 0; i < numVertices; i++)
        visited.push_back(0);
    visited[start] = 1;
    s.push(start);
    while (!s.empty())
    {
        int curr = s.top();
        sol.push_back(curr);
        s.pop();
        for (int i : adjList[curr])
        {
            if (!visited[i])
            {
                s.push(i);
                visited[i] = 1;
                pred[i] = curr;
                dist[i] = dist[curr] + 1;
            }
        }
    }
    return sol;
}

//returns the degree of a vertex. Since undirected, in degree = out degree
vector<int> Graph::degree()
{
    vector<int> sol;
    for (int i = 0; i < numVertices; i++)
        sol.push_back(0);
    for (auto iter : adjList)
    {
        for (int i : iter.second)
        {
            sol[iter.first]++;
            if (sol[iter.first] > mostConnected.second)
            {
                mostConnected.first = iter.first;
                mostConnected.second = sol[iter.first];
            }
        }
    }
    return sol;
}

//prints the mapping of string as read in with the vertex number assigned 
void Graph::printMapping()
{
    for (auto iter = mapping.begin(); iter != mapping.end(); iter++)
        cout << "Vertex as read in: " << (*iter).first << "     Assigned Vertex number: " << (*iter).second << endl;
}
//reads in the .edges file
void loadFromFile(string filename, Graph& graph) {
    ifstream fileStream(filename);
    string line;
    string to, from;

    if (fileStream.is_open()) {
        while (getline(fileStream, line)) {
            istringstream stringStream(line);
            getline(stringStream, from, ' ');
            getline(stringStream, to, ' ');

            graph.insertEdge(from, to);
        }
        cout << "File Input from " << filename << " successful." << endl;
    }
}

//recursively runs the dijkstra a specified amount 
void DijkstraStats(Graph& graph, int count)
{
    if (count <= 0)
        return;
    auto start = high_resolution_clock::now();
    graph.Dijkstra(0);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time taken for Dijkstra: " << duration.count() << " microseconds" << endl;
    DijkstraStats(graph, count - 1);
}

//recursively runs the BFS a specified amount, will traverse entire graph 
void BFS_Stats(Graph& graph, int count)
{
    if (count <= 0)
        return;
    auto start = high_resolution_clock::now();
    graph.BFS();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time taken for BFS: " << duration.count() << " microseconds" << endl;
    BFS_Stats(graph, count - 1);
}

//recursively runs the DFS a specified amount, will traverse entire graph 
void DFS_Stats(Graph& graph, int count)
{
    if (count <= 0)
        return;
    auto start = high_resolution_clock::now();
    graph.DFS();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time taken for DFS: " << duration.count() << " microseconds" << endl;
    DFS_Stats(graph, count - 1);
}

void statistics(Graph& graph)
{
    int count = 5;
    DijkstraStats(graph, count);
    cout << endl;
    BFS_Stats(graph, count);
    cout << endl;
    DFS_Stats(graph, count);
    cout << endl;
}

void printMenu() {
    cout << "Please Select a Menu Option:\n1) Print Graph\n2) Djikstra's Path\n3) BFS\n4) DFS\n5) Degree \n6) Statistics\n7) Print mapping of vertices\n8) Exit\n\n";
}

int main()
{
    Graph graph;
    loadFromFile("input1.edges", graph);

    bool running = true;

    while (running) {
        cout << "\n\n";
        printMenu();
        int input;
        cin >> input;

        switch (input) {
        case 1:
            graph.printGraph();
            break;
        case 2:
        {
            bool valid = false;
            int start = 0;
            int end = 0;
            while (!valid)
            {
                cout << "What is the starting vertex: ";
                cin >> start;
                if (start < graph.getNumvertices() && start >= 0)
                    valid = true;
                else
                    cout << "This is not a valid vertex, try again." << endl;

                cout << "What is the end vertex: ";
                cin >> end;
                if (end < graph.getNumvertices() && end >= 0)
                    valid = true;
                else
                {
                    cout << "This is not a valid end vertex, try again." << endl;
                    continue;
                }
            }
            vector<pair<int, int>> distances = graph.Dijkstra(start);

            int nextNode = end;
            vector<int> path;
            path.push_back(nextNode);
            cout << "The path found from " << start << " to " << end << " was: " << endl;

            while (nextNode != start) {
                nextNode = distances[nextNode].second;
                path.push_back(nextNode);
            }
            for (int i = path.size() - 1; i > 0; i--) {
                cout << path[i] << " -> ";
            }
            cout << path[0];

            cout << "\n\n\nHere are the distances and paths to all other nodes in the graph: \n\n";

            cout << "Vertices   " << '|' << setfill(' ') << setw(23) << "Distances from " << start << setfill(' ') << setw(7 - to_string(start).length()) << "|" << setfill(' ') << setw(20) << "Previous Vertex" << endl;
            for (unsigned int i = 0; i < distances.size(); i++)
            {
                cout << i << setfill(' ') << setw(12 - to_string(i).length());
                cout << '|' << setfill(' ') << setw(15) << distances[i].first;
                cout << setfill(' ') << setw(15) << '|' << setfill(' ') << setw(15) << distances[i].second << endl;
            }
            break;
        }
        case 3:
        {
            int start = 0;
            int end = 0;
            bool startValid = false, endValid = false;
            while (!startValid && !endValid)
            {
                cout << "What is the starting vertex: ";
                cin >> start;
                if (start < graph.getNumvertices() && start >= 0)
                    startValid = true;
                else
                {
                    cout << "This is not a valid start vertex, try again." << endl;
                    continue;
                }

                cout << "What is the end vertex: ";
                cin >> end;
                if (end < graph.getNumvertices() && end >= 0)
                    startValid = true;
                else
                {
                    cout << "This is not a valid end vertex, try again." << endl;
                    continue;
                }
            }
            vector<int> pred(graph.getNumvertices());
            vector<int> dist(graph.getNumvertices());
            vector<int> BFS = graph.BFS(start, pred, dist);

            int nextNode = end;
            vector<int> path;
            path.push_back(nextNode);
            cout << "The path found from " << start << " to " << end << " was: " << endl;

            while (nextNode != start) {
                nextNode = pred[nextNode];
                path.push_back(nextNode);
            }
            for (int i = path.size() - 1; i > 0; i--) {
                cout << path[i] << " -> ";
            }
            cout << path[0];

            cout << "\n\n\nHere are the distances and paths to all other nodes in the graph: \n\n";

            cout << "Vertices   " << '|' << setfill(' ') << setw(23) << "Distances from " << start << setfill(' ') << setw(7 - to_string(start).length()) << "|" << setfill(' ') << setw(20) << "Previous Vertex" << endl;
            for (unsigned int i = 0; i < dist.size(); i++)
            {
                cout << i << setfill(' ') << setw(12 - to_string(i).length());
                cout << '|' << setfill(' ') << setw(15) << dist[i];
                cout << setfill(' ') << setw(15) << '|' << setfill(' ') << setw(15) << pred[i] << endl;
            }
            break;
        }
        case 4:
        {
            int start = 0;
            int end = 0;
            bool startValid = false, endValid = false;
            while (!startValid && !endValid)
            {
                cout << "What is the starting vertex: ";
                cin >> start;
                if (start < graph.getNumvertices() && start >= 0)
                    startValid = true;
                else
                {
                    cout << "This is not a valid start vertex, try again." << endl;
                    continue;
                }

                cout << "What is the end vertex: ";
                cin >> end;
                if (end < graph.getNumvertices() && end >= 0)
                    startValid = true;
                else
                {
                    cout << "This is not a valid end vertex, try again." << endl;
                    continue;
                }
            }
            vector<int> pred(graph.getNumvertices());
            vector<int> dist(graph.getNumvertices());
            vector<int> DFS = graph.DFS(start, pred, dist);

            int nextNode = end;
            vector<int> path;
            path.push_back(nextNode);
            cout << "The path found from " << start << " to " << end << " was: " << endl;

            while (nextNode != start) {
                nextNode = pred[nextNode];
                path.push_back(nextNode);
            }
            for (int i = path.size() - 1; i > 0; i--) {
                cout << path[i] << " -> ";
            }
            cout << path[0];

            cout << "\n\n\nHere are the distances and paths to all other nodes in the graph: \n\n";

            cout << "Vertices   " << '|' << setfill(' ') << setw(23) << "Distances from " << start << setfill(' ') << setw(7 - to_string(start).length()) << "|" << setfill(' ') << setw(20) << "Previous Vertex" << endl;
            for (unsigned int i = 0; i < dist.size(); i++)
            {
                cout << i << setfill(' ') << setw(12 - to_string(i).length());
                cout << '|' << setfill(' ') << setw(15) << dist[i];
                cout << setfill(' ') << setw(15) << '|' << setfill(' ') << setw(15) << pred[i] << endl;
            }
            break;
        }
        case 5:
        {
            vector<int> deg = graph.degree();
            for (unsigned int i = 0; i < deg.size(); i++)
            {
                cout << i << " " << deg[i] << endl;
            }
            int mostConnected = graph.getMostConnected().first;
            int numConnections = graph.getMostConnected().second;
            string vertex;
            unordered_map<string, int> temp = graph.getMapping();
            for (auto iter = temp.begin(); iter != temp.end(); iter++)
            {
                if ((*iter).second == mostConnected)
                    vertex = (*iter).first;
            }
            cout << "Most connected Vertex was " << mostConnected << " (Vertex name " << vertex << ")";
            cout << " with " << numConnections << " connections" << endl;
            break;
        }
        case 6:
            statistics(graph);
            break;
        case 7:
            graph.printMapping();
            break;
        case 8:
            running = false;
            break;
        default:
            cout << "INVALID INPUT" << endl;
            break;
        }
    }
    return 0;
}
