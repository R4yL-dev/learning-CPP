#include <ctime>
#include <exception>
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
#include <vector>

#define RESET "\e[0m"
#define RED "\e[31m"

#include "PmergeMe.hpp"

template <typename T>
static void initArray(int argc, char **argv, T &array);
template <typename T>
static void showArray(T &array);
static void showUsage(char *name);

int main(int argc, char **argv) {
	if (argc < 2) {
		showUsage(argv[0]);
		return 1;
	}

	std::vector<unsigned int> array;
	std::list<unsigned int> lst;
	try {
		initArray(argc, argv, array);
		initArray(argc, argv, lst);
	} catch (std::exception &err) {
		std::cout << RED << "[!] " << err.what() << RESET << std::endl;
		showUsage(argv[0]);
		return 1;
	}

	std::cout << "Before std::vector:\t";
	showArray(array);
	std::cout << "Before std::list:\t";
	showArray(lst);

	clock_t startVector = clock();
	PmergeMe pmVector(array);
	clock_t endVector = clock();

	clock_t startList = clock();
	PmergeMe pmList(lst);
	clock_t endList = clock();

	double elapseVector =
		(endVector - startVector) / (double)CLOCKS_PER_SEC * 1000000.0;
	double elapseList =
		(endList - startList) / (double)CLOCKS_PER_SEC * 1000000.0;

	std::cout << "After std::vector:\t";
	showArray(array);
	std::cout << "After std::list:\t";
	showArray(lst);
	std::cout << "Time to process a range of " << argc - 1;
	std::cout << " elements with std::vector : ";
	std::cout << elapseVector << " us" << std ::endl;
	std::cout << "Time to process a range of " << argc - 1;
	std::cout << " elements with std::list : ";
	std::cout << elapseList << " us" << std ::endl;
	return 0;
}

template <typename T>
static void initArray(int argc, char **argv, T &array) {
	for (int i = 1; i < argc; i++) {
		std::istringstream iss(argv[i]);
		int num;
		if (!(iss >> num)) {
			throw std::runtime_error("impossible to convert");
		}
		array.push_back(num);
	}
}

template <typename T>
static void showArray(T &array) {
	typename T::iterator it = array.begin();

	while (it != array.end()) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

static void showUsage(char *name) {
	std::cout << "Usage: " << name << " <list_of_unsigned_integers>"
			  << std::endl;
}
