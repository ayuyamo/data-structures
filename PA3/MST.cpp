#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

void addVertex(int destVertex, vector<int>* visited, vector<int>* unvisited) {
    unvisited->erase(remove(unvisited->begin(), unvisited->end(), destVertex), unvisited->end());
    visited->push_back(destVertex);
}

bool elementExists(int element, vector<int>* vec) {
    return find(vec->begin(), vec->end(), element) != vec->end();
}

void printEdge(int startVertex, int destVertex, int cost) {
    cout << startVertex << " - " << destVertex << " -> " << cost << endl;
}

tuple<int, int, int> updateMST(int row, int (*graph)[5], vector<int>* visited) {
    int minEdge = INT_MAX;
    int minEdgeCol = -1;
    int minEdgeRow = row;
    bool hasMinimumEdgeVisitedVertices = false;
    bool isPermanent = false;

    for (int j = 0; j < 5; j++) {
        hasMinimumEdgeVisitedVertices = elementExists(j, visited);
        if (graph[row][j] != 0 && graph[row][j] < minEdge && !hasMinimumEdgeVisitedVertices) {
            minEdge = graph[row][j];
            minEdgeCol = j;
        }
    }

    for (int i = 0; i < 5; i++) {
        isPermanent = elementExists(i, visited);
        if (graph[i][minEdgeCol] != 0 && graph[i][minEdgeCol] < minEdge && isPermanent) {
            minEdge = graph[i][minEdgeCol];
            minEdgeRow = i;
        }
    }
    // for (int i = 0; i < 5; i++) {
    //     isPermanent = elementExists(i, visited);
    //     if (graph[i][minEdgeCol] != 0 && graph[i][minEdgeCol] < minEdge && isPermanent) {
    //         minEdge = graph[i][minEdgeCol];
    //         minEdgeRow = i;
    //     }
    // }

    return make_tuple(minEdgeRow, minEdgeCol, minEdge);
}

void findMST(int vertex, int (*graph)[5], vector<int>* visited, vector<int>* unvisited) {
    tuple<int, int, int> result;
    int startVertex;
    int endVertex = vertex;
    int minEdge;

    while(visited->size() <= 5 && !unvisited->empty()) {
        result = updateMST(endVertex, graph, visited);
        startVertex = get<0>(result);
        endVertex = get<1>(result);
        minEdge = get<2>(result);

        addVertex(endVertex, visited, unvisited);
        printEdge(startVertex, endVertex, minEdge);
    }
}

int main() {
    const int N = 5;

    int graph[N][N] =
        {     // 0   1   2   3   4
          /*0*/ {0,  3,  65, 0,  0 },
          /*1*/ {3,  0,  85, 20, 45},
          /*2*/ {65, 85, 0,  41, 77},
          /*3*/ {0,  20, 41, 0,  51},
          /*4*/ {0,  45, 77, 51, 0 },
        };

    vector<int> visited;
    vector<int> unvisited = {0, 1, 2, 3, 4};

    cout << "Prim's MST is Edge -> Cost" << endl;
    addVertex(4, &visited, &unvisited);
    findMST(4, graph, &visited, &unvisited);

    cout << "All vertices are visited. Exiting program..." << endl;

    // Print elements in the 'unvisited' vector
    // cout << "Unvisited elements: ";
    // for (int element : unvisited) {
    //     cout << element << " ";
    // }
    // cout << endl;

    // Print elements in the 'visited' vector
    cout << "Visited elements: ";
    for (int element : visited) {
        cout << element << " ";
    }
    cout << endl;

    cout << "-------Program exited-------" << endl;

    return 0;
}
