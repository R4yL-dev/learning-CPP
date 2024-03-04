/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:08:13 by lray              #+#    #+#             */
/*   Updated: 2024/03/04 18:29:01 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>

class NotFoundException;

template <typename T>
int easyfind(T &container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);

	if (it == container.end())
		throw NotFoundException();
	return *it;
}

class NotFoundException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Element not found";
	}
};

#endif
