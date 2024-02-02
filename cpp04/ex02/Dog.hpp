/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:35:23 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 17:00:33 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {

public:
	Dog();
	Dog(Dog const &src);
	Dog &operator=(Dog const &rhs);
	virtual ~Dog();

	void makeSound() const;
private:
	Brain *_brain;
};

#endif
