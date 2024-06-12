#include <iostream>
using namespace std;

const int MAX_VERTICES = 10;

int cost[MAX_VERTICES][MAX_VERTICES];
int n; // Number of vertices

void createGraph() {
    int m;
    cout << "\nEnter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    cout << "\nEnter the Edges:\n";
    for (int k = 1; k <= m; k++) {
        int i, j;
        cin >> i >> j;
        cost[i][j] = 1;
        cost[j][i] = 1;
    }
}

void displayAdjacencyMatrix() {
    cout << "\nThe adjacency matrix of the graph is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }
}

void BFS() {
    int v;
    cout << "\nEnter initial vertex to find BFS: ";
    cin >> v;

    bool visited[MAX_VERTICES] = {false};
    cout << "\nThe BFS of the Graph is: ";
    cout << v << " ---> ";
    visited[v] = true;

    int qu[MAX_VERTICES], front = 0, rear = 0;
    qu[rear++] = v;

    while (front < rear) {
        v = qu[front++];
        for (int j = 0; j < n; j++) {
            if (cost[v][j] && !visited[j]) {
                cout << j << " ---> ";
                visited[j] = true;
                qu[rear++] = j;
            }
        }
    }
    cout << endl;
}

void DFSUtil(int v, bool visited[]) {
    cout << v << " ---> ";
    visited[v] = true;
    for (int j = 0; j < n; j++) {
        if (cost[v][j] && !visited[j]) {
            DFSUtil(j, visited);
        }
    }
}

void DFS() {
    int v;
    cout << "\nEnter initial vertex to find DFS: ";
    cin >> v;

    bool visited[MAX_VERTICES] = {false};
    cout << "\nThe DFS of the Graph is: ";
    DFSUtil(v, visited);
    cout << endl;
}

int main() {
    int ch;
    do {
        cout << "\n*DSAL Practical No - 06(C-13)*\n";
        cout << "\n------------MENU--------------\n";
        cout << "1. Create Graph\n";
        cout << "2. Display Adjacency Matrix\n";
        cout << "3. Find BFS\n";
        cout << "4. Find DFS\n";
        cout << "5. Exit\n";
        cout << "\nEnter Your Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                createGraph();
                break;
            case 2:
                displayAdjacencyMatrix();
                break;
            case 3:
                BFS();
                break;
            case 4:
                DFS();
                break;
            case 5:
                cout << "\n*Successfully Terminated*\n";
                break;
            default:
                cout << "Invalid Choice\n";
        }
    } while (ch != 5);

    return 0;
}