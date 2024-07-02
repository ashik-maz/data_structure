#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

template <typename Type>
class LinkedList {
    struct Node {
        Type data;
        Node* next;
        Node(Type val) : data(val), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(Type val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void remove(Type val) {
        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;  // Value not found

        if (prev == nullptr) {
            head = head->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
    }

    bool contains(Type val) const {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void print() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    Node* getHead() const {
        return head;
    }
};

template <typename Type>
class Graph {
    unordered_map<Type, LinkedList<Type>> adjList;
    unordered_map<Type, bool> visit;

public:
    void addEdge(Type src, Type dest) {
        adjList[src].add(dest);
        adjList[dest].add(src); // Assuming undirected graph
    }

    void removeEdge(Type src, Type dest) {
        adjList[src].remove(dest);
        adjList[dest].remove(src); // Assuming undirected graph
    }

    void display() const {
        for (const auto& node : adjList) {
            cout << node.first << " : [ ";
            node.second.print();
            cout << "]" << endl;
        }
    }

    void DFSUtil(Type node) {
        cout << node << " ";
        visit[node] = true;

        auto head = adjList[node].getHead();
        while (head != nullptr) {
            if (!visit[head->data]) {
                DFSUtil(head->data);
            }
            head = head->next;
        }
    }

    void DFS(Type startNode) {
        for (auto& node : adjList) {
            visit[node.first] = false;
        }
        cout << "DFS traversal starting from node " << startNode << ": ";
        DFSUtil(startNode);
        cout << endl;
    }

    void BFS(Type startNode) {
        for (auto& node : adjList) {
            visit[node.first] = false;
        }

        queue<Type> q;
        q.push(startNode);
        visit[startNode] = true;

        cout << "BFS traversal starting from node " << startNode << ": ";
        while (!q.empty()) {
            Type node = q.front();
            q.pop();
            cout << node << " ";

            auto head = adjList[node].getHead();
            while (head != nullptr) {
                if (!visit[head->data]) {
                    q.push(head->data);
                    visit[head->data] = true;
                }
                head = head->next;
            }
        }
        cout << endl;
    }
};

int main() {
    Graph<string> graph;
    int choice;
    string src, dest, startNode;

    do {
        cout << "Menu:\n";
        cout << "1. Add edge\n";
        cout << "2. Delete edge\n";
        cout << "3. DFS\n";
        cout << "4. BFS\n";
        cout << "5. Display Graph\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter source node and destination node: ";
                cin >> src >> dest;
                graph.addEdge(src, dest);
                break;
            case 2:
                cout << "Enter source node and destination node: ";
                cin >> src >> dest;
                graph.removeEdge(src, dest);
                break;
            case 3:
                cout << "Enter the starting node for DFS: ";
                cin >> startNode;
                graph.DFS(startNode);
                break;
            case 4:
                cout << "Enter the starting node for BFS: ";
                cin >> startNode;
                graph.BFS(startNode);
                break;
            case 5:
                cout << "Graph:\n";
                graph.display();
                break;
            case 6:
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}










// #include<iostream>
// #include<vector>
// using namespace std;

// struct Node {
//     int data;
//     Node* next=nullptr;
//     Node(int val) : data(val), next(nullptr) {}
// };

// vector<Node*> graph;

// bool visit[1000];

// void DFS(int startNode) {
//     cout << startNode << ' ';
//     visit[startNode] = true;

//     Node* temp = graph[startNode];
//     while (temp != nullptr) {
//         int tmp = temp->data;
//         if (!visit[tmp]) {
//             DFS(tmp);
//         }
//         temp = temp->next;
//     }
// }

// int main() {
//     cout << "Enter the number of edges :" << endl;
//     int edge, source, destination;
//     cin >> edge;

//     graph.resize(edge , nullptr);

//     for (int i = 0; i < edge; i++) {
//         cout << "Enter source node and destination node: " << endl;
//         cin >> source >> destination;

//         Node* newNode1 = new Node(destination);
//         newNode1->next = graph[source];
//         graph[source] = newNode1;

//         Node* newNode2 = new Node(source);
//         newNode2->next = graph[destination];
//         graph[destination] = newNode2;
//     }

//     cout << "Enter the starting node for DFS: ";
//     cin >> source;

//     cout << "DFS traversal starting from node " << source << ": ";
//     DFS(source);
// }

// //Grapgh