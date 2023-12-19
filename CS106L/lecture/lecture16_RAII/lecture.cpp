#include <iostream>
#include <fstream>
#include <mutex>
#include <map>
#include <memory>
/*
avoid using exception as it won't free the resources
RAII: resource acquisition is initialization
Or CADRE: constructor acquires, destructor releases
*/

// below codes are non-RAII compliant
void printFile() {
    std::ifstream input;
    input.open("hamlet.txt");

    input.close();
}

void cleanDatabase(std::mutex& databaseLock, std::map<int, int>& database) {
    databaseLock.lock();

    databaseLock.unlock();
}

// the fix is to wrap it in an object to ensure that the resource is released
void pirntFile1() {
    std::ifstream input("hamlet.txt");

    // read file
    // no close call needed
}
// stream destructor
// release access to file

void clearnDatabase1(std::mutex& databaseLock, std::map<int, int>& database) {
    std::lock_guard<std::mutex> lock(databaseLock);
    // other threads will not modify database
}

// std::unique_ptr
// uniquely owns its resources and deletes it when the object is destroyed.
void rawPtrFn() {
    Node* n = new Node;
    delete n;
}

void warPtrFn1() {
    std::unique_ptr<Node> n(new Node);
    // do struff
}

// std::shared_ptr
// resources can be shared by any number of shared_ptr
// delete when none of them point to it.     reference counting, keep track of counting how many pointers are pointing to the heap data

// std::weak_ptr
// similar to shared_ptr, but doesn't contribute to the reference count
