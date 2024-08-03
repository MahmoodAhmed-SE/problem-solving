#include <bits/stdc++.h>

using namespace std;

struct edge {
    int vertexIndex;
    edge* next;

    edge(int i) : vertexIndex(i), next(nullptr) {}
};

class graph {
private:
    vector<pair<char, edge*>> graph;

public:
    void insertVtx(char vtx) {
        graph.push_back(make_pair(vtx, nullptr));
    }

    void addEdge(char from, char to) {
        int i = -1;
        int k = -1;

        for (int pos = 0; pos < graph.size(); pos++) {
            if (graph[pos].first == from) {
                i = pos;
            }
            if (graph[pos].first == to) {
                k = pos;
            }
        }

        if (i == -1 || k == -1) {
            cout << "missing vertex" << endl;
            return;
        }

        if (graph[i].second == nullptr) {
            graph[i].second = new edge(k);
        } else {
            edge* temp = graph[i].second;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = new edge(k);
        }
    }

    void print() {
        for (const auto& p : graph) {
            cout << "Vertex: " << p.first << " Edges: ";
            edge* temp = p.second;
            while (temp != nullptr) {
                cout << graph[temp->vertexIndex].first << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    vector<int> findPath(char from, char to) {
   		int i = -1;
        int k = -1;

        for (int pos = 0; pos < graph.size(); pos++) {
            if (graph[pos].first == from) {
                i = pos;
            }
            if (graph[pos].first == to) {
                k = pos;
            }
        }

        if (i == -1 || k == -1) {
            cout << "missing vertex" << endl;
            return {};
        }

        unordered_set<int> st;
        stack<int> path;


        
    }
};

int main() {
    graph g;

    g.insertVtx('A');
    g.insertVtx('B');
    g.insertVtx('C');
    g.insertVtx('D');
    g.insertVtx('E');
    g.insertVtx('F');


    g.addEdge('A', 'C');
    g.addEdge('A', 'B');
    g.addEdge('B', 'D');
    g.addEdge('B', 'F');
    g.addEdge('C', 'E');
    g.addEdge('B', 'D');

    g.print();

    return 0;
}
