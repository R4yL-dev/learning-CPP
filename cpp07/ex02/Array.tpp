/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:19:31 by lray              #+#    #+#             */
/*   Updated: 2024/03/03 22:35:55 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <class T>
Array<T>::Array()
{
	this->_array = new T[0];
	this->_size = 0;
}

template <class T>
Array<T>::Array(unsigned int n)
{
	this->_array = new T[n];
	this->_size = n;
}

template <class T>
Array<T>::Array(Array const &src)
{
	this->_array = new T[src.size()];
	this->_size = src.size();
	for (unsigned int i = 0; i < src.size(); ++i)
	{
		this->_array[i] = src[i];
	}
}

template <class T>
Array<T>::~Array()
{
	delete[] this->_array;
}

template <class T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
{
	if (this != &rhs)
	{
		delete[] this->_array;
		this->_array = new T[rhs.size()];
		this->_size = rhs.size();
		for (unsigned int i = 0; i < rhs.size(); ++i)
		{
			this->_array[i] = rhs[i];
		}
	}
	return *this;
}

template <class T>
T &Array<T>::operator[](unsigned int i) const
{
	if (i >= this->_size)
		throw(IndexOutOfBoundsException());
	return this->_array[i];
}

template <class T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <class T>
const char *Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return "Array index is out of bounds";
}

#endif
