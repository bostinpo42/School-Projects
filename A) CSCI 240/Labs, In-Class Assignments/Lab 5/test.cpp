
#include<iostream>
#include"priorityqueue.h"

const unsigned char MAX{'M'};
const unsigned char MIN{'m'};

const size_t ASIZE = 20;
const size_t TARRAY[] {5, 10, 25, 15, 55, 35, 75, 99, 32, 65, 31, 42, 3, 88, 1, 100, 57, 33, 96, 26};

void testDequeue(PQueue<int> pq);
void testDequeue(PQueue<size_t> pq);

int main(int argc, char const *argv[]){
    PQueue<int> Default([] (size_t l, size_t r) { return l < r; });

    PQueue<size_t> h(10, [] (size_t l, size_t r) { return l < r; });

	PQueue<size_t> q(TARRAY, ASIZE, [] (size_t l, size_t r) { return l > r; });

    std::cout << std::boolalpha << "Is Default empty?: " << Default.isEmpty() << std::endl;

    std::cout << "Front of q: " << q.front() << std::endl;

    for(size_t i{0}; i <= ASIZE; i++) {
        Default.enqueue(TARRAY[i]);
    }

    testDequeue(Default);

    for(size_t i{0}; i <= ASIZE - 1; i++) {
        h.enqueue(TARRAY[i]);
    }

    testDequeue(h);

    testDequeue(q);

	return 0;
}

void testDequeue(PQueue<int> pq) {
    for(size_t i{0}; i < ASIZE; ++i) {
        std::cout<< "Removed " << pq.dequeue() << " from the queue. \n";
    }
}

void testDequeue(PQueue<size_t> pq) {
    for(size_t i{0}; i < ASIZE; ++i) {
        std::cout<< "Removed " << pq.dequeue() << " from the queue. \n";
    }
}
