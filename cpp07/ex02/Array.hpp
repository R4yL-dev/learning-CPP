/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:07:17 by lray              #+#    #+#             */
/*   Updated: 2024/03/03 22:34:52 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(Array const &src);
	~Array();
	Array &operator=(Array const &rhs);

	T &operator[](unsigned int i) const;
	unsigned int size() const;

	class IndexOutOfBoundsException : public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	T *_array;
	unsigned int _size;
};

#endif
