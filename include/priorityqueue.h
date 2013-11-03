#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>

using namespace std;

class PriorityQueue
{
    public:

        struct closed_pair
        {
            int node_id_x;
            int node_id_y;
            float distance;
        };

        PriorityQueue();

//chgPrioirity(PQ, priority): changes the priority (node value) of queue element
//minPrioirty(PQ): removes the top element of the queue
//contains(PQ, queue_element): does the queue contain queue_element?
        void insert(closed_pair c); // insert queue_element into queue
        closed_pair top(); // returns the top element of the queue.
        int size(); // return the number of queue_elements.


    private:
        vector<closed_pair> closed_set;
        int num_pairs;

};

#endif // PRIORITYQUEUE_H
