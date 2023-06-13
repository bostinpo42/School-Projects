#include "array_queue.h"
#include "linked_queue.h"
#include <iostream>

void testEnqueue(Queue<int>* queue);
void testDequeue(Queue<int>* queue);
int testFront(Queue<int>* queue);
char testEmpty(Queue<int>* queue);
void testClear(Queue<int>* queue);

const int tArrayValues[]{12, 25, 37, 49, 51, 62, 73, 86, 94, 10};


int main(int argc, char const *argv[])
{
    ArrayQueue<int> a;
    WQueue<int> w;

    try {
        testDequeue(&a);
        std::cout << "Front: " << testFront(&a) << "\n";
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        testClear(&a);
        std::cout << "Front: " << testFront(&a) << "\n";
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        testEnqueue(&a);
        testDequeue(&a);
        std::cout << "Front: " << testFront(&a) << "\n";
        testClear(&a);
        std::cout << "Is empty?: " << testEmpty(&a) << "\n";
        std::cout << "Front: " << testFront(&a) << "\n";
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        testDequeue(&w);
        std::cout << "Front: " << testFront(&w) << "\n";
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        testClear(&w);
        std::cout << "Front: " << testFront(&w) << "\n";
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        testEnqueue(&w);
        testDequeue(&w);
        std::cout << "Front: " << testFront(&w) << "\n";
        testClear(&w);
        std::cout << "Is empty?: " << testEmpty(&w) << "\n";
        std::cout << "Front: " << testFront(&w) << "\n";
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
                                                        
	return 0;
}

void testEnqueue(Queue<int>* queue) {
    for (size_t i = 0; i < DEFAULT_SIZE; ++i) {
           queue->enqueue(tArrayValues[i]); 
    }
}

void testDequeue(Queue<int>* queue) {
    queue->dequeue();
}

int testFront(Queue<int>* queue) {
    return queue->front();
}

char testEmpty(Queue<int>* queue) {
    if (queue->isEmpty()) return 'T';
    return 'F';
    
}

void testClear(Queue<int>* queue) {
    queue->clear();
}