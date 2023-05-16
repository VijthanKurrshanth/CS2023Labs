#include <iostream>
#include<list>
using namespace std;

struct Node{
    // A node will 2 entities
    //1. data type int called label
    //2. a int type list called neighbours
    int label = 0;
    list<int> neighbours{};

};

struct Graph{
    //graph will have an array of type "node" with length specified by n
    int n=8;
    Node * nodes = new Node[n];

    void intializenodes(){
        //iterate through the nodes and assign labels
        for(int i=0;i<n;i++){
            nodes[i].label=i+1;
        }
    }

    void addedge(int u, int v){
        //select node u and push v into u's neighbour
        nodes[u-1].neighbours.push_back(v-1);

        //select node v and push u into v's neighbour
        nodes[v-1].neighbours.push_back(u-1);
    }

    void print(){
        //lets iterate through each node and print its neighbours
        for(int i=0;i<n;i++){
            cout << nodes[i].label << " -> ";
            for (auto i : nodes[i].neighbours) {
                cout << i+1 << ' ';
            }
            cout << endl;
        }

    }
};

int main() {
    Graph * g = new Graph;
    g->intializenodes();
    //add edges for the graphs here.
    int first_node = 0;
    int second_node = 0;
    int no_edges = 0;
    int count = 0;
    cout << "Enter no. of edges in the graph: ";
    cin >> no_edges;
    while (no_edges != 0){
        count +=1 ;
        cout << "Enter 1st node of the edge " << count <<" : ";
        cin >> first_node;
        cout << "Enter 2nd node of the edge " << count <<" : ";
        cin >> second_node;
        g->addedge(first_node, second_node);
        no_edges -= 1;
    }
    
    //print the graph adjaceny list
    g->print();
}
