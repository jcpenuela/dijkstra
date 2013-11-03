/*





*/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <graph.h>


using namespace std;

Graph::Graph(int num_nodes)
{
    node new_node;
    this->num_nodes = num_nodes;
    this->num_edges = 0;
    for(int i=0;i<num_nodes;i++)
    {
        new_node.node_id = i;
        new_node.node_value = i;
        this->nodes_list.push_back(new_node);
    }
}

int Graph::get_num_nodes()
{
    return this->num_nodes;
}

int Graph::get_num_edges()
{
    return this->num_edges;
}

// tests whether there is an edge from node x to node y.
bool Graph::is_adjacent(int x, int y)
{

    vector<edge>::iterator v;
    for (v = this->edges_list.begin(); v != this->edges_list.end(); v++)
    {
        if((v->node_id_x==x || v->node_id_y==x) && (v->node_id_x==y || v->node_id_y==y))
            return true;
    }
    return false;
}

vector<Graph::node> Graph::get_neighbors_list(int x)
{
    vector<edge>::iterator e;
    vector<node> neighbors;
    node n;

    for (e = this->edges_list.begin(); e != this->edges_list.end(); e++)
    {
        if(e->node_id_x==x)
        {
            n.node_id = e->node_id_y;
            n.node_value = this->get_node_value(e->node_id_y);
            neighbors.push_back(n);
        }
        else if(e->node_id_y==x)
        {
            n.node_id = e->node_id_x;
            n.node_value = this->get_node_value(e->node_id_x);
            neighbors.push_back(n);
        }
    }
    return neighbors;
}

bool Graph::add_edge(int x, int y, float distance)
{
    edge new_edge;
    vector<edge>::iterator i;

    for(i = this->edges_list.begin() ; i != this->edges_list.end(); i++)
    {
        if((i->node_id_x == x && i->node_id_y == y) || (i->node_id_x == y && i->node_id_y == x))
            return false;
    }
    new_edge.node_id_x=x;
    new_edge.node_id_y=y;
    new_edge.edge_distance=distance;
    this->edges_list.push_back(new_edge);
    this->num_edges++;
    return true;
}

bool Graph::delete_edge(int x, int y)
{
    vector<edge>::iterator i;

    for(i = this->edges_list.begin() ; i != this->edges_list.end(); i++)
    {
        if((i->node_id_x == x && i->node_id_y == y) || (i->node_id_x == y && i->node_id_y == x))
        {
            this->edges_list.erase(i);
            this->num_edges--;
            return true;
        }
    }
    return false;

}

// get_node_value (G, x): returns the value associated with the node x.
int Graph::get_node_value(int x)
{
    vector<node>::iterator i;

    for(i = this->nodes_list.begin() ; i != this->nodes_list.end(); i++)
        if((i->node_id == x))
            return i->node_value;
    return 0;
}

// set_node_value( G, x, a): sets the value associated with the node x to a.
bool Graph::set_node_value(int x, int value)
{
    vector<node>::iterator i;

    for(i = this->nodes_list.begin() ; i != this->nodes_list.end(); i++)
        if((i->node_id == x))
        {
            i->node_value = value;
            return true;
        }
    return false;
}

// get_edge_value( G, x, y): returns the value associated to the edge (x,y).
int Graph::get_edge_value(int x, int y)
{
    vector<edge>::iterator i;
    for(i=this->edges_list.begin();i!=this->edges_list.end();i++)
    {
        if((i->node_id_x == x && i->node_id_y == y) || (i->node_id_x == y && i->node_id_y == x) )
            return i->edge_distance;
    }
    return -1;
}

// set_edge_value (G, x, y, v): sets the value associated to the edge (x,y) to v.
bool Graph::set_edge_value(int x, int y, float distance)
{
    vector<edge>::iterator i;
    for(i=this->edges_list.begin();i!=this->edges_list.end();i++)
    {
        if((i->node_id_x == x && i->node_id_y == y) || (i->node_id_x == y && i->node_id_y == x) )
        {
            i->edge_distance = distance;
            return true;
        }
    }
    return false;
}


Graph::edge Graph::get_edge_number(int n)
{
    return this->edges_list[n];
}


Graph::node Graph::get_node_number(int n)
{
    return this->nodes_list[n];
}


vector<Graph::node> Graph::get_nodes()
{
    return this->nodes_list;
}

vector<Graph::edge> Graph::get_edges()
{
    return this->edges_list;
}

/*
    Load the graph with random data
*/
bool Graph::random_loading(float density, float distance_range)
{

    float probability; // aleatorio que marca la probabilidad de insertar un vértice
    float distance; // distancia aleatoria calculada en base a distance_range

    if(this->num_nodes == 0)
    {
        cout << "Error. Graph is not initialized. It has zero nodes. Initialize it first." << endl;
        return false;
    }

    if(density <= 0.0 || density > 1.0)
    {
        cout << "Error. Density is not in correct range." << endl;
        return false;
    }

    if(distance_range <= 0.0)
    {
        cout << "Error. Distance range must be greater than 1.0 and less or equal to 10.0." << endl;
        return false;
    }

    // Clear the vector content
    this->edges_list.clear();
    srand(time(NULL)); // seed for random
    /*

    Para cada nodo i
        Para cada par i,j
            p = aleatorio entre 0 y 1 (rand()/MAX_RAND)
            si p>densidad
                insertar vértice (i,j)


    */

    for(int i=0; i<this->num_nodes; i++)
    {
        for(int j=0;j<num_nodes;j++)
        {
            probability = ((double)rand() / (double)RAND_MAX);
            if(probability < density)
            {
                distance = ((double)rand() / (double)RAND_MAX) * distance_range;
                this->add_edge(i,j,distance);
            }
        }
    }
    return true;
}


void Graph::dump_graph()
{

    vector<edge>::iterator i;
    cout << "Num. nodos: " << this->num_nodes << endl;
    cout << "Num. vértices: " << this->num_edges << endl;
    for(i=this->edges_list.begin();i!=edges_list.end();i++)
        cout << i->node_id_x << " ->(" << i->edge_distance << ")-> " << i->node_id_y << endl;
}





// openset {x, coste} => vector con nodos y menor coste hacia ese nodo
// closedset {x, y, coste} => vector con los adyacentes y los menores costes

//x <- s
//inserta en openset {s, 0}
//mientras en cola openset no esté el nodo d
//   n <- coje el siguiente de cola openset
//   inserta en closed set cada nodo adyacente de n
//      (inserta sumando el coste de n al coste de cada uno de sus adyacentes)
//      (solo inserta si el adyacente no está en el openset)
//      (solo inserta si el coste hasta el adyacente mejora alguno
//       existente en el closedset hasta él o no está)




