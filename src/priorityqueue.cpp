#include <priorityqueue.h>

PriorityQueue::PriorityQueue()
{
    this->num_pairs = 0;
    //ctor
}
//struct closed_pair
//        {
//            int node_id_x;
//            int node_id_y;
//            float distance;
//        };
void PriorityQueue::insert(PriorityQueue::closed_pair p)
{
    vector<closed_pair>::iterator i;
    i=this->closed_set.begin();
    int n=0;

    // No vamos a tener en cuenta los nodos cuyo inicio y final son el mismo
    if(p.node_id_x == p.node_id_y)
    {
        return;
    }

    while(true)
    {
        // sanity check
        n++;
        if(n>1000) break;
        //



        // Ya estamos en el final de la cola,... insertamos al final
        if(i==this->closed_set.end())
        {
            this->closed_set.push_back(p);
            this->num_pairs++;
            break;
        }

        // Ya está en closedset como nodo de partida
        if(i->node_id_x == p.node_id_y)
        {
            break;
        }

        // está en el closedset como nodo de destino
        if(i->node_id_y == p.node_id_y)
        {
            // comprobar si mejora lo existente
            if(p.distance < i->distance)
            {
                // sustituirlo
                i->distance = p.distance;
                i->node_id_x = p.node_id_x;
                i->node_id_y = p.node_id_y;
                break;

            }
            else
                break;
        }
        // comprobar si mejora lo existente
        if(p.distance < i->distance)
        {
            // insertarlo en ese punto
            this->closed_set.insert(i,p);
            this->num_pairs++;
            break;
        }
        i++;
    }


    // this->closed_set.push_back(p);
}


PriorityQueue::closed_pair PriorityQueue::top()
{
    closed_pair p;
    vector<closed_pair>::iterator it;

    it = this->closed_set.begin();
    p = this->closed_set[0];
    this->closed_set.erase(it);
    return p;

}


int PriorityQueue::size()
{
    return this->closed_set.size();
}

