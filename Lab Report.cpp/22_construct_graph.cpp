

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include<queue>
#include<stack>

using namespace std;


class Graph {
    private:
        unordered_map<string, unordered_set<string> > adjList;
        unordered_map<string, bool > visit;
    
    public:

        bool addVertex(string vertex) {
            if (adjList.count(vertex) == 0) {
                adjList[vertex];
                return true;
            }
            return false;
        }

        
        void printGraph() {
           
            for (auto &node : adjList) {
                cout << node.first << ": [ ";
                for (auto edge : node.second) {  
                    cout << edge << " ";
                }
                cout << "]" << endl;
            }
        }

        bool addEdge(string vertex1, string vertex2){
            if(adjList.count(vertex1) != 0 && adjList.count(vertex2) !=0){
                adjList.at(vertex1).insert(vertex2);
                adjList.at(vertex2).insert(vertex1);
                return true;
            }
            return false;

        }

        bool removeEdge(string vertex1, string vertex2){
            if(adjList.count(vertex1) !=0 && adjList.count(vertex2) != 0){
                adjList.at(vertex1).erase(vertex2);
                adjList.at(vertex2).erase(vertex1);
                return true;
            }
            return false;
        }

        bool removeVertex(string vertex){
            if(adjList.count(vertex)==0) return false;
            for(auto otherVertex : adjList.at(vertex)){
                adjList.at(otherVertex).erase(vertex);
            }
            adjList.erase(vertex);
            return true;
        }


};


int main() {

    Graph* myGraph = new Graph();

    myGraph->addVertex("A");
    myGraph->addVertex("B");
    myGraph->addVertex("C");
    myGraph->addVertex("D");

    /*

    A--------------B           A-------------B
    | \            |           |
    |    \         |           |
    |       \      |  ----->   |
    |          \   |           |
    |            \ |           |
    C--------------D           C
    */

    myGraph->addEdge("A","B");
    myGraph->addEdge("A","C");
    myGraph->addEdge("A","D");
    myGraph->addEdge("B","D");
    myGraph->addEdge("C","D");


    cout<<"Old Graph: \n";
    myGraph->printGraph();

    myGraph->removeVertex("D");
    cout<<"New Graph: \n";
    myGraph->printGraph();
       
}