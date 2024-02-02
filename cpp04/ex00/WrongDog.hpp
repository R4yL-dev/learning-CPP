/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:35:23 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 15:07:59 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {

public:
	WrongDog();
	WrongDog(WrongDog const &src);
	WrongDog &operator=(WrongDog const &rhs);
	~WrongDog();

	void makeSound() const;
};

#endif
