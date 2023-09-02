# include<sstream> // string stream
# include<iostream>
using namespace std;

int main() {
	// output string stream
	// stringstream::ate stands for at end 
    ostringstream oss("Ito En Green Teo ");
    oss << 16.9 << " ounce ";
    oss << "(Pack of " << 12 << ")";
    
    // istringstream reads to the next whitespace
    istringstream iss(oss.str());
    string amount;
    string unit;
    iss >> amount >> unit;
    cout << amount << endl;
    cout << unit << endl;
	return 0;
}
