#include <iostream>
#include <string>
#include <map>
#include <sstream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
/*
associative containers:
have no idea of a sequence
data is accessed using the key instead of indices.
include:
	std::map<T1, T2>
	std::set<T>
	
	Based on ordering property of keys, keys need to be comparable using < (less than) operator. 

	Map/set: keys in sorted order, faster to iterate through a range of elements

	std::unordered_map<T1, T2>
	std::unordered_set<T>

	unordered map/set: faster to access individual elements by key
*/
string GetLine() {
	string response;
	std::getline(cin, response);
	return response;
}

int main() {
	std::map<string, int> frequencyMap;
	cout << "Enter words." << endl;
	while (true) {
		cout << "> ";
		string response = GetLine();
		// if the user doesn't input any messages into the terminal, the while loop will terminate
		if (response.empty()) break;
		std::istringstream stream(response);
		string word;
		while (stream >> word) {
			frequencyMap[word];	// automatically create an entry and default initialize it. 
			// while the api at() will check whether the key exists, if doesn't, it will throw an error
			++frequencyMap[word];
		}
	}

	cout << "Enter words to look up" << endl;
	while (true) {
		cout << "> ";
		string response = GetLine();
		if (response.empty()) break;
		if (frequencyMap.count(response)) {
			cout << frequencyMap[response] << " entries found." << endl;
		} 
		else {
			cout << "None" << endl;
		}
	}
	return 0;
}
