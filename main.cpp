#include <iostream>
#include <vector>
#include <graph.h>
#include <priorityqueue.h>
#include <queue>

using namespace std;





int main()
{
    Graph g;
    g = Graph(6);
    cout << "Graph created.\n";
    g.random_loading(0.2, 10.0);
    cout << "Graph loaded.\n";
    g.dump_graph();
    cout << "Graph dumped.\n";

    // Prueba de cola priorizada
    PriorityQueue q;
    PriorityQueue::closed_pair p;
    for(int i=0;i<g.get_num_edges();i++)
    {
        cout << "("
             << g.get_edge_number(i).node_id_x << ","
             << g.get_edge_number(i).node_id_y << ","
             << g.get_edge_number(i).edge_distance << ")"
             << endl;
        p.distance = g.get_edge_number(i).edge_distance;
        p.node_id_x = g.get_edge_number(i).node_id_x;
        p.node_id_y = g.get_edge_number(i).node_id_y;
        q.insert(p);
    }
    cout << "insertados " << q.size() << endl;

    int s = q.size();
    for(int i=0;i<s;i++)
    {
        p = q.top();
        cout << "("
             << p.node_id_x << ","
             << p.node_id_y << ","
             << p.distance << ")"
             << endl;
    }

    // prueba de cola normal

    struct openset_element
    {
        Graph::node n;
        float distance;
    };

    queue<openset_element> nq;
    openset_element e;
    for(int i=0; i< g.get_num_nodes(); i++ )
    {
        e.n = g.get_node_number(i);
        e.distance = i;
        nq.push(e);
    }
    cout << "Cola cargada... datos de cola" << endl;
    while(!nq.empty())
    {
        e = nq.front();
        nq.pop();
        cout << "<"
             << e.n.node_id << ":"
             << e.distance << ">"
             << endl;
    }





    return 1;



}
