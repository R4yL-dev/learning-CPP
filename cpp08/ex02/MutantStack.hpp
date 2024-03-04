/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:20:02 by lray              #+#    #+#             */
/*   Updated: 2024/03/04 22:42:00 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin() { return std::stack<T>::c.begin(); }
	iterator end() { return std::stack<T>::c.end(); }
	const_iterator begin() const { return std::stack<T>::c.begin(); }
	const_iterator end() const { return std::stack<T>::c.end(); }
};

#endif
