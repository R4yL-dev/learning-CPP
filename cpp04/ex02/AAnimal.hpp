/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:07:47 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 16:58:35 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal {

public:
	AAnimal();
	AAnimal(std::string const &type);
	AAnimal(AAnimal const &src);
	virtual ~AAnimal();
	AAnimal &operator=(AAnimal const &rhs);

	const std::string &getType() const;

	virtual void makeSound() const = 0;

protected:
	std::string _type;
};

#endif
