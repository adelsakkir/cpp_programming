#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
    private:
        int n_nodes = 5;
        int n_edges = 3;

        void add_node_if_not_present (int node) {
            if (find(nodes.begin(), nodes.end(), node) == nodes.end()) {
                nodes.push_back(node);
                n_nodes++;
            }
        };
         

    public:
        vector <int> nodes;
        vector <tuple<int, int>> edges;

        Graph(): n_nodes(0), n_edges(0) {}

        int get_n_nodes(){
            cout << "The number of nodes in the graph is: " << n_nodes  <<endl;
        }
        int get_n_edges(){
            cout << "The number of edges in the graph is: " << n_edges  <<endl;
        }


        void add_edge(tuple<int, int>& edge){
            edges.push_back(edge);
            n_edges++;

        int node1 = get<0>(edge);
        int node2 = get<1>(edge);

        add_node_if_not_present(node1);
        add_node_if_not_present(node2);

        }
};

int main(){
    Graph g;

    g.get_n_edges();
    g.get_n_nodes();
    // cout << g.n_nodes << endl;
    vector<tuple<int, int>> edges = {
        make_tuple(1,2),
        make_tuple(2,3),
        make_tuple(3,4),

    };

    size_t n_edges = edges.size();
    cout << "The number of edges to be added to the graph is: " << n_edges << endl;

    for (int i = 0; i < n_edges; i++){
        g.add_edge(edges[i]);
    }

    g.get_n_edges();
    cout << "Edges in the graph:" << endl;
    for (const tuple<int, int>& edge : g.edges) {
        cout << "(" << get<0>(edge) << ", " << get<1>(edge) << ") ";
    }

    cout << endl;

    g.get_n_nodes();
    cout << "Nodes in the graph:" << endl;
    for (const int& node : g.nodes) {
        cout << node << " ";
    }
    cout << endl;


}