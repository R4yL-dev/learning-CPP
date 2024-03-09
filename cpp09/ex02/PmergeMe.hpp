#ifndef PMERGEME
#define PMERGEME

#include <list>
#include <vector>

class PmergeMe {
   public:
	PmergeMe(std::vector<unsigned int> &array);
	PmergeMe(std::list<unsigned int> &lst);
	~PmergeMe();

   private:
	PmergeMe();
	PmergeMe &operator=(PmergeMe const &src);
	PmergeMe(PmergeMe const &src);
	void mergeSort(std::vector<unsigned int> &array);
	void mergeSort(std::list<unsigned int> &lst);
};

#endif
