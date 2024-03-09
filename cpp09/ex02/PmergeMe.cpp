#include "PmergeMe.hpp"

#include <algorithm>
#include <vector>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(std::vector<unsigned int> &array) { mergeSort(array); }
PmergeMe::PmergeMe(std::list<unsigned int> &lst) { mergeSort(lst); }
PmergeMe::PmergeMe(PmergeMe const &src) { *this = src; }
PmergeMe &PmergeMe::operator=(PmergeMe const &src) {
	if (this != &src) {
		*this = src;
	}
	return *this;
}
PmergeMe::~PmergeMe() {}

void PmergeMe::mergeSort(std::vector<unsigned int> &array) {
	std::vector<unsigned int>::size_type size = array.size();
	if (size <= 1) {
		return;
	}

	unsigned int middle = size / 2;
	std::vector<unsigned int> left(array.begin(), array.begin() + middle);
	std::vector<unsigned int> right(array.begin() + middle, array.end());

	unsigned int iLeft = 0;
	unsigned int iRight = 0;
	for (; iLeft < size; iLeft++) {
		if (iLeft < middle) {
			left[iLeft] = array[iLeft];
		} else {
			right[iRight] = array[iLeft];
			iRight++;
		}
	}
	mergeSort(left);
	mergeSort(right);
	std::merge(left.begin(), left.end(), right.begin(), right.end(),
			   array.begin());
}

void PmergeMe::mergeSort(std::list<unsigned int> &lst) {
	std::list<unsigned int>::size_type size = lst.size();
	if (size <= 1) {
		return;
	}

	unsigned int middle = size / 2;
	std::list<unsigned int> left, right;
	std::list<unsigned int>::iterator it = lst.begin();
	for (unsigned int i = 0; i < middle; ++i) {
		left.push_back(*it);
		++it;
	}
	while (it != lst.end()) {
		right.push_back(*it);
		++it;
	}

	mergeSort(left);
	mergeSort(right);

	lst.clear();
	std::merge(left.begin(), left.end(), right.begin(), right.end(),
			   std::back_inserter(lst));
}
