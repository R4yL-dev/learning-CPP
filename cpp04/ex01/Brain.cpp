/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:17:43 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 15:33:39 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor was call" << std::endl;
}
Brain::Brain(Brain const &src) {
	std::cout << "Brain copy constructor was call" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = src._ideas[i];
	}
}
Brain &Brain::operator=(Brain const &rhs) {
	std::cout << "Copy operator of Brain was call" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = rhs._ideas[i];
		}
	}
	return *this;
}
Brain::~Brain() {
	std::cout << "Brain destructor was call" << std::endl;
}
