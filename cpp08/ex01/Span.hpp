/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:03:10 by lray              #+#    #+#             */
/*   Updated: 2024/03/04 20:51:33 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
public:
	Span(unsigned int n);
	Span(Span const &src);
	~Span();
	Span &operator=(Span const &rhs);

	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;

	template <typename Iter>
	void addRange(Iter begin, Iter end)
	{
		while (begin != end)
		{
			addNumber(*begin);
			++begin;
		}
	}

private:
	unsigned int _maxSize;
	std::vector<int> _data;
	Span();
};

#endif
