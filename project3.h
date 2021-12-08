
#pragma once
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
#include "RandomVertex.h"
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
    Graph();
    void insertEdge(string from, string to);
    set<int> getAdjacent(string vertex);
    void printGraph();
    int getNumvertices() { return numVertices; }
    //Overloaded the functions to either traverse the whole graph from initial vertex inserted, or from specified position 
    vector<pair<int, int>> Dijkstra(int start);
    void BFS(int start, int end);
    vector<int> BFS(int start, int end, vector<int>& pred, vector<int>& dist);
    void DFS(int start, int end);
    vector<int> DFS(int start, int end, vector<int>& pred, vector<int>& dist);
    //returns the degree of a vertex. Since undirected, in degree = out degree
    vector<int> degree();
    //returns the vertex with the highest degree
    pair<int, int> getMostConnected() { return mostConnected; };
    unordered_map<string, int> getMapping() { return mapping; };
    //prints the vertex and the string associated with that vertex
    void printMapping();
    void loadFromFile(string filename);
};

//load in data from the files, initializes graph
Graph::Graph()
{
    loadFromFile("input1.edges");
}

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

//Searches from specified start to end, does not keep track (for stats)
void Graph::BFS(int start, int end)
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
            if (curr == end)
                return;
        }
    }
}


//Overloaded to start from a start vertex until it reaches the target
vector<int> Graph::BFS(int start, int end, vector<int>& pred, vector<int>& dist)
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
            if (curr == end)
                return sol;
        }
    }
    return sol;
}

//DFS for stats, looks for start and target but does not keep track
void Graph::DFS(int start, int end)
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
            if (curr == end)
                return;

        }
    }
}

//Overloaded to start from a start vertex until it reaches the target
vector<int> Graph::DFS(int start, int end, vector<int>& pred, vector<int>& dist)
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
            if (curr == end)
                return sol;
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
void Graph::loadFromFile(string filename) {
    ifstream fileStream(filename);
    string line;
    string to, from;

    if (fileStream.is_open()) {
        while (getline(fileStream, line)) {
            istringstream stringStream(line);
            getline(stringStream, from, ' ');
            getline(stringStream, to, ' ');
            insertEdge(from, to);
        }
        cout << "File Input from " << filename << " successful." << endl;
    }
}

//recursively runs the dijkstra a specified amount 
void DijkstraStats(Graph& graph, int count)
{
    if (count <= 0)
        return;
    //get a random start vertex
    int startV = RandomVertex::Int(0, graph.getNumvertices() - 1);
    auto start = high_resolution_clock::now();
    graph.Dijkstra(startV);
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
    //get a random start vertex and end vertex
    int startV = RandomVertex::Int(0, graph.getNumvertices() - 1);
    int endV = RandomVertex::Int(0, graph.getNumvertices() - 1);
    auto start = high_resolution_clock::now();
    graph.BFS(startV, endV);
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
    //get a random start vertex and end vertex
    int startV = RandomVertex::Int(0, graph.getNumvertices() - 1);
    int endV = RandomVertex::Int(0, graph.getNumvertices() - 1);
    auto start = high_resolution_clock::now();
    graph.DFS(startV, endV);
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
