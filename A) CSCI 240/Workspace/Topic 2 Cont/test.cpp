#include <iostream>
#include "queue.h"
#include "array_queue.h"
#include "linked_queue.h"

#define TESTVAL 5

void testEnqueueEmpty(Queue<int>*);
void testEnqueueMultiItems(Queue<int>*);
void testDequeue(Queue<int>*);
void testClear(Queue<int>*);

int main(int argc, char const *argv[]){
    try{
    testEnqueueEmpty(new ArrayQueue<int>);
    testEnqueueMultiItems(new ArrayQueue<int>);
    testDequeue(new ArrayQueue<int>);
    testClear(new ArrayQueue<int>);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }

	return 0;
}

void testEnqueueEmpty(Queue<int>* queue){
    if(!queue->isEmpty()) throw std::runtime_error("FAIL: initilization not empty");
    queue->enqueue(TESTVAL);    
    if(queue->isEmpty()) throw std::runtime_error("FAIL: queue empty after add");

    std::cout << "SUCCESS: testEnqueueEmpty" << std::endl;
}

void testEnqueueMultiItems(Queue<int>* queue){
    for (size_t i = 0; i <= 3000; ++i){
        queue->enqueue(i);
    }
    if(queue->isEmpty()) throw std::runtime_error("FAIL: queue empty after add");

    std::cout << "SUCCESS: testEnqueueMultiItems" << std::endl;
}

void testDequeue(Queue<int>* queue){
    for (size_t i = 0; i <= 3000; ++i){ queue->enqueue(i); }
    for (size_t i = 0; i < 3000; ++i) {
        if(queue->dequeue() != i) throw std::runtime_error("FAIL: did not dequeue in correct order");
    }
    std::cout << "SUCCESS: testDequeue" << std::endl;
}

void testClear(Queue<int>* queue) {

}