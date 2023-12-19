#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
template <typename T>
class PriorityQueue {
public:
    PriorityQueue() = default;
    ~PriorityQueue() = default;
    
    T top() {}
    void pop() {}
    void push(T val) {}
    void swap(int i, int j);
    void heapify(int i);

private:
    int size;
    std::vector<T> heap;
};

#endif