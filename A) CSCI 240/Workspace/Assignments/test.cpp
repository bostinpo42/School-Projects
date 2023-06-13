#include "array_queue.h"
#include "linked_queue.h"
#include <iostream>

void testQueue(Queue<int>* queue);
void testDequeue(Queue<int>* queue);
int testFront(Queue<int>* queue);
char testEmpty(Queue<int>* queue);
void testClear(Queue<int>* queue);

const int tArrayValues[]{12, 25, 37, 49, 51, 62, 73, 86, 94, 10};


int main(int argc, char const *argv[])
{
    try {
        testQueue(new ArrayQueue<int>);

    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
                                              
	return 0;
}

void testQueue(Queue<int>* queue) {
    for (size_t i = 0; i < DEFAULT_SIZE; ++i) {
           queue->enqueue(tArrayValues[i]); 
    }
    queue->dequeue();
    std::cout << "Front: " << queue->front() << "\n";
}

void testDequeue(Queue<int>* queue) {
    queue->dequeue();
}

char testEmpty(Queue<int>* queue) {
    if (queue->isEmpty()) return 'T';
    return 'F';
    
}

void testClear(Queue<int>* queue) {
    queue->clear();
}