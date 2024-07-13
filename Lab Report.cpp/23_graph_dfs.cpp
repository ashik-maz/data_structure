#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* next=nullptr;
    Node(int val) : data(val), next(nullptr) {}
};

vector<Node*> graph;

bool visit[1000];

void DFS(int startNode) {
    cout << startNode << ' ';
    visit[startNode] = true;

    Node* temp = graph[startNode];
    while (temp != nullptr) {
        int tmp = temp->data;
        if (!visit[tmp]) {
            DFS(tmp);
        }
        temp = temp->next;
    }
}

int main() {
    cout << "Enter the number of edges :" << endl;
    int edge, source, destination;
    cin >> edge;

    graph.resize(edge , nullptr);

    for (int i = 0; i < edge; i++) {
        cout << "Enter source node and destination node: " << endl;
        cin >> source >> destination;

        Node* newNode1 = new Node(destination);
        newNode1->next = graph[source];
        graph[source] = newNode1;

        Node* newNode2 = new Node(source);
        newNode2->next = graph[destination];
        graph[destination] = newNode2;
    }

    cout << "Enter the starting node for DFS: ";
    cin >> source;

    cout << "DFS traversal starting from node " << source << ": ";
    DFS(source);
}
