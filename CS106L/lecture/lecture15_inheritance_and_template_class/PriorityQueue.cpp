#include "PriorityQueue.h"
template <typename T>
T PriorityQueue<T>::top() {
    return this->heap[0];
}

template<typename T>
void PriorityQueue<T>::pop() {
    swap(0, --this->size);
    heapify(0);
}

template<typename T>
void PriorityQueue<T>::push(T val) {
    int i = this->size;
    this->heap[this->size++] = val;
    while (this->heap[i] > this->heap[(i - 1) / 2]) {
        swap(i, (i - 1) /2);
        i = (i - 1) / 2;
    }
}

template<typename T>
void PriorityQueue<T>::swap(int i, int j) {
    T tmp = this->heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;
}

template<typename T>
void PriorityQueue<T>::heapify(int i) {
    int left = 2 * i + 1;
    while (left < this->size) {
        int best = left + 1 < this->size && this->heap[left + 1] > this->heap[left] ? left + 1 : left;
        best = this->heap[best] > heap[i] ? best : i;
        if (best == i) {
            return;
        }
        swap(i, best);
        i = best;
        left = 2 * i + 1;
    }
}


