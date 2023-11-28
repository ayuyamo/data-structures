#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

void addVertex(int destVertex, vector<int>* visited, vector<int>* unvisited) {
    // remove vertex from unvisited array and push it in visited array
    unvisited->erase(remove(unvisited->begin(), unvisited->end(), destVertex), unvisited->end());
    visited->push_back(destVertex);
}

bool elementExists(int element, vector<int>* vec) {
    // check if an element exists inside the given vector array
    return find(vec->begin(), vec->end(), element) != vec->end();
}

void printEdge(int startVertex, int destVertex, int cost) {
    // print the next minimum edge and the new vertex visited
    cout << startVertex << " - " << destVertex << " -> " << cost << endl;
}

tuple<int, int, int> updateMST(int rowIndex, int (*graph)[5], vector<int>* visited) {
    int minEdge = INT_MAX;
    int minEdgeCol = -1;
    int minEdgeRow = rowIndex;
    bool isVisitedVertex = false;
    bool isPermanent = false;

    // start with check for elements inside array at row index = most recently visited vertex
    for (int j = 0; j < 5; j++) {
        // only connect current vertex to one that has not been visited yet
        isVisitedVertex = elementExists(j, visited);
        if (graph[rowIndex][j] != 0 && graph[rowIndex][j] < minEdge && !isVisitedVertex) {
            minEdge = graph[rowIndex][j];
            minEdgeCol = j;
        }
    }

    for (int i = 0; i < 5; i++) {
        isPermanent = elementExists(i, visited);
        // this case happens when the current vertex does not have any edge connected to any other unvisited vertex
        // which means minEdge val for current vertex is still by default -1, or not found 
        if (minEdgeCol == -1){
            for (int j = 0; j < 5; j++) {
                isVisitedVertex = elementExists(j, visited);
                if (graph[i][j] != 0 && graph[i][j] < minEdge && isPermanent && !isVisitedVertex) {
                    minEdge = graph[i][j];
                    minEdgeRow = i;
                    minEdgeCol = j;
                }
            }
        }
        // if minEdge of current vertex -> next vertex < minEdge of any other vertex in 'visited' array -> next vertex
        // replace change val of minEdge to the latter
        else if (graph[i][minEdgeCol] != 0 && graph[i][minEdgeCol] < minEdge && isPermanent) {
            minEdge = graph[i][minEdgeCol];
            minEdgeRow = i;
        }
    }

    return make_tuple(minEdgeRow, minEdgeCol, minEdge);
}

void findMST(int vertex, int (*graph)[5], vector<int>* visited, vector<int>* unvisited) {
    tuple<int, int, int> result;
    int startVertex;
    int endVertex = vertex;
    int minEdge;

    while(visited->size() <= 5 && !unvisited->empty()) {// ensure visited array has size at most == # of all vertices &
                                                        // if unvisited array is empty --> MST process is complete --> exit program
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

    // Check if the 'unvisited' vector is empty
    if (unvisited.empty()) {
        cout << "--> The unvisited array is empty." << endl;
        cout << "--> All vertices are visited." << endl;
        // Print elements in the 'visited' vector
        cout << "--> Visited elements: ";
        for (int element : visited) {
            cout << element << " ";
        }
        cout << endl;
    }



    cout << "-------Program exited-------" << endl;

    return 0;
}
