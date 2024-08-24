#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
private:
    unordered_map<string, unordered_set<string>> adjList;
    unordered_map<string, bool> visit;

public:
    void addVertex(string vertex)
    {
        if (adjList.count(vertex) == 0)
        {
            adjList[vertex];
        }
        return;
    }

    void addEdge(string vertex1, string vertex2)
    {
        if (adjList.count(vertex1) && adjList.count(vertex2))
        {
            adjList.at(vertex1).insert(vertex2);
            adjList.at(vertex2).insert(vertex1);
        }
        return;
    }

    void removeEdge(string vertex1, string vertex2){
        if(adjList.count(vertex1) && adjList.count(vertex2)){
            adjList.at(vertex1).erase(vertex2);
            adjList.at(vertex2).erase(vertex1);
        }
        return;
    }

    void removeVertex(string vertex){
        if(adjList.count(vertex)){
            for(auto child:adjList.at(vertex)){
                adjList.at(child).erase(vertex);
            }
            adjList.erase(vertex);
        }
        return;
    }

    void printGraph()
    {
        for (auto &node : adjList)
        {
            cout << node.first << " : [ ";
            for (auto edge : node.second)
            {
                cout << edge << " ";
            }
            cout << "]" << endl;
        }
    }

    void BFS(string startingNode){
        cout << "BFS traversal starting from node " << startingNode << " : ";

        for(auto &node:adjList){
            visit[node.first]=false;
        }
        visit[startingNode]=true;
        queue<string>q;
        q.push(startingNode);
        while(!q.empty()){
            string temp=q.front();
            q.pop();
            cout<<temp<<" ";
            for(auto child:adjList[temp]){
                if(!visit[child]){
                    q.push(child);
                    visit[child]=true;
                }
            }
        }
        cout<<endl;
    }

    void DFS(string startingNode){
        for(auto &node:adjList){
            visit[node.first]=false;
        }
        stack<string> s;
        s.push(startingNode);
        cout<<"DFS traversal starting from node "<<startingNode<<" : ";
        while(!s.empty()){
            string temp=s.top();
            s.pop();
            if(!visit[temp]){
                cout<<temp<<" ";
                visit[temp]=true;
                for(auto child : adjList[temp]){
                    s.push(child);
                }
            }
        }
        cout<<endl;
    }

};
int main()
{
    Graph graph;
    int choice;
    // do
    // {
    //     cout << "\n1.Addvertex\n2.AddEdge\n3.Remove Vertex\n4.remove Edge\n5.Print\n6.exit\nEnter your choice: ";
    //     cin >> choice;
    //     switch (choice)
    //     {
    //     case 1:
    //     {
    //         cout << "Enter your vertex: ";
    //         string vertex;
    //         cin >> vertex;
    //         graph.addVertex(vertex);
    //         break;
    //     }

    //     case 2:
    //     {
    //         cout << "Enter your starting and Ending vertex:  ";
    //         string vertex1, vertex2;
    //         cin >> vertex1 >> vertex2;
    //         graph.addEdge(vertex1, vertex2);
    //         break;
    //     }
    //     case 3:
    //     {
    //         cout << "Enter your vertex:  ";
    //         string vertex;
    //         cin >> vertex;
    //         graph.removeVertex(vertex);
    //         break;
    //     }
    //     case 4:
    //     {
    //         cout << "Enter your starting and Ending vertex:  ";
    //         string vertex1, vertex2;
    //         cin >> vertex1 >> vertex2;
    //         graph.removeEdge(vertex1, vertex2);
    //         break;
    //     }
    //     case 5:
    //     {
    //         graph.printGraph();
    //         break;
    //     }
    //     }

    // } while (choice != 6);

    graph.addVertex("1");
    graph.addVertex("2");
    graph.addVertex("3");
    graph.addVertex("4");
    //graph.addVertex(4);
    graph.addEdge("1","2");
    graph.addEdge("3","2");
    graph.addEdge("3","4");
    graph.addEdge("1","4");

    graph.printGraph();
    graph.BFS("1");
    graph.DFS("1");
    // graph.removeEdge("1","4");
    // graph.printGraph();
}