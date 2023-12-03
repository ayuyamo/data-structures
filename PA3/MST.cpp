#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>

using namespace std;

const int N = 5;

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

tuple<int, int, int> updateMST(int rowIndex, int (*graph)[N], vector<int>* visited) {
    int minEdge = INT_MAX;
    int minEdgeCol = -1;
    int minEdgeRow = rowIndex;
    bool isVisitedVertex = false;
    bool isPermanent = false;

    // start with check for elements inside array at row index = most recently visited vertex
    for (int j = 0; j < N; j++) {
        // only connect current vertex to one that has not been visited yet
        isVisitedVertex = elementExists(j, visited);
        if (graph[rowIndex][j] != 0 && graph[rowIndex][j] < minEdge && !isVisitedVertex) {
            minEdge = graph[rowIndex][j];
            minEdgeCol = j;
        }
    }

    for (int i = 0; i < N; i++) {
        isPermanent = elementExists(i, visited);
        // this case happens when the current vertex does not have any edge connected to any other unvisited vertex
        // which means minEdge val for current vertex is still by default -1, or not found 
        if (minEdgeCol == -1){
            for (int j = 0; j < N; j++) {
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

void findMST(int vertex, int (*graph)[N], vector<int>* visited, vector<int>* unvisited) {
    int startVertex;
    int endVertex = vertex;
    int minEdge;
    while(visited->size() <= N && !unvisited->empty()) 
    {// ensure visited array has size at most == # of all vertices &
     // if unvisited array is empty --> MST process is complete --> exit program
        tie(startVertex, endVertex, minEdge) = updateMST(endVertex, graph, visited);
        addVertex(endVertex, visited, unvisited);
        printEdge(startVertex, endVertex, minEdge);
    }
}

int main() {
    int graph1[N][N] =
        {     // 0   1   2   3   4
          /*0*/ { 0, 3, 65, 0, 0 },
          /*1*/ { 3, 0, 85, 20, 45 },
          /*2*/ { 65, 85, 0, 41, 77 },
          /*3*/ { 0, 20, 41, 0, 51 },
          /*4*/ { 0, 45, 77, 51, 0 },
        };


    // int graph2[N][N] = 
    //     {      //  0   1   2   3   4   5
    //         /*0*/ {0, 11, 0, 33, 0, 32},      
    //         /*1*/ {11, 0, 0, 0, 7, 0},
    //         /*2*/ {0, 0, 0, 0, 0, 25},
    //         /*3*/ {33, 0, 0, 0, 24, 0},
    //         /*4*/ {0, 7, 0, 24, 0, 16},
    //         /*5*/ {32, 0, 25, 0, 16, 0},
    //     };

    vector<int> visited;
    vector<int> unvisited(N);
    // initializing unvisited array using iota()
	iota(unvisited.begin(), unvisited.end(), 0);

    cout << "Prim's MST is Edge -> Cost" << endl;
    addVertex(0, &visited, &unvisited); // change the first parameter here and the line below
    findMST(0, graph1, &visited, &unvisited); // to select different start vertex

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
