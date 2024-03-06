#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

class RPN {
   public:
	RPN(std::string const &str);
	RPN(RPN const &src);
	RPN &operator=(RPN const &rhs);
	~RPN();

   private:
	std::stack<int> _stack;

	RPN();
};

#endif
