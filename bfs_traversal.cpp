#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

void BFS(int start, unordered_map<int, vector<int>>& graph) {
    queue<int> q;
    unordered_map<int, bool> visited;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    unordered_map<int, vector<int>> graph;
    
    graph[0] = {1, 2};
    graph[1] = {2};
    graph[2] = {0, 3};
    graph[3] = {3};

    cout << "BFS Traversal: ";
    BFS(0, graph);

    return 0;
}
