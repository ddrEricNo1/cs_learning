/*
 * TODO: complete this file comment.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <chrono>
#include <vector>
#include "SimpleGraph.h"

using namespace std;

const double kPi = 3.14159265358979323;
const double kattract = 0.001;
const double krepel = 0.001;
static string filename = "";
static int mseconds;
static char trash;
static string secondsStr = "";

void Welcome();
void initialize_nodes(int);
void iterate_edge();
void iterate_node();
bool inputFile();
bool openFile();
bool inputSeconds();
bool checkSeconds();

vector<Node> nodeList;
vector<Edge> edgeList;
SimpleGraph graph;

// Main method
int main() {
    Welcome();
    InitGraphVisualizer(graph);

    /* TODO: your implementation here */

    // prompt the user for the name of a file that contains the graph data, and open th file. If unsuccessful, reprompt
    while (1) {
        // ask the user to input the file name
        bool fileRes = false;
        while (!fileRes) {
            fileRes = inputFile();
            if (fileRes == false) continue;
            fileRes = true;
        }

        bool fileOpenRes = false;
        while (!fileOpenRes) {
            fileOpenRes = openFile();
            if (!fileOpenRes) continue;
        }

        // prompt the user for the number of microseconds to run the algorithm, which should be a positive integer. If the input is invalid, reprompt.
        bool secondsRes = false;
        while (!secondsRes) {
            secondsRes = inputSeconds();
            if (secondsRes == false) continue;
        }

        bool secondsValid = false;
        while (!secondsValid) {
            secondsValid = checkSeconds();
            if (!secondsValid) continue;
        }

        // place all the nodes into a circle
        string lineContents;
        int numNodes = 0;

        // proces the first line in the file
        ifstream ifs(filename);
        getline(ifs, lineContents);

        istringstream contentiss(lineContents);
        contentiss >> numNodes;

        initialize_nodes(numNodes);

        // add all the edges to the graph
        while (ifs.peek() != EOF && getline(ifs, lineContents)) {	// keep fetching contents from the file line by line
            // the first and second node indices in one line
            size_t first, second;
            istringstream lineiss(lineContents);
            lineiss >> first >> second;
            Edge newEdge{first, second};
            edgeList.push_back(newEdge);
            lineiss.clear();
        }
        graph.edges = edgeList;

        // determine when to continue iterating
        auto start = std::chrono::high_resolution_clock::now();
        while ((std::chrono::duration_cast<std::chrono::milliseconds>(chrono::high_resolution_clock::now() - start)).count() < mseconds) {
            // iterate over each edge in edgeList
            iterate_edge();

            // iterate over each node in nodeList
            iterate_node();
        }

        graph.edges = edgeList;
        graph.nodes = nodeList;
        DrawGraph(graph);
    }
    // read the next lines of the files
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

// initialize the nodes into a circle, k represents the number of nodes in the graph
void initialize_nodes(int k) {
    for (int i = 0; i < k; i++) {
        auto [x, y] = make_pair(cos(2 * kPi * i / k),sin(2 * kPi * i / k));
        Node newNode = {x, y};
        nodeList.push_back(newNode);
    }
    graph.nodes = nodeList;
}

void iterate_edge() {
    // iterate over each edge in edgeList
    for (auto iter = edgeList.begin(); iter != edgeList.end(); iter++) {
        Node& first = nodeList[(*iter).start];
        Node& second = nodeList[(*iter).end];
        auto [x0, y0] = make_pair(first.x, first.y);
        auto [x1, y1] = make_pair(second.x, second.y);
        double Fattract = kattract * ((y1 - y0) * (y1 - y0) + (x1 - x0) * (x1 - x0));
        double theta = atan2(y1 - y0, x1 - x0);
        first.x += Fattract * cos(theta);
        first.y += Fattract * sin(theta);
        second.x -= Fattract * cos(theta);
        second.y -= Fattract * sin(theta);
    }
}

void iterate_node() {
    // iterate and update the coordinates of the ndoes
    for (size_t i = 0; i < nodeList.size() - 1; i++) {
        for (size_t j = i + 1; j < nodeList.size(); j++) {
            auto [x0, y0] = make_pair(nodeList[i].x, nodeList[i].y);
            auto [x1, y1] = make_pair(nodeList[j].x, nodeList[j].y);
            double Frepel = krepel / sqrt((y1 - y0) * (y1 - y0) + (x1 - x0) * (x1 - x0));
            double theta = atan2(y1 - y0, x1 - x0);
            nodeList[i].x -= Frepel * cos(theta);
            nodeList[i].y -= Frepel * sin(theta);
            nodeList[j].x += Frepel * cos(theta);
            nodeList[j].y += Frepel * sin(theta);
        }
    }
}

bool inputFile() {
    cout << "Enter the file name> ";

    // if the user fails to input the correct filename
    if (!getline(cin, filename)) {
        cout << "the system fails to fetch file name from the user input. Please input the file path again" << endl;
        return false;
    }
    cout << "you input the file name:> " << filename << endl;
    return true;
}


bool openFile() {
    // use input file stream to open a file
    ifstream ifs(filename);
    if (ifs.fail()) {
        cout << "fail to open the file, please input the file name again!" << endl;
        return false;
    }
    return true;
}

bool inputSeconds() {
    cout << "Input the number of microseconds to run the algorithm:> ";
    if (!getline(cin, secondsStr)) {
        cout << "Invalid input! Please re-input it again!" << endl;
        return false;
    }
    return true;
}

bool checkSeconds() {
    istringstream iss(secondsStr);
    if (!(iss >> mseconds) || (iss >> trash)) {
        cout << "invalid input!" << endl;
        return false;
    }

    if (mseconds <= 0) {
        cout << "the input number of microseconds should be a positive number!" << endl;
        return false;
    }
    return true;
}
