#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class LinkedList {
    struct Node {
        string value;
        Node* next;
        Node(string value){
            this->value=value;
            this->next=nullptr;
        }
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

    void add(string value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void remove(string value) {
        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->value != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;  // value not found

        if (prev == nullptr) {
            head = head->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
    }

    bool contains(string value) const {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->value == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void print() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
    }

    Node* getHead() const {
        return head;
    }
};

class Graph {
    unordered_map<string, LinkedList> adjList;
    unordered_map<string, bool> visit;

public:
    void addEdge(string src, string dest) {
        adjList[src].add(dest);
        adjList[dest].add(src); // Assuming undirected graph
    }

    void removeEdge(string src, string dest) {
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

    void DFSUtil(string node) {
        cout << node << " ";
        visit[node] = true;

        auto head = adjList[node].getHead();
        while (head != nullptr) {
            if (!visit[head->value]) {
                DFSUtil(head->value);
            }
            head = head->next;
        }
    }

    void DFS(string startNode) {
        for (auto& node : adjList) {
            visit[node.first] = false;
        }
        cout << "DFS traversal starting from node " << startNode << ": ";
        DFSUtil(startNode);
        cout << endl;
    }

    void BFS(string startNode) {
        for (auto& node : adjList) {
            visit[node.first] = false;
        }

        queue<string> q;
        q.push(startNode);
        visit[startNode] = true;

        cout << "BFS traversal starting from node " << startNode << ": ";
        while (!q.empty()) {
            string node = q.front();
            q.pop();
            cout << node << " ";

            auto head = adjList[node].getHead();
            while (head != nullptr) {
                if (!visit[head->value]) {
                    q.push(head->value);
                    visit[head->value] = true;
                }
                head = head->next;
            }
        }
        cout << endl;
    }
};

int main() {
    Graph graph;
    int choice;
    string src, dest, startNode;

    do {
        cout << "Graph:\n";
        graph.display();
        cout << "\nMenu:\n";
        cout << "1. Add edge\n";
        cout << "2. Delete edge\n";
        cout << "3. DFS\n";
        cout << "4. BFS\n";
        cout << "5. Exit\n";
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
                break;
            default:
                cout << "Invalueid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
