/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:07:47 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 15:08:02 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {

public:
	WrongAnimal();
	WrongAnimal(std::string const &type);
	WrongAnimal(WrongAnimal const &src);
	~WrongAnimal();
	WrongAnimal &operator=(WrongAnimal const &rhs);

	const std::string &getType() const;

	void makeSound() const;

protected:
	std::string _type;
};

#endif
