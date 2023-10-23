#include <iostream>
#include <vector>
using namespace std;

const int KNumInts = 20;
void doBubbleSort(vector<int>& v) {
	for (size_t i = 0; i < v.size() - 1; i++) {
		for (size_t j = 0; j < v.size() -i - 1; j++) {
			if (v[j] > v[j+1]) {
				int tmp = v[j];
				v[j] = v[j+1];
				v[j+1] = tmp;
			}
		}
	}
}

/*int main() {
	vector<int> vec(KNumInts);
	for (size_t i = 0; i < vec.size(); i++) {
		vec[i] = rand();
	}	
	doBubbleSort(vec);
	
	// print out N numbers
	for (size_t i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
	return 0;
}*/

int main() {
	vector<int> bec(KNumInts);
	std::generate(vec.begin(), vec.end(), rand);
	std::sort(vec.begin(), vec.end());
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, "\n"));
	return 0;
}
