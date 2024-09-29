#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/print_graph.hpp>

using namespace boost;

// Define the graph type using adjacency_list
typedef adjacency_list<vecS, vecS, undirectedS, no_property, property<edge_weight_t, int>> Graph;
typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef graph_traits<Graph>::edge_descriptor Edge;
typedef std::pair<int, int> EdgePair;

int main() {
    // Create a graph object
    Graph g;

    // Add vertices and edges to the graph
    add_edge(0, 1, 10, g);
    add_edge(1, 2, 20, g);
    add_edge(2, 3, 30, g);
    add_edge(3, 0, 40, g);

    // Get and print the number of vertices and edges
    std::cout << "Number of vertices: " << num_vertices(g) << std::endl;
    std::cout << "Number of edges: " << num_edges(g) << std::endl;

    // Print edges with weights
    std::cout << "Edges and their weights:" << std::endl;
    graph_traits<Graph>::edge_iterator ei, ei_end;
    for (tie(ei, ei_end) = edges(g); ei != ei_end; ++ei) {
        Edge e = *ei;
        std::cout << "(" << source(e, g) << ", " << target(e, g) << ") with weight " << get(edge_weight, g, e) << std::endl;
    }

    return 0;
}
