#include <iostream>

struct Course {
	std::string name;
	double rating;
};

std::vector<Course> readCourses() {
	std::vector<Course> v = {{"CS 106A", 4.4337}, {"CS 106B", 4.4025}, {"CS 107", 4.6912}, {"CS103", 4.0532}, {"CS 109", 4.6062}, {"CS 110", 4.343}};
	return v;
}

int main() {
	auto courses = readCourses();	
	auto numbers = readNumbers();
	std::sort(numbers.begin(), numbers.end());
	std::sort(courses.begin(), courses.end());

	return 0;
}
