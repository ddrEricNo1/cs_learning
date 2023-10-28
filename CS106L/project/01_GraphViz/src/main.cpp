/*
 * TODO: complete this file comment.
 */
#include <iostream>
#include <fstream>
#include "SimpleGraph.h"

using namespace std;

void Welcome();

// Main method
int main() {
    Welcome();
    /* TODO: your implementation here */
    string filename = "";
    while (1) {
        cout << "Enter the file name> ";
        getline(cin, filename);

        // use input file stream to open a file
        ifstream ifs = ifstream(filename);

    }
    return 0;
}

/* Prints a message to the console welcoming the user and
 * describing the program. */
void Welcome() {
    cout << "Welcome to CS106L GraphViz!" << endl;
    cout << "This program uses a force-directed graph layout algorithm" << endl;
    cout << "to render sleek, snazzy pictures of various graphs." << endl;
    cout << endl;
}


