/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:03:24 by lray              #+#    #+#             */
/*   Updated: 2024/03/04 20:51:29 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}
Span::Span(unsigned int n) : _maxSize(n){};
Span::Span(Span const &src) : _maxSize(src._maxSize), _data(src._data) {}
Span::~Span() {}
Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_maxSize = rhs._maxSize;
		this->_data = rhs._data;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (_data.size() >= _maxSize)
		throw std::runtime_error("Span is full");
	_data.push_back(number);
}

int Span::shortestSpan() const
{
	if (_data.size() < 2)
		throw std::runtime_error("Not enough numbers in span");
	std::vector<int> vecCopy = _data;
	std::sort(vecCopy.begin(), vecCopy.end());
	int shortest = vecCopy[1] - vecCopy[0];
	for (unsigned int i = 2; i < vecCopy.size(); ++i)
	{
		shortest = std::min(shortest, vecCopy[i] - vecCopy[i - 1]);
	}
	return shortest;
}

int Span::longestSpan() const
{
	if (_data.size() < 2)
		throw std::runtime_error("Not enough numbers in span");
	std::vector<int>::const_iterator minElement = std::min_element(_data.begin(), _data.end());
	std::vector<int>::const_iterator maxElement = std::max_element(_data.begin(), _data.end());
	return *maxElement - *minElement;
}
