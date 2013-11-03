

#ifndef GRAPH_H
#define GRAPH_H

using namespace std;

class Graph
{
    public:
        struct node
        {
            int node_id;
            int node_value;
        };

        struct edge
        {
            int node_id_x;
            int node_id_y;
            float edge_distance;
        };

        struct openset
        {
            node node_to;
            float shortest_distance;
        };


        // Constructor:
        //  int n: number of nodes
        Graph(int num_nodes=0);
        //
        bool random_loading(float, float);
        void dump_graph();
        // returns the number of vertices in the graph
        int get_num_nodes();
        // returns the number of edges in the graph
        int get_num_edges();
        // tests whether there is an edge from node x to node y.
        bool is_adjacent(int x, int y);
        // lists all nodes y such that there is an edge from x to y.
        // vector<int> a = {1,2,3};
        // return a;
        vector<node> get_neighbors_list(int x);
        //  adds to G the edge from x to y, if it is not there.
        bool add_edge(int x, int y, float distance);
        // removes the edge from x to y, if it is there
        bool delete_edge(int x, int y);
        // get_node_value (G, x): returns the value associated with the node x.
        int get_node_value(int x);
        // set_node_value( G, x, a): sets the value associated with the node x to a.
        bool set_node_value(int x, int a);
        // get_edge_value( G, x, y): returns the value associated to the edge (x,y).
        int get_edge_value(int x, int y);
        // set_edge_value (G, x, y, v): sets the value associated to the edge (x,y) to v.
        bool set_edge_value(int x, int y, float distance);
        // get edge number n
        edge get_edge_number(int i);
        // get node number
        node get_node_number(int i);

        vector<node> get_nodes();
        vector<edge> get_edges();


private:
        vector<node> nodes_list;
        vector<edge> edges_list;
        int num_nodes;
        int num_edges;
};

#endif // GRAPH_H

